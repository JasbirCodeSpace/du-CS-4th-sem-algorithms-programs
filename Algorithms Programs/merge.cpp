#include<iostream>

using namespace std;

void merge(int *Arr,int l,int m,int r){

int i,j,k;

int num1 = m-l+1;
int num2 = r-m;

int L[num1],R[num2];

for(i=0;i<num1;i++)
L[i] = Arr[l+i];

for(j=0;j<num2;j++)
R[j] = Arr[m+j+1];


i=j=0;
k=l;

while(i<num1 and j<num2){
  if(L[i] <= R[j]){
    Arr[k++] = L[i++];
  
  }
  
  else
    Arr[k++] = R[j++];

}

while(i<num1){
  
    Arr[k++] = L[i++];
  
  }
  
  while(j<num2){
  
    Arr[k++] = R[j++];
  
  }

}


void MergeSort(int *Arr,int p,int r){

if(p<r){

int m = p+(r-p)/2;
MergeSort(Arr,p,m);
MergeSort(Arr,m+1,r);
merge(Arr,p,m,r);



}



}


int main(){



        int size;
	cout<<"\nenter the size of\n";
	cin>>size;

        int arr[size];


        int temp = size;


        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }

        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        MergeSort(arr,0,size-1);

         cout<<"\n the given array after applying merge sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}


