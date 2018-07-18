
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
void siftdown(int arr[], int n, int i)
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

// max heap siftup
void siftup(int arr[], int son) 
{
	int j = son;
	int i = (j-1)/2; //i 为父结点
	int temp = arr[j];
	while (i>=0)
	{
		if (arr[i] < temp)
		{
			arr[j] = arr[i];  //较小元素下移
			j = i;
			i = (j-1)/2; //迭代下标上移， siftup
		}
		else break;
	}
	arr[j] = temp; //回送
}
//递归
void siftup2(int arr[], int son) 
{
	int j = son;
	int i = (j-1)/2; //i 为父结点
	if (i >=0 && arr[i]<arr[j])
	{
		swap(arr[i], arr[j]);
		siftup2(arr, i);
	}
}

//最大堆，堆尾插入元素
//不考虑空间不足的情况
void insert(int arr[], int size, int x)
{
	arr[size] = x;
	siftup(arr, size); 
	size++;
}

//最大堆删除，删除堆顶元素


// main function to do heap sort
void heapSort(int arr[], int n)
{
	//case1: right = 2*i + 2(偶数) = n - 1 , -> i = (n-2)/2, n 为奇数下取整， 
	//case2: left = 2*i + 1(奇数) = n-1, i = (n-2)/2, n为偶数, 所以case1,2均满足 i = (n-2)/2
	
	// Build max heap (rearrange array) by using siftdown method
	for (int i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);

	// One by one extract an element from heap
	for (int i = n - 1; i >= 0; i--)
	{
		// Move current root to end
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		//缩减调整范围，末尾排好序的元素不调整 
		heapify(arr, i, 0);
	}
}