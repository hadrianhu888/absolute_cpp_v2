/**
 * @file multiple_inheritance.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"
#include "multiple_inheritance.h"

using namespace std;
using namespace parent;
using namespace child;
using namespace gchild;

Parent::Parent()
{
    cout << "Parent constructor called" << endl;
}

int Parent::setParentPrivate(int parent_private)
{
    this->parent_private = parent_private;
    return 0;
}

int Parent::getParentPrivate(int parent_private)
{
    return this->parent_private;
}

int Parent::setParentProtected(int parent_protected)
{
    this->parent_protected = parent_protected;
    return 0;
}

int Parent::getParentProtected(int parent_protected)
{
    return this->parent_protected;
}

int Parent::setParentPublic(int parent_public)
{
    this->parent_public = parent_public;
    return 0;
}

int Parent::getParentPublic(int parent_public)
{
    return this->parent_public;
}

Parent::~Parent()
{
    cout << "Parent destructor called" << endl;
}

Child::Child()
{
    cout << "Child constructor called" << endl;
}

int Child::setChildPrivate(int child_private)
{
    this->child_private = child_private;
    return 0;
}

int Child::getChildPrivate(int child_private)
{
    return this->child_private;
}

int Child::setChildProtected(int child_protected)
{
    this->child_protected = child_protected;
    return 0;
}

int Child::getChildProtected(int child_protected)
{
    return this->child_protected;
}

int Child::setChildPublic(int child_public)
{
    this->child_public = child_public;
    return 0;
}

int Child::getChildPublic(int child_public)
{
    return this->child_public;
}

Child::~Child()
{
    cout << "Child destructor called" << endl;
}

GChild::GChild()
{
    cout << "GrandChild constructor called" << endl;
}

int GChild::setGChildPrivate(int gchild_private)
{
    this->gchild_private = gchild_private;
    return 0;
}

int GChild::getGChildPrivate(int gchild_private)
{
    return this->gchild_private;
}

int GChild::setGChildProtected(int gchild_protected)
{
    this->gchild_protected = gchild_protected;
    return 0;
}

int GChild::getGChildProtected(int gchild_protected)
{
    return this->gchild_protected;
}

int GChild::setGChildPublic(int gchild_public)
{
    this->gchild_public = gchild_public;
    return 0;
}

int GChild::getGChildPublic(int gchild_public)
{
    return this->gchild_public;
}

GChild::~GChild()
{
    cout << "GrandChild destructor called" << endl;
}
