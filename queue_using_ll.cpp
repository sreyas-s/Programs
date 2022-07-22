#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *next;
	};

void enqueuefun(struct node **, struct node **, int);
               	     	
void dequeuefun(struct node **, struct node **);
               	     	
void getfrontfun(struct node **);
               	    	 
void getrearfun(struct node **);
             
void displayfun(struct node **);

int main(){
	//we have to have two pointers front and rear.
	//front will be head, and rear is last element added.
	struct node *f=NULL;
	struct node *r=NULL;
	int ch, x;
	//because we are implementing queue using linked list, we dont need to limit it to a certain size.
    	while(1){
        	cout<<"\n Enter your choice. \n 1. Enqueue an element. \n 2. Dequeue an element \n 3. Get the Front element \n 4. Get the rear element \n 5. Display elements in Queue from Front. \n 6. Exit \n";
        	cin>>ch;
        	switch(ch){
            		case 1: cout<<"Enter the element to be inserted";
               	     	cin>>x;
               	     	enqueuefun(&f, &r, x);
               	     	break;
            		case 2: dequeuefun(&f, &r);
               	     	break;
            		case 3: getfrontfun(&f);
               	    	 break;
            		case 4: getrearfun(&r);
               	     	break;
            		case 5: displayfun(&f);
                 	   	break;
            		case 6: return 0;
            		default: break;
       	 	}
   	 	}
   	 	return 0;
	}

void enqueuefun(struct node **fref, struct node **rref, int x){
	//when inserting here we dont need to check for overflow as it is linked list.
	if(*fref==NULL){
		struct node *p=new node();
		p->data=x;
		p->next=NULL;
		*fref=p;
		*rref=p;
		}
	else{
		//there is at least one element in list/queue.
		struct node *p=new node();
		p->data=x;
		(*rref)->next=p;
		p->next=NULL;
		*rref=p;
		}
	}
void dequeuefun(struct node **fref, struct node **rref){
	//we have to check for underflow condition.
	if(*fref==NULL){
		cout<<"Underflow. "<<endl;
		}
	else{
		//there is at least one element in linked list/queue.
		//we have to delete element at the beginning.
		//what if there was only one element. then front and rear pointing to same.
		if(*fref==*rref){
			struct node *temp=*fref;
			delete temp;
			*fref=NULL;
			*rref=NULL;
			}
		else{
			//there are at least two elements.
			struct node *temp=*fref;
			*fref=(*fref)->next;
			delete temp;
			}
		}
	}

void getfrontfun(struct node **fref){
	if(*fref==NULL){
		cout<<"Queue is empty. No front element. "<<endl;
		}
	else{
		cout<<"Front element is "<<(*fref)->data<<endl;
		}
	}

void getrearfun(struct node **rref){
	if(*rref==NULL){
		cout<<"Queue is empty. No rear element. "<<endl;
		}
	else{
		cout<<"Rear element is "<<(*rref)->data<<endl;
		}
	}
		
void displayfun(struct node **fref){
	if(*fref==NULL){
		cout<<"Queue is empty. Nothing to display. "<<endl;
		}
	else{
		struct node *temp=*fref;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	}
			
	
