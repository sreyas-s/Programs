#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *prev;
	struct node *next;
	};

void initializer(struct node **);
void add_at_pos(struct node **, int, int);
void del_at_pos(struct node **, int);
void val_at_pos(struct node **, int);
void display(struct node **);

int main(){
	struct node *head;
	initializer(&head);
	int ch,i,n;
	while(1){
		cout<<"\n Enter the choice:\n 1. add at position \n 2. delete from position \n 3. value at position \n 4. display \n 5. Exit \n";
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
			case 5: return 0;
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
			p->prev=NULL;
			*headref=p;
			}
		else{
			cout<<"List is empty now. Not able to add at position "<<pos<<endl;
			}
		}
	else{
		if(pos==1){
			struct node *p=new node();
			p->data=n;
			p->next=*headref;
			p->prev=NULL;
			*headref=p;
			}
		else{
			//have to check if user is asking for a valid position.
			int count=0;
			struct node *temp=*headref;
			while(temp!=NULL){
				temp=temp->next;
				count=count+1;
				}
			temp=*headref;
			if(pos>(count+1) || pos<=0){
				cout<<"Not able to add at position "<<pos<<endl;
				}
			else{
				//we have to reach pos-1 node.
				for(int j=1;j<=pos-2;j++){
					temp=temp->next;
					}
				struct node *p=new node();
				p->data=n;
				p->next=temp->next;
				p->prev=temp;
				temp->next=p;
				}
			}
		}
	}

void del_at_pos(struct node **headref, int pos){
	if(*headref==NULL){
		cout<<"List is empty now. Not able to delete from position "<<pos<<endl;
		}
	else{
		if(pos==1){
			struct node *q=*headref;
			*headref=(*headref)->next;
			delete q;
			}
		else{
			//have to check if user is asking for a valid position.
			int count=0;
			struct node *temp=*headref;
			while(temp!=NULL){
				temp=temp->next;
				count=count+1;
				}
			temp=*headref;
			if(pos>(count) || pos<=0){
				cout<<"Not able to delete from position "<<pos<<endl;
				}
			else{
				//we have to reach pos-1 node.
				for(int j=1;j<=pos-2;j++){
					temp=temp->next;
					}
				struct node *q=temp->next;
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

void val_at_pos(struct node **headref, int pos){
	if(*headref==NULL){
		cout<<"List is empty";
		}
	else{
		int count=0;
		struct node *temp=*headref;
		while(temp!=NULL){
			temp=temp->next;
			count=count+1;
			}
		temp=*headref;
		if(pos>(count+1) || pos<=0){
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
				
void display(struct node **headref){
	if(*headref==NULL){
		cout<<"List is empty";
		}
	else{
		struct node *temp=*headref;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	}

