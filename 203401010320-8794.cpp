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

int work();                     //�����˵�
Node* paixu(Node *head);        //���ݺ��������
void shanchu(Node *head);       //ɾ��ָ��������Ϣ
void hangbanhao(Node *head);    //����Ų�ѯ
void qidianzhan(Node *head);    //���վ��ѯ
void daodazhan(Node *head);     //�յ�վ��ѯ
void banqi(Node *head);         //���ڲ�ѯ
void qifeishijian(Node *head);  //���ʱ���ѯ
void daodashijian(Node *head);  //����ʱ���ѯ
void output(Node *head);        //��ʾ������Ϣ
Node* input();                  //���뺽����Ϣ

int work()
{
	Node *head;
	while(1)
	{
		printf("          ��ӭʹ�ú�����Ϣ��ѯ�����ϵͳ       \n");
		printf("          1.��������        2.ɾ������         \n");
		printf("          3.����Ų�ѯ      4.���վ��ѯ       \n");
		printf("          5.����վ��ѯ      6.���ڲ�ѯ         \n");
		printf("          7.���ʱ���ѯ    8.����ʱ���ѯ     \n");
		printf("          9.��ʾ��������    10.�˳�����        \n");
		printf("               ��ѡ��Ҫʹ�õĹ���            \n");
		int t;

		cin>>t;
		switch(t)
		{
		case 1:
			{
				head = input();
				system("cls");
				cout<<"�ɹ�¼����Ϣ"<<endl;
				break;
			}
		case 2:
			{
				cout<<"������Ҫɾ���ĺ����:";
				shanchu(head);
				break;
			}
		case 3:
			{
				system("cls");
				output(head);
				cout<<"�����뺽���:";
				hangbanhao(head);
				break;
			}
		case 4:
			{
				system("cls");
				output(head);
				cout<<"���������վ:";
				qidianzhan(head);
				break;
			}
		case 5:
			{
				system("cls");
				output(head);
				cout<<"�������յ�վ:";
				daodazhan(head);
				break;
			}
		case 6:
			{
				system("cls");
				output(head);
				cout<<"���������:";
				banqi(head);
				break;
			}
		case 7:
			{
				system("cls");
				output(head);
				cout<<"���������ʱ��:";
				qifeishijian(head);
				break;
			}
		case 8:
			{
				system("cls");
				output(head);
				cout<<"�����뵽��ʱ��";
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
				cout<<"�������";
				return 0;
				break;
			}
		default:
			{
				cout<<"�������룬������"<<endl;
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
		cout<<"�����뺽���:";
		cin>>p1->name;
		cout<<"\n���������վ:";
		cin>>p1->start;
		cout<<"\n�������յ�վ:";
		cin>>p1->arrive;
		cout<<"\n���������:";
		cin>>p1->banqi;
		cout<<"\n���������ʱ��:";
		cin>>p1->time1;
		cout<<"\n�����뵽��ʱ��:";
		cin>>p1->time2;
		cout<<"\n���������:";
		cin>>p1->mode;
		cout<<"\n������Ʊ��:";
		cin>>p1->price;
		p2->next=p1;
		p2=p1;
		cout<<"\n�˳�������0/��������������1\n";
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
	printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
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
			printf("ɾ���ɹ���\n");
			return;
		} 
		if(flag==0)
		printf("δ�ҵ���Ҫɾ���Ĳ���"); 
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ���ú���������Ϣ\n");
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ�������վ�����Ϣ\n");
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ�����յ�վ�����Ϣ\n");
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ���ð��������Ϣ\n");
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ�������ʱ�������Ϣ\n");
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
			printf("����� ���վ �յ�վ ���� ���ʱ�� ����ʱ�� ���� Ʊ��\n");
			printf("%s %s %s %s %s %s %s %d\n",p->name,p->start,p->arrive,p->banqi,p->time1,p->time2,p->mode,p->price);
			flag=1;
		}
	}
	if(flag==0)
		printf("δ��ѯ���õ���ʱ�������Ϣ\n");
}


int main()
{
	work();
	return 0;
}