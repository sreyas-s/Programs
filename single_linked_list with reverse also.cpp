#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	};
	
void initializer(struct node **);
void add_at_pos(struct node **, int, int);
void del_at_pos(struct node **, int);
void val_at_pos(struct node **, int);
void display(struct node **);
void revfun(struct node **);

int main(){
	struct node *head;
	initializer(&head);
	//have to write a menu driven program.
	int ch,n,i;
	while(1){
		cout<<"\n Enter the choice:\n 1. add at position \n 2. delete from position \n 3. value at position \n 4. display \n 5. reverse the linked list and display. \n 6. Exit \n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element to be inserted";
				cin>>n;
				cout<<"\n Enter the position";
				cin>>i;
				add_at_pos(&head, n, i);
				break;
			case 2: cout<<"\n Enter the position";
				cin>>i;
				del_at_pos(&head, i);
				break;
			case 3: cout<<"\n Enter the position";
				cin>>i;
				val_at_pos(&head, i);
				break;
			case 4: display(&head);
				break;
			case 5: revfun(&head);
				break;
			case 6: return 0;
			default: cout<<"Invalid choice";
			}
		}
	return 0;
	}

void initializer(struct node **headref){
	*headref=NULL;
	}

void add_at_pos(struct node **headref, int n, int pos){
	if(*headref==NULL){
		if(pos==1){
			struct node *p=new node();
			p->data=n;
			p->next=NULL;
			*headref=p;
			}
		else{
			cout<<"List is empty. Not able to add at position "<<pos<<endl;
		}
	}
	else{
		
		if(pos==1){
			struct node *temp=*headref;
			struct node *p=new node();
			p->data=n;
			p->next=temp;
			*headref=p;
			temp=*headref;
			}
		else{
			struct node *temp=*headref;
			int count=0;
			while(temp!=NULL){
				temp=temp->next;
				count=count+1;
				}
			if(pos>(count+1) || pos<=0){
				cout<<"Not able to add at position "<<pos<<endl;
				}
			else{
				temp=*headref;
				//a temporary pointer have to be reached to the pos-1 node.
				for(int j=1;j<=pos-2;j++){
					temp=temp->next;
					}
				struct node *p=new node();
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

void del_at_pos(struct node **headref, int pos){
	if(*headref==NULL){
		cout<<"List is empty. Not able to delete from position "<<pos<<endl;
		}
	else{
		struct node *temp=*headref;
		if(pos==1){
			struct node *q=*headref;
			*headref=(*headref)->next;
			delete q;
			}
		else{
			temp=*headref;
			int count=0;
			while(temp!=NULL){
				temp=temp->next;
				count=count+1;
				}
			if(pos>(count) || pos<=0){
				cout<<"Not able to delete from position "<<pos<<endl;
				}
			else{
				temp=*headref;
				//a temporary pointer have to be reached to the pos-1 node.
				for(int j=1;j<=pos-2;j++){
					temp=temp->next;
					}
				struct node *q=temp->next;
				temp->next=q->next;
				delete q;
				
			}
		}
	}
}

void display(struct node **headref){
	if(*headref==NULL){
		cout<<"List is empty."<<endl;
		}
	else{
		struct node *temp=*headref;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	}

void val_at_pos(struct node **headref, int pos){
	if(*headref==NULL){
		cout<<"List is empty."<<endl;
		}
	else{
		struct node *temp=*headref;
		int count=0;
			while(temp!=NULL){
				temp=temp->next;
				count=count+1;
				}
			if(pos>(count) || pos<=0){
				cout<<"Invalid position "<<endl;
				}
			else{
				temp=*headref;
				//a temporary pointer have to be reached to position pos.
				for(int j=1;j<=pos-1;j++){
					temp=temp->next;
					}
				cout<<"Value at position "<<pos<<" is "<<temp->data<<endl;
				}
			}
		}
				
						
void revfun(struct node **headref){
	if(*headref==NULL){
		cout<<"List is empty."<<endl;
		}
	else{
		//at least one element is there. 
		//do we have to check if two elements are there?
		//lets not do that currently and go ahead with logic.
		
		struct node *prev=NULL;
		struct node *temp=*headref;
		struct node *aage=temp->next;
		if(aage==NULL){
			// meaning that only one element is there in list.
			cout<<temp->data;
			}
		else if(aage->next==NULL){
			//meaning that there are only two elements in the list.
			//then the new head is aage.
			*headref=aage;
			aage->next=temp;
			temp->next=NULL;
			cout<<aage->data<<" "<<temp->data;
			}
		else{
			//there are more than two elements in the list.
			
			while(aage!=NULL){
				temp->next=prev;
				prev=temp;
				temp=aage;
				aage=aage->next;				
				}
			//it will stop when aage is null.
			//when aage is null, temp would have been pointing at the last element in the list.
			//we have to make temp->next as prev and temp as head.
			temp->next=prev;
			*headref=temp;
			struct node *temp1=*headref;
			while(temp1!=NULL){
				cout<<temp1->data<<" ";
				temp1=temp1->next;
				}
			}
		}
	}
