/**
 * @file graph_v1.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-05-20
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

    Node(const T &data, Node<T> *next = NULL) : _data(data), _next(next)
    {
    }
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

    Edge(const T &v1, const T &v2, int weight = 0, float time = 0.0, Edge<T> *next = NULL)
        : _v1(v1), _v2(v2), weight(weight), time(time), _next(next)
    {
    }
    friend ostream &operator<<(ostream &os, const Edge &e)
    {
        os << e._v1 << " " << e._v2 << " " << e.weight << " " << e.time;
        return os;
    }
};

template <class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    void insert(const T &data);
    void remove(const T &data);
    bool search(const T &data) const;
    void print() const;
    Node<T> *getHead() const;
    Node<T> *getTail() const;
private:
    Node<T> *_head;
    Node<T> *_tail;
};

template <class T>
class Graph
{
public:
    Graph(int size = 0);
    ~Graph();
    void addEdge(const T &v1, const T &v2);
    void print() const;
    Graph TraverseGraph(const T &v1, const T &v2);
    Graph DepthFirstSearch(const T &v1, const T &v2);
    Graph BreadthFirstSearch(const T &v1, const T &v2);
    vector<T> findShortestRoute(const T &v1, const T &v2);

private:
    int _size;
    LinkedList<Edge<T>> *_adjacencyList;
};

template <class T>
class Maze
{
public:
    Maze(int size = 0);
    ~Maze();
    void addEdge(const T &v1, const T &v2);
    void print() const;
    Maze findShortestRoute(const T &v1, const T &v2);
private:
    int _size;
    LinkedList<Edge<T>> *_adjacencyList;
    Node<T> *_start;
    Node<T> *_end;
};

int main(int argc, char **argv);

template <class T>
LinkedList<T>::LinkedList()
{
    _head = NULL;
    _tail = NULL;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *current = _head;
    Node<T> *next;

    while (current != NULL)
    {
        next = current->_next;
        delete current;
        current = next;
    }
}

template <class T>
void LinkedList<T>::insert(const T &data)
{
    Node<T> *newNode = new Node<T>(data);

    if (_head == NULL)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        _tail->_next = newNode;
        _tail = newNode;
    }
}

template <class T>
void LinkedList<T>::remove(const T &data)
{
    Node<T> *current = _head;
    Node<T> *previous = NULL;

    while (current != NULL && current->_data != data)
    {
        previous = current;
        current = current->_next;
    }

    if (current == NULL)
    {
        return;
    }

    if (previous == NULL)
    {
        _head = _head->_next;
    }
    else
    {
        previous->_next = current->_next;
    }

    if (current == _tail)
    {
        _tail = previous;
    }

    delete current;
}

template <class T>
bool LinkedList<T>::search(const T &data) const
{
    Node<T> *current = _head;

    while (current != NULL && current->_data != data)
    {
        current = current->_next;
    }

    return current != NULL;
}

template <class T>
void LinkedList<T>::print() const
{
    Node<T> *current = _head;

    while (current != NULL)
    {
        cout << current->_data << " ";
        current = current->_next;
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
    return _tail;
}

template <class T>
Graph<T>::Graph(int size)
{
    _size = size;
    _adjacencyList = new LinkedList<Edge<T>>[_size];
}

template <class T>
Graph<T>::~Graph()
{
    delete[] _adjacencyList;
}

template <class T>
void Graph<T>::addEdge(const T &v1, const T &v2)
{
    _adjacencyList[v1].insert(Edge<T>(v1, v2));
}

template <class T>
void Graph<T>::print() const
{
    for (int i = 0; i < _size; i++)
    {
        cout << i << ": ";
        _adjacencyList[i].print();
    }
}

template <class T>
Graph<T> Graph<T>::TraverseGraph(const T &v1, const T &v2)
{
    Graph<T> result(_size);
    Node<Edge<T>> *current = _adjacencyList[v1].getHead();

    while (current != NULL)
    {
        result.addEdge(current->_data._v1, current->_data._v2);
        current = current->_next;
    }

    return result;
}

template <class T>
Graph<T> Graph<T>::DepthFirstSearch(const T &v1, const T &v2)
{
    Graph<T> result(_size);
    stack<T> stack;
    unordered_set<T> visited;

    stack.push(v1);

    while (!stack.empty())
    {
        T current = stack.top();
        stack.pop();

        if (current == v2)
            return result;

        if (visited.count(current) == 0)
        {
            visited.insert(current);
            Node<Edge<T>> *edge = _adjacencyList[current].getHead();

            while (edge != NULL)
            {
                stack.push(edge->_data._v2);
                result.addEdge(edge->_data._v1, edge->_data._v2);
                edge = edge->_next;
            }
        }
    }

    // The path from v1 to v2 was not found.
    return Graph<T>();
}

template <class T>
Graph<T> Graph<T>::BreadthFirstSearch(const T &v1, const T &v2)
{
    Graph<T> result(_size);
    queue<T> queue;
    unordered_set<T> visited;

    queue.push(v1);

    while (!queue.empty())
    {
        T current = queue.front();
        queue.pop();

        if (current == v2)
            return result;

        if (visited.count(current) == 0)
        {
            visited.insert(current);
            Node<Edge<T>> *edge = _adjacencyList[current].getHead();

            while (edge != NULL)
            {
                queue.push(edge->_data._v2);
                result.addEdge(edge->_data._v1, edge->_data._v2);
                edge = edge->_next;
            }
        }
    }

    // The path from v1 to v2 was not found.
    return Graph<T>();
}

template <class T>
vector<T> Graph<T>::findShortestRoute(const T &v1, const T &v2)
{
    priority_queue<pair<int, T>, vector<pair<int, T>>, greater<pair<int, T>>> pq;
    unordered_map<T, T> prev;
    unordered_map<T, int> dist;

    for (auto const &[key, val] : _adjacencyList)
    {
        dist[key] = INT_MAX;
    }

    pq.push(make_pair(0, v1));
    dist[v1] = 0;

    while (!pq.empty())
    {
        T u = pq.top().second;
        pq.pop();

        Node<Edge<T>> *head = _adjacencyList[u].getHead();
        while (head != nullptr)
        {
            T v = head->_data._v2;
            int weight = head->_data._weight; // Assuming Edge has a 'weight' member

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                prev[v] = u;
            }

            head = head->_next;
        }
    }

    vector<T> path;
    for (T at = v2; at != v1; at = prev[at])
    {
        path.push_back(at);
    }
    path.push_back(v1);

    reverse(path.begin(), path.end());
    return path;
}

int main(int argc, char **argv)
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

    return 0;
}
