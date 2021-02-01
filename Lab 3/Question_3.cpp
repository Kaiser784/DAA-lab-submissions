#include<iostream>
#include<unordered_map>
using namespace std;

class findSubarraySum
{
    public:
        int countSubarraySum(int *arr, int size, int sum);
        void printSubarraySum(int *arr, int size, int sum);
};

int findSubarraySum::countSubarraySum(int *arr, int size, int sum)
{
    unordered_map<int,int> totsum;
    int currsum=0, ans=0;
    for(int i = 0; i < size; i++)
    {
        currsum+=arr[i];
        if (currsum == sum)
        {
            ans++;
        }
        if(totsum.find(currsum-sum) != totsum.end())
        {
            ans+=totsum[currsum-sum];
        }
        totsum[currsum]++;
    }
    return ans;
}

int main()
{
    findSubarraySum subarraysum;
    int size, sum;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int arr[size];
    cout<<"Enter the array values: ";
    for (int i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the sum: ";
    cin>>sum;
    cout<<"Number of subarrays with sum '"<<sum<<"' = "<<subarraysum.countSubarraySum(arr, size, sum)<<endl;

	return 0;
}
