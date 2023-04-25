/**
 * @file correct_cin_cout_stream_syntax.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-04-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

#include <clang/ASTMatchers/ASTMatchFinder.h>
#include <clang/ASTMatchers/ASTMatchers.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>

using namespace clang;
using namespace clang::ast_matchers;
using namespace clang::tooling;
using namespace llvm;

static cl::OptionCategory ToolCategory("cin-cout-syntax-fixer");

class CinCoutSyntaxFixer : public MatchFinder::MatchCallback
{
public:
    explicit CinCoutSyntaxFixer(Replacements &Replace) : Replace(Replace)
    {
    }

    void run(const MatchFinder::MatchResult &Result) override
    {
        const auto *WrongCin = Result.Nodes.getNodeAs<CXXOperatorCallExpr>("wrongCin");
        const auto *WrongCout = Result.Nodes.getNodeAs<CXXOperatorCallExpr>("wrongCout");

        if (WrongCin)
        {
            Replace.insert(Replacement(*Result.SourceManager, WrongCin->getOperatorLoc(), 2, ">>"));
        }

        if (WrongCout)
        {
            Replace.insert(Replacement(*Result.SourceManager, WrongCout->getOperatorLoc(), 2, "<<"));
        }
    }

private:
    Replacements &Replace;
};

int main(int argc, const char **argv)
{
    CommonOptionsParser OptionsParser(argc, argv, ToolCategory);
    ClangTool Tool(OptionsParser.getCompilations(), OptionsParser.getSourcePathList());

    MatchFinder Finder;
    Replacements Repls;

    CinCoutSyntaxFixer Fixer(Repls);

    Finder.addMatcher(cxxOperatorCallExpr(
                          hasOverloadedOperatorName("<<"),
                          hasArgument(0, expr(hasType(asString("std::basic_istream<char, std::char_traits<char> >")))))
                          .bind("wrongCin"),
                      &Fixer);

    Finder.addMatcher(cxxOperatorCallExpr(
                          hasOverloadedOperatorName(">>"),
                          hasArgument(0, expr(hasType(asString("std::basic_ostream<char, std::char_traits<char> >")))))
                          .bind("wrongCout"),
                      &Fixer);

    Tool.run(newFrontendActionFactory(&Finder).get());

    for (const auto &Replacement : Repls)
    {
        llvm::errs() << Replacement.toString() << "\n";
    }

    return 0;
}
