#include<iostream>
using namespace std;

void pushfun(int *, int, int, int *);
void popfun(int *, int *);
void topfun(int *, int *);
void isemptyfun(int *, int *);
void displayfun_b2t(int *, int *);
void displayfun_t2b(int *, int *);

int main(){
	int n,x;
	int top=-1;
	cout<<"The maximum number of elements you might be entering";
	cin>>n;
	int a[n];
	int ch;
	while(1){
		cout<<"\n Enter the choice. What do with stack? \n 1. Push an element \n 2. Pop an element \n 3. Find the topmost element \n 4. Check if stack is empty \n 5. Display all elements in stack from bottom to top \n 6. Display all elements in stack from top to bottom \n 7. Exit. \n";
		cin>>ch;
		switch(ch){
			case 1: cout<<"Enter the element you want to push";
				cin>>x;
				pushfun(a,x,n,&top);
				break;
			case 2: popfun(a, &top);
				break;
			case 3: topfun(a, &top);
				break;
			case 4: isemptyfun(a, &top);
				break;
			case 5: displayfun_b2t(a, &top);
				break;
			case 6: displayfun_t2b(a, &top);
				break;
			case 7: return 0;
			}
		}
	return 0;
}

void pushfun(int *arr, int x, int n, int *top){
	if(*top==-1){
		*top=*top+1;
		arr[*top]=x;
		}
	else{
		if(*top==(n-1)){
			cout<<"Overflow"<<endl;
			}
		else{
			*top=*top+1;
			arr[*top]=x;
			}
		}
	}

void popfun(int *arr, int *top){
	//check if stack is empty
	if(*top==-1){
		cout<<"Underflow"<<endl;
		}
	else{
		*top=*top-1;
		}
	}

void topfun(int *arr, int *top){
	if(*top==-1){
		cout<<"Stack is empty. No topmost element."<<endl;
		}
	else{
		cout<<"Topmost element in the stack is "<<arr[*top]<<endl;
		}
	}

void isemptyfun(int *arr, int *top){
	if(*top==-1){
		cout<<"Stack is empty."<<endl;
		}
	else{
		cout<<"Not empty"<<endl;
		}
	}	
		
void displayfun_b2t(int *arr, int *top){
	if(*top==-1){
		cout<<"Stack is empty"<<endl;		
		}
	else{
		for(int i=0;i<=*top;i++){
			cout<<arr[i]<<" ";
		}
	}
}
	
void displayfun_t2b(int *arr, int *top){
	if(*top==-1){
		cout<<"Stack is empty"<<endl;		
		}
	else{
		for(int i=*top;i>=0;i--){
			cout<<arr[i]<<" ";
		}
	}
}
	
			
