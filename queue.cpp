#include <iostream>
using namespace std;

class queue
{
private:
    int front;
    int rear;
    int arr[5];

public:
    queue()
    {
        front = -1;
        rear = -1;
        for (int i = 0; i < 5; i++)
        {
            arr[i] = 0;
        }
    }
    bool isempty()
    {
        if (rear == -1 || front == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (rear == 4)
            return true;
        else
            return false;
    }
    void enqueue(int val)
    {
        if (isFull())
        {
            cout << "queue is full " << endl;
        }
        else if (isempty())
        {
            rear = front = 0;
            arr[rear] = val; // both the front and rear are pointing at the same value
        }
        else
        {
            rear++;
            arr[rear] = val;// the front is going to reamin the same but the threar will incremnet as the val are added in the queue
        }
    }
    int dequeue()
    {
        int x;
        if (isempty())
        {
            cout << "queue is empty " << endl;
        }
        else if (front == rear)// here need to rememeber the front and the rear are same when there is only one value in the queue
        {
            x = arr[front]; //first storing the value in X 
            arr[front] = 0; // then storing 0 or say nothing in place of 5 
            front = -1;
            rear = -1;
            return x;
        }
        else
        {// here there is more than 2 values in the array or queue
            x = arr[front];
            arr[front] = 0;
            front++;
            return x;
        }
    }
    int count()
    {
        if (isempty())
        {
            cout << "queue is empty " << endl;
        }
        else
            return (rear - front + 1);
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
    int option, value;
    queue q1;
    do
    {
        cout << " Select an option from the menu. Press 0 for exit " << endl;
        cout << "1. Enqueue() " << endl;
        cout << "2. Dequeue() " << endl;
        cout << "3. isEmpty() " << endl;
        cout << "4. isFull() " << endl;
        cout << "5. Count() " << endl;
        cout << "6. Clear Screen " << endl;
        cout << "7. Display()  " << endl;
        cout << " " << endl;
        cout << "Your value: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << " Enter a value to enqueue in the queue: ";
            cin >> value;
            q1.enqueue(value);
            break;
        case 2:
            cout << " Dequeue function called - dequeued value: " << q1.dequeue() << endl;
            break;
        case 3:
            if (q1.isempty())

                cout << " Queue is empty " << endl;
            else
                cout << " Queue is not empty " << endl;
            break;
        case 4:
            if (q1.isFull())
                cout << " Queue is full " << endl;
            else
                cout << " Queue is not full " << endl;
            break;
        case 5:
            cout << " Count function called - number of items in the queue are: " << q1.count() << endl;
            break;
        case 6:
            system("cls");
            break;
        case 7:
            q1.display();
            break;
        }

    } while (option != 0);
}