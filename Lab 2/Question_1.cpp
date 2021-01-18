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
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            cout<<"";
            if (A[i]+A[j] == p)
            {
                return 1;
            }
        }
    }
    return -1;
}

/*Sorting and using binary search to find the pair
  Time complexity of sorting - O(NlogN) and of binary search - O(logN)
  Time complexity - O(NlogN)
*/
int solve::logic_2(int *A, int size, int p)
{
    sort(A, A+size);
    int i=0, j=size-1;
    while (i<j)
    {
        cout<<"";
        if (A[i]+A[j]==p)
        {
            return 1;
        }
        else if (A[i]+A[j]<p)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return -1;
}

/*Using Hash Table to store frequency of each element
  For each element finding a approriate pair for sum to be 'p'
  Time complexity - O(n)
*/
int solve::logic_3(int *A, int size, int p)
{
    unordered_map<int, int> h;
    for (int i = 0; i < size; i++)
    {
        int q=p-A[i];
        if (h.find(q) == h.end())
        {
            h.insert(make_pair(A[i], 1));
        }
        else
        {
            return 1;
        }
    }
    return -1;
}

int main()
{
    int size, p, t, check;
    double time1, time2, time3;
    cout<<"Enter the number of testcases: ";
    cin>>t;

    solve s;
    clock_t start, end;

    ofstream outdata;
    outdata.open("output.csv", ios::out | ios::app);

    outdata<<"Time-1, Time-2, Time-3\n";

    while (t--)
    {
        //cout<<"Enter the size of array: ";
        cin>>size>>p;
        //cout<<"Enter the integer 'p': ";
        int A[size];
        //cout<<"Enter the numbers: ";
        for (int i = 0; i < size; i++)
        {
            cin>>A[i];
        }
        start =  clock();
        check = s.logic_1(A, size, p);
        end = clock();
        time1 = double(end-start)/double(CLOCKS_PER_SEC);
        cout<<"Logic-1: "<<check<<"\n";

        start =  clock();
        check = s.logic_2(A, size, p);
        end = clock();
        time2 = double(end-start)/double(CLOCKS_PER_SEC);
        cout<<"Logic-2: "<<check<<"\n";

        start =  clock();
        check = s.logic_3(A, size, p);
        end = clock();
        time3 = double(end-start)/double(CLOCKS_PER_SEC);
        cout<<"Logic-3: "<<check<<"\n";

        cout<<fixed<<time1<<setprecision(6)<<","<<fixed<<time2<<setprecision(6)<<","<<fixed<<time3<<setprecision(6)<<"\n";
        outdata<<fixed<<time1<<setprecision(6)<<","<<fixed<<time2<<setprecision(6)<<","<<fixed<<time3<<setprecision(6)<<"\n";
    }

    outdata.close();

    return 0;
}