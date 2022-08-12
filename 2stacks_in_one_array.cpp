
//implement two stacks using one array.-efficiently.

#include<iostream>
using namespace std;

void pushfun1(int *, int*, int *, int, int); 
void popfun1(int *, int *);
void topfun1(int *, int *);
void displayfun1(int *, int *);
void pushfun2(int *, int*,int *, int, int); 
void popfun2(int *, int *, int);
void topfun2(int *, int *);
void displayfun2(int *, int *, int);

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int top1, top2; //as there are going to be two stacks-we maintain two pointers.
    //initially let both of them point to -1.
    top1=-1;
    top2=-1;
    int a[n]; //no initializations.
    int ch;
    int x;
    while(1){
        cout<<"\n 1. Push element to stack 1 \n 2. Push element to stack 2 \n 3.Pop element from stack 1 \n 4.Pop element from stack 2 \n 5. Top element of stack 1 \n 6. Top element of stack 2 \n 7. Display elements of stack1-top to bottom \n 8. Display elements of stack2-top to bottom \n 9. Exit \n  ";
        cin>>ch;
        switch(ch){
        	case 1: cout<<"Enter the element"<<endl;
        		cin>>x;
        		pushfun1(a, &top1, &top2, x, n);
        		break;
        	case 2: cout<<"Enter the element"<<endl;
        		cin>>x;
        		pushfun2(a, &top2, &top1, x, n);
        		break;
        	case 3: popfun1(a, &top1);
        		break;
        	case 4: popfun2(a, &top2, n);
        		break;
        	case 5: topfun1(a, &top1);
        		break;
        	case 6: topfun2(a, &top2);
        		break;
        	case 7: displayfun1(a, &top1);
        		break;
        	case 8: displayfun2(a, &top2, n);
        		break;
        	case 9: return 0;
        	default: cout<<"Invalid choice"<<endl;
        	}
        }
   return 0;
   }
  
void pushfun1(int *arr, int *top1, int *top2, int x, int n){
	//what all we have to see when we push an element to stack-only worry about overflow condition.
	//also check if it is empty-to change top pointer accordingly.
	if(*top1==-1){
		//because it is stack1 and for stack1 we are allocating the first part of array,
		*top1=0;
		arr[*top1]=x;
		}
	else{
		//what if stack is full?
		if((*top2-*top1)==1 && *top1<=(n-1)){
			cout<<"Overflow"<<endl;
			}
		else{
			//generic case.
			*top1+=1;
			arr[*top1]=x;
			}
		}
	}

void pushfun2(int *arr, int *top2, int *top1, int x, int n){
	//what all we have to see when we push an element to stack-only worry about overflow condition.
	//also check if it is empty-to change top pointer accordingly.
	if(*top2==-1){
		//because it is stack1 and for stack1 we are allocating the first part of array,
		*top2=n-1;
		arr[*top2]=x;
		}
	else{
		//what if stack is full?
		if((*top2-*top1)==1 && *top2>=0){
			cout<<"Overflow"<<endl;
			}
		else{
			//generic case.
			*top2=*top2-1;
			arr[*top2]=x;
			}
		}
	}

void popfun1(int *arr, int *top1){
	//what all we have to see when we have to delete an element from stack.
	//if it is empty already-then underflow condition.
	//also when stack only has one element in it-when deleting that element-stack becomes empty and has to set pointer accordingly.
	if(*top1==-1){
		cout<<"Underflow"<<endl;
		}
	else{
		if(*top1==0){
			cout<<"deleted "<<arr[*top1]<<endl;
			*top1-=1;
			}
		else{
			//generic case.
			cout<<"deleted "<<arr[*top1]<<endl;
			*top1-=1;
			}
		}
	}

void popfun2(int *arr, int *top2, int n){
	//what all we have to see when we have to delete an element from stack.
	//if it is empty already-then underflow condition.
	//also when stack only has one element in it-when deleting that element-stack becomes empty and has to set pointer accordingly.
	if(*top2==-1){
		cout<<"Underflow"<<endl;
		}
	else{
		if(*top2==(n-1)){
			cout<<"deleted "<<arr[*top2]<<endl;
			*top2-=1;
			}
		else{
			//generic case.
			cout<<"deleted "<<arr[*top2]<<endl;
			*top2-=1;
			}
		}
	}

void topfun1(int *arr, int *top1){
	if(*top1==-1){
		cout<<"No top element"<<endl;
		}
	else{
		cout<<"Top element: "<<arr[*top1]<<endl;
		}
	}

void topfun2(int *arr, int *top2){
	if(*top2==-1){
		cout<<"No top element"<<endl;
		}
	else{
		cout<<"Top element: "<<arr[*top2]<<endl;
		}
	}

void displayfun1(int *arr, int *top1){
	if(*top1==-1){
		cout<<"Stack-1 is empty"<<endl;
		}
	else{
		for(int i=*top1;i>=0;i--){
			cout<<arr[i]<<" ";
			}
		}
	}

void displayfun2(int *arr, int *top2, int n){
	if(*top2==-1){
		cout<<"Stack-2 is empty"<<endl;
		}
	else{
		for(int i=*top2;i<=(n-1);i++){
			cout<<arr[i]<<" ";
			}
		}
	}

