/****************************************
 File Name: PrintCircleArray.cpp
# Author:yxg
# mail:yxi7899@gmail.com
# Created Time: Fri 11 Jan 2019 09:09:41 AM CST
 ****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//----------------顺时针打印一个矩阵
using std::cout;
using std::endl;

void PrintCircleArray(int a[][],int rows,int columns)
{
	if(numbers==nullptr||rows<=0||columns<=0)
		return;
	int start=0;
	while(rows>start*2&&columns>start*2)
	{
		PrintMatrixInCircle(a,rows,columns,start);
		++start;
	}
}
void PrintMatrixInCircle(int **a,int rows,int columns,int start)
{
	int endx=columns-1-start;
	int endy=rows-1-start;

	//从左向右打印一行
	for(int i=start;i<=endx;++i)
	{
		int number=a[start][i];
		printfNumber(number);
	}
	//从上到下打印一列
	if(start<endy)
	{
		for(int i=statt+1;i<=endy;++i)
		{
			int number=a[i][endx];
			printNumber(number);
		}
	}
	//从右向左打印一行
	if(start<endx&&start<endy-1)
	{
		for(int i=endx-1;i>=start+1;--i)
		{
			int number=a[endy][i];
			printNumber(number);
		}
	}
	//从下向上打印一列
	if(start<endx&&start<endy-1)
	{
		for(int i=endy-1;i>=start+1;--i)
		{
			int number=a[i][start];
			printNumber(number);
		}
	}
}
void printNumber(int number)
{
	printf("%d\t",number);
}
