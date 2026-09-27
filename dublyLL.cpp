#include <iostream>
using namespace std;

class Node
{
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

    Node()
    {
        key=0;
        data = 0;
        next = NULL;
        previous = NULL;
    }

    Node(int k, int d)
    {
        key= k;
        data = d;
    }

};
class doublylinkedlist
{
    public:
        Node* head;

    doublylinkedlist()
    {
        head = NULL;
    }
    doublylinkedlist(Node *n)
    {
        head = n;
    }

    //1. Check if the node exists
    Node* checknodeexist(int k)
    {
        Node* ptr = head;
        Node* temp = NULL;

        while(ptr!= NULL)
        {
            if(ptr->key == k)
            {
                temp = ptr;
            }
            ptr= ptr->next;
        }
        return temp;
    }
    //2 append node in doubly linked list
    void appendnode(Node* n)
    {
        if(checknodeexist(n->key)!= NULL)
        {
            cout<< "the node already exist at "<< n->key << " please enter a unique node!"<< endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout<< "Node Appened in the list as head node"<< endl;
            }
            else
            {
                Node* ptr = head;
                while(ptr->next!= NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout<< "node is Appended in the Doubly linked list"<< endl;
            }
        }
    }
    //3. prepend node which is adding a node at the start of th list

    void prependnode(Node* n)
    {
        if(checknodeexist(n->key)!= NULL)
        {
            cout<< "the node already exist at "<< n->key << " please enter a unique node!"<< endl;
        }
        else
        {
            if(head == NULL)
            {
                head = n;
                cout<< "Node is prepended"<< endl;
            }
            else
            {
                head->previous = n; // in doubly linked it is easy for us to prepend node bacause we can traverse the opposite way 
                                // first we assianged the previous pointer to the node
                n->next = head;
                //then we assianged the next pointer of the node to the head

                head = n;
                //we declared the new head beacause in the proccess of prepeding we have to change the pointer head to the new node which is at the start of the list
                cout<< "node prepended succesfully!"<< endl;
            } 
        }
    }

    //4. insert a node after a particular key
    void insertnode(int k, Node* n)
    {
        Node* ptr = checknodeexist(k); // this is the pointer n2 we want to inert a node n4 after and nextNode below is n3
        if(ptr == NULL)//checking the key after which we will insert a node exists
        {
            cout<< "No Node exists with that partcular key"<< endl;
        }
        else
        {
            if(checknodeexist(n->key)!= NULL)// checking if there is a node with the same key
            {
                cout<< "the node already exist at "<< n->key << " please enter a unique node!"<< endl;
            }
            else
            {
                Node* nextNode = ptr-> next;// this is basically the node which is already after the node we want to insert 

                // dont forget the pointer has the key value after which we will insert a node
                if(nextNode == NULL)// this means inserting a node at the end of the list
                {
                    ptr-> next = n;
                    n->previous = ptr;
                    cout<< "The node is inserted at the end of the list!"<< endl;
                }
                else
                {
                    n->next = ptr->next; //first we link the next of the new node to the next of the ptr
                    nextNode->previous= n;// second we link the new node n4 to the previous front node n3
                    ptr->next = n;//then linking the next of n2 to n4 address
                    n->previous= ptr;//now the previous of the new node link with n2
                    cout<< "Node is inserted after"<< ptr->key << endl;
                }
            }
        }
    }

    //5. delete node by key from the linked list it is unlink basically and delete
    void deletenode(int k)
    {
        Node* ptr = checknodeexist(k);
        if(ptr == NULL)
        {
            cout<< "No Node exists with that partcular key"<< endl;
        }
        else
        {
            if(head->key == k)
            {
                head = head->next;
                cout<< "the particular node is deleted"<< endl;
            }
            else
            {
                Node* nextNode = ptr->next;//node infront of the node we want to delete
                Node* preNode = ptr->previous;//node on the backside of the node we want to delete
                if(nextNode== NULL)//if the node is at the last
                {
                    preNode->next = NULL;
                    cout<< "Node deleted from the end of the list!"<< endl;
                } 
                else
                {
                    preNode->next = nextNode;//linking the next of the node behind the node we want to delete to its front node
                    nextNode->previous = preNode;//linking the previous pointer of node infront of the node we want to delete to the next behind the we want to delete
                    cout<< "Node is deleted from the middle of the list"<< endl;
                }
            }
        }
    }

    //6. Update node by key
    void Updatenodebykey(int k, int d)
    {
        Node* ptr = checknodeexist(k);
        if(ptr!= NULL)
        {
            ptr->data=d;
            cout<< "Node is Updated"<< endl;
        }
        else
        {
            cout<< "the particular node was not found!!"<< endl;
        }
    }

    //7. display linked list
    void displaylinkedlist()
    {
        if(head == NULL)
        {
            cout << "there is node in the dubly linked list"<< endl;
        }   

        else
        {
            cout<< "Doubly linked list: "<< endl;

            Node* temp = head;

            while(temp!=NULL)
            {
                cout<< "("<< temp->key << " , "<< temp->data<< ")"<< "<---->";
                temp = temp->next;
            }
        }

    }   



};

int main()
{

    doublylinkedlist obj;
    int option;
    int key1, data1, k1;
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

        cout<< "Enter your Option: ";

        cin>> option;
        Node* n1 = new Node();//what this is exactly this is a pointer to Node obj which is created on the heap memory

        switch(option)
        {
            case 1:
            cout<< "option append is selected enter a unique key value and data value repectively!: "<< endl;
            cout<< "key: ";
            cin >> key1;
            cout<< "data: ";
            cin>> data1;
            n1->key = key1;
            n1->data = data1;
            obj.appendnode(n1);
            break;

            case 2:
            cout<< "option prepend is selected enter a unique key value and data value repectively!: "<< endl;
            cin >> key1;
            cout<< endl;
            cin>> data1;
            n1->key = key1;
            n1->data = data1;
            obj.prependnode(n1);
            break;

            case 3:
            cout<< "option updatenodebykey() is selected enter the key value you want to update : "<< endl;
            cout<< "Enter key : ";
            cin >> k1;
            cout<< "data: ";
            cin>> data1;
            obj.Updatenodebykey(k1, data1);
            break;

            case 4:
            cout<< "option deletenode() is selected enter the key value you want to delete : "<< endl;
            cout<< "Enter key : ";
            cin >> k1;
            obj.deletenode(k1);
            break;

            case 5:
            cout<< "option insertnodeafter() is selected "<< endl;
            cout<< "Enter key after you want to add the node: ";
            cin >> k1;
            cout<< "Enter key of the new node: ";
            cin>> key1;
            cout<< "Enter data of the new node: ";
            cin>> data1;
            n1->key = key1;
            n1->data = data1;
            obj.insertnode(k1, n1);
            break;

            case 6:
            cout<< "option displaynodes() is selected "<< endl;
            cout<< "DOUBLY LINKED LIST: ";
            obj.displaylinkedlist();
            break;

            case 7:
            system("cls");
            break;

            default:
            {
                cout<< "Please enter the valid Value!"<< endl;
            }
        }


    }while(option != 0);


    return 0;
}