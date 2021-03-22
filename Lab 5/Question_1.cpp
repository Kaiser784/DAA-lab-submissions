/*
Consider a large integer array of size at least 1000. Populate the array using rand() function. 
Use 2-way merge sort as part of divide phase and stop the recursion when the input size is less than or equal to 20. 
For all subproblems of size at most 20, sort the subproblem using insertion sort, selection, bubble; 
compare the system times and display which Hybrid sorting is better (Merge+insertion, Merge+selection, Merge+bubble)
*/
#include <bits/stdc++.h>
using namespace std;

//Parent class
class Sorting {
    public:
        void bubbleSort(int *arr, int l, int r);
        void selectionSort(int *arr, int l, int r);
        void insertionSort(int* arr, int l, int r);
        void display(int *arr, int size);
};

void Sorting::bubbleSort(int *arr, int l, int r)
{
    int temp;

	for(int i = l; i <= r; i++)
	{
		for(int j = l; j <= r; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;			
			}
		}
	}
}

void Sorting::selectionSort(int *arr, int l, int r)
{
    int indexMin, temp;

    for(int i = l; i <= r; i++)
    {
        indexMin = i;

        for(int j = i+1; j <= r; j++)
        {
            if(arr[indexMin] > arr[j])
            {
                indexMin = j;
                temp = arr[j];
            }
        }

        if(indexMin != i)
        {
            arr[indexMin] = arr[i];
            arr[i] = temp;
        }
    }
}

void Sorting::insertionSort(int *arr, int l, int r)
{
    int j, temp;
	for(int i = l+1; i <= r; i++)
	{
		j = i;
		while(j > l && arr[j]<arr[j-1])
		{
            temp = arr[j];
			arr[j] = arr[j-1];
            arr[j-1] = temp;
			j--;
		}
	}
}

//Function to display all elements in an array
void Sorting::display(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}


//Child class
class MergeSort:public Sorting {
    public:
        void merge(int *arr, int l, int m, int r);
        void mergesort_bubbleSort(int *arr, int l, int r);
        void mergesort_selectionSort(int *arr, int l, int r);
        void mergesort_insertionSort(int *arr, int l, int r);
};

//Function to merge sorted arrays
void MergeSort::merge(int *arr, int l, int m, int r)
{
    int i = l, j=m+1, k = l;
	int temp[r+1];

	while(i <= m && j <= r)
	{
		if(arr[i] < arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
		}
	}
	while(i <= m)
	{
		temp[k++] = arr[i++];
	}
	while(j <= l)
	{
		temp[k++] = arr[j++];
	}
	for(int i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
}

void MergeSort::mergesort_bubbleSort(int *arr, int l, int r)
{
    int m = l + (r-l)/2;
    //Use Bubble Sort once array size is <= 20
    if(r-l <= 20)
    {
        bubbleSort(arr, l, r);
        return;
    }
    else if(l < r)
    {
        mergesort_bubbleSort(arr,l,m);
        mergesort_bubbleSort(arr,m+1,r);
    }
    merge(arr,l,m,r);
}

void MergeSort::mergesort_selectionSort(int *arr, int l, int r)
{
    int m = l + (r-l)/2;
    //Use Selection Sort once array size is <= 20
    if(r-l <= 20)
    {
        selectionSort(arr, l, r);
        return;
    }
    else if(l < r)
    {
        mergesort_selectionSort(arr,l,m);
        mergesort_selectionSort(arr,m+1,r);
    }
    merge(arr,l,m,r);
}

void MergeSort::mergesort_insertionSort(int *arr, int l, int r)
{
    int m = l + (r-l)/2;
    //Use Selection Sort once array size is <= 20
    if(r-l <= 20)
    {
        insertionSort(arr, l, r);
        return;
    }
    else if(l < r)
    {
        mergesort_insertionSort(arr,l,m);
        mergesort_insertionSort(arr,m+1,r);
    }
    merge(arr,l,m,r);
}


//Function to generate a random number within a range
int RandomRange(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//Main function
int main()
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[1000];
    MergeSort obj;

    for (int i = 0; i < n; i++)
    {
        arr[i] = RandomRange(1,100);
    }
    obj.display(arr, n);

    cout<<"1. Merge and Bubble Sort\n";
    obj.mergesort_bubbleSort(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n";


    for (int i = 0; i < n; i++)
    {
        arr[i] = RandomRange(1,100);
    }
    obj.display(arr, n);

    cout<<"2. Merge and Selection Sort\n";
    obj.mergesort_selectionSort(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n";
    

    for (int i = 0; i < n; i++)
    {
        arr[i] = RandomRange(1,100);
    }
    obj.display(arr, n);

    cout<<"3. Merge and Insertion Sort\n";
    obj.mergesort_insertionSort(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n";

    return 0;
}