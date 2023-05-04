/**
 * @file multiple_inheritance.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef MULTIPLE_INHERITANCE_H
#define MULTIPLE_INHERITANCE_H

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

namespace parent
{
    class Parent
    {
        private:
            int parent_private;
        protected:
            int parent_protected;
        public:
            int parent_public;
            Parent();
            int setParentPrivate(int parent_private);
            int getParentPrivate(int parent_private);
            int setParentProtected(int parent_protected);
            int getParentProtected(int parent_protected);
            int setParentPublic(int parent_public);
            int getParentPublic(int parent_public);
            ~Parent();
    };
} // namespace parent

namespace child
{
    class Child:public parent::Parent
    {
        private:
            int child_private;
        protected:
            int child_protected;
        public:
            int child_public;
            Child();
            int setChildPrivate(int child_private);
            int getChildPrivate(int child_private);
            int setChildProtected(int child_protected);
            int getChildProtected(int child_protected);
            int setChildPublic(int child_public);
            int getChildPublic(int child_public);
            ~Child();
    };
} // namespace child

namespace gchild
{
    class GChild:public child::Child, public parent::Parent
    {
        private:
            int gchild_private;
        protected:
            int gchild_protected;
        public:
            int gchild_public;
            GChild();
            int setGChildPrivate(int gchild_private);
            int getGChildPrivate(int gchild_private);
            int setGChildProtected(int gchild_protected);
            int getGChildProtected(int gchild_protected);
            int setGChildPublic(int gchild_public);
            int getGChildPublic(int gchild_public);
            ~GChild();
    };
} // namespace gchild

#endif // MULTIPLE_INHERITANCE_H
