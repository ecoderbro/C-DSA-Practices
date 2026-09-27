/*
Mid Term Syllabus 
Algorithm Specification: Properties of Algorithm, examples, performance, analysis,
measurement, and Big Oh notation. Introduction to ADTs: Array and Polynomial as an ADT,

Sparse Matrices, and Representation of Arrays. The Stack ADT: Linked list and array

implementations, Expressions, Postfix Notation, and Infix to postfix conversion. The Queue ADT:


Linked and array implementations of circular and double ended queue.
Linked List: Singly
Linked Lists, Circular Lists, Linked Stacks and Queues (Double Ended List?),
*/



#include <iostream>
#include <string>

using namespace std;
class stack
{
private:
    int top;
    int arr[5];

public:
    stack()
    {
        top = -1;
        for (int i = 0; i < 5; i++) // everthing in the stck is already assianged to zero the stack has to be emplty when called
        {
            arr[i] = 0;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == 4)
            return true;
        else
            return false;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << " stack overflow" << endl;
        }
        else
        {
            top++; // now top is 0
            arr[top] = val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << " stack underflow" << endl;
            return 0;
        }
        else
        {
            int popvalue = arr[top];
            arr[top] = 0;
            top--;
            return popvalue;
        }
    }

    int count()
    {
        return (top + 1);
    }
    int peek(int pos)
    {
        if (isEmpty())
        {
            cout << " stack underflow" << endl;
            return 0;
        }
        else
        {
            return arr[pos];
        }
    }
    void change(int pos, int val)
    {
        if (pos < 0 || pos > 4)
        {
            cout << " Invalid position " << endl;
        }
        else
        {
            arr[pos] = val;
            cout << " value changed at position " << pos << endl;
        }
    }
    void display()
    {
        cout << " All values in the stack are " << endl;
        for (int i = 4; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{

    stack s1;
    int option, position, value;

    do
    {
        cout << " What operation do you want to perform? Select option number. Enter 0 to exit." << endl;
        cout << " 1. Push() " << endl;
        cout << " 2. Pop() " << endl;
        cout << " 3. isEmpty() " << endl;
        cout << " 4. isFull() " << endl;
        cout << " 5. peek() " << endl;
        cout << " 6. count() " << endl;
        cout << " 7. change() " << endl;
        cout << " 8. display() " << endl;
        cout << "clear screen " << endl;
        cout << " Option: ";

        cin >> option;

        switch (option)
        {
        case 1:
            cout << " Enter an item to push in the stack: ";
            cin >> value;
            s1.push(value);
            break;
        case 2:
            cout << " Pop function called - popped value: " << s1.pop() << endl;
            break;
        case 3:
            if (s1.isEmpty())
            {
                cout << " Stack is empty " << endl;
            }
            else
            {
                cout << " Stack is not empty " << endl;
            }
            break;
        case 4:
            if (s1.isFull())
            {
                cout << " Stack is full " << endl;
            }
            else
            {
                cout << " Stack is not full " << endl;
            }
            break;
        case 5:
            cout << " Enter position of item you want to peek: ";
            cin >> position;
            cout << " Peek function called - value at position " << position << " is " << s1.peek(position) << endl;
            break;
        case 6:
            cout << " Count function called - number of items in the stack are: " << s1.count() << endl;
            break;
        case 7:
            cout << " Enter position of item you want to change: ";
            cin >> position;
            cout << " Enter new value: ";
            cin >> value;
            s1.change(position, value);
            break;
        case 8:
            cout << " Display function called - " << endl;
            s1.display();
            break;
        case 9:
            system("cls");
            break;

        default:
            cout << " Enter proper option number " << endl;
            break;
        }

    } while (option != 0);

    return 0;
}