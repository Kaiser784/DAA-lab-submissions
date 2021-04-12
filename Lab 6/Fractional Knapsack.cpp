#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, int> item1, pair<int, int> item2)
{
    double r1 = (double)item1.first/(double)item1.second;
    double r2 = (double)item2.first/(double)item2.second;
    return r1>r2;
}

class frac_knapsack
{
    public:
        double max_value(vector<pair<int, int>> items, int num, int max_wgt)
        {
            sort(items.begin(), items.end(), compare);
            
            int curr = 0, i = 0;
            double res = 0;

            while (max_wgt>0 && i<num)
            {
                if (curr + items[i].second <= max_wgt)
                {
                    curr += items[i].second;
                    res += items[i].first;
                    i++;
                }
                else
                {
                    int rem = max_wgt - curr;
                    res += items[i].first * ((double)rem / (double)items[i].second);
                    return res;
                }
            }
            return res;
        }
};

int main()
{
    vector<pair<int, int>> items;
    int num, wgt, tot_wgt, value;
    cout<<"Enter the number of items: ";
    cin>>num;
    cout<<"Enter the items as - value, weight\n";
    for (int i = 0; i < num; i++)
    {
        cin>>wgt>>value;
        items.push_back(make_pair(wgt, value));
    }
    cout<<"Enter the total weight: ";
    cin>>tot_wgt;

    frac_knapsack obj;
    double res = obj.max_value(items, num, tot_wgt);
    cout<<"Max Value: "<<res<<"\n";
    
    return 0;
}