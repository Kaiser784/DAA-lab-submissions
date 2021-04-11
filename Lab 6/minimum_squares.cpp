#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{
    public:
        vector<int> dim{29, 13};
        map<int, int> total;
        void find();
        void print();
};

void data::find()
{   
    int leftover = 0;
    

    while(dim[1] > 0)
    {
        int square = dim[0]/dim[1];
        total.insert({dim[1], square});

        leftover = dim[0] % dim[1];
        dim[0] = dim[1];
        dim[1] = leftover;
    }    

}

void data::print()
{   
    map<int, int>::iterator i;

    for(i = total.begin(); i != total.end(); i++)
    {
        cout << i->second << "\t" << i->first <<"x"<< i->first << "\n";
    }
}

int main()
{
    data squares;
    
    squares.find();
    squares.print();

    return 0;
}