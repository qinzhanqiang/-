#include <iostream>
#include <thread>
#include "MyAlgorithms.h"
#include "SortTestHelper.h"
#include "Student.h"
#include <cassert>
#include "MyUtils.h"
#include "TestDemo.h"
 


using namespace std;
int main(){
	int n =100000;
	

	int *arr = SortTestHelper::generateRandomArray(n,0,10);
//	/*int *arr = SortTestHelper::genrateNearlyOrderedArray(n,100);*/

	
	
	SortTestHelper::testSort2<int>("selection sort", arr, n, MyAlgorithms::SelectionSort);
//	SortTestHelper::testSort2<int>("Insert sort", arr, n, MyAlgorithms::InsertSort);
	SortTestHelper::testSort2<int>("Insert sort Improve", arr, n, MyAlgorithms::InsertSortImprove);
	SortTestHelper::testSort2<int>("Merge sort", arr, n, MyAlgorithms::mergeSort);
	SortTestHelper::testSort2<int>("Merge sort Improve", arr, n, MyAlgorithms::mergeSortImprove);
	SortTestHelper::testSort2<int>("Quick sort", arr, n, MyAlgorithms::quickSort);
	SortTestHelper::testSort2<int>("Quick sort Improve", arr, n, MyAlgorithms::quickSortImprove);
	SortTestHelper::testSort2<int>("Quick sort Improve2", arr, n, MyAlgorithms::quickSortImprove2);
	SortTestHelper::testSort2<int>("Quick sort 3 Ways", arr, n, MyAlgorithms::quickSort3Ways);


	system("pause");
	return 0;
}




