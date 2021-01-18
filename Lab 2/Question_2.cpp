#include<iostream>
#include<iomanip>
#include<vector>
#include<time.h>

using namespace std;

class search
{
    public:
        int logic2(vector<int> &array);
        int logic3(vector<int> &array, int posn);
};

int search::logic2(vector<int> &array)
{
    int posn = 0;
    int size = array.size();

    for(int i = 0; i < size; i++)
    {
        posn++;
        if(array[i] == -1)
        {
            return posn;
        }
        if(array[size-1-i] != -1)
        {
            return size-posn+2;
        }
    }
    return 0;
}

int search::logic3(vector<int> &array, int posn)
{
    if(array[posn] == -1)
    {
        return posn+1;
    }
    else
    {
        search::logic3(array, posn+1);
    }
}

int main()
{
    vector<int> array;
    int temp;
    int count = 0;

    while(1)
    {
        cout << "Enter the number (-1 is the delimiter) : ";
        cin >> temp;
        count++;

        if(temp == -1)
        {
            goto delimiter;
        }
        array.push_back(temp);
    }

    delimiter:
    
    while(1)
    {   
        begin:
        cout << "Enter the number (0 to exit) : ";
        cin >> temp;

        if(temp == 0)
        {
            break;
        }
        else if(temp != -1)
        {
            cout << "You are only allowed to enter -1 after entering the delimiter" << endl;
            cout << "If you want to exit the program enter 0" << endl;
            goto begin;
        }
        array.push_back(temp);
    }

    int posn;   
    search srch;
    clock_t start, end;
    
    cout << "The position of -1 using logic-1 is "<< count << endl;

    start = clock();
    posn = srch.logic2(array);
    end = clock();

    double time2 = double(end-start)/double(CLOCKS_PER_SEC);

    cout << "The position of -1 using logic-2 is "<< posn << endl;
    cout << "Time taken by logic-2 is "<< fixed << time2 << setprecision(6) <<" seconds" << endl;

    start = clock();
    posn = srch.logic3(array, 0);
    end = clock();

    double time3 = double(end-start)/double(CLOCKS_PER_SEC);

    cout << "The position of -1 using logic-3 is "<< posn << endl;
    cout << "Time taken by logic-3 is "<< fixed << time3 << setprecision(6) <<" seconds" << endl;
}   