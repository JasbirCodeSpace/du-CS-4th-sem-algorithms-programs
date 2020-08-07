#include<iostream>
using namespace std;

int BinarySearch(int *Arr,int low ,int high,int target){

if(low==high)
return low;

int mid = (low+high)/2;

if(Arr[mid]==target)
return mid;

else if(Arr[mid]>target)
return BinarySearch(Arr,low,mid,target);

else
return BinarySearch(Arr,mid+1,high,target);

}

void InsertionSort(int *Arr,int size){

for(int i=1;i<size;i++){

int bin = BinarySearch(Arr,0,i,Arr[i]);

if(bin<i){
	int temp = Arr[i];
for(int j=i-1;j>=0;j--){

Arr[j+1] = Arr[j];

}

Arr[bin] = temp;

}

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


        InsertionSort(arr,size);

         cout<<"\n the given array after applying insertion sort is:";
         for(int i=0;i<size;i++){
          cout<<arr[i]<<" ";

        }
	return 0;

}