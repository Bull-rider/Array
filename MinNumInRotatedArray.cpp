/****************************************
 File Name: MinNumInRotatedArray.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Tue 08 Jan 2019 08:48:08 AM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

int min(int *numbers,int length)
{
	if(numbers==nullptr||length<=0)
		throw new std::exception("Invalid parameters");
	int index1=0;
	int index2=length-1;
	int indexMid=index1;
	while(numbers[index1]>=numbers[index2])
	{
		if(index2-index1==1)//如果数组只有两个元素
		{
			indexMid=index2;
			break;
		}
		//下面时利用二分法查找，找到第一个比index1小的数的下标
		indexMid=(index1+index2)/2;
		if(numbers[indexMid]>=numbers[index1])
			index1=indexMid;
		else if(numbers[indexMid]<=numbers[index2])
			index2=indexMid;
	}
	return numbers[indexMid];
}
//上述代码未考虑连续元素相同的情况
int min(int *numbers,int length)
{
	if(numbers==NULL||length<=0)
	{
		throw new std::exception("Invalid parameters");
	}
	int index1=0;
	int index2=length-1;
	int indexMid=index1;
	while(numbers[index1]>=numbers[index2])
	{
		if(index2-index1==1)
		{
			indexMid=index2;
			break;
		}
		indexMid=(index1+index2)/2;
		//如果下标为index1,index2,indexMid指向的三个元素相等
		//则只能顺序查找
		if(numbers[index1]==numbers[index2]==numbers[indexMid])
			return MinInOrder(numbers,index1,index2);
		if(numbers[indexMid]>=numbers[index1])
			index1=indexMid;
		else if(numbers[indexMid]<=numbers[index2])
			index2=indexMid;
	}
	return numbers[indexMid];
}
//顺序查找
int MinInOrder(int *numbers,int index1,int index2)
{
	int result=numbers[index1];
	for(int i=index+1;i<index2;++i)
	{
		if(result>numbers[i])
			result=numbers[i];
	}
	return result;
}
