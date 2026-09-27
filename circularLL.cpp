#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};
class circularlinkedlist
{
public:
    Node *head;

    circularlinkedlist()
    {
        head = NULL;
    }

    Node* nodeexists(int k)
    {
        Node* ptr = head;
        Node* temp = NULL;

        if (ptr == NULL)
        {
            return temp;
        }
        else
        {
            do
            {
                if (ptr->key == k)
                {
                    temp = ptr;
                }
                ptr = ptr->next;

            } while (ptr != head);
            return temp;
        }
    }
    void appendnode(Node* new_node)
    {
        if (nodeexists(new_node->key) != NULL)
        {
            cout << "node already axists at " << new_node->key << " append new node with unique key" << endl;
        }
        else
        {
            if (head == NULL) // here we will first check if the there is any node
            {
                head = new_node;
                new_node->next = head;
                cout << "node appended" << endl;
            }
            else
            {
                Node* ptr = head;
                while (ptr->next != head)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
                new_node->next = head;
                cout << "new node appended" << endl;
            }
        }
    }
    void prependnode(Node *new_node)
    {
        if (nodeexists(new_node->key) != NULL)
        {
            cout << "node already axists at " << new_node->key << " append new node with unique key" << endl;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != head)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;
            new_node->next = head;
            head = new_node;
            cout << "new node prepended" << endl;
        }
    }
    void insertnode(int k, Node *new_node)
    {
        Node *ptr = nodeexists(k); // we dont need to lenght the code with this we can traverse throgh the linked list easily!!
        if (head == NULL)
        {
            cout << "there is no node in the linked list" << endl;
        }
        else
        {
            if (nodeexists(new_node->key) != NULL)
            {
                cout << "node already axists at " << new_node->key << " append new node with unique key" << endl;
            }
            else
            {
                if (ptr->next == head)
                {
                    ptr->next = new_node;
                    new_node->next = head;
                    cout << "node inserted at the end" << endl;
                }
                else
                {
                    new_node->next = ptr->next;
                    ptr->next = new_node;
                    cout << "node inerted in between nodes" << endl;
                }
            }
        }
    }
    void deletenode(int k)
    {
        Node *ptr = nodeexists(k);
        if (ptr == NULL)
        {
            cout << "there is no particular node with this key" << endl;
        }
        else
        {
            if (ptr == head)
            {
                if (head == NULL)
                {
                    cout << "there is no node in the circular linked list" << endl;
                }
                else
                {
                    if (head->next = NULL)
                    {
                        head = NULL;
                    }
                    else
                    {
                        Node *temp = head;
                        while (temp->next != head)
                        {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        head = ptr->next;
                    }
                }
            }
            else
            {
                Node *temp = NULL;
                Node *preptr = head;           // say we have n1 n2 n3 this preptr is n1
                Node *currentptr = head->next; // and this currentptr is n2
                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        preptr = preptr->next;         // here preptr is n2 now
                        currentptr = currentptr->next; // here n2 is n3 now
                    }
                    preptr->next = temp->next;
                    cout << "The node is deleted from the circular linked list!" << endl;
                }
            }
        }
    }
    void updatenode(int k, int new_data)
    {
        Node *ptr = nodeexists(k);
        if (ptr != NULL) // meaning the key matched
        {
            ptr->data = new_data;
            cout << "node updated with that key" << endl;
        }
        else // if key is not matched
        {
            cout << "no node exists with that key" << endl;
        }
    }

    void printnodes()
    {
        if (head == NULL)
        {
            cout << "No node exists in the linked list" << endl;
        }
        else
        {
            cout << "head value: " << head << endl;
            cout << "The values in the circular linked list are!" << endl;

            Node *temp = head;
            do
            {

                cout << "(----> " << temp->key << "," << temp->data << "," << temp->next << "---->";
                temp = temp->next;

            } while (temp != head);
            cout<< endl;
        }
    }
};

int main()
{
    circularlinkedlist obj1;
    int key1,data1,k1;
    int option;

    do
    {
        cout<< "What operation do you want to perform. Enter 0 to exit"<< endl;
        cout<< "1 . appendnode()"<< endl;
        cout<< "2 . prependnode()"<< endl;
        cout<< "3 . updatenode()"<< endl;
        cout<< "4 . deletenode()"<< endl;
        cout<< "5 . insertnodeafter()"<< endl;
        cout<< "6 . displaynodes()"<< endl;
        cout<< "7 . clear screen"<< endl;

        cin >> option;
        Node* n1 = new Node();

        switch (option)
        {
            case 1:
            cout<< "option 1 is selected append node. Enter the key and data:"<< endl;
            cout<< "key:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj1.appendnode(n1);
            break;

            case 2:
            cout<< "option 2 is selected preppend node. Enter the key and data:"<< endl;
            cout<< "key:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj1.prependnode(n1);
            break;

            case 3:
            cout<< "option 3 is selected update node. Enter the key you want to update and  the data:"<< endl;
            cout<< "key:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            obj1.updatenode(key1, data1);
            break;

            case 4:
            cout<< "option 4 is selected delete node. Enter the key of the node you want to delete"<< endl;
            cout<< "key:";
            cin>> k1;
            obj1.deletenode(k1);

            case 5:
            cout<< "option 5 is selected inert after particular node. Enter the key after which you want to add a node then the "<< endl;
            cout<< "key:";
            cin>> k1;
            cout<< "Enter key for the node:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj1.insertnode(k1, n1);

            case 6:
            cout<< "option 6 is selected display the nodes in the linked list."<< endl;
            obj1.printnodes();
            break;

            case 7:
            system ("cls");
            break;

            default:
            cout<< "please only pick the option metioned!!";
            break;
        }

    }while(option != 0);

    return 0;
}