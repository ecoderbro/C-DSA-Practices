#include <iostream>
#include <math.h>
using namespace std;

class minheap
{
    public:
        int *harr; // pointer to array of elements in heap
        int capacity; // the limit of the array 
        int heap_size;  // the actual data stored in the array

        minheap(int cap)
        {
            capacity = cap;
            harr = new int[cap];
            heap_size = 0;
        }


        int swap(int &x, int &y) //swapping is not a standard minheap funtion so it can stay outside the min heap class
        {
            int z = x;
            x = y;
            y = z;
        }


        void linearsearch(int val) // searching a specific value in a heap
        {

            for(int i = 0; i < heap_size; i++)
            {
                if(harr[i] == val)
                {
                    cout<< "value found!"<< endl;
                    return;
                }
                else{
                    cout<< "not found"<< endl;
                }
            }
        }

        void printArray()
        {
            for(int i = 0; i < heap_size; i++)
            {
                cout<< harr[i]<< " "<< endl;
            }
        }

        int height()
        {
            return ceil(log2(heap_size+1))-1;
        }

        // parent formaula with left and right key formula 


        int parentkey(int i)
        {
            return (i-1)/2;
        }

        int left(int i)
        {
            return (2*i)+1;
        }

        int right(int i)
        {
            return (2*i)+1;
        }
        
        int getmin()
        {
            return harr[0];
        }

        

        void insertvalue(int k)
        {
            if(heap_size == capacity)
            {
                cout<< "overflow bro!"<< endl;
            }
            heap_size ++;
            int i = heap_size-1;
            harr[i] = k;

            while (i!=0 && harr[parentkey(i) > harr[i]])
            {
                swap(harr[i], harr[parentkey(i)]);
                i = parentkey(i);
            }
        }

        void minheapify(int i)
        {
            int l = left(i);
            int r = right(i);
            int smallest = harr[0];

            if (l<heap_size && harr[l] < harr[i])
            {
                smallest = l;
            }
            if (r<heap_size && harr[r] < harr[smallest])
            {
                smallest = r;
            }
            if( smallest!=i)
            {
            swap(smallest, harr[i]);
            minheapify(smallest);
            }
        }


        int extractmin()
        {
            if (heap_size <= 0)
            {
                return __INT_MAX__;//heap is empty
            }

            if (heap_size == 1)
            {
                heap_size--;
                return harr[0];
            }

            int root = harr[0]; // we need root so initialized it and it is also the value that will be removed
            harr[0] = harr[heap_size-1];
            heap_size--;
            minheapify(0);
            return root;
        }

        void getunsortedarray()
        {
            cout<< "enter "<< capacity << " number in the array: ";
            for(int i = 0; i < capacity; i++)
            {
                cin >> harr[i];
            }
            cout<< endl;
        }

        void heapsort()
        {
            int temp[capacity];
            for(int i = 0; i < capacity; i++)
            {
                temp[i] = extractmin();
                cout<< temp[i]<< " ";
            }
            cout<< endl;
        }

};

int main()
{
    int capacity;
    cout<< "enter the capcity of the array: ";
    cin >> capacity;
    minheap obj(capacity);

    obj.getunsortedarray();

    cout<< "Unsorted array : ";
    obj.printArray();

    cout<< "sorted array: ";
    obj.heapsort();

    return 0;
}
