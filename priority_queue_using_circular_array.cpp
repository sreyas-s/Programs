//priority queue implementation using circular array.

#include<iostream>
using namespace std;

void insertfun(int *, int *, int *, int, int);
void deletefun(int *, int *, int *, int);
void peekfun(int *, int *, int *);
void displayfun(int *, int *, int *, int);
void swap(int *, int *);

int main(){
    //size of the array is fixed.
    int n;
    cout<<"Size of the queue?"<<endl;
    cin>>n;
    int a[n];
    //queue has front and rear.
    int front, rear;
    front=-1;
    rear=-1;
    //now, let's say we are implementing the ascending priority queue-elt with lesser value-higher priority.
    //we have to implement three basic operations of P.Q
    int ch;
    int x;//dataitem
    while(1){
        cout<<"Enter the choice: \n 1. Insert \n 2. Delete \n 3. Peek \n 4. Display Queue from front to rear \n 5. Exit \n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the item"<<endl;
                    cin>>x;
                    insertfun(a, &front, &rear, x, n);
                    break;
            case 2: deletefun(a, &front, &rear, n);
                    break;
            case 3: peekfun(a, &front, &rear);
                    break;
            case 4: displayfun(a, &front, &rear, n);
                    break;
            case 5: return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
//now, write the functions.

void insertfun(int *arr, int *front, int *rear, int x, int n){
    //basically insertions happen at the rear end-in normal queue.
    //here, we are implementing a priority queue.
    //so, insert the element in such a way that, after insertion elements from front to rear are in decreasing order of priority
    if(*front==-1){
       *front=(*front+1)%n;
       *rear=(*rear+1)%n;
        arr[*rear]=x;
    }
    else{
        if((*rear+1)%n==*front){
            cout<<"Queue overflow"<<endl;
        }
        else{
            //if the queue is not empty, then?
            //lets see about when we insert second element.
            //we can check data with existing rear item's data.
            *rear=(*rear+1)%n;
            arr[*rear]=x;
            //now, that we have added this element at the end position.
            //how do we do insertion sort???
            //we can apply the same technique here.
            int pos=*rear;
            int j=pos;
            int nextelement;
            while(j!=*front){
                nextelement=(j-1)%n;
                if(arr[j]<arr[nextelement]){
                    swap(&arr[j], &arr[nextelement]);
                }
                j=(j-1)%n;
            }
            //after this while loop, element x will be in its correct position.
        }
    }
}

void deletefun(int *arr, int *front, int *rear, int n){
    if(*front==-1){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        //at least 1 element is there in the queue.
        if(*front==*rear){
            cout<<"Deleting "<<arr[*front]<<endl;
            *front=-1;
            *rear=-1;
        }
        else{
            //if there are at least two elements in the queue.
            //when we are deleting, we can just delete the front element in the queue-because we have inserted elements that way
            cout<<"Deleting "<<arr[*front]<<endl;
            *front=(*front+1)%n;
        }
    }
}

void peekfun(int *arr, int *front, int *rear){
    //we have to just look at the front element in the queue.
    if(*front==-1){
        cout<<"Queue is empty. Nothing to peek at"<<endl;
    }
    else{
        cout<<"Front element in the queue is "<<arr[*front]<<endl;
    }
}

void displayfun(int *arr, int *front, int *rear, int n){
    if(*front==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        //we have to start from front. and go till we see rear.
        int j=*front;
        while(j!=*rear){
            cout<<arr[j]<<" ";
            j=(j+1)%n;
        }
        cout<<arr[j]<<endl;
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

