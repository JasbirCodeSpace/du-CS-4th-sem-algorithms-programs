#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

int swap(int *Arr,int x,int y){
	int temp = Arr[x];
	Arr[x] = Arr[y];
	Arr[y] = temp;
	
}

int Partition(int *Arr,int p,int r){
	int i = p-1;
	int j = p;
	int pivot = Arr[r];
	
	for(j=p;j<r;j++){
		if(Arr[j]<=pivot){
			
			i++;
			swap(Arr,i,j);
		}
		
	}
	
	swap(Arr,i+1,r);
	
	return i+1;
	
}

int Random_Partition(int *Arr,int p,int r){
	int x = rand()%(r+1 - p) + p;
	cout<<"!!!"<<x<<endl;
	swap(Arr,r,x);
	return Partition(Arr,p,r);
	
}



void QuickSort(int *Arr,int p,int r){
	
	if(p<r){
		cout<<"p="<<p<<"r="<<r<<endl;
		int q = Random_Partition(Arr,p,r);
		cout<<"##"<<q<<endl;
		QuickSort(Arr,p,q-1);
		QuickSort(Arr,q+1,r);
	}
	
	
}
int main(){
int size;
cout<<"\nenter the size of array\n";
cin>>size;

int *Arr = new int[size];
for(int i=0;i<size;i++){
Arr[i] = size-i;
}

cout<<"\ninput array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

QuickSort(Arr,0,size-1);

cout<<"\nsorted array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;



return 0;
}