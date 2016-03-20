#include<stdio.h>
int main()
{
	float a,b,c,m;
	scanf("%f%f%f",&a,&b,&c);
	if(a>b)m=a;
	else m=b;
	if(m<c)m=c;
	printf("m=%f\n",m);
	return 0;
}
