/**
 * @file parent_child_gchild_main.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "parent_child_gchild.cpp"

using namespace std;
using namespace parent;
using namespace child;
using namespace gchild;

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    Parent parent;
    Child child;
    GChild gchild;

    parent.setParentPublic(1);
    child.setParentPublic(2);
    gchild.setParentPublic(3);

    cout << "parent.getParentPublic(): " << parent.getParentPublic(1) << endl;
    cout << "child.getParentPublic(): " << child.getParentPublic(2) << endl;
    cout << "gchild.getParentPublic(): " << gchild.getParentPublic(3) << endl;

    printParentChildGChild(parent,child,gchild,3);
    saveParentChildGChildToDataTimeStampedFile(parent,child,gchild,3,"parent_child_gchild.txt");

    return 0;
}
