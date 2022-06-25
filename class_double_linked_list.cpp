#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		node *prev;
		//default constructor
		node(){
			next=NULL;
			prev=NULL;
			}
		};

class list{
	public:
		node *head;
		//definining functions inside the class
		void initializer(){
			head=NULL;
			}
		void add_at_pos(int n, int pos){
			if(head==NULL){
				if(pos==1){
					node *p=new node();
					p->data=n;
					p->next=NULL;
					p->prev=NULL;
					head=p;
					}
				else{
					cout<<"List is empty now. Not able to add at position "<<pos<<endl;
					}
				}
			else{
				if(pos==1){
					node *p=new node();
					p->data=n;
					p->next=head;
					p->prev=NULL;
					head=p;
					}
				else{
					//have to check if user is asking for a valid position.
					int count=0;
					node *temp=head;
					while(temp!=NULL){
						temp=temp->next;
						count=count+1;
						}
					temp=head;
					if(pos>(count+1) || pos<=0){
						cout<<"Not able to add at position "<<pos<<endl;
						}
					else{
						//we have to reach pos-1 node.
						for(int j=1;j<=pos-2;j++){
							temp=temp->next;
							}
						node *p=new node();
						p->data=n;
						p->next=temp->next;
						p->prev=temp;
						temp->next=p;
						}
					}
				}
			}

		void del_at_pos(int pos){
			if(head==NULL){
				cout<<"List is empty now. Not able to delete from position "<<pos<<endl;
				}
			else{
				if(pos==1){
					node *q=head;
					head=head->next;
					delete q;
					}
				else{
					//have to check if user is asking for a valid position.
					int count=0;
					node *temp=head;
					while(temp!=NULL){
						temp=temp->next;
						count=count+1;
						}
					temp=head;
					if(pos>(count) || pos<=0){
						cout<<"Not able to delete from position "<<pos<<endl;
						}
					else{
						//we have to reach pos-1 node.
						for(int j=1;j<=pos-2;j++){
							temp=temp->next;
							}
						node *q=temp->next;
						if(q->next!=NULL){
							temp->next=q->next;
							q->next->prev=temp;
							}
						else{
							temp->next=NULL;
					}
				
				delete q;
				}
			}
		}
	}

		void val_at_pos(int pos){
			if(head==NULL){
				cout<<"List is empty";
				}
			else{
				int count=0;
				node *temp=head;
				while(temp!=NULL){
					temp=temp->next;
					count=count+1;
					}
				temp=head;
				if(pos>(count) || pos<=0){
					cout<<"Invalid position "<<pos<<endl;
					}	
				else{
					for(int j=1;j<=pos-1;j++){
						temp=temp->next;
						}
					cout<<"Value at position "<<pos<<" is "<<temp->data;	
				}
			}
		}
				
		void display(){
			if(head==NULL){
				cout<<"List is empty";
				}
			else{
				node *temp=head;
				while(temp!=NULL){
					cout<<temp->data<<" ";
					temp=temp->next;
					}
				}
			}
	
		};	

int main(){
	list mylist;
	mylist.initializer();
	int ch,i,n;
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

