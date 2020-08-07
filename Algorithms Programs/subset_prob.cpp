#include<iostream>
using namespace std;

int arr[10][20];
int *items;
int n,w;

int subset(int i,int w)
{
	//cout<<"\n"<<i<<" "<<w;
	if(i==0||w<=0)
   		arr[i][w]=0;
	//if(arr[i][w]!=-1)
	//	return arr[i][w];
	else
	if(items[i]>w)
		arr[i][w]=subset(i-1,w);
	else
		arr[i][w]=max(subset(i-1,w),items[i]+subset(i-1,w-items[i])); 		

	return arr[i][w];
}

int max(int a ,int b)
{
	if(a>b)
	return a;
	
	return b;
}


void output()
{
	cout<<"\n\t\t";
	for(int i=0;i<=w;i++)
		cout<<i<<"  ";
	for(int i=0;i<=n;i++)
	{
		cout<<"\n\t"<<i<<"       ";	
		for(int j=0;j<=w;j++)
		  cout<<arr[i][j]<<"  ";
	}
	
	int i=n,j=w;
	while(i!=0 && w!=0)
	{
		if(arr[i][w]==arr[i-1][w])
			i--;
		else
		{ 
			cout<<"\nItem "<<i<<"\t"<<items[i];
			w=w-items[i];
			i--;
		}	
	}	
}

void input()
{
	cout<<"\nEnter the total number of items :";
	cin>>n;
	items=new int[n+1];
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the weight of item "<<i+1<<":";
		cin>>items[i+1];
	}
	
	cout<<"\nEnter the weight constrained factor:";
	cin>>w;
	//arr=new int*[n+1];
	//for(int i=0;i<n;i++)
	 //arr[i]=new int[w+1];	
	
	for(int i=0;i<=n;i++)
	 for(int j=0;j<=w;j++)
	 	arr[i][j]=0;
	cout<<"\nItems selected";	 
	cout<<"\nMax weight:"<<subset(n,w);
	output();	  
	
}

int main()
{
	input();
	
}
