//program to find multiplication of two polynomials using linked list representation for polynomials.

//We are considering polynomials in one variable only here.

#include<iostream>
using namespace std;

struct node{
	int coeff;
	int power;
	struct node *next;
	};


void insertfun(struct node **, int, int);
void printfun(struct node **);
void multiplyfun(struct node **, struct node **, struct node **);
void optimizefun(struct node **);

int main(){
	struct node *head1=NULL;
	struct node *head2=NULL;	
	//we whave two polynomials given.
	struct node *head3=NULL;
	//third polynomial to store the result of multiplication of these two polynomials.
	int ch;
	int coeff,power;
	cout<<"Enter polynomial-1"<<endl;
	while(1){
		cout<<"Add node for polynomial-1?"<<endl;
		cin>>ch;
		if(ch==1){
			//ask for details and call function for inserting.
			cout<<"Enter the coefficient"<<endl;
			cin>>coeff;
			cout<<"Enter the power of variable"<<endl;
			cin>>power;
			insertfun(&head1, coeff, power);
			}
		else{
			break;
			}
		}
	//call function for printing polynomial-1.
	cout<<"So, polynomial-1 entered is "<<endl;
	printfun(&head1);
	cout<<endl;
	cout<<"Enter polynomial-2"<<endl;
	while(1){
		cout<<"Add node for polynomial-2?"<<endl;
		cin>>ch;
		if(ch==1){
			//ask for details and call function for inserting.
			cout<<"Enter the coefficient"<<endl;
			cin>>coeff;
			cout<<"Enter the power of variable"<<endl;
			cin>>power;
			insertfun(&head2, coeff, power);
			}
		else{
			break;
			}
		}
	//call function for printing polynomial-2.
	cout<<"So, polynomial-2 entered is "<<endl;
	printfun(&head2);
	cout<<endl;
	//now, we have two polynomials-we have to call function to multiply these two polynomials
	cout<<"The result of multiplication:"<<endl;
	//call function for multiplication.
	multiplyfun(&head1,&head2,&head3);
	
	//call function for printing resultant polynomial after multiplication.
	printfun(&head3);
	return 0;
	}

//now, define the functions.

void printfun(struct node **headref){
	if(*headref==NULL){
		cout<<"Zero polynomial"<<endl;
		return;
		}
	else{
		//at least one node is there.
		//after each node-we have to print "+" also.
		int flag=0;
		struct node *temp=*headref;
		while(temp!=NULL){
			if(temp->coeff==0){
				temp=temp->next;
				continue;
				}
			else{
				flag=1;
				cout<<temp->coeff;
				cout<<"x^"<<temp->power;
				if(temp->next!=NULL){
					cout<<" + ";
					}
				temp=temp->next;
				}
			}
		if(flag==0){
			//it means it has not printed anything and it is a zero polynomial.
			cout<<"Zero polynomial"<<endl;
		}
	}
}

void insertfun(struct node **headref, int c, int pow){
	//c is coefficient. p is power.
	struct node *p=new node();
	p->coeff=c;
	p->power=pow;
	p->next=NULL;
	if(*headref==NULL){
		*headref=p;
		}
	else{
		//we are inserting at the end of the list.
		struct node *temp=*headref;
		while(temp->next!=NULL){
			temp=temp->next;
			}
		temp->next=p;
		}
	}


//now, the main function remaining-multiply

void multiplyfun(struct node **headref1, struct node **headref2, struct node **headref3){
	//understand theoretically how we will multiply two polynomials together.
	int result_coeff;
	int result_power;
	if(*headref1==NULL||*headref2==NULL){
		*headref3=NULL;
		return;
		}
	else{
		struct node *temp1=*headref1;
		struct node *temp2=*headref2;
		while(temp1!=NULL){
			//traversing the first list-and for each node we meet in the first list-we have to traverse the entire second list.
			temp2=*headref2;
			while(temp2!=NULL){
				//multiply temp1 and temp2.
				result_coeff=(temp1->coeff)*(temp2->coeff);
				result_power=(temp1->power)+(temp2->power);
				insertfun(headref3, result_coeff, result_power);
				/*struct node *p=new node();
				p->coeff=result_coeff;
				p->power=result_power;
				p->next=NULL;
				if(*headref3==NULL){
					*headref3==p;
					}
				else{
					struct node *temp3=*headref3;
					while(temp3->next!=NULL){
						temp3=temp3->next;
						}
					temp3->next=p;
					}
				*/
				//I could have called an insertfunction here.
				temp2=temp2->next;
				}
			temp1=temp1->next;	
			}
	}
	optimizefun(headref3);
}

void optimizefun(struct node **headref){
	//basically we have to club elements with same power into one.
	if(*headref==NULL){
		return;
		}
	else{
		struct node *temp1=*headref;
		struct node *temp2=(*headref)->next;
		while(temp1!=NULL){
			temp2=temp1->next;
			while(temp2!=NULL){
				if(temp1->power==temp2->power){
					//then accumalate things in temp1 and make temp2 literally 0.
					temp1->coeff=(temp1->coeff)+(temp2->coeff);
					temp2->coeff=0;
					}
				temp2=temp2->next;
				}
			temp1=temp1->next;
			}
		}
	//so, here basically we have optimized.
	//now, we can also remove nodes which have coeff 0.
	//we dont need to remove 0 coeff nodes-we can just print nodes whose coefffs are non-zero.
	}


