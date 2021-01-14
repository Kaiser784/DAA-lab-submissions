#include<iostream>
#include<iomanip>
#include<vector>
#include<unordered_map>
#include<time.h>
using namespace std;

class solve
{
    public:
        int logic_1(vector<int> &v, int p);
        int logic_2(vector<int> &v, int p);
        int logic_3(vector<int> &v, int p);
};

/*Checking each element 
  Comparing it with remaining elements in array
  Time complexity - O(n^2)
*/
int solve::logic_1(vector<int> &v, int p)
{
    int len = v.size(), ctr = 0;
    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (v[i]+v[j] == p)
            {
                ctr++;
            }
        }
    }
    return ctr;
}

/*Using Hash Table to store frequency of each element
  For each element finding a approriate pair for sum to be 'p'
  Time complexity - O(n)
*/
int solve::logic_2(vector<int> &v, int p)
{
    int len = v.size();
    unordered_map<int, int> freq;
    for (int i = 0; i < len; i++)
    {
        freq[v[i]]++;
    }
    int ctr = 0;
    for (int i = 0; i < len; i++)
    {
        ctr += freq[p-v[i]];
        if (p-v[i] == v[i])
        {
            ctr--;
        }
    }
    return ctr/2;
}

/*
*/
int solve::logic_3(vector<int> &v, int p)
{
}

int main()
{
    vector<int> A;
    int a, p;
    while (1)
    {
        cout<<"Enter the values('-1' to stop)\n";
        cin>>a;
        if (a==-1)
        {
            break;
        }
        A.push_back(a);
    }
    cout<<"Enter the integer p\n";
    cin>>p;

    int check;
    solve s;
    clock_t start, end;

    start =  clock();
    check = s.logic_1(A, p);
    end = clock();
    double time1 = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Logic-1: "<<check<<"\n";
    cout<<"Time taken by Logic-1: "<<fixed<<time1<<setprecision(6)<<" seconds\n";

    start =  clock();
    check = s.logic_2(A, p);
    end = clock();
    double time2 = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Logic-2: "<<check<<"\n";
    cout<<"Time taken by Logic-1: "<<fixed<<time2<<setprecision(6)<<" seconds\n";

    return 0;
}