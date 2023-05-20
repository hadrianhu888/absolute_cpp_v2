/**
 * @file graph.cpp
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

template <class T>
class Node
{
    public:
        T _data;
        Node<T> *_next;

        Node(const T& data, Node<T> *next = NULL) : _data(data), _next(next) {}
};

template <class T>
class Edge
{
    public:
        T _v1;
        T _v2;
        int weight;
        float time;
        Edge<T> *_next;

        Edge(const T& v1, const T& v2, int weight = 0, float time = 0.0, Edge<T> *next = NULL) : _v1(v1), _v2(v2), weight(weight), time(time), _next(next) {}
};

template <class T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        void insert(const T& data);
        void remove(const T& data);
        bool search(const T& data) const;
        void print() const;
        Node<T> *getHead() const;
        Node<T> *getTail() const;
        Node<T> *getCurrent() const;
        Node<T> *getLeft() const;
        Node<T> *getRight() const;
        Node<T> *getForward() const;
        Node<T> *getBackward() const;
    private:
        Node<T> *_head;
        Node<T> *_tail;
        Node<T> *_current;
        Node<T> *_left;
        Node<T> *_right;
        Node<T> *_forward;
        Node<T> *_backward;

};

template <class T>
class Graph: public LinkedList<T>
{
    public:
        Graph(int size = 0);
        ~Graph();
        void addEdge(const T& v1, const T& v2);
        void print() const;
        Graph TravereGraph(const T &v1, const T &v2);
        Graph DepthFirstSearch(const T &v1, const T &v2);
        Graph BreadthFirstSearch(const T &v1, const T &v2);
        Graph findShortestRoute(const T &v1, const T &v2);
        Graph findShortestTimedRoute(const T &v1, const T &v2);
    private:
        int _size;
        LinkedList<int> *_adjacencyList;
};

template <class T>
LinkedList<T>::LinkedList() : _head(NULL)
{
    return;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = _head;
    while (p != NULL)
    {
        Node<T> *next = p->_next;
        delete p;
        p = next;
    }
}

template <class T>
void LinkedList<T>::insert(const T& data)
{
    Node<T> *p = _head;
    Node<T> *prev = NULL;
    while (p != NULL && p->_data < data)
    {
        prev = p;
        p = p->_next;
    }
    if (p != NULL && p->_data == data)
    {
        return;
    }
    Node<T> *newNode = new Node<T>(data, p);
    if (prev == NULL)
    {
        _head = newNode;
    }
    else
    {
        prev->_next = newNode;
    }
}

template <class T>
void LinkedList<T>::remove(const T& data)
{
    Node<T> *p = _head;
    Node<T> *prev = NULL;
    while (p != NULL && p->_data < data)
    {
        prev = p;
        p = p->_next;
    }
    if (p == NULL || p->_data > data)
    {
        return;
    }
    if (prev == NULL)
    {
        _head = p->_next;
    }
    else
    {
        prev->_next = p->_next;
    }
    delete p;
}

template <class T>
bool LinkedList<T>::search(const T& data) const
{
    Node<T> *p = _head;
    while (p != NULL && p->_data < data)
    {
        p = p->_next;
    }
    if (p == NULL || p->_data > data)
    {
        return false;
    }
    return true;
}

template <class T>
void LinkedList<T>::print() const
{
    Node<T> *p = _head;
    while (p != NULL)
    {
        cout << p->_data << " ";
        p = p->_next;
    }
    cout << endl;
}

template <class T>
Node<T> *LinkedList<T>::getHead() const
{
    return _head;
}

template <class T>
Node<T> *LinkedList<T>::getTail() const
{
    Node<T> *p = _head;
    while (p != NULL && p->_next != NULL)
    {
        p = p->_next;
    }
    return p;
}

template <class T>
Node<T> *LinkedList<T>::getCurrent() const
{
    return _current;
}

template <class T>
Node<T> *LinkedList<T>::getLeft() const
{
    return _left;
}

template <class T>
Node<T> *LinkedList<T>::getRight() const
{
    return _right;
}

template <class T>
Node<T> *LinkedList<T>::getForward() const
{
    return _forward;
}

template <class T>
Node<T> *LinkedList<T>::getBackward() const
{
    return _backward;
}

template <class T>
Graph<T>::Graph(int size) : _size(size)
{
    _adjacencyList = new LinkedList<int>[_size];
}

template <class T>
Graph<T>::~Graph()
{
    delete [] _adjacencyList;
}

template <class T>
void Graph<T>::addEdge(const T& v1, const T& v2)
{
    _adjacencyList[v1].insert(v2);
    _adjacencyList[v2].insert(v1);
}

template <class T>
Graph<T> Graph<T>::TravereGraph(const T &v1, const T &v2)
{
    Graph<T> g(_size);
    g.addEdge(v1, v2);
    return g;
}

template <class T>
Graph<T> Graph<T>::DepthFirstSearch(const T &start, const T &end)
{
    Graph<T> g(_size);
    vector<bool> visited(_size, false);
    stack<T> s;

    s.push(start);
    while (!s.empty())
    {
        T v = s.top();
        s.pop();

        if (!visited[v])
        {
            visited[v] = true;
            if (v == end)
            {
                break;
            }

            Node<int> *p = _adjacencyList[v].getHead();
            while (p)
            {
                if (!visited[p->_data])
                {
                    g.addEdge(v, p->_data);
                    s.push(p->_data);
                }
                p = p->_next;
            }
        }
    }

    return g;
}


template <class T>
Graph<T> Graph<T>::BreadthFirstSearch(const T &v1, const T &v2)
{
    Graph<T> g(_size);
    vector<bool> visited(_size, false);
    queue<T> q;

    q.push(v1);
    while (!q.empty())
    {
        T v = q.front();
        q.pop();

        if (!visited[v])
        {
            visited[v] = true;
            if (v == v2)
            {
                break;
            }

            Node<int> *p = _adjacencyList[v].getHead();
            while (p)
            {
                if (!visited[p->_data])
                {
                    g.addEdge(v, p->_data);
                    q.push(p->_data);
                }
                p = p->_next;
            }
        }
    }

    return g;
}

template <class T>
Graph<T> Graph<T>::findShortestRoute(const T &v1, const T &v2)
{
    // Array to store shortest distances from v1
    vector<int> dist(_size, INT_MAX);
    dist[v1] = 0;

    // Array to store previous node in shortest path
    vector<int> prev(_size, -1);

    // Set of vertices not yet processed
    set<pair<int, T>> vertices;
    vertices.insert({0, v1});

    while (!vertices.empty())
    {
        // Vertex with minimum distance will be first in the set
        T u = vertices.begin()->second;
        vertices.erase(vertices.begin());

        // 'i' is used to get all adjacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = _adjacencyList[u].getHead(); i != _adjacencyList[u].getTail(); ++i)
        {
            T v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // If distance of v is not INF then it must be in
                // our set, so removing it and inserting again
                // with updated less distance.
                if (dist[v] != INT_MAX)
                    vertices.erase(vertices.find({dist[v], v}));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                vertices.insert({dist[v], v});

                // Update previous node for v
                prev[v] = u;
            }
        }
    }

    // At this point, `dist` contains the shortest distances from `v1` to all other vertices,
    // and `prev` contains the previous node in the shortest path from `v1` to each vertex.
    // You can use this information to build the shortest path from `v1` to `v2` and add it to a new graph.

    Graph<T> g(_size);
    T v = v2;
    while (v != v1)
    {
        g.addEdge(v, prev[v]);
        v = prev[v];
    }

    return g;
}


template <class T>
Graph<T> Graph<T>::findShortestTimedRoute(const T &v1, const T &v2)
{
    // Array to store shortest distances from v1
    vector<int> dist(_size, INT_MAX);
    dist[v1] = 0;

    // Array to store previous node in shortest path
    vector<int> prev(_size, -1);

    // Set of vertices not yet processed
    set<pair<int, T>> vertices;
    vertices.insert({0, v1});

    while (!vertices.empty())
    {
        // Vertex with minimum distance will be first in the set
        T u = vertices.begin()->second;
        vertices.erase(vertices.begin());

        // 'i' is used to get all _adjacencyListacent vertices of a vertex
        list<pair<int, int>>::iterator i;
        for (i = _adjacencyList[u].getHead(); i != _adjacencyList[u].getTail(); ++i)
        {
            T v = (*i).first;
            int weight = (*i).second;

            // If there is shorter path to v through u.
            if (dist[v] > dist[u] + weight)
            {
                // If distance of v is not INF then it must be in
                // our set, so removing it and inserting again
                // with updated less distance.
                if (dist[v] != INT_MAX)
                    vertices.erase(vertices.find({dist[v], v}));

                // Updating distance of v
                dist[v] = dist[u] + weight;
                vertices.insert({dist[v], v});

                // Update previous node for v
                prev[v] = u;
            }
        }
    }

    // At this point, `dist` contains the shortest distances from `v1` to all other vertices,
    // and `prev` contains the previous node in the shortest path from `v1` to each vertex.
    // You can use this information to build the shortest path from `v1` to `v2` and add it to a new graph.

    Graph<T> g(_size);
    T v = v2;
    while (v != v1)
    {
        g.addEdge(v, prev[v]);
        v = prev[v];
    }

    return g;
}

template <class T>
void Graph<T>::print() const
{
    for (int i = 0; i < _size; ++i)
    {
        cout << i << ": ";
        _adjacencyList[i].print();
    }
}

int main()
{
    Graph<int> g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.print();
    g.TravereGraph(0, 4).print();
    Graph<int> g2 = g.DepthFirstSearch(0, 4);
    g2.print();
    Graph<int> g3 = g.BreadthFirstSearch(0, 4);
    g3.print();
    Graph<int> g4 = g.findShortestRoute(0, 4);
    g4.print();
    Graph<int> g5 = g.findShortestTimedRoute(0, 4);
    g5.print();
    return 0;
}
