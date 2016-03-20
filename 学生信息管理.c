#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>

typedef struct student 

{
	
	char studentnumber[20];//学生学号
	char studentname[20];//学生姓名
	char classname[20];//班级名称
	float mark1;//第一门成绩
	float mark2;//第二门成绩
	float mark3;//第三门成绩
	struct student *next;
	 
}student;
//struct student student;

student *headlink;//链表表头指针
int i=0;
char gg[20];

//函数声明 
student *mallocnode(); //申请一个新节点并初始化
void createheadlink();//建立链表表头
void readinformationfile();//从文件中读学生信息
void gotoxy (int x,int y);//移动光标 
void setadministrator();//输入授权码
void changepassword(); 
void displaymenu();//显示菜单
void getinformation(student*t);//要求用户输入学生信息
void outputinformation();//显示所有学生信息 
void displayinformationbystudentname();//根据名字显示学生信息
void displayinformationbystudentnumber();//根据学号显示学生信息
void deletenodebystudentnumber();//根据学号删除学生信息
void changemarkbystudentname();//根据姓名修改学生成绩
void changemarkbystudentnumber();//根据学号改学生成绩
void displaymarksegment();//显示各分数段学生成绩

void displayonenode(student * t);//输出一个节点学生信息
void insertonenode(student *t);// 加入一个新节点
void savelinktofile();//保留数据后退出
void compositorbytotalmark();//按总成绩排序
int choose;//用户输入


//主函数
main()
{
	createheadlink();//建立链表表头 
	readinformationfile();// 从文件中读学生信息 
    setadministrator();//
	displaymenu();//显示菜单，根据用户输入完成相应的功能 
} 

 /////////////////////建立链表表头
 void createheadlink()
 {
 	student *p;
 	p=(student*)malloc(sizeof(student));
 	headlink=p;
 	p->next=NULL;
 }
 
 ////////////////////从文件中读学生信息
 void readinformationfile()
 {
 	FILE *fp;
 	student *p;
 	fp=fopen("student.txt","r");
 	if(!fp)
 	{
 		printf("文件不存在\n");
 		return;
 	}
 	p=mallocnode();
 	while(fscanf(fp,"%s%s%s%f%f%f",p->studentnumber,p->studentname,p->classname,&p->mark1,&p->mark2,&p->mark3)>0)
    {
    	insertonenode(p);
    	p=mallocnode();
    }
    fclose(fp);
 } 
 
 ///////////////////////设置账户密码~~
 void setadministrator()
 {
 	int flag=0,t=2;
 	char ad[20],password[20],ss[20];
 	 
 	FILE *p,*q;

    system("color fd");
    printf("\n\n\n\n\n\n                    ★★★★★★★★★★★★★★★★★★★★★★\n");
 	printf("                    ★   欢迎使用松园19-403学生信息管理系统   ★\n");
 	printf("                    ★★★★★★★★★★★★★★★★★★★★★★\n");
 	/*gotoxy(20,8);
        printf("Press any key to continue~~");*/
    while(!kbhit())//闪烁 
 	{
 		gotoxy(20,12);
 		printf("Press any key to continue~~");
 		Sleep(150);
 		gotoxy(20,12);
 		printf("                           ");
 		Sleep(150);
 		gotoxy(20,12);
		printf("Press any key to continue~~");
 	}
 	
    getch();
 	system("cls");
AB:
	i=0;
	q=fopen("admin.txt","r");
	fscanf(q,"%s",gg);
	fclose(q);
 	printf("请输入授权碼:");
    while((ss[i]=getch())!='\r')
		{
			putchar('*');
			
			i++;
		} 
	ss[i]='\0';
	if(t!=0)
	{
	
		if(strcmp(ss,gg)==0)
		{
			gotoxy(20,8);
		    printf("身份已经确认：最高授权！\n"); 
		    Sleep(1500);
		}
		else
		{
			gotoxy(20,8);
			printf("\a\aWarning:身份未确认!" );
			gotoxy(20,9);
			printf("你还有%d次机会！",t);
			t--; 
			Sleep(1500);
			system("cls") ;
			goto AB;
		}
	}
	else
	exit(0);
	system("cls");
	

 	/*if(p=fopen("admin.txt","r")==NULL)
 	{
 		p=fopen("admin.txt","w+");
 		flag=1;
 	}
 	if(flag==1)
 	{
 		printf("暂无账户，请创建：\n")； 
 		printf("请创立账号：");
 		scanf("%s",ad);
 		printf("请设置密码：")； 
 		i=0;
		while(getch()!='\r')
		{
			putchar("*");
			password[i]=getch();
			i++;
		} 
		fprintf(p,"%s %s",ad,password);
		printf("创建成功！\n"); 
 	}
    if(flag==0)
    {
    	printf("请输入账号："); 
    }*/
 	
 } 
 
/////////////////////////移动光标 
void gotoxy (int x,int y)
{
	COORD pos={x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
 
 //////////////////////显示菜单，根据用户输入完成相应的功能
 void displaymenu()
 {
 	student *p;
    system("color 5e");
   /* HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);*/
 	printf("                    ********请选择相应的功能********\n");
	printf("                    1  显示所有学生信息\n");
	printf("                    2  按姓名查询学生信息\n");
	printf("                    3  按学号查询学生信息\n");
	printf("                    4  增加学生信息\n");
	printf("                    5  删除学生信息\n");
	printf("                    6  按姓名修改学生成绩\n");
	printf("                    7  按学号修改学生成绩\n");
	printf("                    8  保存所有学生信息\n");
	printf("                    9  显示优秀和不及格学生成绩\n");
	printf("                    10 排序结果并输出成绩\n");
	printf("                    11 退出程序\n");
	printf("                    12 修改密码\n"); 
	scanf("%d",&choose);//用户选择
	switch(choose)
	{
		case 1:
			outputinformation();
		break;	
		case 2:
		     displayinformationbystudentname();
        break;
        case 3:
        	displayinformationbystudentnumber();
       	break;
       	case 4:
       		p=mallocnode();
       		getinformation(p);
       		insertonenode(p);
    	break;
		case 5:
		    deletenodebystudentnumber();
		break;
		case 6:
		    changemarkbystudentname();
		break;
		case 7:
		    changemarkbystudentnumber();
		break;	 
		case 8:
			savelinktofile();
		break;
		case 9:
			displaymarksegment();
		break;
		case 10:
			compositorbytotalmark();
		break;
		case 11:
			savelinktofile();
		free(headlink);
		return;
		case 12:
			changepassword();
		break;
		default: 
		break;
	} 
    displaymenu();//递归调用 
 } 
 
 ///////////////////申请新的结点并初始化
 student *mallocnode()
 {
 	student *p;
 	int i;
 	p=(student*)malloc(sizeof(student));
 	if(p==NULL)
 	    return NULL;
 	for(i=0;i<20;i++)
       p->studentnumber[i]='\0';
    for(i=0;i<20;i++)
       p->studentname[i]='\0';
    for(i=0;i<20;i++)
       p->classname[i]='\0';
    p->mark1=0.0;
    p->mark2=0.0;
    p->mark3=0.0;
    p->next=NULL;
    return p;
 } 
 
 /////////////////获取学生信息
 void getinformation(student *t)
 {
 	printf("请输入学生学号：\n");
 	scanf("%s",t->studentnumber);
 	printf("请输入学生姓名：\n");
 	scanf("%s",t->studentname);
 	printf("请输入学生所在班级：\n");
 	scanf("%s",t->classname);
 	printf("请输入第一门成绩：\n");
 	scanf("%f",&t->mark1);
 	printf("请输入第二门成绩：\n");
 	scanf("%f",&t->mark2);
 	printf("请输入第三门成绩：\n");
 	scanf("%f",&t->mark3);
 	
 } 
 
 ////////////////////////显示所有学生信息
void outputinformation()
{
	student *p;
	p=headlink->next;
	if(p==NULL)
	{
		printf("现在没有学生信息，请先输入学生信息。\n");
		return;
	}
	printf("学号\t      姓名\t班级   \t成绩1  \t成绩2  \t成绩3  \t总成绩  平均成绩\n");
	while(p)
	{
		displayonenode(p);
		p=p->next;
	}
} 

 
 //////////////////在链表结尾添加一个结点
 void insertonenode(student *t)
 {
 	student *p;
 	p=headlink;
 	while(p->next)
 	   p=p->next;
    p->next=t;
 } 
 
 //////////////////根据学生姓名显示学生信息
 void displayinformationbystudentname()
 {
 	student *p;
 	char studentname[20];
	 int flag=0;
	 p=headlink->next;
	 printf("请输入学生姓名：\n");
	 scanf("%s",studentname);
	 while(p)
	 {
	 	if(strcmp(p->studentname,studentname)==0)
	 	{
	 		printf("学号\t姓名\t班级\t成绩1\t成绩2\t成绩3\t总成绩\t平均成绩\n\n");
	 		displayonenode(p);
	        flag=1;
	        
	 		break;
	 	}
	 	p=p->next;
	 	
	 }
	 if(!flag)
	 printf("对不起，不存在姓名为%s的学生\n",studentname);
 } 
 
 //////////////////////根据学号显示学生信息
 void displayinformationbystudentnumber()
 {
 	student *p;
 	char studentnumber[20];
 	int flag=0;
 	p=headlink->next;
 	printf("请输入学生学号：\n");
 	scanf("%s",studentnumber);
 	while(p)
 	{
 		if(strcmp(p->studentnumber,studentnumber)==0)
 		{
 			printf("学号\t姓名\t班级\t成绩1\t成绩2\t成绩3\t总成绩\t平均成绩\n\n");
 			displayonenode(p);
            flag=1;		
 			break;
 		}
 		p=p->next;
 	}
 	if(!flag)
 	printf("对不起，不存在学号为%s的学生\n");
 } 
 
 //////////////////////////输出一个结点的信息
void displayonenode(student *t)
{
	printf("%s   ",t->studentnumber);
	printf("%s   ",t->studentname);
	printf("%s   ",t->classname);
	printf("%.2f   ",t->mark1);
	printf("%.2f   ",t->mark2);
	printf("%.2f   ",t->mark3);
	printf("%.2f   ",t->mark1+t->mark2+t->mark3);
	printf("%.2f\n",(t->mark1+t->mark2+t->mark3)/3);
	 
} 

/////////////////////////根据学号删除学生信息
void deletenodebystudentnumber()
{
	char studentnumber[20];
	student *p,*q;
	int flag=0;
	printf("请输入要删除的学生学号：");
	scanf("%s",studentnumber);
	p=headlink;
	q=headlink->next;
	while(q)
	{
		if(strcmp(q->studentnumber,studentnumber)==0)
		{
			p->next=q->next;
			free(q);
			flag=1;
			break;
		}
		p=p->next;
		q=q->next;
	}
	if(!flag)
	{
		printf("不存在该学号的学生\n");
		return;
		
	}
	printf("成功删除\n");
} 


////////////////////////////根据姓名修改成绩
void changemarkbystudentname()
{
	student *p;
	char studentname[20];
	int flag=0;
	float mark1,mark2,mark3;
	p=headlink->next;
	printf("请输入学生姓名：\n");
	scanf("%s",studentname);
	while(p)
	{
		if(strcmp(p->studentname,studentname)==0)
		{
			printf("请输入新的第一门成绩：\n");
			scanf("%f",&mark1);
			printf("请输入新的第二门成绩：\n");
			scanf("%f",&mark2);
			printf("请输入新的第三门成绩：\n");
			scanf("%f",&mark3);
			p->mark1=mark1;
			p->mark2=mark2;
			p->mark3=mark3;
			printf("修改成功\n");
			flag=1;
			break;
		}
		p=p->next;
	
	}
		if(!flag)
     	printf("对不起，不存在姓名为%s的学生\n",studentname);
   
} 

////////////////////////根据学号修改成绩
void changemarkbystudentnumber()
{
	student *p;
	char studentnumber[20];
	int flag=0;
	float mark1,mark2,mark3;
	p=headlink->next;
	printf("请输入学生学号：\n");
	scanf("%s",studentnumber);
	while(p)
	{
		if(strcmp(p->studentnumber,studentnumber)==0)
		{
			printf("请输入新的第一门成绩：\n");
			scanf("%f",&mark1);
			printf("请输入新的第二门成绩：\n");
			scanf("%f",&mark2);
			printf("请输入新的第三门成绩:\n");
			scanf("%f",&mark3);
			p->mark1=mark1;
			p->mark2=mark2;
			p->mark3=mark3;
			printf("修改成功\n");
			flag=1;
			break;
		}
		p=p->next;
	}
	if(!flag)
	printf("对不起，不存在学号为%s的学生\n",studentnumber);
} 

////////////////////////保存链表数据到文件
void savelinktofile()
{
	student *p;
	FILE *fp;
	p=headlink->next;
	if(p==NULL)
	{
		printf("现在没有学生信息，请先输入学生信息\n");
		return;
	}
	fp=fopen("student.txt","w+");
/*	if(!fp)
	{
		printf("文件不存在\n");
		return;
	}
*/
	while(p)
	{
		fprintf(fp,"%s %s %s %f %f %f\n",p->studentnumber,p->studentname,p->classname,p->mark1,p->mark2,p->mark3);
		p=p->next;
	}
	fclose(fp);
} 

///////////////////////////显示优秀和不及格学生成绩
void displaymarksegment()
{
	student *p;
	int count=0;
	p=headlink->next;
	printf("60分以下的学生成绩如下：\n");
	printf("学号\t      姓名\t班级   \t成绩1  \t成绩2  \t成绩3  \t总成绩  平均成绩\n");
	while(p)
	{
			if(6>(int)p->mark1/10||6>(int)p->mark2/10||6>(int)p->mark3/10)//一门不及格就算不及格
		{
			count++;
			displayonenode(p);
		}
		p=p->next;
    }
    printf("不及格的学生一共有%d人\n",count);
    p=headlink->next;
    printf("优秀成绩学生如下：\n");
    printf("学号\t      姓名\t班级   \t成绩1  \t成绩2  \t成绩3  \t总成绩  平均成绩\n");
    count=0;
    while(p)
    {
    	if((8<=(int)(p->mark1/10))&&(8<=(int)(p->mark2/10))&&(8<=(int)(p->mark3/10)))
    	{
    		count++;
    		displayonenode(p);
    	}
     p=p->next; 
    	
    }
   	printf("优秀成绩的学生一共有%d人\n",count);	
} 

////////////////////////////////按总成绩排序
void compositorbytotalmark()
{
	student exchange,*r,*p,*q;
	r=headlink->next;
	if(r==NULL)
	{
		printf("现在还没学生信息，请先输入学生信息\n");
		return;
	}
    while(r)//两层while循环实现排序    类似选择排序 
	{
		p=r;
		q=r->next;
		while(q)
		{
			if((q->mark1+q->mark2+q->mark3)>(p->mark1+p->mark2+p->mark3))
			{
				strcpy(exchange.studentnumber,q->studentnumber);//先复制q结点信息岛exchange
				strcpy(exchange.studentname,q->studentname);
				strcpy(exchange.classname,q->classname);
	            exchange.mark1=q->mark1;
				exchange.mark2=q->mark2;
				exchange.mark3=q->mark3;
				
				strcpy(q->studentnumber,p->studentnumber);//再复制p结点信息到q结点
				strcpy(q->studentname,p->studentname);
				strcpy(q->classname,p->classname);
				q->mark1=p->mark1;
				q->mark2=p->mark2;
				q->mark3=p->mark3;
				
				strcpy(p->studentnumber,exchange.studentnumber);//最后复制exchange中信息到p结点	
				strcpy(p->studentname,exchange.studentname);
				strcpy(p->classname,exchange.classname);
				p->mark1=exchange.mark1;
				p->mark2=exchange.mark2;
				p->mark3=exchange.mark3;
					 
			}
			q=q->next;
		}
		r=r->next;
	} 
	outputinformation();
} 

/////////////////////修改授权码
void changepassword()
{
	char qq[20];
	FILE *q;
	i=0;
	//memset(gg,'\0',sizeof(gg[20]));

	printf("请输入新的授权码:");
	while((gg[i]=getch())!='\r')
		{
			putchar('*');
			
			i++;
		} 
	gg[i]='\0';
	i=0;
	printf("请再次输入:");
		while((qq[i]=getch())!='\r')
		{
			putchar('*');
			
			i++;
		} 
	qq[i]='\0';
	if(strcmp(gg,qq)==0)
	{
	    q=fopen("admin.txt","w");
		fprintf(q,"%s",gg);
		printf("修改成功！\n");
		fclose(q);
      //  displaymenu(); 
	}
	else
	printf("修改未成功，两次输入密码不同。\n");
	//displaymenu();
	
} 