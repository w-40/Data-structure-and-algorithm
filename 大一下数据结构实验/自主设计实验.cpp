#include<iostream>
#include<cstdlib>
#include<string>
#include<map>
#include<cstdio> 
using namespace std;

struct people 
{
	int n;
	int stack[100];//存储项目编号 
	people()
	{
		n=0;
	}
};//姓名

struct message
{
	int n;
	string name[100];
	message()
	{
		n=0;
	}	
};//学生信息 
map<string,people> in;//用map存储学生信息 
message program[100];//每个学生的项目
void Input(int j)//输入
{
	string name; 
	printf("输入第%d个学生名称：",j+1);
	cin>>name;
	cout<<"输入参加的项目数"<<endl;
	cin>>in[name].n;
	for(int i=0;i<in[name].n;i++)
	{
		int x;
		printf("输入第%d个项目：",i+1);
		cin>>x;
		in[name].stack[i]=x;
		program[x].name[program[x].n++]=name;
	}
}

void Print()//输出 
{
	string name;
	cin>>name;
	for(int i=0;i<in[name].n;i++)
	{
		
		int x=in[name].stack[i];
		if(program[x].n<=1) continue;
		printf("项目%d队友：",x);
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
		printf("\t\t 互联网+大赛学生信息管理系统\n");
		printf("\t\t==========================\n"); 
		printf("\t\t1--添加学生姓名与项目信息\n"); 		
		printf("\t\t2--查询学生项目以及队友\n"); 
		printf("\t\t3--退出\n"); 
		printf("\t\t==========================\n"); 
		printf("请选择要进行的操作：");
		cin>>flag;
		switch(flag)
		{
			case 1:
				cout<<"请输入要存入的学生数"<<endl;
				cin>>n;
				for(i=0;i<n;i++)
				{
					Input(i);
				}
				break;
			case 2:
				cout<<"输入要查询学生的名字"<<endl; 
				Print();
				break;
			default:
				printf("没有您想要的功能\n");
		}
		system("pause");
	}	
	return 0;
} 

