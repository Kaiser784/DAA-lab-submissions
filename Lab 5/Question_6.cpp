#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{   
    public:
        vector<int> heap{20, 18, 10, 12, 9, 9, 3, 5, 6, 8};
        vector<int> temp;
};

class heaps : public data
{
    public:
        void min_in_heap();
        int height(int size);
};

int heaps::height(int size)
{   
    int height = ceil(log2(heap.size() + 1)) - 1;
    return height;
}

void heaps::min_in_heap()
{
    int hyt = height(heap.size());

    for(int i = heap.size()-1; i >= 0; i--)
    {   
        int temphyt = height(i + 1);

        if(temphyt == hyt)
        {
            temp.push_back(heap[i]);
        }
        else if(temphyt == hyt - 1 && heap.size() <= ((2*i) + 1))
        {
            temp.push_back(heap[i]);
        }
        else
        {
            break;
        }
    }

    int min = temp[0];
    int smin = temp[0];

    for(int i = 0; i < temp.size(); i++)
    {
        if(temp[i] < min)
        {
            smin = min;
            min = temp[i];
        }
        else if (temp[i] < smin && temp[i] != min)
        {
            smin = temp[i];
        }
    }

    cout << "\n" << "The minimum element in the heap is " << min;
    cout << "\n" << "The 2nd minimum element in the heap is " << smin;
}

int main()
{   
    heaps arr;

    arr.min_in_heap();  
    
    cout << "\n";

    return 0;
}