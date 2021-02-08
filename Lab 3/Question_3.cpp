// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

#define maxN 20 
#define maxSum 50 
#define minSum 50 
#define base 50

int dp[20][100];

int findCnt(int* arr, int i, int required_sum, int n) 
{
	if (i == n) { 
		if (required_sum == 0) 
			return 1; 
		else
			return 0; 
	}

	if (dp[i][required_sum + base])
		return dp[i][required_sum + base];

	dp[i][required_sum + base] = findCnt(arr, i + 1, required_sum, n) + findCnt(arr, i + 1, required_sum - arr[i], n); 
	
	return dp[i][required_sum + base]; 
} 

int main() 
{ 
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

	for (int i = 0; i < 20; i++)
	{
		dp[i][50]={0};
	}

	cout << findCnt(arr, 0, sum, size); 

	return 0; 
}