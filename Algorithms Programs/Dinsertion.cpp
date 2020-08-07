#include<iostream>
using namespace std;

template<class T>
class node{
public:
T data;
node<T> *next;
node<T> *previous;
};

template<class T>
class DLList{
private:
node<T> *head,*tail;

public:
DLList(){head=tail=0;}

void insert(T data){
node<T>* temp = new node<T>;

if(head==0){

head =tail = temp;
temp->data = data;
temp->previous=0;
temp->next=0;

}
else{
	
	tail->next = temp;
	temp->data = data;
	temp->previous= tail;
	tail = tail->next;
	temp->next =0;
}



}

void display(){
	
	
	node<T> *temp = new node<T>;
	temp = head;
	
	if(temp!=0){
		
		
		while(temp->next!=0){
			cout<<" "<<temp->data<<" ";
		temp = temp->next;
		}
	}
	cout<<" "<<temp->data<<" ";
	cout<<endl;
}

void sort(){
	
	node<T> *i = new node<T>;
	node<T> *j = new node<T>;
	
	
	if(head!=0){
		
		if(head->next==0)
			return;
	else{	
	i = head->next;
	while(i!=0){
		
		j=i;
		while(j!=0){
			if(j->previous != 0 and j->data < j->previous->data){
				T temp = j->data;
				j->data = j->previous->data;
				j->previous->data = temp;
				
			}
			j = j->previous;
			
		}
		i = i->next;
		
	}
	
	}
	
	}
	
}

};

int main(){

DLList<int> list;

int choice ;

do{


cout<<"\n\n =========== option ========== ";
cout<<"\n(1) insert number";
cout<<"\n(2) show list";
cout<<"\n(3) sort list using insertion";
cout<<"\n(4) exit\n";
cout<<"\nenter choice :: ";

cin>>choice;

switch(choice){

case 1 :   cout<<"\n\n===== input =====\n\n";
           cout<<"enter number :: ";
           int num;
           cin>>num;
           
           list.insert(num);
           break;


case 2 :   cout<<"\n\n===== output =====\n\n";
           cout<<"array :: ";
           list.display();
           cout<<endl;
           
           break;

case 3 :   list.sort();

           break;


case 4 :  cout<<"\n\n===== exit =====\n\n";
          cout<<"exiting .....\n";
          exit(0); 




}

}while(true);










return 0;

}
