#include <iostream>
using namespace std;

#define SIZE 5

class Deque
{
private:
    int arr[SIZE];

    int front;
    int rear;

public:
    // Constructor
    Deque()
    {
        front = -1;
        rear = -1;
    }

    // Check Empty
    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    // Check Full
    bool isFull()
    {
        return (rear == SIZE - 1);
    }

    // Insert at Rear
    void insertRear(int val)
    {
        cout << "\n--- INSERT REAR ---" << endl;

        if (isFull())
        {
            cout << "Deque is Full!" << endl;
            return;
        }

        // First element
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = val;

        cout << val << " inserted at REAR." << endl;
    }

    // Insert at Front
    void insertFront(int val)
    {
        cout << "\n--- INSERT FRONT ---" << endl;

        // No space before front
        if (front == 0)
        {
            cout << "No space at front!" << endl;
            return;
        }

        // First element
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front--;
        }

        arr[front] = val;

        cout << val << " inserted at FRONT." << endl;
    }

    // Delete from Front
    void deleteFront()
    {
        cout << "\n--- DELETE FRONT ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        cout << arr[front] << " deleted from FRONT." << endl;

        // Last element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Delete from Rear
    void deleteRear()
    {
        cout << "\n--- DELETE REAR ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        cout << arr[rear] << " deleted from REAR." << endl;

        // Last element
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear--;
        }
    }

    // Display
    void display()
    {
        cout << "\n--- DISPLAY ---" << endl;

        if (isEmpty())
        {
            cout << "Deque is Empty!" << endl;
            return;
        }

        cout << "Deque elements are:\n";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Deque d;

    int option, value;

    do
    {
        cout << "\n==================================" << endl;
        cout << " DOUBLE ENDED QUEUE (DEQUE) " << endl;
        cout << "==================================" << endl;

        cout << "1. Insert Rear" << endl;
        cout << "2. Insert Front" << endl;
        cout << "3. Delete Front" << endl;
        cout << "4. Delete Rear" << endl;
        cout << "5. Display" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter option: ";
        cin >> option;

        switch (option)
        {
        case 1:

            cout << "Enter value: ";
            cin >> value;

            d.insertRear(value);

            break;

        case 2:

            cout << "Enter value: ";
            cin >> value;

            d.insertFront(value);

            break;

        case 3:

            d.deleteFront();

            break;

        case 4:

            d.deleteRear();

            break;

        case 5:

            d.display();

            break;

        case 0:

            cout << "Program Ended." << endl;

            break;

        default:

            cout << "Invalid Option!" << endl;
        }

    } while (option != 0);

    return 0;
}