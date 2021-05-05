#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 
#define maxn 31

using namespace std;

class data
{
    public:
        void greedy_truck();
        int dp_truck(int capacity, int i);
        vector<int> weights{30, 60, 90}; //weights of containers
        int limit = 120;                 //capacity of trucks

};

void data::greedy_truck()
{
    vector<int> w_temp;

    w_temp = weights;
    sort(w_temp.begin(), w_temp.end());

    int i = 0;
    int load = 0;

    while(load <= limit)
    {
        load = load + w_temp[i];
        if(load > limit)
        break;
        
        i++;
    }

    cout<<"The maximum no of containers is " << i << "  [Greedy]" << endl;

}

int table[maxn][maxn];

int data::dp_truck(int capacity, int i)
{
    if(i == weights.size())
    {
        return 0;
    }
    if(table[i][capacity] != -1)
    {
        return table[i][capacity];
    }

    int loadtk = 0;
    int unload = 0;

    if(capacity >= weights[i])
    {
        loadtk = 1 + dp_truck(capacity-weights[i], i+1);
    }

    unload = dp_truck(capacity, i+1);

    table[i][capacity] = max(unload, loadtk);

    return table[i][capacity];
}

int main()
{
    data truck;

    truck.greedy_truck();

    for(int i = 0; i < maxn; i++) // initializing table
    {
        for(int j = 0; j < maxn; j++)
        {
            table[i][j] = -1;
        }
    }

    int load_count = truck.dp_truck(truck.limit, 0);

    cout<<"The maximum no of containers is " << load_count << "  [DP]" << endl; 


    return 0;
}