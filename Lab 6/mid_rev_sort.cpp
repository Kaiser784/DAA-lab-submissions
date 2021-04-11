#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{
    public:
        vector<int> array{1, 6, 3, 4, 5, 7, 2};//non-working array => 1, 6, 3, 4, 5, 7, 2
        int find();                            //working array => {1, 6, 3, 4, 5, 2, 7}
};

int data::find()
{   
    vector<int> sorted = array;

    sort(sorted.begin(), sorted.end());

    for(int i = 0; i < array.size(); i++)
    {
        if(array[i] != sorted[i] && array[array.size()-i-1] != sorted[i])
        {
            cout <<"It's Not Possible" <<"\n";
            return 0;
        }
    }
    cout <<"It's Possible" <<"\n";
    return 0;
}

int main()
{
    data mid_rev;
    
    mid_rev.find();

    return 0;
}