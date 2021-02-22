#include<iostream>
#include<algorithm>
using namespace std;

//To find the max in an array
class maximum
{
    public:
        //Finding Maximum in array using k-way method
        int max_k_way(int *arr, int n, int max, int incr, int size)
        {
            if (size<n)
            {
                if (size+incr<n)
                {
                    sort(arr, arr+incr);
                    max=arr[incr-1]>max?arr[incr-1]:max;
                }
                else
                {
                    sort(arr, arr+(n-size));
                    max=arr[n-size-1]>max?arr[n-size-1]:max;
                }
            }

            if (size>=n)
            {
                return max;
            }

            return max_k_way(arr+incr, n, max, incr, size+incr);
        }
};

//Maximum in an array using 2 way method
class max_two_way : public maximum
{
    public:
        int max_2_way(int *arr, int n, int ctr, int incr, int size)
        {
            return max_k_way(arr, n, ctr, incr, size);
        }
};

//Maximum in an array using 3 way method
class max_three_way : public maximum
{
    public:
        int max_3_way(int *arr, int n, int ctr, int incr, int size)
        {
            return max_k_way(arr, n, ctr, incr, size);
        }
};

//Driver function
int main(int argc, char const *argv[])
{
    int n, k, max;
    cout<<"Enter value of n: ";
    cin>>n;
    int arr[n];
    cout<<"Enter array values: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    max_two_way obj1;
    max=obj1.max_2_way(arr, n, 0, n/2, 0);
    cout<<"Max using 2 way: "<<max<<"\n";

    max_three_way obj2;
    max=obj2.max_3_way(arr, n, 0, n/3, 0);
    cout<<"Max using 3 way: "<<max<<"\n";

    cout<<"Enter value of k: ";
    cin>>k;
    maximum obj3;
    max = obj3.max_k_way(arr, n, 0, n/k, 0);
    cout<<"Max using "<<k<<" way: "<<max<<"\n";
    return 0;
}