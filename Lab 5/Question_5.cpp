#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h> 

using namespace std;

class data
{   
    public:
        vector<int> array1{1, 3, 5, 7, 9, 11};
        vector<int> array2{2, 4, 6, 8};
        vector<int> result;  
};

class merging : public data
{
    public:
        void method1();
        void method2();
        void method3();
};

void merging::method1()
{
    int i = 0;
    int j = 0;

    while(i < array1.size() && j < array2.size())
    {
        if(array1[i] < array2[j])
        {
            result.push_back(array1[i]);
            i++;
        }
        else
        {
            result.push_back(array2[j]);
            j++;
        }
    }

    while(i < array1.size())
    {
        result.push_back(array1[i]);
        i++;
    }

    while(j < array2.size())
    {
        result.push_back(array2[j]);
        j++;
    }


    for(i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }

}

void merging::method2()
{
    int i = 0;
    int posn;

    result.clear();

    while(i < array1.size())
    {
        result.push_back(array1[i]);
        i++;
    }

    for(int j = 0; j < array2.size(); j++)
    {
        i = result.size()-1;
        while(array2[j] < result[i] && i>=0)
        {
            i--;
        }
        result.insert(result.begin()+i+1, array2[j]);
    }

    for(i = 0; i < result.size(); i++)
    {
        cout << result[i] << ",";
    }
}

void merging::method3()
{
    result.clear();

    map<int, bool> reslt;
    
    for(int i = 0; i < array1.size(); i++)
    {
        reslt[array1[i]] = true;
    }
    for(int i = 0; i < array2.size(); i++)
    {
        reslt[array2[i]] = true;
    }

    for(auto i: reslt)
    {
        cout<< i.first <<",";
    }
}

int main()
{   
    merging arr;

    cout << "\n"<< "The merged array using method-1" << " : ";
    arr.method1(); 
    
    cout << "\n"<< "The merged array using method-2" << " : ";
    arr.method2(); 

    cout << "\n"<< "The merged array using method-3" << " : ";
    arr.method3(); 
    
    cout << "\n";

    return 0;
}