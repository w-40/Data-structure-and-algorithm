#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<cstdio> 
using namespace std;

struct people 
{
	int n;
	int stack[100];//�洢��Ŀ��� 
	people()
	{
		n=0;
	}
};//����

struct message
{
	int n;
	string name[100];
	message()
	{
		n=0;
	}	
};//ѧ����Ϣ 
map<string,people> in;//��map�洢ѧ����Ϣ 
message program[100];//ÿ��ѧ������Ŀ
void Input(int j)//����
{
	string name; 
	printf("�����%d��ѧ�����ƣ�",j+1);
	cin>>name;
	cout<<"����μӵ���Ŀ��"<<endl;
	cin>>in[name].n;
	for(int i=0;i<in[name].n;i++)
	{
		int x;
		printf("�����%d����Ŀ��",i+1);
		cin>>x;
		in[name].stack[i]=x;
		program[x].name[program[x].n++]=name;
	}
}

void Print()//��� 
{
	string name;
	cin>>name;
	for(int i=0;i<in[name].n;i++)
	{
		
		int x=in[name].stack[i];
		if(program[x].n<=1) continue;
		printf("��Ŀ%d���ѣ�",x);
		for(int i1=0;i1<program[x].n;i1++)
		{
			if(program[x].name[i1]!=name)
			{
				cout<<program[x].name[i1]<<" ";
			}
			cout<<endl;
		}
	}
}

int main()
{
	int i,n,flag;
	while(1)
	{
		printf("\n\n"); 
		printf("\t\t ������+����ѧ����Ϣ����ϵͳ\n");
		printf("\t\t==========================\n"); 
		printf("\t\t1--���ѧ����������Ŀ��Ϣ\n"); 		
		printf("\t\t2--��ѯѧ����Ŀ�Լ�����\n"); 
		printf("\t\t3--�˳�\n"); 
		printf("\t\t==========================\n"); 
		printf("��ѡ��Ҫ���еĲ�����");
		cin>>flag;
		switch(flag)
		{
			case 1:
				cout<<"������Ҫ�����ѧ����"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					Input(i);
				}
				break;
			case 2:
				cout<<"����Ҫ��ѯѧ��������"<<endl; 
				Print();
				break;
			default:
				printf("û������Ҫ�Ĺ���\n");
		}
		system("pause");
	}	
	return 0;
} 

