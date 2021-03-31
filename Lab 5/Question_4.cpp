#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{   
    public:
    void print(array<int, 100>& arr, int size);
    int bin_search(array<int, 100>& arr, int key, int start, int end);
};

void data::print(array<int, 100>& arr, int size)
{   
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ",";
    }
}

class sorting : public data
{
    public:
        void insertion_sort(array<int, 100>& arr, int size);
};

int data::bin_search(array<int, 100>& arr, int key, int start, int end)
{
    if(end <= start)
    {
        if(key > arr[start])
        {
            return start + 1;
        }
        else
        {
            return start;
        }
    }
    
    int mid = (start + end) / 2;

    if(key == arr[mid])
    {
        return mid + 1;
    }
    if(key > arr[mid])
    {
        return bin_search(arr, key, mid + 1, end);
    }
    else
    {
        return bin_search(arr, key, start, mid - 1);
    }
}

void sorting::insertion_sort(array<int, 100>& arr, int size)
{   
    int posn;
    int current;

    for(int i = 1; i < size; i++)
    {
        int j = i - 1;
        current = arr[i];

        posn = bin_search(arr, current, 0, j);

        while(j >= posn)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main()
{   
    sorting arr; 
    array<int,100> array{12, 56, 1, 67, 45, 8, 82, 16, 63, 23, 150};
    int size = 11;

    cout << "\n";
    cout << "The sorted array is : ";
    arr.insertion_sort(array, size); 
    arr.print(array, size);
    cout << "\n";

    return 0;
}