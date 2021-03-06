#pragma once
#include <algorithm>
#include <string>
#include <assert.h>



template<typename Item>
class MaxHeap
{
private:
	Item * data;
	int count;
	int capcatity;

	int copy_flag = 1;	//判断堆是否拷贝数据，开辟了新的空间，若开辟空间则析构函数中释放空间

	void shiftUp(int k) {
		while (k> 1 && data[k / 2] < data[k]) {
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	//当堆从第一个元素开始时调用
	void shiftDown(int k) {
		//判断该节点有子节点
		while (2 * k <= count) {
			int j = 2 * k;
			//判断是否有右子节点，若有右子节点且右子节点大于左子节点，则与右子节点进行交换
			if (j + 1 <= count&&data[j + 1] > data[j]) {
				j += 1;
			}

			if (data[k] >= data[j])
				break;

			swap(data[k], data[j]);
			k = j;
		}
	}
	

	////testprint调用
	//void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft) {

	//	int sub_tree_width = (cur_tree_width - 1) / 2;
	//	int offset = index_cur_level * (cur_tree_width + 1) + sub_tree_width;
	//	assert(offset + 1 < line.size());
	//	if (num >= 10) {
	//		line[offset + 0] = '0' + num / 10;
	//		line[offset + 1] = '0' + num % 10;
	//	}
	//	else {
	//		if (isLeft)
	//			line[offset + 0] = '0' + num;
	//		else
	//			line[offset + 1] = '0' + num;
	//	}
	//}
	////testprint调用
	//void putBranchInLine(string &line, int index_cur_level, int cur_tree_width) {

	//	int sub_tree_width = (cur_tree_width - 1) / 2;
	//	int sub_sub_tree_width = (sub_tree_width - 1) / 2;
	//	int offset_left = index_cur_level * (cur_tree_width + 1) + sub_sub_tree_width;
	//	assert(offset_left + 1 < line.size());
	//	int offset_right = index_cur_level * (cur_tree_width + 1) + sub_tree_width + 1 + sub_sub_tree_width;
	//	assert(offset_right < line.size());

	//	line[offset_left + 1] = '/';
	//	line[offset_right + 0] = '\\';
	//}


public:
	MaxHeap(int capacity) {
		data = new Item[capacity + 1];
		count = 0;
		this->capcatity = capacity;
	};
	//从1开始构建二叉堆
	MaxHeap(Item arr[], int n) {
		data = new Item[n + 1];
		capcatity = n;

		for (int i = 0; i < n; i++)
		{
			data[i + 1] = arr[i];
		}
		count = n;

		//将数组整理成二叉堆
		for (int i = count / 2;i >= 1 ;i--)
		{
			shiftDown(i);
		}
	}
	//从零开始构建二叉堆,zero传入空
	MaxHeap(Item arr[], int n,bool zero) {		
		if (zero == false)
		{
			copy_flag = 0;
			data = arr;
			count = n;

			//将数组整理成二叉堆
			for (int i = (count - 1) / 2; i >= 0; i--)
			{
				shiftDown(n,i,false);
			}
		}
		else {
			data = new Item[n + 1];
			capcatity = n;
			for (int i = 0; i < n; i++)
			{
				data[i + 1] = arr[i];
			}
			count = n;

			//将数组整理成二叉堆
			for (int i = count / 2; i >= 1; i--)
			{
				shiftDown(i);
			}
		}
		
	}

	~MaxHeap() {
		if(copy_flag != 0)
			delete[] data;
	};

	int size() 
	{ 
		return count; 
	}
	bool isEmpty() 
	{ 
		return count == 0; 
	}
	void swapData(int i,int j) {
		swap(data[i], data[j]);
	}

	void insert(Item item) {
		assert(count + 1 <= capcatity);
		data[count + 1] = item;
		count++;
		//将新加入的元素向上移
		shiftUp(count);
	}
	Item extractMax() {
		assert(count > 0);
		Item ret = data[1];

		swap(data[1] , data[count]);
		count--;

		shiftDown(1);
		return ret;
	}

	////打印二叉树
	//void testPrint() {
	//	if (size() >= 100) {
	//		cout << "Fancy print can only work for less than 100 int";
	//		return;
	//	}

	//	if (typeid(Item) != typeid(int)) {
	//		cout << "Fancy print can only work for int item";
	//		return;
	//	}

	//	cout << "The Heap size is: " << size() << endl;
	//	cout << "data in heap: ";
	//	for (int i = 1; i <= size(); i++)
	//		cout << data[i] << " ";
	//	cout << endl;
	//	cout << endl;

	//	int n = size();
	//	int max_level = 0;
	//	int number_per_level = 1;
	//	while (n > 0) {
	//		max_level += 1;
	//		n -= number_per_level;
	//		number_per_level *= 2;
	//	}

	//	int max_level_number = int(pow(2, max_level - 1));
	//	int cur_tree_max_level_number = max_level_number;
	//	int index = 1;
	//	for (int level = 0; level < max_level; level++) {
	//		string line1 = string(max_level_number * 3 - 1, ' ');

	//		int cur_level_number = min(count - int(pow(2, level)) + 1, int(pow(2, level)));
	//		bool isLeft = true;
	//		for (int index_cur_level = 0; index_cur_level < cur_level_number; index++, index_cur_level++) {
	//			putNumberInLine(data[index], line1, index_cur_level, cur_tree_max_level_number * 3 - 1, isLeft);
	//			isLeft = !isLeft;
	//		}
	//		cout << line1 << endl;

	//		if (level == max_level - 1)
	//			break;

	//		string line2 = string(max_level_number * 3 - 1, ' ');
	//		for (int index_cur_level = 0; index_cur_level < cur_level_number; index_cur_level++)
	//			putBranchInLine(line2, index_cur_level, cur_tree_max_level_number * 3 - 1);
	//		cout << line2 << endl;

	//		cur_tree_max_level_number /= 2;
	//	}
	//}
	//当堆从第0个元素开始
	void shiftDown(int n, int k, bool zero) {
		if (zero == false)		//从零开始时
		{
			//判断该节点有子节点
			while (2 * k + 1 < n) {
				int j = 2 * k + 1;
				//判断是否有右子节点，若有右子节点且右子节点大于左子节点，则与右子节点进行交换
				if (j + 1 < n && data[j + 1] > data[j]) {
					j += 1;
				}

				if (data[k] >= data[j])
					break;

				swap(data[k], data[j]);
				k = j;
			}
		}
		else {					//从一开始时
			//判断该节点有子节点
			while (2 * k <= count) {
				int j = 2 * k;
				//判断是否有右子节点，若有右子节点且右子节点大于左子节点，则与右子节点进行交换
				if (j + 1 <= count&&data[j + 1] > data[j]) {
					j += 1;
				}

				if (data[k] >= data[j])
					break;

				swap(data[k], data[j]);
				k = j;
			}
		}
		
		
	}
};

