#include<iostream>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;
using high_resolution_clock=system_clock;

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

/*Using Hash Table
  For each element finding a approriate pair for sum to be 'p'
  Time complexity - O(n)
*/
int solve::logic_3(int *A, int size, int p)
{
    unordered_map<int, int> h;
    for (int i = 0; i < size; i++)
    {
        int q=p-A[i];
        if (h[q]==1)
        {
            return 1;
        }
        else
        {
            h.insert(make_pair(A[i], 1));
        }
    }
    return -1;
}

int main()
{
    int size, p, t, check, pos=1;
    cout<<"Enter the number of testcases: ";
    cin>>t;

    solve s;
    ofstream outdata;
    outdata.open("output.csv", ios::out | ios::app);

    outdata<<"Serial No, Time-1, Time-2, Time-3\n";

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

        outdata<<pos++<<",";

        auto start =  system_clock::now();
        check = s.logic_1(A, size, p);
        auto stop = system_clock::now();
        auto duration = duration_cast<nanoseconds>(stop-start);
        cout<<"Logic-1: "<<check<<"\n";
        outdata<<duration.count()<<",";
        
        start =  system_clock::now();
        check = s.logic_2(A, size, p);
        stop = system_clock::now();
        duration = duration_cast<nanoseconds>(stop-start);
        cout<<"Logic-2: "<<check<<"\n";
        outdata<<duration.count()<<",";

        start =  system_clock::now();
        check = s.logic_3(A, size, p);
        stop = system_clock::now();
        duration = duration_cast<nanoseconds>(stop-start);
        cout<<"Logic-3: "<<check<<"\n";
        outdata<<duration.count()<<"\n";
    }

    outdata.close();

    return 0;
}