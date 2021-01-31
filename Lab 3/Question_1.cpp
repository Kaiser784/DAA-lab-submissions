#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

class sort
{
    public:
        void logic1(vector<int> &array, int size);
        void logic2(vector<int> &array, int size);
        void logic3(vector<int> &array, int size);
};

void sort::logic1(vector<int> &array, int size)
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

void sort::logic2(vector<int> &array, int size)
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

    sort ternary;

    cout << "The sorted ternary array using logic-1 is : ";
    ternary.logic1(array, size);
    cout << "The sorted ternary array using logic-2 is : ";
    ternary.logic2(array, size);
}