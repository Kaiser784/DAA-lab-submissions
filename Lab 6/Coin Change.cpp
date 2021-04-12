#include<bits/stdc++.h>
using namespace std;

class coin_change
{
    public:
        int min_num(int *deno, int size, int value)
        {
            int ctr=0, i=size-1;
            while (value>0 && i>=0)
            {
                while (value>=deno[i])
                {
                    value -= deno[i];
                    cout<<deno[i]<<" ";
                    ctr++;
                }
                i--;
            }
            cout<<"\n";
            return ctr;
        }
};

int main()
{
    int value;
    cout<<"Enter the value: ";
    cin>>value;

    int deno[] = {1,2,5,10,20,50,100,500,1000,2000};
    int size = sizeof(deno)/sizeof(deno[0]);
    coin_change obj;
    cout<<obj.min_num(deno, size, value)<<"\n";

    return 0;
}