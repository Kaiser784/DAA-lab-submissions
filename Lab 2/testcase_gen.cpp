#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int RandomRange(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

int main()
{
    srand(time(0));
    ofstream fin;
    fin.open("input.text");
    int t = 20;
    fin<<t<<"\n";
    int arr[1000];
    while(t--)
    {
        int num1 = RandomRange(1,100);
        int num2 = RandomRange(1,100);
        fin<<num1<<" "<<num2<<endl;
        for (int i = 0; i < num1; i++)
        {
            arr[i] = RandomRange(1,100);
            fin<<arr[i]<<" ";
        }
        fin<<endl;
    }
    fin.close();
    return 0;
}