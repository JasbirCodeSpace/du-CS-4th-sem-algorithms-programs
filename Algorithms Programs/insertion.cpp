#include<iostream>
using namespace std;

void swap(int *Arr,int x,int y){

int temp = Arr[x];
Arr[x] = Arr[y];
Arr[y] = temp;
}


void InsertionSort(int *Arr,int size){

for(int i=1;i<size;i++){
 for(int j=i;j>0;j--){
   if(Arr[j]<Arr[j-1])
    swap(Arr,j,j-1);
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

InsertionSort(Arr,size);

cout<<"\nsorted array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

return 0;

}