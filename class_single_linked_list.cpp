#include<iostream>
using namespace std;

class node{
	public:
		 int data;
		 node *next;
		 //default constructor
		 node(){
		 	next=NULL;
		 	}
		 
		 
		};
class list{
	public:
		node * head;
		
		void initializer(){
			head=NULL;
			}

		void add_at_pos(int n, int pos){
			if(head==NULL){
				if(pos==1){
					node *p=new node();
					p->data=n;
					p->next=NULL;
					head=p;
					}
				else{
					cout<<"List is empty. Not able to add at position "<<pos<<endl;
					}
				}
			else{
				if(pos==1){
					node *temp=head;
					node *p=new node();
					p->data=n;
					p->next=temp;
					head=p;
					temp=head;
					}
				else{
					node *temp=head;
					int count=0;
					while(temp!=NULL){
						temp=temp->next;
						count=count+1;
						}
					if(pos>(count+1) || pos<=0){
						cout<<"Not able to add at position "<<pos<<endl;
						}
					else{
						temp=head;
						//a temporary pointer have to be reached to the pos-1 node.
						for(int j=1;j<=pos-2;j++){
							temp=temp->next;
							}
						node *p=new node();
						p->data=n;
						//temp->next can be NULL ? so dangling pointer will happen? 
						if(temp->next==NULL){
							p->next=NULL;
							}
						else{
							p->next=temp->next;
							}
						temp->next=p;
					}
				}
			}
		}

		void del_at_pos(int pos){
			if(head==NULL){
				cout<<"List is empty. Not able to delete from position "<<pos<<endl;
				}
			else{
				node *temp=head;
				if(pos==1){
					node *q=head;
					head=head->next;
					delete q;
					}
				else{
					temp=head;
					int count=0;
					while(temp!=NULL){
						temp=temp->next;
						count=count+1;
						}
					if(pos>(count) || pos<=0){
						cout<<"Not able to delete from position "<<pos<<endl;
						}
					else{
						temp=head;
						//a temporary pointer have to be reached to the pos-1 node.
						for(int j=1;j<=pos-2;j++){
							temp=temp->next;
							}
						node *q=temp->next;
						temp->next=q->next;
						delete q;
				
					}
				}
			}
		}

		void display(){
			if(head==NULL){
				cout<<"List is empty."<<endl;
				}
			else{
				node *temp=head;
				while(temp!=NULL){
					cout<<temp->data<<" ";
					temp=temp->next;
					}
				}
			}

		void val_at_pos(int pos){
			if(head==NULL){
				cout<<"List is empty."<<endl;
				}
			else{
				node *temp=head;
				int count=0;
					while(temp!=NULL){
						temp=temp->next;
						count=count+1;
						}
					if(pos>(count) || pos<=0){
						cout<<"Invalid position "<<endl;
						}
					else{
						temp=head;
						//a temporary pointer have to be reached to position pos.
						for(int j=1;j<=pos-1;j++){
							temp=temp->next;
							}
						cout<<"Value at position "<<pos<<" is "<<temp->data<<endl;
						}
					}
				}			
	};
	
	
int main(){
	//have to write a menu driven program.
	int ch,n,i;
	//have to create object of the class and access methods.
	list mylist;
	mylist.initializer();
	while(1){
		cout<<"\n Enter the choice:\n 1. add at position \n 2. delete from position \n 3. value at position \n 4. display \n 5. Exit \n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element to be inserted";
				cin>>n;
				cout<<"\n Enter the position";
				cin>>i;
				mylist.add_at_pos(n, i);
				break;
			case 2: cout<<"\n Enter the position";
				cin>>i;
				mylist.del_at_pos(i);
				break;
			case 3: cout<<"\n Enter the position";
				cin>>i;
				mylist.val_at_pos(i);
				break;
			case 4: mylist.display();
				break;
			case 5: return 0;
			default: cout<<"Invalid choice";
			}
		}
	return 0;
	}
	
