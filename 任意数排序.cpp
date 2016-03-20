#include<stdio.h>
#include <malloc.h>
int main()
{
	int i, j, n, t;
	float *p;
	printf("你想输入几个数n=");
	scanf("%d",&n);
	p = (float *)malloc(sizeof(float) * n);
	printf("输入数字:");
	for(i=0;i<n;i++)
		scanf("%f",&p[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(p[j]>p[j+1])
		{ 
		  t=p[j];
		  p[j]=p[j+1];
		  p[j+1]=t;
		} 
	}
	for(j=0;j<n-1;j++)
	printf("%f<",p[j]);
	printf("%f",p[n-1]);
	return 0;
	
}