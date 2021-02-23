/*
* ������4����ά����Ĳ���
* ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�˳������
* ��ɺ�����
* ���룺�������͵������һ������
* ������ж��������Ƿ��и�����
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

/* C++�ж�ά���� 
* ��ά����Ķ���
* ��ά����Ĵ洢��ʽ https://blog.csdn.net/ginny97/article/details/109248707
* ��ά��������� int item = arr[row * columns + column];
* ��ά�����ʹ�ã�ָ���Ƕ��
*/
