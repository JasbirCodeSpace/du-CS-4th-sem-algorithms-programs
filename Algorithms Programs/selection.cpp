#include<iostream>
using namespace std;


void swap(int *Arr,int x,int y){

int temp = Arr[x];
Arr[x] = Arr[y];
Arr[y] = temp;
}


void SelectionSort(int *Arr,int size){

int minIndex;
for(int i=0;i<size-1;i++){
minIndex=i;
for(int j=i+1;j<size;j++){
 if(Arr[j] < Arr[minIndex]){
   swap(Arr,j,minIndex);
 
 }

}

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

SelectionSort(Arr,size);

cout<<"\nsorted array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

return 0;

}