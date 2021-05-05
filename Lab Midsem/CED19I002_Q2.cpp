#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{   
    public:
        vector<int> heap;
        vector<int> leaves;
};

class heaps : public data
{
    public:
        void max_in_heap();
        void min_in_heap();
        void make_leaves();
        int height(int size);
};

int heaps::height(int size)
{   
    int height = ceil(log2(heap.size() + 1)) - 1;
    return height;
}

void heaps::make_leaves()
{
    int hyt = height(heap.size());

    for(int i = heap.size()-1; i >= 0; i--) //checks from back of the heap to reduce time and stops after all leaf nodes are pushed
    {   
        if(height(i + 1) == hyt) //check if leaf nodes at last level
        {
            leaves.push_back(heap[i]);
        }
        else if(height(i + 1) == hyt - 1 && heap.size() <= ((2*i) + 1)) //check if leaf nodes on other level
        {
            leaves.push_back(heap[i]);
        }
        else
        {
            break;
        }
    }
}

void heaps::min_in_heap()
{
    make_leaves();

    int min = INT_MAX;
    int second_min = INT_MAX;

    for(int i = 0; i < leaves.size(); i++) // checks for the elements 
    {
        if(leaves[i] < min)
        {
            second_min = min;
            min = leaves[i];
        }
        else if (leaves[i] < second_min && leaves[i] != min)
        {
            second_min = leaves[i];
        }
    }

    if(second_min == INT_MAX || leaves.size() == 2)
    {
        cout << "\n" << "There is no 2nd minimum element";
    }
    else
    {   
        cout << "\n" << "The 2nd minimum element is " << second_min;
    }
}

int main()
{   
    heaps array;

    int size, input;

    cout << "Enter the size of the array : ";
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> input;

        array.heap.push_back(input);
    }
    make_heap(array.heap.begin(),array.heap.end()); //usng stl to heapify the given array

    cout << "\n" << "The maximum element is " << array.heap[0];

    array.min_in_heap();  
    
    cout << "\n";

    return 0;
}