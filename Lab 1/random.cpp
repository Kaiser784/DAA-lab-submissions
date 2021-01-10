#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class max_min
{
    public:
        int random(int, int, int, int*);
        int maximum(int* array, int size);
        int minimum(int* array, int size);
};

int max_min::maximum(int* array, int size)
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

int max_min::minimum(int* array, int size)
{
    int min = array[0];

    for (int i = 1; i < size; i++)
    {
        if (min > array[i])
        {
            min = array[i];
        }
    }
    return min;
}

int max_min::random(int max, int min, int size, int* array)
{    
    int temp;
    for(int i = 0; i < size; i++)
    {
        if(array[i] != max && array[i] != min)
        {
            temp = array[i];
            break;
        }
    }
    return temp;
}

int main()
{
    int size;

    begin:
    cout << "Enter the size of the integer array you're going to enter : ";
    cin >> size;

    if (size <= 2)
    {
        cout << "Please enter a size greater than 2 so that there may be other numbers than maximum and minimum" << endl;
        goto begin;
    }

    int array[size];

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> array[i];
    }

    max_min numbers;

    int max = numbers.maximum(array, size);
    int min = numbers.minimum(array, size);
    int random = numbers.random(max, min, size, array);

    cout << "The number which is neither MAXIMUM or MINIMUM is " << random << endl;

    return 0;
}