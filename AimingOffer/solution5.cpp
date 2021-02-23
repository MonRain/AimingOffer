/*字符串*/
#include <stdio.h>

// 知识点：变量在内存中存储的方式
void ifSame() {
	char str1[] = "hello world";
	char str2[] = "hello world";

	const char* str3 = "hello world";
	const char* str4 = "hello world";

	if (str1 == str2)
		printf("str1 and str2 are same.\n");
	else
		printf("str1 and str2 are not same.\n");

	if (str3 == str4)
		printf("str3 and str4 are same.\n");

	else
		printf("str4 and str4 are not same.\n");
	/*
	* 解析：输出为
	* str1 and str2 are not same.
	* str3 and str4 are same.
	* str1和str2被视为字符串数组，C会为他们分配对应长度的内存空间存储各自的字符串内容。
	* 因此，二者的内存地址自然是不一样的。
	* str3和str4是const字符串的指针，他们只需要记录对应的const字符串在内存中的地址。
	* 因此，他们记录同一个const字符串的内存地址。
	*/
}

/* 面试题5：替换空格
* 题目：实现一个函数，吧字符串每个空格替换成%20。
* 如：
* 	输入"We are happy."
*	输出"We%20are%20happy."	
*/

char* solution5(char* str, int length) {
	if (str == nullptr || length <= 0)
		return nullptr;


	/*
	* 首先应该想到的：
	* 原来是一个字符' '，替换之后会变成三个字符'%', '2', '0'。
	* 因此，字符串长度会改变
	* 如果执行原地算法，可能会覆盖后方的内存数据
	* 如果不执行原地算法，需要预分配足够空间
	* 这象征两种需求
	*/
	/* 遇到的第一个问题 
	* 如何访问和遍历字符串内部元素
	*/
	/* 
	* 第一个想法：先查找存在空格的数量，记录。再创建/扩展足够内存——实践复杂度O(n)
	* 契合参考答案
	*/

	int num_blank = 0;
	char* p_end;//记录原来的的字符串结尾
	char* p_new_end;//记录扩展后字符串结尾

	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			num_blank++;
		}
	}

	p_end = str + (length+1) * 2;
	p_new_end = p_end + 2 * num_blank;


	//总结：C语言中 字符串后边都有一个'\0'结束符
}

// 反思：善于用while循环

