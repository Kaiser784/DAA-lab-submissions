#include<bits/stdc++.h>
#include"prime_factor.h"
using namespace std;

class GCD
{
    public:
    int GCD_1(int n, int m);
    int GCD_2(int n, int m);
    int GCD_3(int n, int m);
};

int GCD::GCD_1(int n, int m)
{
    if (m == 0)
    {
        return n;
    }
    return GCD_1(m, n % m);
}

int GCD::GCD_2(int n, int m)
{
    if (m == 0)
       return n;
    if (n == 0)
       return m;
    if (n == m)
        return n;
    if (n > m)
        return GCD_2(n-m, m);
    return GCD_2(n, m-n); 
}

int GCD::GCD_3(int n, int m)
{
    prime_factor pf;
    vector<pair<int, int>> fact1 = pf.factor(n);
    vector<pair<int, int>> fact2 = pf.factor(m);
    int i = 0, j = 0, gcd = 0;
    while (i < fact1.size() &&  j < fact2.size())
    {
        if (fact1[i].first < fact2[j].first)
        {
            i++;
        }
        else if (fact1[i].first > fact2[j].first)
        {
            j++;
        }
        else if (fact1[i].first == fact2[j].first)
        {
            int comm_pow = min(fact1[i].second, fact2[j].second);
            gcd += pow(fact1[i].first, comm_pow);
            i++;
            j++;
        }
    }
    return gcd;
}

int main()
{
    int n, m;
    cout<<"Enter 2 values\n";
    cin>>n>>m;
    GCD val;
    cout<<"Logic 1: "<<val.GCD_1(n, m)<<"\n";
    cout<<"Logic 2: "<<val.GCD_2(n, m)<<"\n";
    cout<<"Logic 3: "<<val.GCD_3(n, m)<<"\n";
    return 0;
}