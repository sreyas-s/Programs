//implementation of queue using array.

#include<iostream>
using namespace std;

void enqueuefun(int *, int *, int *, int, int);
void dequeuefun(int *, int *, int *);
void getfrontfun(int *, int *);
void getrearfun(int *, int *);
void displayfun(int *, int *, int *);

int main(){
    int n;
    cout<<"Maximum number of elements you might be entering? "<<endl;
    cin>>n;
    int a[n];
    int fptr, rptr;
    fptr=-1;
    rptr=-1;
    int ch, x;
    while(1){
        cout<<"\n Enter your choice. \n 1. Enqueue an element. \n 2. Dequeue an element \n 3. Get the Front element \n 4. Get the rear element \n 5. Display elements in Queue from Front. \n 6. Exit \n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the element to be inserted";
                    cin>>x;
                    enqueuefun(a, &fptr, &rptr, x, n);
                    break;
            case 2: dequeuefun(a, &fptr, &rptr);
                    break;
            case 3: getfrontfun(a, &fptr);
                    break;
            case 4: getrearfun(a, &rptr);
                    break;
            case 5: displayfun(a, &fptr, &rptr);
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
    if(*r==(n-1)){
        cout<<"Oveflow."<<endl;
    }
    else{
        if(*f==-1){
          *f=0;
          *r=*r+1;
          arr[*r]=x;
         }
        else{
            *r=*r+1;
            arr[*r]=x;
        }
    }
}

void dequeuefun(int *arr, int *f, int *r){
    //have to check for underflow condition.
    if(*f==-1){
        cout<<"Underflow."<<endl;
    }
    else{
        //queue is not empty.
        if(*f==*r){
            //that means only one element is there.
            //make it point to -1.
            *f=-1;
            *r=-1;
        }
        else{
            *f=*f+1;
        }
    }
}

void getfrontfun(int *arr, int *f){
    //we have to identify the element in front of queue.
    //just access arr[f].
    if(*f==-1){
        cout<<"Queue is empty. No front element"<<endl;
    }
    else{
        cout<<"Front element is "<<arr[*f]<<endl;
    }
}

void getrearfun(int *arr, int *r){
    //we have to identify the element in front of queue.
    //just access arr[f].
    if(*r==-1){
        cout<<"Queue is empty. No rear element"<<endl;
    }
    else{
        cout<<"Rear element is "<<arr[*r]<<endl;
    }
}

void displayfun(int *arr, int *f, int *r){
    if(*f==-1){
        cout<<"Queue is empty."<<endl;
    }
    else{
        for(int i=*f;i<=*r;i++){
            cout<<arr[i]<<" ";
        }
    }
}

