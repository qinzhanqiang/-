#pragma once

//测试排序算法的运行时间
template<typename T>
void testSelectionSort(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::SelectionSort(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;


	cout << "selection sort:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
}

//测试排序算法的运行时间
template<typename T>
void testInsertSort(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::InsertSort(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Insert sort:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}

//测试排序算法的运行时间
template<typename T>
void testInsertSortImprove(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::InsertSortImprove(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Insert sort Improve:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}

//测试排序算法的运行时间
template<typename T>
void testMergeSort(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::mergeSort(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Merge sort:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}


//测试排序算法的运行时间
template<typename T>
void testMergeSortImprove(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::mergeSortImprove(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Merge sort Improve:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}


//测试排序算法的运行时间
template<typename T>
void testQuickSort(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::quickSort(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Quick sort:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}

//测试排序算法的运行时间
template<typename T>
void testQuickSortImprove(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::quickSortImprove(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time = endTime - startTime;
	cout << "Quick sort Improve:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}

//测试排序算法的运行时间
template<typename T>
void testQuickSortImprove2(T arr[],int n)
{
	int *arr2 = SortTestHelper::copyIntArray(arr,n);
	double time;

	clock_t startTime = clock();
	MyAlgorithms::quickSortImprove2(arr2,n);
	clock_t endTime = clock();
	//	SortTestHelper::printArray(arr2,n);
	assert(SortTestHelper::isSorted(arr2,n));
	time =double(endTime - startTime) ;
	cout << "Quick sort Improve2:" << time/CLOCKS_PER_SEC <<endl;
	delete [] arr2;
	
}