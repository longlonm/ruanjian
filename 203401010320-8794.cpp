#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;

typedef struct Node
{
	char name[10];
	char start[10];
	char arrive[10];
	char banqi[10];
	char time1[10];
	char time2[10];
	char mode[10];
	int price;
	struct Node*next;
}node;

int work();                     //操作菜单
Node* paixu(Node *head);        //根据航班号排序
void shanchu(Node *head);       //删除指定航班信息
void hangbanhao(Node *head);    //航班号查询
void qidianzhan(Node *head);    //起点站查询
void daodazhan(Node *head);     //终点站查询
void banqi(Node *head);         //班期查询
void qifeishijian(Node *head);  //起飞时间查询
void daodashijian(Node *head);  //到达时间查询
void output(Node *head);        //显示航班信息
Node* input();                  //输入航班信息

int work()
{
	Node *head;
	while(1)
	{
		printf("          欢迎使用航班信息查询与检索系统       \n");
		printf("          1.读入数据        2.删除数据         \n");
		printf("          3.航班号查询      4.起点站查询       \n");
		printf("          5.到达站查询      6.班期查询         \n");
		printf("          7.起飞时间查询    8.到达时间查询     \n");
		printf("          9.显示所有数据    10.退出程序        \n");
		printf("               请选择将要使用的功能            \n");
		int t;

		cin>>t;
		switch(t)
		{
		case 1:
			{
				head = input();
				system("cls");
				cout<<"成功录入信息"<<endl;
				break;
			}
		case 2:
			{
				cout<<"请输入要删除的航班号:";
				shanchu(head);
				break;
			}
		case 3:
			{
				system("cls");
				output(head);
				cout<<"请输入航班号:";
				hangbanhao(head);
				break;
			}
		case 4:
			{
				system("cls");
				output(head);
				cout<<"请输入起点站:";
				qidianzhan(head);
				break;
			}
		case 5:
			{
				system("cls");
				output(head);
				cout<<"请输入终点站:";
				daodazhan(head);
				break;
			}
		case 6:
			{
				system("cls");
				output(head);
				cout<<"请输入班期:";
				banqi(head);
				break;
			}
		case 7:
			{
				system("cls");
				output(head);
				cout<<"请输入起飞时间:";
				qifeishijian(head);
				break;
			}
		case 8:
			{
				system("cls");
				output(head);
				cout<<"请输入到达时间";
				daodashijian(head);
				break;
			}
		case 9:
			{
				output(head);
				break;
			}
		case 10:
			{
				cout<<"程序结束";
				return 0;
				break;
			}
		default:
			{
				cout<<"错误输入，请重试"<<endl;
				break;
			}
		}
	}
	return 0;
}

Node *input()
{
	struct Node*head=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	struct Node*p1=NULL;
	struct Node*p2=head;
	int i;
	while(1)
	{
		p1=(struct Node*)malloc(sizeof(struct Node));
		p1->next=NULL;
		cout<<"请输入航班号:";
		cin>>p1->name;
		cout<<"\n请输入起点站:";
		cin>>p1->start;
		cout<<"\n请输入终点站:";
		cin>>p1->arrive;
		cout<<"\n请输入班期:";
		cin>>p1->banqi;
		cout<<"\n请输入起飞时间:";
		cin>>p1->time1;
		cout<<"\n请输入到达时间:";
		cin>>p1->time2;
		cout<<"\n请输入机型:";
		cin>>p1->mode;
		cout<<"\n请输入票价:";
		cin>>p1->price;
		p2->next=p1;
		p2=p1;
		cout<<"\n退出请输入0/继续输入请输入1\n";
		cin>>i;
		if(i==0)
			break;
	}
	return head;
}

Node* paixu(Node *head)
{
	Node *p=head->next,*pre,*r=p->next;
	p->next=NULL;
	p=r;
	while(p)
	{
		r=p->next;
		pre=head;
		while(pre->next&&strcmp(pre->next->name,p->name)<0)
			pre=pre->next;
		p->next=pre->next;
		pre->next=p;
		p=r;
	}
	return head;
}

void output(Node *head)
{
	system("cls");
	Node *temp;
	temp=paixu(head);
	struct Node*p=temp->next;
	if(temp==NULL)return;
	printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
	while(p!=NULL)
	{
		printf("%s   %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
		p=p->next;
	}
}

void shanchu(Node *head)
{
	system("cls");
	output(head);
	char no[10];
	struct Node*p1=head->next;
	struct Node*p2=head;
	scanf("%s",no);
	int flag=0;
	while(p1!=NULL)
	{
		if(strcmp(p1->name,no)==0)
		{
			p2->next=p1->next;
			p1=p2->next;
			flag=1;
			break;
		}
		
	}
		if(flag==1)
		{
			printf("删除成功！\n");
			return;
		} 
		if(flag==0)
		printf("未找到需要删除的材料"); 
}

void hangbanhao(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->name,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该航班号相关信息\n");
}
void qidianzhan(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->start,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该起点站相关信息\n");
}
void daodazhan(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->arrive,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该终点站相关信息\n");
}
void banqi(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->banqi,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该班期相关信息\n");
}

void qifeishijian(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->time1,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该起飞时间相关信息\n");
}

void daodashijian(Node *head)
{
	struct Node*p=head;
	int flag=0;
	char no[10];
	scanf("%s",no);
	for(p;p!=NULL;p=p->next)
	{
		if(strcmp(p->time2,no)==0)
		{
			printf("航班号 起点站 终点站 班期 起飞时间 到达时间 机型 票价\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("未查询到该到达时间相关信息\n");
}


int main()
{
	work();
	return 0;
}