#include<iostream>
#include<algorithm>
using namespace std;

class count_negative
{
    public:
        int count_k_way(int *arr, int n, int ctr, int incr, int size);
};

//Counting negative numbers in array using k-way method
int count_negative::count_k_way(int *arr, int n, int ctr, int incr, int size)
{
    if (size<n)
    {
        if (size+incr<n)
        {
            for (int i = 0; i < incr; i++)
            {
                if (arr[i]<0)
                    ctr++;
            }
        }
        else
        {
            for (int i = 0; i < n-size; i++)
            {
                if (arr[i]<0)
                    ctr++;
            }
        }
    }

    if (size>=n)
    {
        return ctr;
    }

    return count_k_way(arr+incr, n, ctr, incr, size+incr);
}

//Driver function
int main(int argc, char const *argv[])
{
    int n, k;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cin>>k;

    count_negative count;
    int incr = n/k;
    int max = count.count_k_way(arr, n, 0, incr, 0);
    cout<<max;
    return 0;
}