//deleting an element from heap.

#include<iostream>
using namespace std;

void deletefun(int *, int *);
void printarray(int *, int);
void heapify(int *, int, int);
void swap(int *, int *);

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int nd;
    cin>>nd;
    for(int i=0;i<nd;i++){
        deletefun(a, &n);
        cout<<"After deleting "<<i+1<<" time: ";
        printarray(a, n);
    }
    return 0;
}

void deletefun(int *arr, int *n){
    //there are n elements currently.
    //delete the first node.
    int last_elt=arr[*n-1];
    arr[0]=last_elt;
    *n=*n-1;
    //after doing this, now we have to heapify the current root node again.
    heapify(arr, *n, 0);
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int *arr, int n, int i){
    int max_elt=i;
    int lc=2*i+1;
    int rc=2*i+2;
    if(lc < n && arr[lc]>arr[max_elt]){
        max_elt=lc;
    }
     if(rc < n && arr[rc]>arr[max_elt]){
        max_elt=rc;
    }
    if(max_elt!=i){
        swap(&arr[max_elt], &arr[i]);
        heapify(arr, n, max_elt);
    }
}
   
void printarray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
