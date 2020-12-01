// sort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
/*
00000001 一个字节
1k = 1024 字节 10次方
1m = 1024 k
1g = 1024 m
1t = 1024 g 

4g = 2的32次方
*/
/* 每天吃10%,第n天剩余量 */
int f(int n)
{
   if (n = 1)
       return 42300;
   else
	   return f(n-1)*0.9;
}

//冒泡从小到大
void sort(int *a,int n)
{
	for (int i = 0; i < n-1; i++) {
		for(int j=0;j<n-i-1;j++){
		    if (a[j]>a[j+1]){
				int max = a[j];
				a[j] = a[j+1];
				a[j+1] = max;
			}
		}
	}
}

//插入法

//从小到大进行排序
void insertsort(int *k,int n)             /*直接插入排序*/
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp = k[i];                //将要比较的值先绶存起来留出一个空位，方便移动
        j = i - 1;
        while(j>=0 && k[j]>temp)    //比较直到出现比temp大的值，或向前找到头
        {
            k[j+1] = k[j];            //将前面的值往后移
            j--;
        }
        k[j+1] = temp;                 //插在a[j]的后面
    }
}

//选择法
void selectsort(int *k,int n)
{
	for (int i = 0; i<n-1;i++){
		for(int j=i+1;j<n-1;j++){
			if(k[i]>k[j]){
				int temp=k[i];
				k[i]=k[j];
				k[j]=temp;
			}
		}
	}
}
//
void selectsort1(int *k,int n)
{
	int i,j,small,temp;
	for(i=0;i<n-1;i++){
		small=-1;
		for(j=i;j<n-1;j++){
			if(k[i]>k[j])
				small=j;
		}
		if(small!=-1){
			temp=k[i];
			k[i]=k[small];
			k[small]=temp;
		}
	}
}

void print(int *a, int n)
{
	for(int i=0;i<n;i++){
		if(i==0)
		    printf("%d",a[i]);
		else if (i==n-1)
			printf(",%d\r\n",a[i]);
		else
			printf(",%d",a[i]);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int a[5]={18,28,22,30,79};
	sort(a,5);
	print(a,5);
	int b[5]={18,28,22,30,79};
	insertsort(b,5);
	print(b,5);
	int c[5]={18,28,22,30,79};
	selectsort(c,5);
	print(c,5);
	int d[5]={18,28,22,30,79};
	selectsort1(d,5);
	print(d,5);
	getchar();
	return 0;
}

