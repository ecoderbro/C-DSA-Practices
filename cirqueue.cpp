#include <iostream>
using namespace std;

class queue
{
private:
    int front;
    int rear;
    int arr[5];
    int count;

public:
    queue()
    {
        count = 0;
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isempty()
    {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if ((rear + 1) % 5 == front) //imagine front as index 1 and rear as 0 will make logic
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is Full!" << endl;
        }
        else if (isempty())
        {
            rear = front = 0;
            arr[rear] = val;
        }
        else
        {
            rear = (rear + 1) % 5;
            arr[rear] = val;
        }
        count++;
    }
    int degueue()
    {
        int x;
        if (isempty())
        {
            cout << "queue is empty " << endl;
            return 0;
        }
        else if (rear == front)// only when there is only one value in the array which is at 0
        {
            x = arr[rear]; // x store 5
            arr[rear] = 0; // instead of 5 we store 0
            count--;
            front = -1;
            rear = -1;
            return x;
        }
        else// meaning there are more than one value
        {
            cout << "dequeue function called - dequeued value: " << arr[front] << endl;
            x = arr[front]; //
            arr[front] = 0;
            count--;
            front = (front + 1) % 5;// incrementation
            return x;
        }
    }
    int itemcount()
    {
        if (isempty())
        {
            cout << "queue is empty " << endl;
            return 0;
        }
        else
        {
            return count;
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "queue is empty! " << endl;
        }
        else
        {
            cout << "All values in the queue are: " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};
int main()
{
    queue q1;
    int option, value;

    do
    {
        cout << "What operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << "1. Enqueue() " << endl;
        cout << "2. Dequeue() " << endl;
        cout << "3. isEmpty() " << endl;
        cout << "4. isFull() " << endl;
        cout << "5. count() " << endl;
        cout << "6. display() " << endl;
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter an item to enqueue in the queue: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            q1.degueue();
            break;
        case 3:
            if (q1.isempty())
            {
                cout << "Queue is empty " << endl;
            }
            else
            {
                cout << "Queue is not empty " << endl;
            }
            break;
        case 4:
            if (q1.isFull())
            {
                cout << "Queue is full " << endl;
            }
            else
            {
                cout << "Queue is not full " << endl;
            }
            break;
        case 5:
            cout << "Number of elements in the queue: " << q1.itemcount() << endl;
            break;
        case 6:
            q1.display();
            break;
        default:
            if (option != 0)
            {
                cout << "Invalid option! Please try again. " << endl;
            }
            break;
        }

    } while (option != 0);
}