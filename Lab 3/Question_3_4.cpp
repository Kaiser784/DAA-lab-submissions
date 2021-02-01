#include<iostream>
#include<unordered_map>
using namespace std;

class findSubarraySum
{
    public:
        int countSubarraySum(int *arr, int size, int sum);
        void printSubarraySum(int *arr, int size, int sum);
};

void printArray(int *arr, int start, int end)
{
    cout<<"{ ";
    for (int i = start; i <= end; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"}\n";
}

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

void findSubarraySum::printSubarraySum(int *arr, int size, int sum)
{
    for (int i = 0; i < size; i++)
    {
        int currsum = 0;
        
        for (int j = i; j < size; j++)
        {
            currsum += arr[j];
            if (currsum == sum)
            {
                printArray(arr, i, j);
            }
        }
    }
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
    subarraysum.printSubarraySum(arr, size, sum);

	return 0;
}