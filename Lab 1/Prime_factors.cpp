#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class prime_factor
{
    public:
        vector<pair<int, int>> factor(int num);
};

vector<pair<int, int>> prime_factor::factor(int num)
{
    vector<pair<int, int>> factors;
    int ctr=0;
    while (num%2==0)
    {
        ctr++;
        num=num/2;
    }
    if (ctr!=0)
    {
        factors.push_back(make_pair(2, ctr));
    }
    for (int i = 3; i <= sqrt(num); i=i+2)
    {
        ctr=0;
        while (num%i==0)
        {
            ctr++;
            num=num/i;
        }
        if (ctr!=0)
        {
            factors.push_back(make_pair(i, ctr));
        }
    }
    if (num > 2)
    {
        factors.push_back(make_pair(num, 1));
    }
    return factors;
}

int main()
{
    int num;
    while (1)
    {
        cout<<"Enter a number\n";
        cin>>num;
        if (num <= 0)
            cout<<"Only enter positive non-zero intergers\n";
        else if (num == 1)
            cout<<"1 is neither prime nor composite number\n";
        else
            break;
    }
    prime_factor pf;
    vector<pair<int, int>> fact = pf.factor(num);
    for (int i = 0; i < fact.size(); i++)
    {
        cout<<"Prime Factor: "<<fact[i].first<<" Power: "<<fact[i].second<<"\n";
    }
    return 0;
}