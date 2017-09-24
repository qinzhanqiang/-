//#include <iostream>
//#include "MyAlgorithms.h"
//#include "SortTestHelper.h"
//#include "Student.h"
//#include <cassert>
//#include "MyUtils.h"
//#include "TestDemo.h"
//#include "MaxHeap.h"
// 
//
//
//using namespace std;
//int main(){
//	int n =100000;
//	
//
//	int *arr = SortTestHelper::generateRandomArray(n,0,n);
//	int *arr2 = SortTestHelper::generateRandomArray(n, 0, 10);
//	int *arr3 = SortTestHelper::genrateNearlyOrderedArray(n,100);
//
//	
//	cout << endl << "测试用例数据量:"<< n <<"   测试用例arr:" << endl;
//	SortTestHelper::testSort2<int>("selection sort", arr, n, MyAlgorithms::SelectionSort);
////	SortTestHelper::testSort2<int>("Insert sort", arr, n, MyAlgorithms::InsertSort);
//	SortTestHelper::testSort2<int>("Insert sort Improve", arr, n, MyAlgorithms::InsertSortImprove);
//	SortTestHelper::testSort2<int>("Merge sort", arr, n, MyAlgorithms::mergeSort);
//	SortTestHelper::testSort2<int>("Merge sort Improve", arr, n, MyAlgorithms::mergeSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort", arr, n, MyAlgorithms::quickSort);
//	SortTestHelper::testSort2<int>("Quick sort Improve", arr, n, MyAlgorithms::quickSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort Improve2", arr, n, MyAlgorithms::quickSortImprove2);
//	SortTestHelper::testSort2<int>("Quick sort 3 Ways", arr, n, MyAlgorithms::quickSort3Ways);
//	SortTestHelper::testSort2<int>("Heap Sort", arr, n, MyAlgorithms::heapSort);
//	SortTestHelper::testSort2<int>("Heap Sort2", arr, n, MyAlgorithms::heapSort2);
//	SortTestHelper::testSort2<int>("Heap Sort3", arr, n, MyAlgorithms::heapSort3);
//
//	cout << endl << "测试用例数据量:" << n << "   测试用例arr2,存在大量重复值的数组:" << endl;
//	SortTestHelper::testSort2<int>("selection sort", arr2, n, MyAlgorithms::SelectionSort);
//	//	SortTestHelper::testSort2<int>("Insert sort", arr2, n, MyAlgorithms::InsertSort);
//	SortTestHelper::testSort2<int>("Insert sort Improve", arr2, n, MyAlgorithms::InsertSortImprove);
//	SortTestHelper::testSort2<int>("Merge sort", arr2, n, MyAlgorithms::mergeSort);
//	SortTestHelper::testSort2<int>("Merge sort Improve", arr2, n, MyAlgorithms::mergeSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort", arr2, n, MyAlgorithms::quickSort);
//	SortTestHelper::testSort2<int>("Quick sort Improve", arr2, n, MyAlgorithms::quickSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort Improve2", arr2, n, MyAlgorithms::quickSortImprove2);
//	SortTestHelper::testSort2<int>("Quick sort 3 Ways", arr2, n, MyAlgorithms::quickSort3Ways);
//	SortTestHelper::testSort2<int>("Heap Sort", arr2, n, MyAlgorithms::heapSort);
//	SortTestHelper::testSort2<int>("Heap Sort2", arr2, n, MyAlgorithms::heapSort2);
//	SortTestHelper::testSort2<int>("Heap Sort3", arr2, n, MyAlgorithms::heapSort3);
//
//	cout << endl << "测试用例数据量:" << n << "   测试用例arr3，近乎有序的数组:" << endl;
//	SortTestHelper::testSort2<int>("selection sort", arr3, n, MyAlgorithms::SelectionSort);
//	//	SortTestHelper::testSort2<int>("Insert sort", arr3, n, MyAlgorithms::InsertSort);
//	SortTestHelper::testSort2<int>("Insert sort Improve", arr3, n, MyAlgorithms::InsertSortImprove);
//	SortTestHelper::testSort2<int>("Merge sort", arr3, n, MyAlgorithms::mergeSort);
//	SortTestHelper::testSort2<int>("Merge sort Improve", arr3, n, MyAlgorithms::mergeSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort", arr3, n, MyAlgorithms::quickSort);
//	SortTestHelper::testSort2<int>("Quick sort Improve", arr3, n, MyAlgorithms::quickSortImprove);
//	SortTestHelper::testSort2<int>("Quick sort Improve2", arr3, n, MyAlgorithms::quickSortImprove2);
//	SortTestHelper::testSort2<int>("Quick sort 3 Ways", arr3, n, MyAlgorithms::quickSort3Ways);
//	SortTestHelper::testSort2<int>("Heap Sort", arr3, n, MyAlgorithms::heapSort);
//	SortTestHelper::testSort2<int>("Heap Sort2", arr3, n, MyAlgorithms::heapSort2);
//	SortTestHelper::testSort2<int>("Heap Sort3", arr3, n, MyAlgorithms::heapSort3);
//	
//	
//	
//	system("pause");
//	return 0;
//}
//
//
//
//
