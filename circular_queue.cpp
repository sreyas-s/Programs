#include<iostream>
using namespace std;

void enqueuefun(int *, int *, int *, int, int);
void dequeuefun(int *, int *, int *, int);
void getfrontfun(int *, int *);
void getrearfun(int *, int *);
void displayfun(int *, int *, int *, int);

int main(){
	int n;
	cout<<"Maximum value you might be entering?"<<endl;
	cin>>n;
	int a[n];
	int f=-1;
	int r=-1;
	int ch,x;
	while(1){
        	cout<<"\n Enter your choice. \n 1. Enqueue an element. \n 2. Dequeue an element \n 3. Get the Front element \n 4. Get the rear element \n 5. Display elements in Queue from Front. \n 6. Exit \n";
        	cin>>ch;
       	switch(ch){
            		case 1: cout<<"Enter the element to be inserted";
                   		cin>>x;
                    		enqueuefun(a, &f, &r, x, n);
                    		break;
           		case 2: dequeuefun(a, &f, &r, n);
                   		break;
            		case 3: getfrontfun(a, &f);
                    		break;
           		case 4: getrearfun(a, &r);
                    		break;
           		case 5: displayfun(a, &f, &r, n);
                    		break;
            		case 6: return 0;
            		default: break;
       		 }
    		}
    		return 0;
	}
void enqueuefun(int *arr, int *f, int *r, int x, int n){
    //initially both front and rear are pointing to -1.
    //here overflow condition is?
   //when will the array be full?
   //when we try to add an element -and see that the space we are gonna add to have already an element existing
   //when incrementing rear and doing mod u get front elt then overflow.
   if((*r+1) % n==*f){
   	cout<<"Overflow. "<<endl;
   	}
   else{
   	//what if we are adding an element to an empty queue.
   	if(*f==-1){
   		*f=(*f+1) % n;
   		*r=(*r+1) % n;
   		arr[*r]=x;
   		}
   	else{
   		//at least one element exists in the queue.
   		*r=(*r+1) % n;
   		arr[*r]=x;
   		}
   	}
   }

void dequeuefun(int *arr, int *f, int *r, int n){
    //have to check for underflow condition.
    if(*f==-1){
        cout<<"Underflow."<<endl;
    }
    else{
        //at least 1 element is there.
        //what if only 1 element is there.
        if(*f==*r){
        	*f=-1;
        	*r=-1;
        	}
        else{
        	//more than one element is present.
        	*f=(*f+1) % n;
        	}
        }
      }

void getfrontfun(int *arr, int *f){
    //we have to identify the element in front of queue.
    //just access arr[f].
    if(*f==-1){
    	cout<<"Queue is empty. No front element. "<<endl;
    	}
    else{
    	//at least one element is there.
    	cout<<"The front element is "<<arr[*f]<<endl;
    	}
    }
   

void getrearfun(int *arr, int *r){
    //we have to identify the element in front of queue.
    //just access arr[f].
   if(*r==-1){
   	cout<<"Queue is empty. No rear element. "<<endl;
   	}
   else{
   	cout<<"Rear element is "<<arr[*r]<<endl;
   	}
   }
 
void displayfun(int *arr, int *f, int *r, int n){
    if(*f==-1){
        cout<<"Queue is empty."<<endl;
    }
    else{
      	//how to display
      	int i=*f;
      	while(i!=*r){
      		cout<<arr[i]<<" ";
      		i=(i+1)%n;
      		}
      	cout<<arr[*r];
      }
    }
