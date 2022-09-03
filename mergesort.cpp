//merge-sort.

#include<iostream>
using namespace std;

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main(){
    int n;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mergesort(a, 0, n-1);
    cout<<"\nThe array after sorting:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void mergesort(int *arr, int beg, int end){
    //it is a recursive function. So, we have to identify the base case.
    if(beg<end){
        int mid= beg+ (end-beg)/2;
        mergesort(arr, beg, mid);
        mergesort(arr, mid+1, end);
        merge(arr, beg, mid, end);
    }
    else{
        return;
    }
}

void merge(int *arr, int beg, int mid, int end){
    //we have an array arr- and the array's indices beg, mid and end.
    //also, array is sorted from beg to mid and array is sorted from mid+1 to end.
    int n1=mid-beg+1; //number of elements in first array
    int n2=end-mid; //number of elements in second array.
    //copy content of arr from beg to mid to another array. and from mid+1 to end to other array.
    int arr1[n1];
    int arr2[n2];
    int i=0;
    for(int j=beg;j<=mid;j++){
        arr1[i]=arr[j];
        i++;
    }
    cout<<"\n Printing array-1"<<endl;
    for(int k=0;k<n1;k++){
        cout<<arr1[k]<<" ";
    }
    i=0;
    for(int j=mid+1;j<=end;j++){
        arr2[i]=arr[j];
        i++;
    }
    cout<<"\n Printing array-2"<<endl;
    for(int k=0;k<n2;k++){
        cout<<arr2[k]<<" ";
    }
    //now, we have our required contents in arr1 and arr2.
    //now, we can overwrite in arr-whatever we get by merging arrays arr1 and arr2.
    int ptr1, ptr2, ptr3;
    //ptr1 for traversing in arr1.
    //ptr2 for traversing in arr2.
    //ptr3 for traversing in arr3.
    ptr1=0;
    ptr2=0;
    ptr3=beg;
    //ptr3=0; //biggest error of the century.
    while(ptr1<n1 && ptr2<n2){
        if(arr1[ptr1]<=arr2[ptr2]){
            arr[ptr3]=arr1[ptr1];
            ptr3++;
            ptr1++;
        }
        else{
            arr[ptr3]=arr2[ptr2];
            ptr3++;
            ptr2++;
        }
    }
    while(ptr1<n1){
        arr[ptr3]=arr1[ptr1];
        ptr3++;
        ptr1++;
    }
    while(ptr2<n2){
        arr[ptr3]=arr2[ptr2];
        ptr3++;
        ptr2++;
    }
    //at this point-arr is sorted.
}

