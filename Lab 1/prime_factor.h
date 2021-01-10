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