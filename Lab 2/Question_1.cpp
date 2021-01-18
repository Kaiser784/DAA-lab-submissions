#include<iostream>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<chrono>
#include<fstream>
using namespace std;
using namespace std::chrono;

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

        auto start1 =  high_resolution_clock::now();
        check = s.logic_1(A, size, p);
        auto stop1 = high_resolution_clock::now();
        auto duration1 = duration_cast<microseconds>(stop1-start1);
        cout<<"Logic-1: "<<check<<"\n";
        outdata<<duration1.count()<<",";
        
        auto start2 =  high_resolution_clock::now();
        check = s.logic_2(A, size, p);
        auto stop2 = high_resolution_clock::now();
        auto duration2 = duration_cast<microseconds>(stop2-start2);
        cout<<"Logic-2: "<<check<<"\n";
        outdata<<duration2.count()<<",";

        auto start3 =  high_resolution_clock::now();
        check = s.logic_3(A, size, p);
        auto stop3 = high_resolution_clock::now();
        auto duration3 = duration_cast<microseconds>(stop3-start3);
        cout<<"Logic-3: "<<check<<"\n";
        outdata<<duration3.count()<<"\n";
    }

    outdata.close();

    return 0;
}