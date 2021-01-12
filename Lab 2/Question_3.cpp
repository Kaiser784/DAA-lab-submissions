#include<iostream>
#include<cmath>
using namespace std;

class triangle
{
    public:
        void upper_left_triangle(int n);
        void upper_right_triangle(int n);
        void lower_left_triangle(int n);
        void lower_right_triangle(int n);
        void hourglass(int n);
};

/*Function for upper left triangle
  Eg - for n=5
  1 2 3 4 5
  1 2 3 4
  1 2 3
  1 2
  1
*/
void triangle::upper_left_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

/*Function for upper right triangle
Eg - for n=5
  1 2 3 4 5
    2 3 4 5
      3 4 5
        4 5
          5
*/
void triangle::upper_right_triangle(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"  ";
        }
        for (int j = i+1; j <= n; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

/*Function for lower left triangle
  Eg - for n=5
  1
  1 2
  1 2 3
  1 2 3 4
  1 2 3 4 5
*/
void triangle::lower_left_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

/*Function for lower left triangle
  Eg - for n=5
          5
        4 5
      3 4 5
    2 3 4 5
  1 2 3 4 5
*/
void triangle::lower_right_triangle(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = n-i; j >= 1; j--)
        {
            cout<<"  ";
        }
        for (int j = n-i+1; j <= n; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

void triangle::hourglass(int n)
{
    //Upper triangle
    for (int i = 0; i < ceil(n/2); i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout<<"  ";
        }
        for (int j = 1+i; j <= n-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    //Lower triangle
    for (int i = ceil(n/2)-1; i >= 0; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout<<"  ";
        }
        for (int j = i+1; j <= n-i; j++)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}

int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    triangle create;
    cout<<"\nUpper Left Triangle:\n";
    create.upper_left_triangle(n);
    cout<<"\nUpper Right Triangle:\n";
    create.upper_right_triangle(n);
    cout<<"\nLower Left Triangle:\n";
    create.lower_left_triangle(n);
    cout<<"\nLower Left Triangle:\n";
    create.lower_right_triangle(n);
    cout<<"\nHourglass:\n";
    create.hourglass(n);
    return 0;
}