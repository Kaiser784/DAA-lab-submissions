#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class duplicates
{
    public:
        void logic1(vector<int> &array, int size);
        int logic2(vector<int> &array);
};

void duplicates::logic1(vector<int> &array, int size)
{   
    int check = 0;
    int flag[size] = {0};

    for(int i = 0; i < size; i++)
    {   
        for(int j = 0; j < size; j++)
        {
            if(array[i] == array[j])
            {
                if(i != j)
                {
                    flag[j]++;
                    check++;
                }
            }
        }
        if(flag[i] == 1)
        {
            cout << array[i] <<",";
        }
    }
    if(check == 0)
    {
        cout << "none" << endl;
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

    duplicates dupes;

    cout << "The duplicates in the given array using logic-1 are : ";
    dupes.logic1(array, size);
}
