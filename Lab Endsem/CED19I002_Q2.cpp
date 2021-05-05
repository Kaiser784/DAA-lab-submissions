#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 
#define maxn 31

using namespace std;

class data
{
    public:
        int dp_2truck(int capacity1, int capacity2, int i);
        vector<int> weights{30, 60, 90, 30, 60, 90}; //weights of containers
        int limit = 100;                             //capacity of trucks
};

int table[maxn][maxn][maxn];

int data::dp_2truck(int capacity1, int capacity2, int i)
{
    if(i == weights.size())
    {
        return 0;
    }
    if(table[i][capacity1][capacity2] != -1)
    {
        return table[i][capacity1][capacity2];
    }

    int load_tk1 = 0;
    int load_tk2 = 0;
    int unload = 0;

    if(capacity1 >= weights[i])
    {
        load_tk1 = 1 + dp_2truck(capacity1-weights[i], capacity2, i+1);
    }
    if(capacity2 >= weights[i])
    {
        load_tk2 = 1 + dp_2truck(capacity1, capacity2-weights[i], i+1);
    }

    unload = dp_2truck(capacity1, capacity2, i+1);

    table[i][capacity1][capacity2] = max(unload, max(load_tk1, load_tk2));

    return table[i][capacity1][capacity2];
}

int main()
{
    data trucks;

    for(int i = 0; i < maxn; i++)// initializing table
    {
        for(int j = 0; j < maxn; j++)
        {
            for(int k = 0; k < maxn; k++)
            {
                table[i][j][k] = -1;
            }
        }
    }

    int load_count = trucks.dp_2truck(trucks.limit, trucks.limit, 0);

    cout << "The max containers in both trucks combined is " << load_count << endl;

    return 0;
}