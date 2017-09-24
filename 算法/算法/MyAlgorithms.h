#pragma once
#include "MaxHeap.h"


namespace MyAlgorithms
{
	//------------------------------------------------------------------------//
	//选择排序算法
	template<typename T>
	void SelectionSort(T arr[],int n){
		for (int i=0;i<n;i++)
		{
			//寻找在[i,n)中的最小值
			int minIndex = i;
			for (int j = i+1;j < n; j++)
			{
				if(arr[j] < arr[minIndex])
					minIndex = j;
			}
			swap(arr[i],arr[minIndex]);
		}
	}
	//------------------------------------------------------------------------//
	//插入排序算法
	template<typename T>
	void InsertSort(T arr[],int n){
		for(int i=1;i<n;i++){
			//寻找元素arr[i]合适的插入位置
			for(int j = i;j > 0 && arr[j] < arr[j-1]; j--){	
				swap(arr[j],arr[j-1]);	//交换当前值与前一个值的位置
			}
		}
	}
	//------------------------------------------------------------------------//
	//改进后的插入排序算法
	template<typename T>
	void InsertSortImprove(T arr[],int n){
		for(int i=1;i<n;i++){
			//寻找元素arr[i]合适的插入位置

			T e = arr[i];
			int j;							//j保存元素e应该插入的位置
			for( j = i;j > 0 && arr[j-1] > e; j--){	
				arr[j] = arr[j-1];			//将前一个元素赋值到当前元素位置
			}
			arr[j] = e;						
		}
	}

	//------------------------------------------------------------------------//
	//改进后的插入排序算法2
	template<typename T>
	void InsertSortImprove(T arr[],int l,int r){
		for(int i = l + 1;i <= r; i++){
			//寻找元素arr[i]合适的插入位置

			T e = arr[i];
			int j;							//j保存元素e应该插入的位置
			for( j = i; j > l && arr[j-1] > e; j--){	
				arr[j] = arr[j-1];			//将前一个元素赋值到当前元素位置
			}
			arr[j] = e;						
		}
		return;
	}
	//------------------------------------------------------------------------//
	//归并算法
	template<typename T>
	void static __merge(T arr[],int l,int mid,int r)
	{
		//拷贝一份数据
		T *aux = new T[r-l+1];			//根据传入的数组动态分配空间
		for (int i=l;i<=r;i++)
		{
			aux[i-l] = arr[i];
		}

		int i = l,j = mid +1;
		for (int k = l;k <= r; k++)
		{
			if(i > mid )				//如果左边的元素大于mid越界
			{
				arr[k] = aux[j-l];
				j++;
			}
			else if(j > r)				//如果右边的元素大于r越界
			{
				arr[k] = aux[i-l];
				i++;
			}
			else if (aux[i-l] < aux[j-l])
			{
				arr[k] = aux[i-l];
				i++;
			}
			else
			{
				arr[k] = aux[j-l];
				j++;
			}
			
		}
		delete [] aux;
	}
	//对arr[l...r]的范围内进行排序
	template<typename T>
	void static __mergeSort(T arr[],int l,int r)
	{
		if (l >= r)
		{
			return;
		}

		int mid = (l+r)/2;
		__mergeSort(arr,l,mid);			//保证了从l到mid有序
		__mergeSort(arr,mid+1,r);		//保证了从mid+1到r有序
		__merge(arr,l,mid,r);


	}

	template<typename T>
	void mergeSort(T arr[],int n)
	{
		__mergeSort(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//对归并算法进行改进
	template<typename T>
	void static __mergeImprove(T arr[],int l,int mid,int r)
	{
		//拷贝一份数据
		T *aux = new T[r-l+1];			//根据传入的数组动态分配空间
		for (int i=l;i<=r;i++)
		{
			aux[i-l] = arr[i];
		}

		int i = l,j = mid +1;
		for (int k = l;k <= r; k++)
		{
			if(i > mid )				//如果左边的元素大于mid越界
			{
				arr[k] = aux[j-l];
				j++;
			}
			else if(j > r)				//如果右边的元素大于r越界
			{
				arr[k] = aux[i-l];
				i++;
			}
			else if (aux[i-l] < aux[j-l])
			{
				arr[k] = aux[i-l];
				i++;
			}
			else
			{
				arr[k] = aux[j-l];
				j++;
			}

		}
		delete [] aux;
	}
	//对arr[l...r]的范围内进行排序
	template<typename T>
	void static __mergeSortImprove(T arr[],int l,int r)
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//当数组长度小于等于15时采用插入排序，效率较高
		{
			InsertSortImprove(arr,l,r);
			return ;
		}

		int mid = (l+r)/2;
		__mergeSortImprove(arr,l,mid);		//保证了从l到mid有序
		__mergeSortImprove(arr,mid+1,r);		//保证了从mid+1到r有序

		if (arr[mid] > arr[mid+1])		//改进，对于近乎有序的数组会提高效率
			__mergeImprove(arr,l,mid,r);


	}

	template<typename T>
	void mergeSortImprove(T arr[],int n)
	{
		__mergeSortImprove(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//自底向上的归并排序算法
	template<typename T>
	void mergeSortBU(T arr[],int n)
	{
		for (int sz = 1;sz <= n;sz += sz)
		{
			for (int i = 0; i + sz < n ;i += sz + sz)
			{
				//对arr[i...i+sz-1]和arr[i+sz...i+2*sz-1]进行归并
				__merge2(arr, i, i + sz -1, min(i + sz + sz -1, n-1));
			}
		}
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//快速排序算法
	template<typename T>
	int static __partition(T arr[],int l,int r)	//对arr[l..r]部分进行partition操作,arr[l..p-1] < arr[p] < arr[p+1...r]
	{
		
		T v = arr[l];
		int j = l;
		//arr[l+1...j] < v < arr[j+1...i)
		for(int i = l + 1; i <= r ; i++)
		{
			if (v > arr[i])
			{
				swap(arr[i],arr[j+1]);
				j++;
			}
		}
		swap(arr[l],arr[j]);
		
		return j;
	}
	template<typename T>
	void static __quickSort(T arr[],int l,int r)	//对arr[l..r]部分进行快速排序
	{
		if (l >= r)
		{
			return;
		}
		
		
		int p = __partition(arr,l,r);
		__quickSort(arr,l,p-1);
		__quickSort(arr,p+1,r);

	}
	template<typename T>
	void quickSort(T arr[],int n)
	{
		__quickSort(arr,0,n-1);
	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//优化的快速排序算法
	template<typename T>
	int static __partitionImprove(T arr[],int l,int r)	//对arr[l..r]部分进行partition操作,arr[l..p-1] < arr[p] < arr[p+1...r]
	{
		swap(arr[l],arr[rand()%(r-l+1) + l]);

		T v = arr[l];

		int j = l;
		//arr[l+1...j] < v < arr[j+1...i)
		for(int i = l + 1; i <= r ; i++)
		{
			if (v > arr[i])
			{
				swap(arr[i],arr[j+1]);
				j++;
			}
		}
		swap(arr[l],arr[j]);

		return j;
	}
	template<typename T>
	void static __quickSortImprove(T arr[],int l,int r)	//对arr[l..r]部分进行快速排序
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//当数组长度小于等于15时采用插入排序，效率较高
		{
			InsertSortImprove(arr,l,r);
			return ;
		}

		int p = __partitionImprove(arr,l,r);
		__quickSortImprove(arr,l,p-1);
		__quickSortImprove(arr,p+1,r);

	}
	template<typename T>
	void quickSortImprove(T arr[],int n)
	{
		srand(time(NULL));								//设置随机种子
		__quickSortImprove(arr,0,n-1);
	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//优化的快速排序算法2,解决存在大量重复值时的效率问题
	template<typename T>
	int static __partitionImprove2(T arr[],int l,int r)	//对arr[l..r]部分进行partition操作,arr[l..p-1] < arr[p] < arr[p+1...r]
	{
		swap(arr[l],arr[rand()%(r-l+1) + l]);

		T v = arr[l];

		int i = l+1 ,j = r;
		//arr[l+1...i) <= v  ; arr[j...r] >= v
		while (true)
		{
			while (i <= r && arr[i] < v)
			{
				i++;
			}
			while(j >= l+1 && arr[j] > v)
			{
				j--;
			}

			if (i > j)
			{
				break;
			}

			swap(arr[i],arr[j]);
			i++;
			j--;
		}

		swap(arr[j],arr[l]);

		return j;
	}
	template<typename T>
	void static __quickSortImprove2(T arr[],int l,int r)	//对arr[l..r]部分进行快速排序
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//当数组长度小于等于15时采用插入排序，效率较高
		{
			InsertSortImprove(arr,l,r);
			return ;
		}

		int p = __partitionImprove2(arr,l,r);
		__quickSortImprove2(arr,l,p-1);
		__quickSortImprove2(arr,p+1,r);

	}
	template<typename T>
	void quickSortImprove2(T arr[],int n)
	{
		srand(time(NULL));								//设置随机种子
		__quickSortImprove2(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//三路快速排序算法,解决存在大量重复值时的效率问题 
	template<typename T>
	void static __quickSort3Ways(T arr[], int l,int r) {
		if (r - l <= 15)				//当数组长度小于等于15时采用插入排序，效率较高
		{
			InsertSortImprove(arr, l, r);
			return;
		}

		//partition
		swap(arr[l], arr[rand() % (r - l + 1) + l]);
		T v = arr[l];

		int lt = l, gt = r + 1, i = l + 1; //arr[l+1...lt] < V ; arr[gt...r] > V ; arr[lt+1...i-1] == V
		while (i < gt)
		{
			if (arr[i] < v)
			{
				swap(arr[i], arr[lt + 1]);
				lt++;
				i++;
			}
			else if (arr[i] == v) 
			{
				i++;
			}
			else
			{
				swap(arr[i], arr[gt - 1]);
				gt--;
			}
		}
		swap(arr[l], arr[lt]);

		__quickSort3Ways(arr, l, lt - 1);
		__quickSort3Ways(arr, gt, r);

	}
	template<typename T>
	void quickSort3Ways(T arr[], int n) {
		srand(time(NULL));
		__quickSort3Ways(arr, 0, n - 1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//堆排序算法
	template<typename T>
	void heapSort(T arr[], int n) {
		MaxHeap<T> maxheap = MaxHeap<T>(n);
		//将数组中的元素插入到堆中
		for (int i = 0; i < n; i++)
		{
			maxheap.insert(arr[i]);
		}
		for (int i = n-1 ;i >= 0;i--)
		{
			arr[i] = maxheap.extractMax();
		}

	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//堆排序算法2
	template<typename T>
	void heapSort2(T arr[], int n) {
		MaxHeap<T> maxheap = MaxHeap<T>(arr,n);
		
		for (int i = n - 1; i >= 0; i--)
		{
			arr[i] = maxheap.extractMax();
		}

	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//原地堆排序，空间复杂度小
	template<typename T>
	void heapSort3(T arr[], int n) {
		MaxHeap<T> maxheap = MaxHeap<T>(arr,n,false);

		for (int i = n-1 ;i > 0; i--)
		{
			maxheap.swapData(0, i);		//将当前堆中最大的元素与最后一个元素交换
			maxheap.shiftDown(i,0, false);	//对堆总数为i的第0个元素进行shiftDown操作
		}

	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//二分查找法,在有序数组arr中查找target，如果查找到，返回索引，没有查找到返回-1
	template<typename T>
	int binarySearch(T arr[], int n, T target) {
		int l = 0, r = n-1;
		while (l <= r)
		{
			/*int mid = (l + r) / 2;*/
			int mid = l + (r - l) / 2;
			if (arr[mid] == target)
			{
				return mid;				
			}
			if (target < arr[mid])
			{
				r = mid - 1;

			}
			else
			{
				l = mid + 1;
			}

			return -1;
		}
	}
};

 






