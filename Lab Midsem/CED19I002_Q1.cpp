#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class functions
{
    public: 
        vector<int> array;
        int sum;
        unordered_map<int, pair<int,int>> hash_table; //map with pairs and their sum
        void make_duopairs();
        void find_quadsubset(int sum);
};

void functions::make_duopairs() //makes pairs with their sum as hash
{
    for(int i = 0; i < array.size()-1; i++)
    {
        for(int j = i + 1; j < array.size(); j++)
        {
            hash_table[array[i] + array[j]] = {i, j};
        }
    }
}

void functions::find_quadsubset(int sum)
{
    make_duopairs();
    int count = 0;

    for(int i = 0; i < array.size()-1; i++)
    {
        for(int j = i + 1; j < array.size(); j++)
        {
            int duo_sum = array[i] + array[j];

            if(hash_table.find(sum - duo_sum) != hash_table.end())//checks if there's any hash with the remaining sum
            {
                pair<int, int> pairs = hash_table[sum - duo_sum];

                if(pairs.first != i && pairs.first != j && pairs.second != i && pairs.second != j) // to check for duplicates
                {
                    cout << array[i] << ", ";
                    cout << array[j] << ", ";
                    cout << array[pairs.first] << ", ";
                    cout << array[pairs.second] << "\n";

                    count++;

                    return; //stops running after finding one pair to avoid duplication and different positions of same pair
                }
            }
        }
    }
    if(count == 0)
    {
        cout << "No such quad pairs are present \n";
    }
}

int main()
{   
    functions quad_pairs;

    int size, input;

    cout << "Enter the size of the array : ";
    cin >> size;

    for(int i = 0; i < size; i++)
    {
        cout << "Enter the number : ";
        cin >> input;

        quad_pairs.array.push_back(input);
    }

    cout << "Enter the sum : ";
    cin >> quad_pairs.sum;

    quad_pairs.find_quadsubset(quad_pairs.sum);

    return 0;
}