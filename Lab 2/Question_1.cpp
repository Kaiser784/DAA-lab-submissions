#include<iostream>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<time.h>
#include<fstream>
using namespace std;

class solve
{
    public:
        int logic_1(int *A, int size, int p);
        int logic_2(int *A, int size, int p);
        int logic_3(int *A, int size, int p);
};

/*Checking each element 
  Comparing it with remaining elements in array
  Time complexity - O(n^2)
*/
int solve::logic_1(int *A, int size, int p)
{
    int ctr = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (A[i]+A[j] == p)
            {
                ctr++;
            }
        }
    }
    return ctr;
}

/*Sorting and using binary search to find the pair
  Time complexity of sorting - O(NlogN) and of binary search - O(logN)
  Time complexity - O(NlogN)
*/
int solve::logic_2(int *A, int size, int p)
{
    int ctr=0;
    sort(A, A+size);
    for (int i = 0; i < size; i++)
    {
        bool check = binary_search(A, A+size, p-A[i]);
        if (check)
        {
            ctr++;
        }
    }
    return ctr/2;
}

/*Using Hash Table to store frequency of each element
  For each element finding a approriate pair for sum to be 'p'
  Time complexity - O(n)
*/
int solve::logic_3(int *A, int size, int p)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < size; i++)
    {
        freq[A[i]]++;
    }
    int ctr = 0;
    for (int i = 0; i < size; i++)
    {
        ctr += freq[p-A[i]];
        if (p-A[i] == A[i])
        {
            ctr--;
        }
    }
    return ctr/2;
}

int main()
{
    int size, p;
    //cout<<"Enter the size of array: ";
    //cout<<"Enter the integer 'p': ";
    cin>>size>>p;
    int A[size];
    //cout<<"Enter the numbers: ";
    for (int i = 0; i < size; i++)
    {
        cin>>A[i];
    }

    int check;
    double time1, time2, time3;
    solve s;
    clock_t start, end;

    start =  clock();
    check = s.logic_1(A, size, p);
    end = clock();
    time1 = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Logic-1: "<<check<<"\n";
    cout<<"Time taken by Logic-1: "<<fixed<<time1<<setprecision(6)<<" seconds\n";

    start =  clock();
    check = s.logic_2(A, size, p);
    end = clock();
    time2 = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Logic-2: "<<check<<"\n";
    cout<<"Time taken by Logic-1: "<<fixed<<time2<<setprecision(6)<<" seconds\n";

    start =  clock();
    check = s.logic_3(A, size, p);
    end = clock();
    time3 = double(end-start)/double(CLOCKS_PER_SEC);
    cout<<"Logic-3: "<<check<<"\n";
    cout<<"Time taken by Logic-1: "<<fixed<<time3<<setprecision(6)<<" seconds\n";

    return 0;
}