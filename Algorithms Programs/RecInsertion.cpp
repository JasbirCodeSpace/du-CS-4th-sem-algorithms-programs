#include<iostream>

using namespace std;

int swap(int *Arr,int x,int y){

int temp = Arr[x];
Arr[x]  = Arr[y];
Arr[y] = temp;
}

void InsertionSort(int *Arr,int size,int i){

if(i<size){
for(int j=i;j>0;j--){

if(Arr[j]<Arr[j-1])
swap(Arr,j,j-1);
}

return InsertionSort(Arr,size,++i);
}



}

int main(){



        int size;
	cout<<"\nenter the size of\n";
	cin>>size;

     int temp = size;

        int arr[size];
        for(int i=0;i<size;i++){

          arr[i] = temp;

           temp--;

        }


        cout<<"\n the given array is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }


        InsertionSort(arr,size,1);

         cout<<"\n\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
        
       // cout<<"\n total number of swap : "<<noOfSwap<<endl;
       // cout<<"\n total number of comparisons : "<<noOfComparison<<endl;
        
	return 0;

}


