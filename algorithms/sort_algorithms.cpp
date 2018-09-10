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


/*
希尔排序
对于大规模的数组，插入排序很慢，因为它只能交换相邻的元素，每次只能将逆序
数量减少 1。
希尔排序的出现就是为了改进插入排序的这种局限性，它通过交换不相邻的元素，
每次可以将逆序数量减少大于 1。
希尔排序使用插入排序对间隔 h 的序列进行排序。通过不断减小 h，最后令 h=1，
就可以使得整个数组是有序的。
*/
void shellSort(vector<int>& nums)
{
	int N = nums.size();
	int h = 1;
	while (h < N / 3)
		h = 3 * h + 1; // 1, 4, 13, 40, ...
	while (h >= 1)
	{
		for (int i = h; i < N; i++)
			for (int j = i; j >= h && nums[j]< nums[j -h]; j -= h) //这里和插入排序类似
				swap(nums[j], nums[j - h]);
		h = h / 3;
	}
}

/*
选择排序
选择出数组中的最小元素，将它与数组的第一个元素交换位置。再从剩下的元素中
选择出最小的元素，将它与数组的第二个元素交换位置。不断进行这样的操作，直
到将整个数组排序。
*/
void selectSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		int minidx = i;
		for (int j = i + 1; j < n; j++)
			if (nums[j] < nums[minidx]) minidx = j;
		swap(nums[minidx], nums[i]);
	}
}


//merge the sorted two vec: [i,mid), [mid, j)
// and store the result in vec
//左闭右开写起来方便
void merge(vector<int>& vec, int i, int mid, int j)
{
	cout << i << "," << mid << "," << j << endl;
	// [vec[i], vec[mid]) 左闭右开
	/*
	不能写成：
	vector<int> v1(&vec[i], &vec[mid]);
	vector<int> v2(&vec[mid], &vec[j]);
	当j==n时，vec[j]越界。
	但是string字符串可以写 &str[n], 因为末尾加了0
	*/
	vector<int> v1(vec.begin()+i, vec.begin()+mid);
	vector<int> v2(vec.begin()+mid, vec.begin()+j);
	int len1 = mid - i, len2 = j - mid;
	int k = i, p = 0, q = 0;
	while (p < len1 || q < len2)
	{
		// 从v1中选取
		if (q >= len2 || (p < len1 && v1[p] <= v2[q]))
		{
			vec[k++] = v1[p++];
		}
		else
		{
			vec[k++] = v2[q++];
		}
	}
}
//递归merge sort 自顶向下
void mergeSort(vector<int>& vec, int i, int j) //[i, j)
{
	if (j - i>1)
	{
		int mid = i + (j - i) / 2;
		mergeSort(vec, i, mid);
		mergeSort(vec, mid, j);
		merge(vec, i, mid, j);
	}
}

//--------------------------------------------------------------------
/*
 Iterative Merge Sort
 自底向上
*/
void mergeSort(vector<int>& nums)
{
	int n = nums.size();
	for (int sz = 1; sz < n; sz += sz)
		for (int lo = 0; lo < n - sz; lo += sz + sz)
			merge(nums, lo, lo + sz, min(lo + sz + sz, n));
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

//左闭右开区间[begin, end)
int split(int* a, int begin, int end)
{
	int val = a[begin];
	int less = begin;
	for (int i = begin; i < end; i++)
	{
		if (a[i] < val)
			swap(a[++less], a[i]);
	}
	swap(a[less], a[begin]);
	return less;
}
void quickSort(int* a, int x, int y) //[x,y)
{
	if (y - x > 1)
	{
		int m = split(a, x, y);
		quickSort(a, x, m);
		quickSort(a, m + 1, y);//注意这里排除m，和归并排序不一样
	}
}

//--------------------------------------------------------------------

/*
heap sort
*/
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i) //i为根结点, siftdown
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
//max heap
//迭代
void siftdown(int arr[], int n, int i) //i为根结点, siftdown
{
	int largest = i;  // Initialize largest as root
	int j = 2 * i + 1;  // left = 2*i + 1
	int temp = arr[i]; //调整的元素一直都是 temp
	while (j<n)
	{
		if (j+1<n && arr[j+1] > arr[j]) j++; //指向较大的子结点
		if (temp <arr[j] ) {arr[i] =  arr[j]; i = j; j = 2*i + 1;}
		else break;
	}
	arr[i] = temp; //调整结束， 回送temp
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
	//case1: right = 2*i + 2(偶数) = n - 1 , -> i = (n-2)/2, n 为奇数下取整，
	//case2: left = 2*i + 1(奇数) = n-1, i = (n-2)/2, n为偶数, 所以case1,2均满足 i = (n-2)/2
	// Build max heap (rearrange array)
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
