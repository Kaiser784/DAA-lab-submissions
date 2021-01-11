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

class LCM
{
    public:
    int LCM_1(int n, int m);
    int LCM_2(int n, int m);
    int LCM_3(int n, int m);
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
    if (n == m)
    {
        return n;
    }
    else if (n==0 || m==0)
    {
        return max(n, m);
    }
    prime_factor pf;
    vector<pair<int, int>> fact1 = pf.factor(n);
    vector<pair<int, int>> fact2 = pf.factor(m);
    int i = 0, j = 0, gcd = 1;
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
            gcd *= pow(fact1[i].first, comm_pow);
            i++;
            j++;
        }
    }
    return gcd;
}

int LCM::LCM_1(int n, int m)
{
    GCD val;
    int gcd = val.GCD_1(n, m);
    return (n*m)/gcd;
}

int LCM::LCM_2(int n, int m)
{
    int lcm = max(n, m);
    while (1)
    {
        if (lcm%n==0 && lcm%m==0)
        {
            return lcm;
        }
        lcm++;
    }
}

int LCM::LCM_3(int n, int m)
{
    if (n == m)
    {
        return n;
    }
    prime_factor pf;
    vector<pair<int, int>> fact1 = pf.factor(n);
    vector<pair<int, int>> fact2 = pf.factor(m);
    int i = 0, j = 0, lcm = 1;
    while (i < fact1.size() &&  j < fact2.size())
    {
        if (fact1[i].first < fact2[j].first)
        {
            lcm *= pow(fact1[i].first, fact1[i].second);
            i++;
        }
        else if (fact1[i].first > fact2[j].first)
        {
            lcm *= pow(fact2[j].first, fact2[j].second);
            j++;
        }
        else if (fact1[i].first == fact2[j].first)
        {
            int comm_pow = max(fact1[i].second, fact2[j].second);
            lcm *= pow(fact1[i].first, comm_pow);
            i++;
            j++;
        }
    }
    while (i < fact1.size())
    {
        lcm *= pow(fact1[i].first, fact1[i].second);
        i++;
    }
    while (j < fact2.size())
    {
        lcm *= pow(fact2[j].first, fact2[j].second);
        j++;
    }
    return lcm;
}

int main()
{
    int n, m, choose;
    while (1)
    {
        cout<<"Enter 2 values\n";
        cin>>n>>m;
        cout<<"1. GCD\n2. LCM\n3. Exit\n";
        cin>>choose;
        switch (choose)
        {
        case 1:
            if (n==0 && m==0)
            {
                cout<<"GCD(0,0) is not defined\n";
                break;
            }
            if (n<0 || m<0)
            {
                cout<<"The number should not be negative\n";
                break;
            }
            GCD val1;
            cout<<"GCD Logic 1: "<<val1.GCD_1(n, m)<<"\n";
            cout<<"GCD Logic 2: "<<val1.GCD_2(n, m)<<"\n";
            cout<<"GCD Logic 3: "<<val1.GCD_3(n, m)<<"\n";
            break;
        case 2:
            if (n==0 || m==0)
            {
                cout<<"LCM of zero does not exist(Remove 0)\n";
                break;
            }
            if (n<0 || m<0)
            {
                cout<<"The number should not be negative\n";
                break;
            }
            LCM val2;
            cout<<"LCM Logic 1: "<<val2.LCM_1(n, m)<<"\n";
            cout<<"LCM Logic 2: "<<val2.LCM_2(n, m)<<"\n";
            cout<<"LCM Logic 3: "<<val2.LCM_3(n, m)<<"\n";
            break;

        case 3:
            exit(0);
        default:
            cout<<"Wrong\n";
            break;
        }
    }
}