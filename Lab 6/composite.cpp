#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{
    public:
        int number = 90;
        map<int, int> total;
        int find(); 
        void print();                           
};

int data::find()
{   
    if(number < 4)
    {
        cout <<"Splitting into composite NOT Possible";
        return 0;
    }

    if(number%4 == 0)
    {
        total.insert({number / 4, 4});
        return 0;
    }
    if(number%4 == 1)
    {
        if(number < 9)
        {
            cout <<"Splitting into composite NOT Possible";
            return 0;
        }
        
        total.insert({(number / 4)-2, 4});
        total.insert({1, 9});
    }
    if(number%4 == 2)
    {
        total.insert({(number / 4)-1, 4});
        total.insert({1, 6});
    }
    if(number%4 == 3)
    {
        if(number < 15)
        {
            cout <<"Splitting into composite NOT Possible";
            return 0;
        }
        
        total.insert({(number / 4)-3, 4});
        total.insert({1, 15});
    }
    return 0;
}

void data::print()
{   
    map<int, int>::iterator i;

    for(i = total.begin(); i != total.end(); i++)
    {
        cout << i->second << "\t" << i->first << "\n";
    }
}

int main()
{
    data comp;
    
    comp.find();
    comp.print();

    return 0;
}