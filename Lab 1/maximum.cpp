#include<iostream>
#include<vector>
#include<cmath>
#include <bits/stdc++.h> 
using namespace std;

class maximum
{
    public:
        int logic1(int* array, int size);
        int logic2(int* array, int size);
        int logic3(int* array, int size);
};

int maximum::logic1(int* array, int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (max < array[i])
        {
            max = array[i];
        }
    }
    return max;    
}

int maximum::logic2(int* array, int size)
{   
    int max;
    int temp;

    for(int i = 0; i < size-1; i++)
    {
        if(array[i] > array[i+1])
        {
            temp = array[i];
            array[i] = array[i+1];
            array[i+1] = temp;
        }
    }

    return array[size-1];
}

int maximum::logic3(int* array, int size)
{   
    int AND = 1;
    int max = 0;

    while(AND)
    {   
        AND = 0;

        for(int i = 0; i < size; i++)
        {
            if(array[i])
            {
               array[i]--;
            }
        }
        
        for(int i = 0; i < size; i++)
        {
            AND = AND | array[i];
        }

        max++;
    }

    return max;
}

int main()
{
    int size;

    begin:
    cout << "Enter the size of the integer array you're going to enter : ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Please enter a proper size!!(i.e. greater than or equal to one)" << endl;
        goto begin;
    }

    int array[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> array[i];
    }

    maximum numbers;

    int max1 = numbers.logic1(array, size);
    cout << "The maximum from logic-1 is " << max1 << endl;

    int max2 = numbers.logic2(array, size);
    cout << "The maximum from logic-2 is " << max2 << endl;

    int max3 = numbers.logic3(array, size);
    cout << "The maximum from logic-3 is " << max3 << endl;

    return 0;
}