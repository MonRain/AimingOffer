/*
* 面试题4：二维数组的查找
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下的顺序排序。
* 完成函数：
* 输入：上述类型的数组和一个整数
* 输出：判断数组中是否有该整数
*/

bool solution4(int* arr, int rows, int columns, int value) {
	if (arr == nullptr || columns <= 0 || rows <= 0)
		return false;

	int row = 0;
	int column = columns - 1;

	while (row < rows && column >= 0)
	{
		int item = arr[row * columns + column];
		if (item == value)
			return true;
		else if (item > value) {
			column--;
		}
		else
			row++;
	}

	return false;
}

/* C++中二维数组 
* 二维数组的定义
* 二维数组的存储方式 https://blog.csdn.net/ginny97/article/details/109248707
* 二维数组的索引 int item = arr[row * columns + column];
* 二维数组的使用：指针的嵌套
*/
