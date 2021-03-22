#include <bits/stdc++.h>
using namespace std;

//Parent class
class Sorting {
    public:
        void swap(int *num1, int *num2)
        {
            int temp = *num1;
            *num1 = *num2;
            *num2 = temp;
        }
        void bubbleSort(int *arr, int l, int r);
        void selectionSort(int *arr, int l, int r);
        void insertionSort(int* arr, int l, int r);
        void display(int *arr, int size);
};

//Function for Bubble Sort
void Sorting::bubbleSort(int *arr, int l, int r)
{
    int temp;

	for(int i = l; i <= r; i++)
	{
		for(int j = l; j <= r; j++)
		{
			if(arr[j] > arr[j+1])
			{
                swap(&arr[j], &arr[j+1]);	
			}
		}
	}
}

//Function for Selection Sort
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

//Function for Insertion Sort
void Sorting::insertionSort(int *arr, int l, int r)
{
    int j, temp;
	for(int i = l+1; i <= r; i++)
	{
		j = i;
		while(j > l && arr[j]<arr[j-1])
		{
            swap(&arr[j], &arr[j-1]);
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


class MergeSort_3way:public Sorting {
    public:
        void merge(int *arr, int l, int m1, int m2, int r);
        void bubbleMerge_3way(int *arr, int l, int r);
        void selectionMerge_3way(int *arr, int l, int r);
        void insertionMerge_3way(int *arr, int l, int r);
};

//Funstion to merge 3 arrays
void MergeSort_3way::merge(int *arr, int l, int m1, int m2, int r)
{
    int temp[r+1];

    int i = l, j = m1, k = m2, ind = l; 

	while ((i < m1) && (j < m2) && (k < r)) 
	{ 
		if(arr[i] < arr[j]) 
		{ 
			if(arr[i] < arr[k]) 
			{ 
				temp[ind++] = arr[i++]; 
			} 
			else
			{ 
				temp[ind++] = arr[k++];
			} 
		} 
		else
		{ 
			if(arr[j] < arr[k]) 
			{ 
				temp[ind++] = arr[j++]; 
			} 
			else
			{ 
				temp[ind++] = arr[k++]; 
			} 
		} 
	} 

    //Check remaining elements in the 1st and 2nd ranges
	while ((i < m1) && (j < m2))
	{ 
		if(arr[i] < arr[j]) 
		{ 
			temp[ind++] = arr[i++]; 
		} 
		else
		{ 
			temp[ind++] = arr[j++]; 
		} 
	} 

    //Check whether 2nd and 3rd ranges have remaining elements
	while ((j < m2) && (k < r))
	{ 
		if(arr[j] < arr[k])
		{ 
			temp[ind++] = arr[j++]; 
		} 
		else
		{ 
			temp[ind++] = arr[k++]; 
		} 
	} 

    //Check whether 1st and 3rd ranges have remaining elements
	while ((i < m1) && (k < r)) 
	{ 
		if(arr[i] < arr[k]) 
		{ 
			temp[ind++] = arr[i++]; 
		} 
		else
		{ 
			temp[ind++] = arr[k++]; 
		} 
	} 

    //Check all the remaining values in all the ranges
	while (i < m1)
    {
        temp[ind++] = arr[i++]; 
    }
	while (j < m2)
    {
        temp[ind++] = arr[j++]; 
    }
	while (k < r) 
		temp[ind++] = arr[k++]; 


	for(int i = l; i < r; i++)
	{
		arr[i] = temp[i];
	}
}

void MergeSort_3way::bubbleMerge_3way(int *arr, int l, int r)
{
    if(r-l <= 20)
    {
        bubbleSort(arr, l, r);
        return;
    }

    int m1 = l + (r-l)/3;
    int m2 = l + 2*((r-l)/3);

    bubbleMerge_3way(arr, l, m1);
    bubbleMerge_3way(arr, m1+1, m2);
    bubbleMerge_3way(arr, m2+1, r);

    merge(arr, l, m1, m2, r);
}

void MergeSort_3way::selectionMerge_3way(int *arr, int l, int r)
{
    if(r-l <= 20)
    {
        selectionSort(arr, l, r);
        return;
    }

    int m1 = l + (r-l)/3;
    int m2 = l + 2*((r-l)/3);

    selectionMerge_3way(arr, l, m1);
    selectionMerge_3way(arr, m1+1, m2);
    selectionMerge_3way(arr, m2+1, r);

    merge(arr, l, m1, m2, r);
}

void MergeSort_3way::insertionMerge_3way(int *arr, int l, int r)
{
    if(r-l <= 20)
    {
        insertionSort(arr, l, r);
        return;
    }

    int m1 = l + (r-l)/3;
    int m2 = l + 2*((r-l)/3);

    insertionMerge_3way(arr, l, m1);
    insertionMerge_3way(arr, m1+1, m2);
    insertionMerge_3way(arr, m2+1, r);

    merge(arr, l, m1, m2, r);
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
    cout<<"Enter the number of elements\n";
    cin>>n;
    int unsorted_arr[1000], arr[n];
    MergeSort_3way obj;
    
    for (int i = 0; i < n; i++)
    {
        unsorted_arr[i] = RandomRange(1,100);
    }
    obj.display(unsorted_arr, n);
    cout<<"\n\n";

    
    ///MergeSort + BubbleSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"1. Merge and Bubble Sort\n";
    obj.bubbleMerge_3way(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n\n";


    //MergeSort + SelectionSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"2. Merge and Selection Sort\n";
    obj.selectionMerge_3way(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n\n";
    

    //MergeSort + InsertionSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"3. Merge and Insertion Sort\n";
    obj.insertionMerge_3way(arr, 0, n-1);
    obj.display(arr, n);
    cout<<"\n\n";

    return 0;
}