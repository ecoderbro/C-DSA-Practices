#include <iostream>
using namespace std;

void countingsort(int arr[], int s, int r)
{
    int output_array[s];
    int count_array[r];
    for(int i = 0; i<r ; i++)
    {
        count_array[i] = 0;
    }
    for(int i = 0; i<s ; i++)
    {
        ++count_array[arr[i]];
    }
    for(int i = 1; i<r ; i++)
    {
        count_array[i]= count_array[i] + count_array[i-1];
    }
    for(int i = 0; i<s ; i++)
    {
        output_array[--count_array[arr[i]]] = arr[i];
    }
    for(int i = 0; i<s ; i++)
    {
        arr[i] = output_array[i];
    }
}

int main()
{
    int range = 10;
    int size = 0;
    cout<< "how many elements you want to store in the array: ";
    cin>> size;

    int myarray[size];
    cout<< endl;

    cout<< "Please enter the values you want to store : ";
    for(int i = 0; i< size; i++)
    {
        cin>> myarray[i];
    }
    cout<< endl;

    cout<< "elements stored in the array: ";
    for(int i= 0; i< size; i++)
    {
        cout<<  myarray[i] << " ";
    }
    cout<< endl;

    cout<< "after sorting";

    countingsort(myarray, size, range);

    for(int i= 0; i< size; i++)
    {
        cout<<  myarray[i] << " ";
    }
    return 0;
}