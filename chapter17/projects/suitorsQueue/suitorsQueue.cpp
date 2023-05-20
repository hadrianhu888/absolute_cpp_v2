/**
 * @file suitorsQueue.cpp
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
class Queue
{
private:
    typedef struct Node
    {
        T _data;
        Node *_next;

        Node(const T &data, Node *next = NULL) : _data(data), _next(next) {}
    } Node;

    Node *_front;
    Node *_rear;

public:
    Queue() : _front(NULL), _rear(NULL) {}
    Queue(const Queue &rhs) : _front(NULL), _rear(NULL) { copy(rhs); }
    ~Queue() { makeEmpty(); }

    const Queue &operator=(const Queue &rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            copy(rhs);
        }
        return *this;
    }

    void copy(const Queue &rhs)
    {
        Node *p = rhs._front;
        while (p != NULL)
        {
            enqueue(p->_data);
            p = p->_next;
        }
    }

    void makeEmpty()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    bool isEmpty() const
    {
        return _front == NULL;
    }

    void enqueue(const T &data)
    {
        Node *newNode = new Node(data);
        if (isEmpty())
        {
            _front = newNode;
        }
        else
        {
            _rear->_next = newNode;
        }
        _rear = newNode;
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            Node *temp = _front;
            _front = _front->_next;
            delete temp;
        }
    }

    T front() const
    {
        if (!isEmpty())
        {
            return _front->_data;
        }
    }

    T rear() const
    {
        if (!isEmpty())
        {
            return _rear->_data;
        }
    }
};

template <class T>
class SuitorsQueue
{
private:
    Queue<T> _queue;
    int _numSuitors;
public:
    SuitorsQueue(int numSuitors) : _numSuitors(numSuitors)
    {
        for (int i = 1; i <= numSuitors; i++)
        {
            _queue.enqueue(i);
        }
    }
    SuitorsQueue Survivor()
    {
        SuitorsQueue<T> temp(_numSuitors);
        while (temp._numSuitors > 1)
        {
            temp._queue.dequeue();
            temp._queue.enqueue(temp._queue.front());
            temp._queue.dequeue();
            temp._numSuitors--;
        }
        return temp;
    }
    void printSurvivor()
    {
        cout << "The survivor is suitor #" << _queue.front() << endl;
    }
    bool isEmpty(void)
    {
        return _queue.isEmpty();
    }
    SuitorsQueue elimateThreeSuitorsIteratively()
    {
        SuitorsQueue<T> temp(_numSuitors);
        while (temp._numSuitors != 0)
        {
            temp._queue.dequeue();
            temp._queue.enqueue(temp._queue.front());
            temp._queue.dequeue();
            temp._queue.enqueue(temp._queue.front());
            temp._queue.dequeue();
            temp._numSuitors--;
        }
        return temp;
    }
    void findFinalEveSuitor()
    {
        int numEliminated = 0;
        int numRemaining = _numSuitors;
        int numPasses = 0;
        while (numRemaining > 1)
        {
            numPasses++;
            if (numRemaining >= 3)
            {
                numEliminated = numRemaining / 3;
            }
            else
            {
                numEliminated = 1;
            }

            for (int i = 0; i < numEliminated; i++)
            {
                _queue.dequeue();
            }

            numRemaining -= numEliminated;

            cout << "After pass #" << numPasses << ", " << numEliminated << " suitors eliminated, " << numRemaining << " suitors remaining." << endl;
        }
        if (!isEmpty())
        {
            cout << "The final suitor is #" << _queue.front() << endl;
        }
        else
        {
            cout << "All suitors have been eliminated." << endl;
        }
    }
};

int main(int argc, char **argv)
{
    int numSuitors;
    cout << "Enter the number of suitors: ";
    cin >> numSuitors;
    SuitorsQueue<int> suitors(numSuitors);
    suitors.Survivor().printSurvivor();
    suitors.findFinalEveSuitor();
    return 0;
}
