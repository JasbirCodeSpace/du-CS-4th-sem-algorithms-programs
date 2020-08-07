#include<iostream>
using namespace std;


void CountSort(int *A,int size){

int range = 100;
int *C = new int[range];

for(int i=0;i<size;i++)
C[A[i]]++;


for(int i=1;i<range;i++)
C[i] = C[i]+C[i-1];

int *B = new int[size+1];
for(int i=size-1;i>=0;--i){
B[C[A[i]]] = A[i];

}

for(int i=0;i<size;i++)
A[i] = B[i+1];

return;
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

CountSort(Arr,size);

cout<<"\nsorted array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

return 0;
}