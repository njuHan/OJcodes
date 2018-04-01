#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

/*
Bubble Sort, Recursive Bubble Sort
*/
void bubbleSort(int arr[], int n)
{
	bool flag = true;
	int i = n-1, j = 0;
	while (i >0 && flag)
	{
		flag = false;
		for (j = 0; j < i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				flag = true;
			}
		}
		i--;
	}
}

void bubbleSortR(int a[], int n)
{
	if (n == 1) return;
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] > a[i + 1])
		{
			int temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}
	}
	bubbleSort(a, n - 1);
}
//--------------------------------------------------------------------
/*
Insertion Sort
*/
void instSort(int a[], int n)
{
	int i, j, val;
	for (int i = 1; i < n; i++)
	{
		val = a[i];
		j = i - 1;
		while (j >= 0 && a[j]>val)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = val;

	}
}
void instSortR(int a[], int n)
{
	if (n <= 1) return;
	instSort(a, n - 1);
	int i = n - 2;
	int val = a[n - 1];
	while (a[i]> val && i>=0)
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = val;
}

//--------------------------------------------------------------------
/*
Merge Sort, Iterative Merge Sort
*/
//merge the sorted two vec: [i,mid] and[mid+1,j]
// and store the result in vec
void merge(vector<int>& vec, int i, int mid, int j)
{
	// [vec[i], vec[mid]) ×ó±ÕÓÒ¿ª
	vector<int> v1(&vec[i], &vec[mid] + 1);
	vector<int> v2(&vec[mid + 1], &vec[j] + 1);
	int len1 = mid - i + 1, len2 = j - mid;
	int k = i, p = 0, q = 0;
	while (p<len1 && q<len2)
	{
		if (v1[p] <= v2[q])
			vec[k++] = v1[p++];
		else
			vec[k++] = v2[q++];
	}
	while (p < len1) vec[k++] = v1[p++];
	while (q < len2) vec[k++] = v2[q++];
}
void mergeSort(vector<int>& vec, int i, int j)
{
	if (i < j)
	{
		int mid = i + (j - i) / 2;
		mergeSort(vec, i, mid);
		mergeSort(vec, mid + 1, j);
		merge(vec, i, mid, j);
	}
}
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r);

// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y) ? x : y; }


/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n)
{
	int curr_size;  // For current size of subarrays to be merged
					// curr_size varies from 1 to n/2
	int left_start; // For picking starting index of left subarray
					// to be merged

					// Merge subarrays in bottom up manner.  First merge subarrays of
					// size 1 to create sorted subarrays of size 2, then merge subarrays
					// of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		// Pick starting point of different subarrays of current size
		for (left_start = 0; left_start<n - 1; left_start += 2 * curr_size)
		{
			// Find ending point of left subarray. mid+1 is starting 
			// point of right
			int mid = left_start + curr_size - 1;

			int right_end = min(left_start + 2 * curr_size - 1, n - 1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			merge(arr, left_start, mid, right_end);
		}
	}
}
/* Function to merge the two haves arr[l..m] and arr[m+1..r] of array arr[] */
void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	//int L[n1], R[n2];
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
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

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

//--------------------------------------------------------------------
/*
quick sort
*/
int split(int a[], int f, int l);
void quickSort(int a[], int first, int last)
{
	if (first < last)
	{
		int pos = split(a, first, last);
		quickSort(a, first, pos - 1);
		quickSort(a, pos + 1, last);
	}

}
int split(int a[], int first, int last)
{
	int val = a[first];
	int pos = first;
	for (int i = first + 1; i <= last; i++)
	{
		if (a[i] < val)
		{
			pos++;
			int temp = a[pos];
			a[pos] = a[i];
			a[i] = temp;
		}
	}
	int temp = a[first];
	a[first] = a[pos];
	a[pos] = temp;
	return pos;
}

//--------------------------------------------------------------------

/*
heap sort
*/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
	int largest = i;  // Initialize largest as root
	int l = 2 * i + 1;  // left = 2*i + 1
	int r = 2 * i + 2;  // right = 2*i + 2

						// If left child is larger than root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	// Build heap (rearrange array)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}
int main()
{
	int a[] = { 1,3,5,2,4,6,8,0,7 };
	//quickSort(a, 0,sizeof(a)/sizeof(int)-1);
	heapSort(a, sizeof(a) / sizeof(int) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		cout << a[i] << " ";
	system("pause");
	return 0;
}