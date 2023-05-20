/**
 * @file searchTree.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "F:/GitHubRepos/absolute_cpp_v2/common.hpp"

using namespace std;

template<class T>
class TreeNode
{
public:
    T _data;
    TreeNode *_left;
    TreeNode *_right;

    TreeNode(const T &data, TreeNode *left = NULL, TreeNode *right = NULL)
        : _data(data), _left(left), _right(right) {}
};

template<class T>
class Tree
{
public:
    TreeNode<T> *_root;

    Tree() : _root(NULL) {}
    Tree(const Tree &rhs) : _root(NULL) { copy(rhs); }
    ~Tree() { makeEmpty(); }

    const Tree &operator=(const Tree &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            copy(rhs);
        }
        return *this;
    }

    void copy(const Tree &rhs)
    {
        _root = clone(rhs._root);
    }

    void makeEmpty()
    {
        makeEmpty(_root);
    }

    void insert(const T &data)
    {
        insert(data, _root);
    }

    void remove(const T &data)
    {
        remove(data, _root);
    }

    void printTree() const
    {
        if (isEmpty())
        {
            cout << "Empty tree" << endl;
        }
        else
        {
            printTree(_root);
        }
    }

    bool isEmpty() const
    {
        return _root == NULL;
    }

    TreeNode<T> *findMin() const
    {
        return findMin(_root);
    }

    TreeNode<T> *findMax() const
    {
        return findMax(_root);
    }

    bool contains(const T &data) const
    {
        return contains(data, _root);
    }
};

template <class T>
class SearchTree
{
public:
    T _Root_node;
    SearchTree();
    SearchTree(const SearchTree& rhs);
    ~SearchTree();

    const SearchTree& operator=(const SearchTree& rhs);
    void copy(const SearchTree &rhs);
    const T &findMin() const;
    const T& findMax() const;
    bool contains(const T& x) const;
    bool isEmpty() const;
    void printTree() const;

    void makeEmpty();
    void insert(const T& x);
    void remove(const T& x);
private:
    typedef struct BinaryNode
    {
        T element;
        BinaryNode* left;
        BinaryNode* right;

        BinaryNode(const T& theElement, BinaryNode* lt, BinaryNode* rt)
            : element(theElement), left(lt), right(rt) {}
    } BinaryNode;

    BinaryNode* root;

    void insert(const T& x, BinaryNode*& t) const;
    void remove(const T& x, BinaryNode*& t) const;
    BinaryNode* findMin(BinaryNode* t) const;
    BinaryNode* findMax(BinaryNode* t) const;
    bool contains(const T& x, BinaryNode* t) const;
    void makeEmpty(BinaryNode*& t);
    void printTree(BinaryNode* t) const;
    BinaryNode* clone(BinaryNode* t) const;
};

template <class T>
SearchTree<T>::SearchTree() : root(NULL)
{
}

template <class T>
SearchTree<T>::SearchTree(const SearchTree& rhs)
{
    root = clone(rhs.root);
}

template <class T>
SearchTree<T>::~SearchTree()
{
    makeEmpty();
}

template <class T>
const SearchTree<T>& SearchTree<T>::operator=(const SearchTree& rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
    return *this;
}

template <class T>
const T& SearchTree<T>::findMin() const
{
    return findMin(root)->element;
}

template <class T>
const T& SearchTree<T>::findMax() const
{
    return findMax(root)->element;
}

template <class T>
bool SearchTree<T>::contains(const T& x) const
{
    return contains(x, root);
}

template <class T>
bool SearchTree<T>::isEmpty() const
{
    return root == NULL;
}

template<class T>
void SearchTree<T>::copy(const SearchTree &rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        root = clone(rhs.root);
    }
}

template <class T>
void SearchTree<T>::printTree() const
{
    if (isEmpty())
    {
        cout << "Empty tree" << endl;
    }
    else
    {
        printTree(root);
    }
}

template <class T>
void SearchTree<T>::makeEmpty()
{
    makeEmpty(root);
}

template <class T>
void SearchTree<T>::insert(const T& x)
{
    insert(x, root);
}

template <class T>
void SearchTree<T>::remove(const T& x)
{
    remove(x, root);
}

template <class T>
void SearchTree<T>::insert(const T& x, BinaryNode*& t) const
{
    if (t == NULL)
    {
        t = new BinaryNode(x, NULL, NULL);
    }
    else if (x < t->element)
    {
        insert(x, t->left);
    }
    else if (t->element < x)
    {
        insert(x, t->right);
    }
    else
    {
        // Duplicate; do nothing
    }
}

template <class T>
void SearchTree<T>::remove(const T& x, BinaryNode*& t) const
{
    if (t == NULL)
    {
        return;
    }
    if (x < t->element)
    {
        remove(x, t->left);
    }
    else if (t->element < x)
    {
        remove(x, t->right);
    }
    else if (t->left != NULL && t->right != NULL)
    {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
    }
    else
    {
        BinaryNode* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}

template <class T>
typename SearchTree<T>::BinaryNode* SearchTree<T>::findMin(BinaryNode* t) const
{
    if (t == NULL)
    {
        return NULL;
    }
    if (t->left == NULL)
    {
        return t;
    }
    return findMin(t->left);
}

template <class T>
typename SearchTree<T>::BinaryNode* SearchTree<T>::findMax(BinaryNode* t) const
{
    if (t != NULL)
    {
        while (t->right != NULL)
        {
            t = t->right;
        }
    }
    return t;
}

template <class T>
bool SearchTree<T>::contains(const T& x, BinaryNode* t) const
{
    if (t == NULL)
    {
        return false;
    }
    else if (x < t->element)
    {
        return contains(x, t->left);
    }
    else if (t->element < x)
    {
        return contains(x, t->right);
    }
    else
    {
        return true;
    }
}

template <class T>
void SearchTree<T>::makeEmpty(BinaryNode*& t)
{
    if (t != NULL)
    {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

template <class T>
void SearchTree<T>::printTree(BinaryNode* t) const
{
    if (t != NULL)
    {
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template <class T>
typename SearchTree<T>::BinaryNode* SearchTree<T>::clone(BinaryNode* t) const
{
    if (t == NULL)
    {
        return NULL;
    }
    else
    {
        return new BinaryNode(t->element, clone(t->left), clone(t->right));
    }
}

int main(int argc, char **argv);

int main(int argc, char **argv)
{
    /**
     * @brief test the SearchTree program
     *
     */
    SearchTree<int> t;
    int NUMS = 100;
    const int GAP = 1;
    int i;
    for(i = GAP; i != 0; i = (i + GAP) % NUMS)
    {
        t.insert(i);
    }
    for(i = 1; i < NUMS; i += 2)
    {
        t.remove(i);
    }
    if (NUMS < 40)
    {
        t.printTree();
    }
    if (t.findMin() != 2 || t.findMax() != NUMS - 2)
    {
        cout << "FindMin or FindMax error!" << endl;
    }
    for(i = 2; i < NUMS; i += 2)
    {
        if (!t.contains(i))
        {
            cout << "Find error1!" << endl;
        }
    }
    for(i = 1; i < NUMS; i += 2)
    {
        if (t.contains(i))
        {
            cout << "Find error2!" << endl;
        }
    }
    SearchTree<int> t2;
    t2 = t;
    for(i = 2; i < NUMS; i += 2)
    {
        if (!t2.contains(i))
        {
            cout << "Find error1!" << endl;
        }
    }
    t.printTree();
    t2.printTree();
    return 0;
}
