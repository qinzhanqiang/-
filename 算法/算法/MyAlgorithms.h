#pragma once
#include "MaxHeap.h"


namespace MyAlgorithms
{
	//------------------------------------------------------------------------//
	//ѡ�������㷨
	template<typename T>
	void SelectionSort(T arr[],int n){
		for (int i=0;i<n;i++)
		{
			//Ѱ����[i,n)�е���Сֵ
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
	//���������㷨
	template<typename T>
	void InsertSort(T arr[],int n){
		for(int i=1;i<n;i++){
			//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
			for(int j = i;j > 0 && arr[j] < arr[j-1]; j--){	
				swap(arr[j],arr[j-1]);	//������ǰֵ��ǰһ��ֵ��λ��
			}
		}
	}
	//------------------------------------------------------------------------//
	//�Ľ���Ĳ��������㷨
	template<typename T>
	void InsertSortImprove(T arr[],int n){
		for(int i=1;i<n;i++){
			//Ѱ��Ԫ��arr[i]���ʵĲ���λ��

			T e = arr[i];
			int j;							//j����Ԫ��eӦ�ò����λ��
			for( j = i;j > 0 && arr[j-1] > e; j--){	
				arr[j] = arr[j-1];			//��ǰһ��Ԫ�ظ�ֵ����ǰԪ��λ��
			}
			arr[j] = e;						
		}
	}

	//------------------------------------------------------------------------//
	//�Ľ���Ĳ��������㷨2
	template<typename T>
	void InsertSortImprove(T arr[],int l,int r){
		for(int i = l + 1;i <= r; i++){
			//Ѱ��Ԫ��arr[i]���ʵĲ���λ��

			T e = arr[i];
			int j;							//j����Ԫ��eӦ�ò����λ��
			for( j = i; j > l && arr[j-1] > e; j--){	
				arr[j] = arr[j-1];			//��ǰһ��Ԫ�ظ�ֵ����ǰԪ��λ��
			}
			arr[j] = e;						
		}
		return;
	}
	//------------------------------------------------------------------------//
	//�鲢�㷨
	template<typename T>
	void static __merge(T arr[],int l,int mid,int r)
	{
		//����һ������
		T *aux = new T[r-l+1];			//���ݴ�������鶯̬����ռ�
		for (int i=l;i<=r;i++)
		{
			aux[i-l] = arr[i];
		}

		int i = l,j = mid +1;
		for (int k = l;k <= r; k++)
		{
			if(i > mid )				//�����ߵ�Ԫ�ش���midԽ��
			{
				arr[k] = aux[j-l];
				j++;
			}
			else if(j > r)				//����ұߵ�Ԫ�ش���rԽ��
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
	//��arr[l...r]�ķ�Χ�ڽ�������
	template<typename T>
	void static __mergeSort(T arr[],int l,int r)
	{
		if (l >= r)
		{
			return;
		}

		int mid = (l+r)/2;
		__mergeSort(arr,l,mid);			//��֤�˴�l��mid����
		__mergeSort(arr,mid+1,r);		//��֤�˴�mid+1��r����
		__merge(arr,l,mid,r);


	}

	template<typename T>
	void mergeSort(T arr[],int n)
	{
		__mergeSort(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//�Թ鲢�㷨���иĽ�
	template<typename T>
	void static __mergeImprove(T arr[],int l,int mid,int r)
	{
		//����һ������
		T *aux = new T[r-l+1];			//���ݴ�������鶯̬����ռ�
		for (int i=l;i<=r;i++)
		{
			aux[i-l] = arr[i];
		}

		int i = l,j = mid +1;
		for (int k = l;k <= r; k++)
		{
			if(i > mid )				//�����ߵ�Ԫ�ش���midԽ��
			{
				arr[k] = aux[j-l];
				j++;
			}
			else if(j > r)				//����ұߵ�Ԫ�ش���rԽ��
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
	//��arr[l...r]�ķ�Χ�ڽ�������
	template<typename T>
	void static __mergeSortImprove(T arr[],int l,int r)
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//�����鳤��С�ڵ���15ʱ���ò�������Ч�ʽϸ�
		{
			InsertSortImprove(arr,l,r);
			return ;
		}

		int mid = (l+r)/2;
		__mergeSortImprove(arr,l,mid);		//��֤�˴�l��mid����
		__mergeSortImprove(arr,mid+1,r);		//��֤�˴�mid+1��r����

		if (arr[mid] > arr[mid+1])		//�Ľ������ڽ����������������Ч��
			__mergeImprove(arr,l,mid,r);


	}

	template<typename T>
	void mergeSortImprove(T arr[],int n)
	{
		__mergeSortImprove(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//�Ե����ϵĹ鲢�����㷨
	template<typename T>
	void mergeSortBU(T arr[],int n)
	{
		for (int sz = 1;sz <= n;sz += sz)
		{
			for (int i = 0; i + sz < n ;i += sz + sz)
			{
				//��arr[i...i+sz-1]��arr[i+sz...i+2*sz-1]���й鲢
				__merge2(arr, i, i + sz -1, min(i + sz + sz -1, n-1));
			}
		}
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//���������㷨
	template<typename T>
	int static __partition(T arr[],int l,int r)	//��arr[l..r]���ֽ���partition����,arr[l..p-1] < arr[p] < arr[p+1...r]
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
	void static __quickSort(T arr[],int l,int r)	//��arr[l..r]���ֽ��п�������
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
	//�Ż��Ŀ��������㷨
	template<typename T>
	int static __partitionImprove(T arr[],int l,int r)	//��arr[l..r]���ֽ���partition����,arr[l..p-1] < arr[p] < arr[p+1...r]
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
	void static __quickSortImprove(T arr[],int l,int r)	//��arr[l..r]���ֽ��п�������
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//�����鳤��С�ڵ���15ʱ���ò�������Ч�ʽϸ�
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
		srand(time(NULL));								//�����������
		__quickSortImprove(arr,0,n-1);
	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//�Ż��Ŀ��������㷨2,������ڴ����ظ�ֵʱ��Ч������
	template<typename T>
	int static __partitionImprove2(T arr[],int l,int r)	//��arr[l..r]���ֽ���partition����,arr[l..p-1] < arr[p] < arr[p+1...r]
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
	void static __quickSortImprove2(T arr[],int l,int r)	//��arr[l..r]���ֽ��п�������
	{
		/*if (l >= r)
		{
			return;
		}*/
		if (r - l <= 15)				//�����鳤��С�ڵ���15ʱ���ò�������Ч�ʽϸ�
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
		srand(time(NULL));								//�����������
		__quickSortImprove2(arr,0,n-1);
	}

	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//��·���������㷨,������ڴ����ظ�ֵʱ��Ч������ 
	template<typename T>
	void static __quickSort3Ways(T arr[], int l,int r) {
		if (r - l <= 15)				//�����鳤��С�ڵ���15ʱ���ò�������Ч�ʽϸ�
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
	//�������㷨
	template<typename T>
	void heapSort(T arr[], int n) {
		MaxHeap<T> maxheap = MaxHeap<T>(n);
		//�������е�Ԫ�ز��뵽����
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
	//�������㷨2
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
	//ԭ�ض����򣬿ռ临�Ӷ�С
	template<typename T>
	void heapSort3(T arr[], int n) {
		MaxHeap<T> maxheap = MaxHeap<T>(arr,n,false);

		for (int i = n-1 ;i > 0; i--)
		{
			maxheap.swapData(0, i);		//����ǰ��������Ԫ�������һ��Ԫ�ؽ���
			maxheap.shiftDown(i,0, false);	//�Զ�����Ϊi�ĵ�0��Ԫ�ؽ���shiftDown����
		}

	}


	//------------------------------------------------------------------------//
	//------------------------------------------------------------------------//
	//���ֲ��ҷ�,����������arr�в���target��������ҵ�������������û�в��ҵ�����-1
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

 






