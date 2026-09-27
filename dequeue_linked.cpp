#include <iostream>
using namespace std;

// Doubly Node
class Node
{
public:
    int data;

    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;

        next = NULL;
        prev = NULL;
    }
};

// Deque class
class Deque
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Deque()
    {
        front = NULL;
        rear = NULL;
    }

    // Check Empty
    bool isEmpty()
    {
        return (front == NULL);
    }

    // Insert Front
    void insertFront(int val)
    {
        cout << "\n--- INSERT FRONT ---" << endl;

        Node *newNode = new Node(val);

        // First node
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;

            front->prev = newNode;

            front = newNode;
        }

        cout << val
             << " inserted at FRONT." << endl;
    }

    // Insert Rear
    void insertRear(int val)
    {
        cout << "\n--- INSERT REAR ---" << endl;

        Node *newNode = new Node(val);

        // First node
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;

            newNode->prev = rear;

            rear = newNode;
        }

        cout << val
             << " inserted at REAR." << endl;
    }

    // Delete Front
    void deleteFront()
    {
        cout << "\n--- DELETE FRONT ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        Node *temp = front;

        cout << front->data
             << " deleted from FRONT." << endl;

        // One node only
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;

            front->prev = NULL;
        }

        delete temp;
    }

    // Delete Rear
    void deleteRear()
    {
        cout << "\n--- DELETE REAR ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        Node *temp = rear;

        cout << rear->data
             << " deleted from REAR." << endl;

        // One node only
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;

            rear->next = NULL;
        }

        delete temp;
    }

    // Display
    void display()
    {
        cout << "\n--- DISPLAY DEQUE ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
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
    Deque d;

    d.insertRear(10);
    d.insertRear(20);

    d.insertFront(5);

    d.display();

    d.deleteFront();

    d.display();

    d.deleteRear();

    d.display();

    return 0;
}