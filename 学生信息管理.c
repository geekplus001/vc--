#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<windows.h>

typedef struct student 

{
	
	char studentnumber[20];//ѧ��ѧ��
	char studentname[20];//ѧ������
	char classname[20];//�༶����
	float mark1;//��һ�ųɼ�
	float mark2;//�ڶ��ųɼ�
	float mark3;//�����ųɼ�
	struct student *next;
	 
}student;
//struct student student;

student *headlink;//�����ͷָ��
int i=0;
char gg[20];

//�������� 
student *mallocnode(); //����һ���½ڵ㲢��ʼ��
void createheadlink();//���������ͷ
void readinformationfile();//���ļ��ж�ѧ����Ϣ
void gotoxy (int x,int y);//�ƶ���� 
void setadministrator();//������Ȩ��
void changepassword(); 
void displaymenu();//��ʾ�˵�
void getinformation(student*t);//Ҫ���û�����ѧ����Ϣ
void outputinformation();//��ʾ����ѧ����Ϣ 
void displayinformationbystudentname();//����������ʾѧ����Ϣ
void displayinformationbystudentnumber();//����ѧ����ʾѧ����Ϣ
void deletenodebystudentnumber();//����ѧ��ɾ��ѧ����Ϣ
void changemarkbystudentname();//���������޸�ѧ���ɼ�
void changemarkbystudentnumber();//����ѧ�Ÿ�ѧ���ɼ�
void displaymarksegment();//��ʾ��������ѧ���ɼ�

void displayonenode(student * t);//���һ���ڵ�ѧ����Ϣ
void insertonenode(student *t);// ����һ���½ڵ�
void savelinktofile();//�������ݺ��˳�
void compositorbytotalmark();//���ܳɼ�����
int choose;//�û�����


//������
main()
{
	createheadlink();//���������ͷ 
	readinformationfile();// ���ļ��ж�ѧ����Ϣ 
    setadministrator();//
	displaymenu();//��ʾ�˵��������û����������Ӧ�Ĺ��� 
} 

 /////////////////////���������ͷ
 void createheadlink()
 {
 	student *p;
 	p=(student*)malloc(sizeof(student));
 	headlink=p;
 	p->next=NULL;
 }
 
 ////////////////////���ļ��ж�ѧ����Ϣ
 void readinformationfile()
 {
 	FILE *fp;
 	student *p;
 	fp=fopen("student.txt","r");
 	if(!fp)
 	{
 		printf("�ļ�������\n");
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
 
 ///////////////////////�����˻�����~~
 void setadministrator()
 {
 	int flag=0,t=2;
 	char ad[20],password[20],ss[20];
 	 
 	FILE *p,*q;

    system("color fd");
    printf("\n\n\n\n\n\n                    �����������������������\n");
 	printf("                    ��   ��ӭʹ����԰19-403ѧ����Ϣ����ϵͳ   ��\n");
 	printf("                    �����������������������\n");
 	/*gotoxy(20,8);
        printf("Press any key to continue~~");*/
    while(!kbhit())//��˸ 
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
 	printf("��������Ȩ�a:");
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
		    printf("����Ѿ�ȷ�ϣ������Ȩ��\n"); 
		    Sleep(1500);
		}
		else
		{
			gotoxy(20,8);
			printf("\a\aWarning:���δȷ��!" );
			gotoxy(20,9);
			printf("�㻹��%d�λ��ᣡ",t);
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
 		printf("�����˻����봴����\n")�� 
 		printf("�봴���˺ţ�");
 		scanf("%s",ad);
 		printf("���������룺")�� 
 		i=0;
		while(getch()!='\r')
		{
			putchar("*");
			password[i]=getch();
			i++;
		} 
		fprintf(p,"%s %s",ad,password);
		printf("�����ɹ���\n"); 
 	}
    if(flag==0)
    {
    	printf("�������˺ţ�"); 
    }*/
 	
 } 
 
/////////////////////////�ƶ���� 
void gotoxy (int x,int y)
{
	COORD pos={x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
 
 //////////////////////��ʾ�˵��������û����������Ӧ�Ĺ���
 void displaymenu()
 {
 	student *p;
    system("color 5e");
   /* HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN);*/
 	printf("                    ********��ѡ����Ӧ�Ĺ���********\n");
	printf("                    1  ��ʾ����ѧ����Ϣ\n");
	printf("                    2  ��������ѯѧ����Ϣ\n");
	printf("                    3  ��ѧ�Ų�ѯѧ����Ϣ\n");
	printf("                    4  ����ѧ����Ϣ\n");
	printf("                    5  ɾ��ѧ����Ϣ\n");
	printf("                    6  �������޸�ѧ���ɼ�\n");
	printf("                    7  ��ѧ���޸�ѧ���ɼ�\n");
	printf("                    8  ��������ѧ����Ϣ\n");
	printf("                    9  ��ʾ����Ͳ�����ѧ���ɼ�\n");
	printf("                    10 ������������ɼ�\n");
	printf("                    11 �˳�����\n");
	printf("                    12 �޸�����\n"); 
	scanf("%d",&choose);//�û�ѡ��
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
    displaymenu();//�ݹ���� 
 } 
 
 ///////////////////�����µĽ�㲢��ʼ��
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
 
 /////////////////��ȡѧ����Ϣ
 void getinformation(student *t)
 {
 	printf("������ѧ��ѧ�ţ�\n");
 	scanf("%s",t->studentnumber);
 	printf("������ѧ��������\n");
 	scanf("%s",t->studentname);
 	printf("������ѧ�����ڰ༶��\n");
 	scanf("%s",t->classname);
 	printf("�������һ�ųɼ���\n");
 	scanf("%f",&t->mark1);
 	printf("������ڶ��ųɼ���\n");
 	scanf("%f",&t->mark2);
 	printf("����������ųɼ���\n");
 	scanf("%f",&t->mark3);
 	
 } 
 
 ////////////////////////��ʾ����ѧ����Ϣ
void outputinformation()
{
	student *p;
	p=headlink->next;
	if(p==NULL)
	{
		printf("����û��ѧ����Ϣ����������ѧ����Ϣ��\n");
		return;
	}
	printf("ѧ��\t      ����\t�༶   \t�ɼ�1  \t�ɼ�2  \t�ɼ�3  \t�ܳɼ�  ƽ���ɼ�\n");
	while(p)
	{
		displayonenode(p);
		p=p->next;
	}
} 

 
 //////////////////�������β���һ�����
 void insertonenode(student *t)
 {
 	student *p;
 	p=headlink;
 	while(p->next)
 	   p=p->next;
    p->next=t;
 } 
 
 //////////////////����ѧ��������ʾѧ����Ϣ
 void displayinformationbystudentname()
 {
 	student *p;
 	char studentname[20];
	 int flag=0;
	 p=headlink->next;
	 printf("������ѧ��������\n");
	 scanf("%s",studentname);
	 while(p)
	 {
	 	if(strcmp(p->studentname,studentname)==0)
	 	{
	 		printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
	 		displayonenode(p);
	        flag=1;
	        
	 		break;
	 	}
	 	p=p->next;
	 	
	 }
	 if(!flag)
	 printf("�Բ��𣬲���������Ϊ%s��ѧ��\n",studentname);
 } 
 
 //////////////////////����ѧ����ʾѧ����Ϣ
 void displayinformationbystudentnumber()
 {
 	student *p;
 	char studentnumber[20];
 	int flag=0;
 	p=headlink->next;
 	printf("������ѧ��ѧ�ţ�\n");
 	scanf("%s",studentnumber);
 	while(p)
 	{
 		if(strcmp(p->studentnumber,studentnumber)==0)
 		{
 			printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�2\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n");
 			displayonenode(p);
            flag=1;		
 			break;
 		}
 		p=p->next;
 	}
 	if(!flag)
 	printf("�Բ��𣬲�����ѧ��Ϊ%s��ѧ��\n");
 } 
 
 //////////////////////////���һ��������Ϣ
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

/////////////////////////����ѧ��ɾ��ѧ����Ϣ
void deletenodebystudentnumber()
{
	char studentnumber[20];
	student *p,*q;
	int flag=0;
	printf("������Ҫɾ����ѧ��ѧ�ţ�");
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
		printf("�����ڸ�ѧ�ŵ�ѧ��\n");
		return;
		
	}
	printf("�ɹ�ɾ��\n");
} 


////////////////////////////���������޸ĳɼ�
void changemarkbystudentname()
{
	student *p;
	char studentname[20];
	int flag=0;
	float mark1,mark2,mark3;
	p=headlink->next;
	printf("������ѧ��������\n");
	scanf("%s",studentname);
	while(p)
	{
		if(strcmp(p->studentname,studentname)==0)
		{
			printf("�������µĵ�һ�ųɼ���\n");
			scanf("%f",&mark1);
			printf("�������µĵڶ��ųɼ���\n");
			scanf("%f",&mark2);
			printf("�������µĵ����ųɼ���\n");
			scanf("%f",&mark3);
			p->mark1=mark1;
			p->mark2=mark2;
			p->mark3=mark3;
			printf("�޸ĳɹ�\n");
			flag=1;
			break;
		}
		p=p->next;
	
	}
		if(!flag)
     	printf("�Բ��𣬲���������Ϊ%s��ѧ��\n",studentname);
   
} 

////////////////////////����ѧ���޸ĳɼ�
void changemarkbystudentnumber()
{
	student *p;
	char studentnumber[20];
	int flag=0;
	float mark1,mark2,mark3;
	p=headlink->next;
	printf("������ѧ��ѧ�ţ�\n");
	scanf("%s",studentnumber);
	while(p)
	{
		if(strcmp(p->studentnumber,studentnumber)==0)
		{
			printf("�������µĵ�һ�ųɼ���\n");
			scanf("%f",&mark1);
			printf("�������µĵڶ��ųɼ���\n");
			scanf("%f",&mark2);
			printf("�������µĵ����ųɼ�:\n");
			scanf("%f",&mark3);
			p->mark1=mark1;
			p->mark2=mark2;
			p->mark3=mark3;
			printf("�޸ĳɹ�\n");
			flag=1;
			break;
		}
		p=p->next;
	}
	if(!flag)
	printf("�Բ��𣬲�����ѧ��Ϊ%s��ѧ��\n",studentnumber);
} 

////////////////////////�����������ݵ��ļ�
void savelinktofile()
{
	student *p;
	FILE *fp;
	p=headlink->next;
	if(p==NULL)
	{
		printf("����û��ѧ����Ϣ����������ѧ����Ϣ\n");
		return;
	}
	fp=fopen("student.txt","w+");
/*	if(!fp)
	{
		printf("�ļ�������\n");
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

///////////////////////////��ʾ����Ͳ�����ѧ���ɼ�
void displaymarksegment()
{
	student *p;
	int count=0;
	p=headlink->next;
	printf("60�����µ�ѧ���ɼ����£�\n");
	printf("ѧ��\t      ����\t�༶   \t�ɼ�1  \t�ɼ�2  \t�ɼ�3  \t�ܳɼ�  ƽ���ɼ�\n");
	while(p)
	{
			if(6>(int)p->mark1/10||6>(int)p->mark2/10||6>(int)p->mark3/10)//һ�Ų�������㲻����
		{
			count++;
			displayonenode(p);
		}
		p=p->next;
    }
    printf("�������ѧ��һ����%d��\n",count);
    p=headlink->next;
    printf("����ɼ�ѧ�����£�\n");
    printf("ѧ��\t      ����\t�༶   \t�ɼ�1  \t�ɼ�2  \t�ɼ�3  \t�ܳɼ�  ƽ���ɼ�\n");
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
   	printf("����ɼ���ѧ��һ����%d��\n",count);	
} 

////////////////////////////////���ܳɼ�����
void compositorbytotalmark()
{
	student exchange,*r,*p,*q;
	r=headlink->next;
	if(r==NULL)
	{
		printf("���ڻ�ûѧ����Ϣ����������ѧ����Ϣ\n");
		return;
	}
    while(r)//����whileѭ��ʵ������    ����ѡ������ 
	{
		p=r;
		q=r->next;
		while(q)
		{
			if((q->mark1+q->mark2+q->mark3)>(p->mark1+p->mark2+p->mark3))
			{
				strcpy(exchange.studentnumber,q->studentnumber);//�ȸ���q�����Ϣ��exchange
				strcpy(exchange.studentname,q->studentname);
				strcpy(exchange.classname,q->classname);
	            exchange.mark1=q->mark1;
				exchange.mark2=q->mark2;
				exchange.mark3=q->mark3;
				
				strcpy(q->studentnumber,p->studentnumber);//�ٸ���p�����Ϣ��q���
				strcpy(q->studentname,p->studentname);
				strcpy(q->classname,p->classname);
				q->mark1=p->mark1;
				q->mark2=p->mark2;
				q->mark3=p->mark3;
				
				strcpy(p->studentnumber,exchange.studentnumber);//�����exchange����Ϣ��p���	
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

/////////////////////�޸���Ȩ��
void changepassword()
{
	char qq[20];
	FILE *q;
	i=0;
	//memset(gg,'\0',sizeof(gg[20]));

	printf("�������µ���Ȩ��:");
	while((gg[i]=getch())!='\r')
		{
			putchar('*');
			
			i++;
		} 
	gg[i]='\0';
	i=0;
	printf("���ٴ�����:");
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
		printf("�޸ĳɹ���\n");
		fclose(q);
      //  displaymenu(); 
	}
	else
	printf("�޸�δ�ɹ��������������벻ͬ��\n");
	//displaymenu();
	
} 