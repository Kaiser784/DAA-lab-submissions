#include <bits/stdc++.h>
#define K 30
#define C 30
using namespace std;

class two_knapsack {
    int dp[K][C][C];

    public:
        void initialize_table(int k, int C1, int C2)
        {
            memset(dp, -1, sizeof(dp));
        }

        //DP algorithm for max number of containers
        int max_container_dp(int* wt, int k, int C1, int C2, int i)
        {
            // Base case
            if (i == k)
            {
                return 0;
            }

            //Check whether the solution for subproblem is already calculated
            if (dp[i][C1][C2] != -1)
            {
                return dp[i][C1][C2];
            }
            
            int temp1 = 0, temp2 = 0, temp3 = 0;

            //Put the container into truck 1
            if (C1 >= wt[i])
            {
                //Stores the result obtained by inserting container K_i in truck 1
                temp1 = 1 + max_container_dp(wt, k, C1 - wt[i], C2, i + 1);
            }

            //Put the container into truck 2
            if (C2 >= wt[i])
            {
                //Stores the result obtained by inserting container K_i in truck 2
                temp2 = 1 + max_container_dp(wt, k, C1, C2 - wt[i], i + 1);
            }

            //Container cannot be inserted into either of the trucks
            //We leave that container and go to the next container
            temp3 = max_container_dp(wt, k, C1, C2, i + 1);

            //Pick the max among all 3 parts of recurrence relation
            //Store the value in the table
            dp[i][C1][C2] = max(temp3, max(temp1, temp2));

            return dp[i][C1][C2];
        }
};

int main()
{
    int k, C1, C2;
    cout<<"Enter the number of containers: ";
    cin>>k;
    int wt[k];
    cout<<"Enter the weights: \n";
    for (int i = 0; i < k; i++)
    {
        cin>>wt[i];
    }

    cout<<"Enter the max capacity of both trucks: ";
    cin>>C1>>C2;

    two_knapsack obj;
    obj.initialize_table(k, C1, C2);
	cout << obj.max_container_dp(wt, k, C1, C2, 0);
	return 0;
}
