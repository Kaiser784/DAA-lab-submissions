#include <bits/stdc++.h>
using namespace std;

class max_container {
    public:
        //Greedy Algorithm for max number of containers
        /*
        In greedy approach we start filling the contanier from the smallest weight
        Every time a new container K_i is inserted, we subtract the weight w_i from the max capacity C
        Increment counter for each insertion
        Keep inserting containers until the weight of container K_i is greater than max capacity C
        */
        int max_container_greedy(int* wt, int k, int C)
        {
            int ctr = 0;
            sort(wt, wt+k);
            for (int i = 0; i < k; i++)
            {
                if (C>=wt[i])
                {
                    C -= wt[i];
                    ctr++;
                }
                else
                {
                    break;
                }
            }
            return ctr;
        }

        //DP algorithm for max number of containers
        /*
        We use tabulation or bottom-up approach
        Calculate optimum solution for lower subproblems first and store it in a table (2D array)
        And then use those values to calculate optimum solution for higher subproblems
        */
        int max_container_dp(int* wt, int k, int C)
        {
            //2D array to store the optimum solution of subproblems
            int dp[k+1][C+1];
            
            //We build the table for DP using bottom-up approach
            for (int i = 0; i <= k; i++)
            {
                for (int j = 0; j <= C; j++)
                {
                    if (i == 0 || j == 0)
                    {
                        dp[i][j] = 0;
                    }
                    else if (wt[i-1] <= j)
                    {
                        dp[i][j] = max(1+dp[i-1][j-wt[i-1]], dp[i-1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[k][C];
        }
};

int main()
{
    int C, k;
    cout<<"Enter the max capacity: ";
    cin>>C;
    cout<<"Enter the number of containers: ";
    cin>>k;
    int wt[k];

    cout<<"Enter the number of containers: ";
    for (int i = 0; i < k; i++)
    {
        cin>>wt[i];
    }

    max_container obj;

    cout<<"Max number of containers using Greedy Approach: "<<obj.max_container_greedy(wt, k, C)<<"\n";
    cout<<"Max number of containers using DP: "<<obj.max_container_dp(wt, k, C)<<"\n";

    return 0;
}