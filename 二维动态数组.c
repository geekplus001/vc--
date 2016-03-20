#include<stdio.h>
//#include<stdlib.h>
#include<malloc.h>
int main()
{
    int n1,n2,i,j,**p;
	printf("请输入你要创建的二维数组的第一维第二维长度：\n");
	scanf("%d%d",&n1,&n2);
	p=(int**)malloc(n1*sizeof(int*));//(int**)可有可无 
	for(i=0;i<n1;i++)
		p[i]=(int*)malloc(n2*sizeof(int));
	printf("请输入数字：\n");
	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
			scanf("%d",&p[i][j]);
	for(i=0;i<n1;i++)
	{
	
		for(j=0;j<n2;j++)
	        printf("%4d",p[i][j]);
	    printf("\n");
	}
	//for(i=0;i<n1;i++)
    //free(p[i]);
    //free(p);
   // return 0;
}
