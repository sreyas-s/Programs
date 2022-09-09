//inserting a new element to heap.

#include<iostream>
using namespace std;

void heapify(int *, int, int);
void insertfun(int *, int *, int);
void swap(int *, int *);

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cin>>k;
    insertfun(a, &n, k);
    //after inserting-new heap.
    cout<<"New heap:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void insertfun(int *arr, int *n, int k){
    *n=*n+1;
    arr[*n-1]=k;
    //now, we have to do a heapify the last node added in the bottom up manner.
    heapify(arr, *n, *n-1);
}

//now, write the heapify approach in bottom up manner.

void heapify(int *arr, int n, int i){
    //so, we have to heapify the i^th node.
    //find parent of i. and check.
    int parent=(i-1)/2;
    if(arr[i]>arr[parent]){
        swap(&arr[i], &arr[parent]);
        //after swapping-recursively apply heapify on parent node.
        heapify(arr, n, parent);
    }
    else{
        return;
    }
}

void swap(int *a, int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

