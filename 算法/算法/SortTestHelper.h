#pragma once

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper{
	//-----------------------------------------------------//
	//生成n个元素的随机数组
	int* generateRandomArray(int n,int rangeL,int rangeR){
		assert(rangeR >= rangeL);
		int *arr = new int[n];
		srand(time(NULL));
		for (int i=0;i<n;i++)
		{
			arr[i] = rand()%(rangeR - rangeL +1) + rangeL;
		}
		return arr;
	}

	//-----------------------------------------------------//
	//打印
	template<typename T>
	void printArray(T arr[],int n){
		for (int i=0;i<n;i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}
	//-----------------------------------------------------//
	//判断数组是否有序
	template<typename T>
	bool isSorted(T arr[],int n)
	{
		for(int i=0;i<n-1;i++){
			if(arr[i] > arr[i+1])
				return false;
		}


		return true;

	}


	//-----------------------------------------------------//
	//测试排序
	template<typename T>
	void testSort(string sortName,T arr[],int n,void(*sort)(T*,int))
	{
		clock_t startTime = clock();
		sort(arr,n);
		clock_t endTime = clock();
		
		assert(isSorted(arr,n));
		cout << sortName << ":" << double(endTime-startTime)/CLOCKS_PER_SEC << endl;
		return;
	}

	//-----------------------------------------------------//
	//只测试排序花费的时间，不会修改数组的排列顺序
	template<typename T>
	void testSort2(string sortName, T arr[], int n, void(*sort)(T*, int))
	{
		int *arr2 = SortTestHelper::copyIntArray(arr, n);
		clock_t startTime = clock();
		sort(arr2, n);
		clock_t endTime = clock();
		//printArray(arr2, n);
		delete[] arr2;
		assert(isSorted(arr2, n));
		cout << sortName << ":" << endl  << double(endTime - startTime) / CLOCKS_PER_SEC << endl;
		return;
	}

	

	//-----------------------------------------------------//
	//
	int * copyIntArray(int a[],int n)
	{
		int * arr = new int[n];
		copy(a,a+n,arr);
		return arr;
	}


	int *genrateNearlyOrderedArray(int n,int swapTimes)
	{
		int *arr = new int[n];
		for(int i=0;i<n;i++){
			arr[i] = i;
		}

		srand(time(NULL));
		for(int i=0;i<swapTimes;i++){
			int posx = rand() % n;
			int posy = rand() % n;

			swap(arr[posy],arr[posx]);
		}
		return arr;
	}
}





