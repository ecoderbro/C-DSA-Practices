#include <iostream>
using namespace std;

// Node class for Linked List
class Node
{
public:
    int data;     // stores value
    Node *next;   // pointer to next node

    // Constructor
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Stack class
class stack
{
private:
    Node *top; // top pointer points to top node of stack

public:
    // Constructor
    stack()
    {
        top = NULL; // initially stack is empty
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return (top == NULL);
    }

    // PUSH operation
    void push(int val)
    {
        cout << "\n--- PUSH OPERATION ---" << endl;

        // Step 1: Create new node
        Node *newNode = new Node(val);

        cout << "New node created with value: " << val << endl;

        // Step 2: New node points to current top
        newNode->next = top;//here what is done is the new node is pointing to the node below which was at first considered the top 

        cout << "New node next pointer now points to old top." << endl;

        // Step 3: Move top to new node
        top = newNode;//now it knows the location of the node below here the new node is the top 

        cout << "Top updated to new node." << endl;

        cout << "Value pushed successfully!\n";
    }

    // POP operation
    int pop()
    {
        cout << "\n--- POP OPERATION ---" << endl;

        // Check underflow
        if (isEmpty())
        {
            cout << "Stack Underflow! Stack is empty.\n";
            return 0;
        }

        // Store top value
        int popValue = top->data;

        cout << "Top value to remove: " << popValue << endl;

        // Temporary pointer
        Node *temp = top;

        cout << "Temporary pointer created." << endl;

        // Move top to next node
        top = top->next;

        cout << "Top moved to next node." << endl;

        // Delete old top node
        delete temp;

        cout << "Old top node deleted from memory. poped value is: " << popValue<< endl;

    }

    // PEEK operation
    int peek()
    {
        cout << "\n--- PEEK OPERATION ---" << endl;

        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
            return 0;
        }

        cout << "Top element is: " << top->data << endl;
    }

    // COUNT operation
    int count()
    {
        cout << "\n--- COUNT OPERATION ---" << endl;

        int counter = 0;

        // Start traversal from top
        Node *temp = top;

        cout << "Traversing linked list..." << endl;

        while (temp != NULL)
        {
            counter++;

            cout << "Visited node with value: "
                 << temp->data << endl;

            temp = temp->next;
        }

        cout << "Total nodes counted: " << counter << endl;

    }

    // CHANGE operation
    void change(int pos, int val)
    {
        cout << "\n--- CHANGE OPERATION ---" << endl;

        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
            return;
        }

        Node *temp = top;

        cout << "Starting traversal from top..." << endl;

        // Traverse to required position
        for (int i = 0; i < pos; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position!\n";
                return;
            }

            temp = temp->next;
        }

        // Change value
        if (temp != NULL)
        {
            cout << "Old value at position "
                 << pos << " was: "
                 << temp->data << endl;

            temp->data = val;

            cout << "New value updated to: "
                 << val << endl;
        }
        else
        {
            cout << "Invalid Position!\n";
        }
    }

    // DISPLAY operation
    void display()
    {
        cout << "\n--- DISPLAY OPERATION ---" << endl;

        if (isEmpty())
        {
            cout << "Stack is Empty.\n";
            return;
        }

        Node *temp = top;

        cout << "Displaying stack from TOP to BOTTOM:\n";

        while (temp != NULL)
        {
            cout << "| " << temp->data << " |" << endl;

            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    stack s1;

    int option, value, position;

    do
    {
        cout << "\n====================================" << endl;
        cout << " STACK USING LINKED LIST " << endl;
        cout << "====================================" << endl;

        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. Peek()" << endl;
        cout << "5. Count()" << endl;
        cout << "6. Change()" << endl;
        cout << "7. Display()" << endl;
        cout << "0. Exit()" << endl;

        cout << "\nEnter option: ";
        cin >> option;

        switch (option)
        {
        case 1:

            cout << "Enter value to push: ";
            cin >> value;

            s1.push(value);

            break;

        case 2:

            cout << "Popped Value: "<< s1.pop() << endl;

            break;

        case 3:

            if (s1.isEmpty())
            {
                cout << "Stack is Empty.\n";
            }
            else
            {
                cout << "Stack is NOT Empty.\n";
            }

            break;

        case 4:

            s1.peek();

            break;

        case 5:

            cout << "Number of nodes in stack: "
                 << s1.count() << endl;

            break;

        case 6:

            cout << "Enter position: ";
            cin >> position;

            cout << "Enter new value: ";
            cin >> value;

            s1.change(position, value);

            break;

        case 7:

            s1.display();

            break;

        case 0:

            cout << "Program Ended Successfully.\n";

            break;

        default:

            cout << "Invalid Option!\n";
        }

    } while (option != 0);

    return 0;
}