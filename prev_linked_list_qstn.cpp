#include<iostream>
using namespace std;

struct node{
	char data;
	struct node *next;
	};
	
void move_to_front(struct node **, char);
void transpose(struct node **, char);
void displaymove(struct node **);
void displaytranspose(struct node **);

int final_count2=0;
int final_count=0;

int main(){
	struct node *head1=NULL;
	struct node *head2=NULL;
	char n;
	//wrote two functions- now what to do?
	int ch;
	while(1){
		cout<<"\n Enter the choice \n 1. Move-to-front \n 2. Transpose \n 3. Display list of Move-to-front \n 4. Display list of Transpose \n 5. Exit \n 6. Move to front final comparison \n 7. Transpose final comparison "<<endl;
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the data"<<endl;
				cin>>n;
				move_to_front(&head1, n);
				break;
			case 2: cout<<"Enter the data"<<endl;
				cin>>n;
				transpose(&head2, n);
				break;
			case 3: displaymove(&head1);
				break;
			case 4: displaytranspose(&head2);
				break;
			case 5: return 0;
			case 6: cout<<"Final count is "<<final_count<<endl;
				break;
			case 7: cout<<"Final count is "<<final_count2<<endl;
				break;
			default: cout<<"Invalid choice"<<endl;
			}
		}
	
	
	return 0;

}

void move_to_front(struct node **headref, char x){
	//whenever any node comes-check in list so far.
	//if not present -insert at end.
	//if present somehwere -move that node to head of list.
	
	//for each element getting added-we have to add their count_comp to get final_count.
	
	
	//int final_count=0;
	int pos=0;
	int count_comp=0;
	int flag=0;
	if(*headref==NULL){
		struct node *p=new node();
		p->data=x;
		p->next=NULL;
		*headref=p;
		}
	else{
		//there is at least one element in the list.
		//what if there are only one.
		struct node *temp=*headref;
		struct node *prev_temp;
		while(temp!=NULL){
			pos++;
			count_comp++;
			if(temp->data==x){
				//checking while traversing elements in list so far-that x is already present or not.
				flag=1;
				break;
				}
			else{
				prev_temp=temp;
				temp=temp->next;
				}
			}
		final_count=final_count+count_comp;
		//if flag=1, it means it has found a matching. else-no match found-have to insert at the end of list.
		if(flag==1){
			//temp is now pointing to that node which contain x.
			//temp has to be now shifted to head of list.
			//pos will tell at which place the temp node is currently there in the list.
			//the possible options are it can be anywhere from 1.
			if(pos!=1){
				//when it is already at the head- no action is required. only action required when pos is somehwere else.
				//think at this situation what will you do/
				//we need to get a pointer for node previous to temp.(which is at position pos-1)
				prev_temp->next=temp->next;
				//now attach temp to beginning.
				temp->next=*headref;
				*headref=temp;
				}
				
			}
		else{
			//inserting the element at the end of the list.
			struct node *p=new node();
			p->data=x;
			p->next=NULL;
			temp=*headref;
			while(temp->next!=NULL){
				temp=temp->next;
				}
			temp->next=p;
			}
		}
	}

void transpose(struct node **headref2, char x){
	
	//int final_count2;
	int pos2=0;
	int count_comp2=0;
	int flag2=0;
	//int prevcount;
	
	if(*headref2==NULL){
		struct node *p=new node();
		p->data=x;
		p->next=NULL;
		*headref2=p;
		}
	else{
		//there is at least one element in the list.
		//what if there are only one.
		struct node *temp2=*headref2;
		struct node *prev_temp2;
		struct node *prev_prev;
		while(temp2!=NULL){
			pos2++;
			count_comp2++;
			if(temp2->data==x){
				//checking while traversing elements in list so far-that x is already present or not.
				flag2=1;
				break;
				}
			else{
				prev_temp2=temp2;
				temp2=temp2->next;
				}
		}
		final_count2=final_count2+count_comp2;
		if(flag2==1){
			//temp is now pointing to that node which contain x.
			//temp has to be now shifted to head of list.
			//pos will tell at which place the temp node is currently there in the list.
			//the possible options are it can be anywhere from 1.
			if(pos2!=1){
				//when it is already at the head- no action is required. only action required when pos is somehwere else.
				//think at this situation what will you do/
				//we need to get a pointer for node previous to temp.(which is at position pos-1)
				//we need to swap temp2 with its prev node unless prev node is head of list.
				//we need to swap temp2 with prev_temp2 node.
				//how to swap two nodes?
				prev_temp2->next=temp2->next;
				temp2->next=prev_temp2;
				//now prev node of previous prev_temp2's next pointer has to be changed to temp2.
				//may be we have to traverse till pos2-1 node to get that pointer.
				//prev_prev=*headref2;
				//temp2 is at pos2.
				//we have to check if prev_temp2 is head or not.
				//if so, after swapping head have to be changed.
				if(prev_temp2==*headref2){
					//then 
					*headref2=temp2;
					}
				else{
					//that means prev_temp is not head pointer.
					//so, prev_temp's previous node has to point to temp2.
					//that required pointer is at pos2-2 position.
					prev_prev=*headref2;
					for(int i=1;i<=(pos2-3);i++){
						prev_prev=prev_prev->next;
						}
					prev_prev->next=temp2;
					}
				}
		}
		else{
			//inserting the element at the end of the list.
			struct node *p=new node();
			p->data=x;
			p->next=NULL;
			temp2=*headref2;
			while(temp2->next!=NULL){
				temp2=temp2->next;
				}
			temp2->next=p;
			}
		}
		
	}

void displaymove(struct node **headref){
	if(*headref==NULL){
		cout<<"List is empty"<<endl;
		}
	else{
		struct node *temp=*headref;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	}
	
void displaytranspose(struct node **headref2){
	if(*headref2==NULL){
		cout<<"List is empty"<<endl;
		}
	else{
		struct node *temp2=*headref2;
		while(temp2!=NULL){
			cout<<temp2->data<<" ";
			temp2=temp2->next;
			}
		}
	}

