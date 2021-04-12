#include <bits/stdc++.h>
using namespace std;

bool sortby_endtime(pair<int, int> time1, pair<int, int> time2)
{
    return time1.second<time2.second;
}

class scheduling
{
    public:
        void max_processes(vector<pair<int, int>> time, int num)
        {
            sort(time.begin(), time.end(), sortby_endtime);

            int pro_num = 0, i = 0;
            cout<<pro_num+1<<" ";
            while (i < num)
            {
                if (time[i].first >= time[pro_num].second)
                {
                    cout<<i+1<<" ";
                    pro_num=i;
                }
                i++;
            }
        }
};

int main()
{
    vector<pair<int, int>> time;
    int num, start, end;
    cout<<"Enter the number of processes: ";
    cin>>num;
    cout<<"Enter the start time and end time of process\n";
    for (int i = 0; i < num; i++)
    {
        cin>>start>>end;
        time.push_back(make_pair(start, end));
    }
    
    scheduling obj;
    cout<<"Processes that are selected: ";
    obj.max_processes(time, num);
    return 0;
}