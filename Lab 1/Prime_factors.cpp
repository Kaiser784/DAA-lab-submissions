#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class prime_factor {
    public:
        int num;
        void getNum(int n);
        vector<pair<int, int>> factor(void);
};

void prime_factor::getNum(int n) {
    num=n;
}

vector<pair<int, int>> prime_factor::factor(void) {
    vector<pair<int, int>> factors;
    int ctr=0;
    while (num%2==0)
    {
        ctr++;
        num=num/2;
    }
    if (ctr!=0)
        factors.push_back(make_pair(2, ctr));
    for (int i = 3; i <= sqrt(num); i=i+2)
    {
        ctr=0;
        while (num%i==0)
        {
            ctr++;
            num=num/i;
        }
        if (ctr!=0)
        factors.push_back(make_pair(i, ctr));
    }
    factors.push_back(make_pair(num, 1));
    return factors;
}

int main(int argc, char const *argv[])
{
    int num;
    cin>>num;
    prime_factor pf;
    pf.getNum(num);
    vector<pair<int, int>> fact = pf.factor();
    for (int i = 0; i < fact.size(); i++)
        cout<<"Factor: "<<fact[i].first<<" Power: "<<fact[i].second<<"\n";
    return 0;
}