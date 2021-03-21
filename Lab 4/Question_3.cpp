#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class others
{
    public:
        void prints(int flag, int key);
        void insertion_sort(vector<int> &array, int size);
        void print_array(vector<int> &array, int size);
};

void others::prints(int flag, int key)
{
    if(flag == -1)
    {
        cout << "The entered key "<< key << " is not present in the array" << endl << endl;
    }
    else
    {
        cout << "The entered key is present at position-" << flag+1 << " in the array" << endl << endl;
    }

}
    
void others::insertion_sort(vector<int> &array, int size)
{
    int i, temp, j;  
    for (i = 1; i < size; i++) 
    {  
        temp = array[i];  
        j = i - 1;  
  
        while (j >= 0 && array[j] > temp) 
        {  
            array[j + 1] = array[j];  
            j = j - 1;  
        }  
        array[j + 1] = temp;  
    }  
}

void others::print_array(vector<int> &array, int size)
{
    int i;  
    for (i = 0; i < size; i++)
    {  
        cout << array[i] << " ";  
    }
    cout << endl; 
}
class binary : public others
{
    public:
        int recursive(vector<int> &array, int start, int end, int key);
        int iterative(vector<int> &array, int start, int end, int key);
};

int binary::recursive(vector<int> &array, int start, int end, int key)
{
    if(end >= start)
    {
        int mid = start + (end-start)/2;

        if(array[mid] == key)
        {
            return mid;
        }
        else if(array[mid] > key)
        {
            return binary::recursive(array, start, mid-start, key);
        }
        else
        {
            return binary::recursive(array, mid+start, end, key);
        }
    }
    return -1;
}

int binary::iterative(vector<int> &array, int start, int end, int key)
{
    while(end >= start)
    {
        int mid = start + (end-start)/2;

        if(array[mid] == key)
        {
            return mid;
        }
        else if(array[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

class ternary : public others
{
    public:
        int recursive(vector<int> &array, int start, int end, int key);
        int iterative(vector<int> &array, int start, int end, int key);
};

int ternary::recursive(vector<int> &array, int start, int end, int key)
{
    if(end >= start)
    {
        int mid1 = start + (end-start)/3;
        int mid2 = end - (end-start)/3;

        if(array[mid1] == key)
        {
            return mid1;
        }
        if(array[mid2] == key)
        {
            return mid2;
        }

        if( array[mid1] > key)
        {
            return ternary::recursive(array, start, mid1-1, key);
        }
        else if(array[mid2] < key)
        {
            return ternary::recursive(array, mid2+1, end, key);
        }
        else
        {
            return ternary::recursive(array, mid1+1, mid2-1, key);
        }
    }
    return -1;
}

int ternary::iterative(vector<int> &array, int start, int end, int key)
{
    while(end >= start)
    {
        int mid1 = start + ((end-start)/3);
        int mid2 = end - ((end-start)/3);

        if(array[mid1] == key)
        {
            return mid1;
        }
        if(array[mid2] == key)
        {
            return mid2;
        }

        if( array[mid1] > key)
        {
            end = mid1-1;
        }
        else if(array[mid2] < key)
        {
            start = mid2+1;
        }
        else
        {
            start = mid1+1;
            end = mid2-1; 
        }
    }
    return -1;
}

int main()
{
    vector<int> array;
    int size, temp;
    int flag, key;

    cout << "Enter the size of the array : ";
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> temp;

        array.push_back(temp);
    }

    cout << "Enter the number you want to find in the array : ";
    cin >> key;
    cout << endl;

    binary bin;
    ternary tern;

    bin.insertion_sort(array, size);
    cout << "The sorted array is : ";
    bin.print_array(array, size);
    cout << endl;
    cout << "Recursion Binary Search =>";
    flag  = bin.recursive(array, 0, size-1, key);
    bin.prints(flag, key);
    cout << "Iterative Binary Search =>";
    flag  = bin.iterative(array, 0, size-1, key);
    bin.prints(flag, key);
    cout << "Recursion Ternary Search =>";
    flag  = tern.recursive(array, 0, size-1, key);
    tern.prints(flag, key);
    cout << "Iterative Ternary Search =>";
    flag  = tern.iterative(array, 0, size-1, key);
    tern.prints(flag, key);

    return 0;
}