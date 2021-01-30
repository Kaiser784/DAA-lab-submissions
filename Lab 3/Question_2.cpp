#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

class duplicates
{
    public:
        void logic1(vector<int> &array, int size);
        void logic2(vector<int> &array, int size);
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

void duplicates::logic2(vector<int> &array, int size)
{
    unordered_map<int, int> map;
    unordered_map<int, int>:: iterator i;
    int check = 0;

    for(int i = 0; i < size; i++)
    {
        map[array[i]]++;
    }

    for(i = map.begin(); i != map.end(); i++)
    {
        if(i->second > 1)
        {
            cout << i->first << ",";
            check++;
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

    cout << "The duplicates in the given array using logic-2 are : ";
    dupes.logic2(array, size);
}
