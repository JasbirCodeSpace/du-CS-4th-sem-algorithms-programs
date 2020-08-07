#include<iostream>

using namespace std;

int Maximum(int *Arr,int n){
int max = Arr[0];
for(int i=1;i<n;i++){
 if(Arr[i]>max)
 max = Arr[i];
}

return max;
}

void CountSort(int *Arr,int n,int exp){

int B[n];
int C[10]={0};

for(int i=0;i<n;i++)
C[(Arr[i]/exp)%10]++;

for(int i=1;i<n;i++)
C[i]+=C[i-1];

for(int i=n-1;i>=0;i--){
B[C[(Arr[i]/exp)%10]-1] = Arr[i];
C[(Arr[i]/exp)%10]--;

}

for(int i=0;i<n;i++)
	Arr[i] = B[i];



}


void RadixSort(int *Arr,int n){

int max = Maximum(Arr,n);
for(int exp=1;max/exp>0;exp*=10)
CountSort(Arr,n,exp);


}
int main(){
int size;
cout<<"\nenter the size of array\n";
cin>>size;

int *Arr = new int[size];
for(int i=0;i<size;i++){
Arr[i] = (size-i)*(10-i);
}

cout<<"\ninput array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

RadixSort(Arr,size);

cout<<"\nsorted array :: ";
for(int i=0;i<size;i++){
cout<<Arr[i]<<" ";
}
cout<<endl;

return 0;


}