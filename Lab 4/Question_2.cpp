#include<iostream>
#include<algorithm>
using namespace std;

//Counting negative numbers in an array
class count_negative
{
    public:
        //Counting negative numbers using k way method
        int count_k_way(int *arr, int n, int ctr, int incr, int size)
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
};

//Counting negative numbers in array using 2 way method
class count_two_way
{
    public:
        int count_2_way(int *arr, int n, int ctr, int incr, int size)
        {
            count_negative obj;
            return obj.count_k_way(arr, n, ctr, incr, size);
        }
};

//Counting negative numbers in array using 3 way method
class count_three_way
{
    public:
        int count_3_way(int *arr, int n, int ctr, int incr, int size)
        {
            count_negative obj;
            return obj.count_k_way(arr, n, ctr, incr, size);
        }
};

//Driver function
int main(int argc, char const *argv[])
{
    int n, k, ctr;
    cout<<"Enter value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array values: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    count_two_way obj1;
    ctr=obj1.count_2_way(arr, n, 0, n/2, 0);
    cout<<"Count using 2 way: "<<ctr<<"\n";

    count_three_way obj2;
    ctr=obj2.count_3_way(arr, n, 0, n/3, 0);
    cout<<"Count using 3 way: "<<ctr<<"\n";

    cout<<"Enter value of k: ";
    cin>>k;
    count_negative obj3;
    ctr = obj3.count_k_way(arr, n, 0, n/k, 0);
    cout<<ctr;
    return 0;
}