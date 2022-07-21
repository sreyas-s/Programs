#include<iostream>
using namespace std;

void pushfun(struct node **, int);
void popfun(struct node **);
void topfun(struct node **);
void isemptyfun(struct node **);
void displayfun_t2b(struct node **);



struct node{
	int data;
	struct node *next;
	};

int main(){
	//linked list is dynamic. we can add any number of nodes/elts to stack when implemented using ll.
	//only underflow condition can happen. no overflow mostly.
	int ch,x;
	struct node *top=NULL;
	//top acts as head.
	//as and when we push an element, we are adding at beg of linked list, thats at the head.
	//deleting also from beg.
	while(1){
		cout<<"\n Enter the choice. What do with stack? \n 1. Push an element \n 2. Pop an element \n 3. Find the topmost element \n 4. Check if stack is empty \n  5. Display all elements in stack from top to bottom \n 6. Exit. \n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element you want to push";
				cin>>x;
				pushfun(&top, x);
				break;
			case 2: popfun(&top); //pass by reference?
				break;
			case 3: topfun(&top);
				break;
			case 4: isemptyfun(&top);
				break;
			case 5: displayfun_t2b(&top);
				break;
			case 6: return 0;
			}
		}
	return 0;
}

void pushfun(struct node **topref, int x){
	if(*topref==NULL){
		//then currently no elements are there in stack and we have to add one and make it head/top.
		struct node *p=new node();
		p->data=x;
		p->next=NULL;
		*topref=p;
		}
	else{
		//have to insert at beginning.
		//we have come here means- at least 1 element is there in stack/list.
		//we have to anyway create a new node first and then link it.
		struct node *p=new node();
		p->data=x;
		p->next=*topref;
		//now we created a node and linked it to head.
		//we have to make this currently added node as top/head now.
		*topref=p;
		}
	}

void popfun(struct node **topref){
	if(*topref==NULL){
		cout<<"Underflow."<<endl;
		}
	else{
		//we have to delete from the beginning.
		struct node *temp=*topref;
		*topref=(*topref)->next;
		free(temp);
		}
	}

void topfun(struct node **topref){
	if(*topref==NULL){
		cout<<"Stack is empty. No topmost element "<<endl;
		}
	else{
		cout<<"The topmost element of stack is "<<(*topref)->data<<endl;
		}
	}

void isemptyfun(struct node **topref){
	if(*topref==NULL){
		cout<<"Stack is empty. "<<endl;
		}
	else{
		cout<<"Not empty. "<<endl;
		}
	}


void displayfun_t2b(struct node **topref){
	if(*topref==NULL){
		cout<<"Stack is empty. "<<endl;
		}
	else{
		struct node *temp=*topref;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
			}
		}
	}


