// sort.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
/*
00000001 һ���ֽ�
1k = 1024 �ֽ� 10�η�
1m = 1024 k
1g = 1024 m
1t = 1024 g 

4g = 2��32�η�
*/
/* ÿ���10%,��n��ʣ���� */
int f(int n)
{
   if (n = 1)
       return 42300;
   else
	   return f(n-1)*0.9;
}

//ð�ݴ�С����
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

//���뷨

//��С�����������
void insertsort(int *k,int n)             /*ֱ�Ӳ�������*/
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp = k[i];                //��Ҫ�Ƚϵ�ֵ��練���������һ����λ�������ƶ�
        j = i - 1;
        while(j>=0 && k[j]>temp)    //�Ƚ�ֱ�����ֱ�temp���ֵ������ǰ�ҵ�ͷ
        {
            k[j+1] = k[j];            //��ǰ���ֵ������
            j--;
        }
        k[j+1] = temp;                 //����a[j]�ĺ���
    }
}

//ѡ��
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

