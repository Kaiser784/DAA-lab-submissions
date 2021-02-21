#include<iostream>
#include<algorithm>
using namespace std;

class compare
{
    public:
        int greaterthan(int num1, int num2);
        int lesserthan(int num1, int num2);
};

//Function to find the max among 2 numbers
int compare::greaterthan(int num1, int num2)
{
    return num1>num2?num1:num2;
}

class maximum
{
    public:
        int max_k_way(int *arr, int n, int max, int incr, int size);
};

//Finding Maximum in array using k-way method
int maximum::max_k_way(int *arr, int n, int max, int incr, int size)
{
    compare comp;

    if (size<n)
    {
        if (size+incr<n)
        {
            sort(arr, arr+incr);
            max=comp.greaterthan(arr[incr-1], max);
        }
        else
        {
            sort(arr, arr+(n-size));
            max=comp.greaterthan(arr[n-size-1], max);
        }
    }

    if (size>=n)
    {
        return max;
    }

    return max_k_way(arr+incr, n, max, incr, size+incr);
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

    maximum max_array;
    int incr = n/k;
    int max = max_array.max_k_way(arr, n, 0, incr, 0);
    cout<<max;
    return 0;
}