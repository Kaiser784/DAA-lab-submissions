#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

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
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Temp arrays
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }
 
    //Initial index of the temp arrays
    int i = 0;
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;

    //Merge the arrays using 2 pointers
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Check all the remaining values in the temp arrays
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
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
    mergesort_bubbleSort(arr,l,m);
    mergesort_bubbleSort(arr,m+1,r);

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
    mergesort_selectionSort(arr,l,m);
    mergesort_selectionSort(arr,m+1,r);
    
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
    mergesort_insertionSort(arr,l,m);
    mergesort_insertionSort(arr,m+1,r);
    
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
    int n, time;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int unsorted_arr[1000], arr[n];
    MergeSort obj;

    cout<<"\nThe Unsorted array is:\n";
    for (int i = 0; i < n; i++)
    {
        unsorted_arr[i] = RandomRange(1,100);
    }
    obj.display(unsorted_arr, n);
    cout<<"\n\n";


    //MergeSort + BubbleSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"1. Merge and Bubble Sort\n";
    auto start = high_resolution_clock::now();
    obj.mergesort_bubbleSort(arr, 0, n-1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time = duration.count();
    
    obj.display(arr, n);
    cout<<"\nTime Duration: "<<time<<"\n\n"<<endl;



    //MergeSort + SelectionSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"2. Merge and Selection Sort\n";
    start = high_resolution_clock::now();
    obj.mergesort_selectionSort(arr, 0, n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    time = duration.count();
    
    obj.display(arr, n);
    cout<<"\nTime Duration: "<<time<<"\n\n"<<endl;
    

    //MergeSort + InsertionSort
    for (int i = 0; i < n; i++)
    {
        arr[i]=unsorted_arr[i];
    }
    cout<<"3. Merge and Insertion Sort\n";
    start = high_resolution_clock::now();
    obj.mergesort_insertionSort(arr, 0, n-1);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    time = duration.count();
    
    obj.display(arr, n);
    cout<<"\nTime Duration: "<<time<<"\n\n"<<endl;


    return 0;
}