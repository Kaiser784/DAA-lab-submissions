#include<bits/stdc++.h>
using namespace std;



class Parent{
    public:
        void swap (int *a, int *b);
        void display(int a[],int n);
};

class QuickSort:public Parent{
public:
	void DualPivotQuickSort (int *arr, int low, int high);
	int partition (int *arr, int low, int high, int *lp);

};

void Parent::display(int a[],int n)
{
	cout<<"Dual Pivot Quick sort"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

 
void Parent::swap (int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b;  
    *b = temp;
} 
 
void QuickSort::DualPivotQuickSort (int *arr, int low, int high) 
{
    if (low < high)
    {	
        // lp means left pivot, and rp means right pivot.
        int lp, rp;  
        rp = partition (arr, low, high, &lp);
        
        DualPivotQuickSort (arr, low, lp - 1);  
        DualPivotQuickSort (arr, lp + 1, rp - 1);
        DualPivotQuickSort (arr, rp + 1, high);
    }
}


int QuickSort::partition (int *arr, int low, int high, int *lp) 
{
    if (arr[low] > arr[high])
        swap (&arr[low], &arr[high]);

    // p is the left pivot, and q is the right pivot.
    int j = low + 1;
    int g = high -1, k = low + 1, p = arr[low], q = arr[high];
    
    while (k <= g)
    {	
        // if elements are less than the left pivot 
        if (arr[k] < p)
        {
            swap (&arr[k], &arr[j]);
            j++;
        }			
        // if elements are greater than or equal // to the right pivot 
        else if (arr[k] >= q)
        {
            while (arr[g] > q && k < g) g--;
                swap (&arr[k], &arr[g]);
                g--;
            
            if (arr[k] < p)
                {
                swap (&arr[k], &arr[j]);  
                j++;
                } 
        }
        k++;
    }
    
    j--;
    
    g++;				// bring pivots to their appropriate positions.
    swap (&arr[low], &arr[j]);
    swap (&arr[high], &arr[g]);	// returning the indices of the pivots.
    *lp = j;			// because we cannot return two elements // from a function.
    return g;
}				

int main () 
{
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;

    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     
    QuickSort obj;
    obj.DualPivotQuickSort (arr, 0, n-1);
 
    obj.display(arr,n);

}		