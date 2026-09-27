#include <iostream>
using namespace std;

class Node
{
    public:
        int key; // this is unique and only one node has it unique key when we access the node we can access it using key.
        int data; // datd storing inside that key
        Node* next; // the next is the pointer of type node which is same as class or same name as class that will point to the object of node type only

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
class singlylinkedlist
{
    public:
        Node* head; // our first node will be called the head 

    singlylinkedlist(){
        head = NULL;
    }

    singlylinkedlist( Node *n)// we are storing the address of the node in the head the node we want to be the head.
    {
        head = n; 
    }
    // 1. Check if the node exists. using key value

    Node* nodeexists(int k)
    {
        Node* temp = NULL;
        Node* ptr = head;
        while( ptr != NULL)
        {
            if( ptr -> key == k)
            {
                temp = ptr;
            }
            ptr = ptr -> next ;
        }
        return temp;
    }     
    // 2. Appemed a node to the list.
    void appenednode(Node *n)
    {
        if (nodeexists(n -> key) != NULL)// appened ma pehla node create hota or list ka last ma node lgata ab ya dhikn ak last node ma null mojood ha k nai agr ha to appened hojaye ga 
                                         // agr nai ha to jo node hum dalna ki koshish kr rha ha oska key kisi pehla mojooda node ka key ka sath match hogya or node exits message display hoga
        {
            cout<< "Node already exist at " << n->key << "appened node with another key value"<< endl;
        }
        else //in this part we first have to check if there is a node in the linked list or not..if i have created 2 or 3 nodes if i have not linked them it cannot form a linked list
        {
            if(head == NULL) //the key inside the head node will only be null when we know there is no address for another anode inside the linked list 
            {                //this is for our very first node. which is the head
                head = n;// meaning we have our first node created
                cout<< "Node appended"<< endl;
            }
            else// what i am doing here is I know in the above part no node existed and we created one. if it is not pointing to null then this means there is some key address to other node
            //this part is for that purpose.
            {
                Node* ptr = head;// first we created a pointer that points to the head for traversing

                while(ptr-> next != NULL)//in while loop the ptr of next node meaning the head node is not NULL then Go the next node with the address stored in the head node and same for the other nodes
                {
                    ptr= ptr-> next;// now this loop will go on as long as the condition is not met meaning not NULL.
                }
                ptr-> next = n;// now the last node which was storing null in it will have the address of the new added node which is 'n'.
                cout<< "Node appended"<< endl;
            }
        }
    } 
    // 3. Prepend Node meaning adding node at the start.
    void prependnode(Node *n)
    {
        if(n->key!=NULL)
        {
            cout<< "Node already exists at "<< n-> key << "prepend with another different value"<< endl;
        }
        else
        {
            n-> next = head; //what we did here is we basically dont need to traverse to the end of the node in prepend we adding the node at the first.
            //we took the address 'n' we pointed to head and stored the next address in it. meaning the first node which was the head..
            head = n;
            //now the head pointer is pointing to the new node we created.
            cout<< "Node prepended"<< endl;
        }
    }   
    //4. Inserting the node after particular node    
    void insertnode(int k, Node *n)// first one is the key after which we want to add the node and second is the actual node the address of the node that we want to attach
    {
        Node* ptr = nodeexists(k);// what this instead of using if that node exists what we have to do is also access it too that is why we are using a pointer wo we can
                                  //access it later.
        if(ptr == NULL)//we are checking if the node we want to place the new node after exists 
        {
            cout<< "Node does not exists"<< k << endl;

        }
        else
        {
            if(nodeexists(n->key)!= NULL)// we are also checking if the new node doesnt has the same key as the already present nodes
            {
                cout<< "Node already exists at "<< n-> key << "prepend with another different value"<< endl;

            }
            else
            {
                n->next = ptr-> next;// what this is doing is that we are putting the next address which is in the poniter "ptr" in to the 'next' of the newly made node say "n4" now n4 will point to the next node which the ptr was pointing
                ptr->next = n;// now the next of pointer ptr is pointing to the new node address
                cout<< "Node Inserted"<< k << endl;
            }
        }
        //5. Delete a specific node
        

    }  
    void deletenode(int k)
        {
           if( head == NULL)// Checking if there is any node in linked list 
           {
            cout<< "there is no node is linked list!"<< endl;

           }
           else if(head != NULL)// checkin if the node is the head because if it is need to point the head to the next node which will be the new head 
           {
             if( head-> key == k)
             {
                head = head -> next;// next of head N1 which is n2 address is now stored in the head which makes the n2 the new head!
                cout<< "Node is UNLINKED with that particular node"<< k << endl;
             }
             else//if we want ot delete a node which is in between the linked list then
             {
                Node* temp= NULL;// temp which storing null as of now
                Node* preptr = head;// a pointer which is pointer to head.
                Node* currentptr = head->next;// a current pointer which pointing to the next of the head(n1) pointer meaning (n2)
                while( currentptr!= NULL) // what we did here is after finding that particular node say N2 we stored it in the temp pointer and we decalared the currentptr to null which will stop the loop
                {
                    if(currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else // if there is no key matching the paramerter then every thing is stored to back 
                    {
                        preptr = preptr-> next; // goes back to previous position
                        currentptr = currentptr -> next; // goes back to next of head
                    }
                    if(temp != NULL)
                    {
                        preptr-> next = currentptr-> next; // what we did here is we put the next address whic was stored in the node which we wanted to delete is now being stored in the head pointer 
                        cout<< "the particular node which was mentioned is unlinked" << endl;
                    }
                    else
                    {
                        cout<< "the particular node which was mentioned is is not found" << endl;

                    }
                }
             }
           }
     }  
     // 6. Update node by key 
     void updatenodebykey(int k, int d)
     {
        Node* ptr = nodeexists(k);
        if(ptr != NULL)
        {
            ptr -> data = d;
            cout<< "the particular node is updated"<< endl;
        }
        else
        {
            cout<< "the particular node is not found with key "<< k <<  endl;
        }
     }   
     // 7. Display the list which we made  
     void display()
     {
        Node* temp = head;
        if(head == NULL)
        {
            cout<< "there is node in the linked list"<< endl;
        }
        else
        {
            cout<< endl<< "Singly linked list Values:";
            while(temp != NULL)
            {
                cout<< "(" <<temp->key << " , "<< temp -> data<< ")----> ";
                temp= temp->next;
            }
            cout<< endl;
        }
     }

};


int main(){
    int option;
    int key1, data1, k1;
    singlylinkedlist s;

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
            s.appenednode(n1);
            break;

            case 2:
            cout<< "option 2 is selected preppend node. Enter the key and data:"<< endl;
            cout<< "key:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            s.prependnode(n1);
            break;

            case 3:
            cout<< "option 3 is selected update node. Enter the key you want to update and  the data:"<< endl;
            cout<< "key:";
            cin>> key1;
            cout<< "data:";
            cin>> data1;
            s.updatenodebykey(key1, data1);
            break;

            case 4:
            cout<< "option 4 is selected delete node. Enter the key of the node you want to delete"<< endl;
            cout<< "key:";
            cin>> k1;
            s.deletenode(k1);

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
            s.insertnode(k1, n1);

            case 6:
            cout<< "option 6 is selected display the nodes in the linked list."<< endl;
            s.display();
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