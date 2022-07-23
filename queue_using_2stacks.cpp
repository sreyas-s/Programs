//In this program, we are going to implement a queue using two stacks. (without stl)
//so, first we have to have two stacks.
//we can implement two stacks using linked list/array.
//here we can implement stack using linked list.

#include<iostream>
using namespace std;

//do we need two structures is also something to try.

struct node{
	int data;
	struct node *next;
	};

void enqueuefun(struct node **, int);
void dequeuefun(struct node **, struct node **);
void getfrontfun(struct node **, struct node **);
void getrearfun(struct node **, struct node **);

//we only need to have a top pointer for stack.
//since we are implementing using linked list-head of list acts as top of stack. insertion and deletion can be done on top/head/beginning of list.

int main(){
	struct node *top1=NULL;
	struct node *top2=NULL;
	//we are implementing a queue here.
	//so we have to ask for basic operations to be done.
	//fifo have to be implemented
	int ch, x;
	//because we are implementing queue using linked list, we dont need to limit it to a certain size.
    	while(1){
        	cout<<"\n Enter your choice. \n 1. Enqueue an element. \n 2. Dequeue an element \n 3. Get the Front element \n 4. Get the rear element  \n 5. Exit \n";
        	cin>>ch;
        	switch(ch){
            		case 1: cout<<"Enter the element to be inserted";
               	     	cin>>x;
               	     	enqueuefun(&top1, x);
               	     	break;
            		case 2: dequeuefun(&top1, &top2);
               	     	break;
            		case 3: getfrontfun(&top1, &top2);
               	    	 break;
            		case 4: getrearfun(&top1, &top2);
               	     	break;
            		case 5: return 0;
            		default: break;
       	 	}
   	 	}
   	 	return 0;
	}

void enqueuefun(struct node **top1, int x){
	//all we have to do is push to stack 1.
	//top1 is pointing to top of stack 1.
	if(*top1==NULL){
		struct node *p=new node();
		p->data=x;
		p->next=NULL;
		*top1=p;
		}
	else{
		//at least one element is there in the stack 1.
		struct node *p=new node();
		p->data=x;
		p->next=*top1;
		*top1=p;
		}
	}
void dequeuefun(struct node **top1, struct node **top2){
	//whenever a dequeue operation comes, we have to remove an element from beginning of queue.
	//we have to look if stack1 is empty, if stack1 is empty-then check if stack 2 is empty-if both are empty-then queue is empty.
	//if stack2 is not empty, then we have to pop an element from stack2
	//while stack1 is not empty-we have to pop each element one by one and push to stack 2.
	if(*top1==NULL){
		//meaning that stack-1 is empty
		if(*top2==NULL){
			cout<<"Underflow. "<<endl;
			}
		else{
			//meaning that stack-2 is not empty.
			//remove the first node in list.
			struct node *temp=*top2;
			*top2=(*top2)->next;
			cout<<"Deleting "<<temp->data<<" from queue"<<endl;
			delete temp;
			}
		}
	else{
		//meaning that stack1 is not empty.
		while(*top1!=NULL){
			//we have to pop an element from stack1 and push that element to stack 2.
			struct node *temp=*top1;
			*top1=(*top1)->next;
			enqueuefun(top2, temp->data);
			delete temp;
			}
		//so, we have pushed elts from stack1 to stack 2.
		//now we just need to remove top element from stack2.
		struct node *temp=*top2;
		*top2=(*top2)->next;
		cout<<"Deleting "<<temp->data<<" from queue"<<endl;
		delete temp;
		}
	}
//so far written enqueue and dequeue functions.
//how to get the front element in the queue, at any point of time.

void getfrontfun(struct node **top1, struct node **top2){
	if(*top1==NULL){
		if(*top2==NULL){
			cout<<"Queue is empty. No front element"<<endl;
			}
		else{
			//when stack 2 is not empty, top element of stack2 is the front element of queue.
			cout<<"The front element of queue is "<<(*top2)->data<<endl;
			}
		}
	else{
		if(*top2==NULL){
			//then stack1 is not empty-but stack2 is empty.
			//so last element in stack-1 is front element.
			struct node *temp=*top1;
			while(temp->next!=NULL){
				temp=temp->next;
				}
			cout<<"The front element of queue is "<<temp->data<<endl;
			}
		else{
			//stack-1 is not empty and stack-2 is also not empty.
			//which means front element is top element in stack-2.
			cout<<"The front element of queue is "<<(*top2)->data<<endl;
			}
		}
	}

//how to get the rear element in the queue.
void getrearfun(struct node **top1, struct node **top2){
	if(*top1==NULL){
		if(*top2==NULL){
			cout<<"Queue is empty. No rear element"<<endl;
			}
		else{
			//when stack 2 is not empty, last element of stack2 is the rear element of queue.
			struct node *temp=*top2;
			while(temp->next!=NULL){
				temp=temp->next;
				}
			cout<<"The rear element of queue is "<<temp->data<<endl;
			}
		}
	else{
		if(*top2==NULL){
			//then stack1 is not empty-but stack2 is empty.
			//so first element in stack-1 is rear element.
			cout<<"The rear element of queue is "<<(*top1)->data<<endl;
			}
		else{
			//stack-1 is not empty and stack-2 is also not empty.
			//which means rear element is at top of stack-1.
			cout<<"The rear element of queue is "<<(*top1)->data<<endl;
			}
		}
	}

/*void displayfun(struct node1 **top1, struct node2 **top2){
		//front to rear we have to display.
		//front element is either at top of stack-2 or at end of stack-1 ,if stack-2 is empty.
		if(*top2==NULL){
			if(*top1==NULL){
				cout<<"Queue is empty. "<<endl;
				}
			else{
				//when stack-2 is empty but stack-1 is not empty. front element is at end of stack-1.
				//will have to reverse linked list to print elements in that order.
				}
			}
		else{
			
			}
		}
	*/
	
