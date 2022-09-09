//heapsort.

#include<iostream>
using namespace std;

void heapsort(int *, int);
void heapify(int *, int, int);
void swap(int *, int *);

int main(){
    int n;
    cout<<"Enter size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //now, we got the array,
    heapsort(a, n);
    cout<<"After sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void heapsort(int *arr, int n){
    //have to do heapify procedure for elements of array from index n/2-1 to 0 in reverse order.
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr, n, i);
    }
    //after heapifying for all those elts-now we have heap.
    //we have to extract max each time and keep in the last index of array.
    for(int i=n-1;i>=0;i--){
        swap(&arr[0], &arr[i]); //bringing the last elements in correct place.
        //after swapping, we have to heapify the element which was swapped to first place.
        heapify(arr, i, 0); //heapify root elyt to get highest elt at root again. and max elts in heap are i
    }
}

//we have to write heapify function and swap function.

void heapify(int *arr, int n, int i){
    //array has n elements and we have to heapify the i^th element.(reading the function with arguments)
    int max_elt=i;
    int lc=2*i+1;
    int rc=2*i+2;
    //current index we are gonna heapify is i.
    //left child of index i is at position 2i+1.
    //right child of index i is at position 2i+2.
    //we have to compare if arr[i]>= both arr[lc] and arr[rc].
    //n is the number of elts in array so when we calculate lc and rc they have to be less than n.
    if(lc<n && arr[lc]>arr[max_elt]){
        max_elt=lc;
    }
    if(rc<n && arr[rc]>arr[max_elt]){
        max_elt=rc;
    }
    //so suppose the node at i was violating heap property,
    if(max_elt!=i){
        //then we have to swap i with max_elt.
        swap(&arr[i], &arr[max_elt]);
        //after swapping we get another tree. we have to heapify that also.
        heapify(arr, n, max_elt);
    }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
