#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
#include <algorithm>

using namespace std;

class sortter
{
    public:
        void logic1(vector<int> &array, int size);
        void logic2(vector<int> &array, int size);
        void logic3(vector<int> &array, int size);
        void logic4(vector<int> &array, int size);
};

void sortter::logic1(vector<int> &array, int size)
{
    vector<int> sorted;

    for(int i = 0; i < size; i++)
    {
        if(array[i] == 0)
        {
            sorted.push_back(array[i]);
        }
    }
    for(int i = 0; i < size; i++)
    {
        if(array[i] == 1)
        {
            sorted.push_back(array[i]);
        }
    }
    for(int i = 0; i < size; i++)
    {
        if(array[i] == 2)
        {
            sorted.push_back(array[i]);
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << sorted[i] << ",";
    }
    cout << endl;    
}

void sortter::logic2(vector<int> &array, int size)
{
    for(int i = 0; i < size-1; i++)
    {
        for(int j = 0; j < size-i-1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;
}

void sortter::logic3(vector<int> &array, int size)
{
    vector<int> arr0;
    int count0 = 0;
    vector<int> arr1;
    int count1 = 0;
    vector<int> arr2;
    int count2 = 0;

    vector<int> arr;

    for(int i = 0; i < size; i++)
    {
        if(array[i] == 0)
        {
            arr0.push_back(array[i]);
            count0++;
        }
        if(array[i] == 1)
        {
            arr1.push_back(array[i]);
            count1++;
        }
        if(array[i] == 2)
        {
            arr2.push_back(array[i]);
            count2++;
        }
    }

    arr.reserve(arr0.size() + arr1.size() + arr2.size());
    arr.insert(arr.end(), arr0.begin(), arr0.end());
    arr.insert(arr.end(), arr1.begin(), arr1.end());
    arr.insert(arr.end(), arr2.begin(), arr2.end());

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << ",";
    }
    cout << endl;
}

void sortter::logic4(vector<int> &array, int size)
{
    for(int i = 0; i < size; i++)
    {   
        int key = array[i];
        int j = i - 1;

        while(j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << ",";
    }
    cout << endl;
}


int main()
{
    vector<int> array;
    int size, temp;

    cout << "Enter the size of the array : "<< endl;
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> temp;

        array.push_back(temp);
    }

    sortter ternary;

    cout << "The sorted ternary array using logic-1 is : ";
    ternary.logic1(array, size);
    cout << "The sorted ternary array using logic-2 is : ";
    ternary.logic2(array, size);
    cout << "The sorted ternary array using logic-3 is : ";
    ternary.logic3(array, size);
}