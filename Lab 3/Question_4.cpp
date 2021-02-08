#include<iostream>
#include<vector>
using namespace std;

class findSubarraySum
{
    public:
        int countSubarraySum(int *arr, int size, int sum);
        void printSubarraySum(int *arr, int size, int sum);
};

void printAllSubsets(int arr[], int size, vector<int> v, int sum) 
{
	if (sum == 0)
    { 
		for (auto x : v) 
			cout << x << " "; 
		cout << endl; 
		return; 
	} 

	if (size == 0) 
		return; 

	printAllSubsets(arr, size - 1, v, sum); 
	v.push_back(arr[size - 1]); 
	printAllSubsets(arr, size - 1, v, sum - arr[size - 1]); 
} 

void findSubarraySum::printSubarraySum(int *arr, int size, int sum) 
{ 
	vector<int> v; 
	printAllSubsets(arr, size, v, sum); 
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

    //cout<<"Number of subarrays with sum '"<<sum<<"' = "<<subarraysum.countSubarraySum(arr, size, sum)<<endl;
    subarraysum.printSubarraySum(arr, size, sum);

	return 0;
}