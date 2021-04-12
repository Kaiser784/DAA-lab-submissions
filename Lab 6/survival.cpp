#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{
    public:
        int max_food = 10;
        int days = 16;
        int required= 2;
        void find();                            
};

void data::find()
{   
    if(((max_food * 6) < (required * 7) && days > 6)|| required > max_food)
    {
       cout << "Will NOT Survive \n"; 
    }
    else
    {
        int shopped = (days*required) / max_food;

        if((days * required) % max_food != 0)
        {
            shopped++;
        }
        cout << "Will Survive \n"<< "Shopped for "<< shopped << " days\n";
    }
}

int main()
{
    data survive;
    
    survive.find();

    return 0;
}