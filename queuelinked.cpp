#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Check Empty
    bool isEmpty()
    {
        return (front == NULL && rear == NULL);
    }

    // ENQUEUE
    void enqueue(int val)
    {
        cout << "\n--- ENQUEUE OPERATION ---" << endl;

        // Create new node
        Node *newNode = new Node(val);

        cout << "New node created with value: "
             << val << endl;

        // First element
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;

            cout << "Front and Rear both point to new node." << endl;
        }
        else
        {
            // Old rear connects to new node
            rear->next = newNode;

            cout << "Old rear connected to new node." << endl;

            // Move rear forward
            rear = newNode;

            cout << "Rear moved to new node." << endl;
        }
    }

    // DEQUEUE
    void dequeue()
    {
        cout << "\n--- DEQUEUE OPERATION ---" << endl;

        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front;

        cout << front->data
             << " removed from queue." << endl;

        // One element only
        if (front == rear)
        {
            front = NULL;
            rear = NULL;
        }
        else
        {
            front = front->next;
        }

        delete temp;
    }

    // DISPLAY
    void display()
    {
        cout << "\n--- DISPLAY QUEUE ---" << endl;

        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    return 0;
}