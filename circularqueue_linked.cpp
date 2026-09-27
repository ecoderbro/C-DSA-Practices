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

// Circular Queue class
class CircularQueue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    CircularQueue()
    {
        front = NULL;
        rear = NULL;
    }

    // Check Empty
    bool isEmpty()
    {
        return (front == NULL);
    }

    // ENQUEUE
    void enqueue(int val)
    {
        cout << "\n--- ENQUEUE OPERATION ---" << endl;

        // Create new node
        Node *newNode = new Node(val);

        cout << "New node created with value: "
             << val << endl;

        // First node
        if (isEmpty())
        {
            front = rear = newNode;

            // Make circular link
            rear->next = front;

            cout << "Front and Rear point to same node." << endl;
        }
        else
        {
            // Rear connects to new node
            rear->next = newNode;

            cout << "Old rear connected to new node." << endl;

            // Move rear
            rear = newNode;

            cout << "Rear moved to new node." << endl;

            // Circular link
            rear->next = front;

            cout << "Rear linked back to front." << endl;
        }
    }

    // DEQUEUE
    void dequeue()
    {
        cout << "\n--- DEQUEUE OPERATION ---" << endl;

        // Empty queue
        if (isEmpty())
        {
            cout << "Circular Queue is Empty!" << endl;
            return;
        }

        cout << front->data
             << " deleted from queue." << endl;

        // One node only
        if (front == rear)
        {
            delete front;

            front = NULL;
            rear = NULL;

            cout << "Queue became empty." << endl;
        }
        else
        {
            Node *temp = front;

            // Move front forward
            front = front->next;

            // Rear should point to new front
            rear->next = front;

            delete temp;

            cout << "Front moved forward." << endl;
        }
    }

    // DISPLAY
    void display()
    {
        cout << "\n--- DISPLAY CIRCULAR QUEUE ---" << endl;

        // Empty queue
        if (isEmpty())
        {
            cout << "Queue is Empty!" << endl;
            return;
        }

        Node *temp = front;

        do
        {
            cout << temp->data << " ";

            temp = temp->next;

        } while (temp != front);

        cout << endl;
    }
};

int main()
{
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(40);

    q.display();

    return 0;
}