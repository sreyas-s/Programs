//move all negative elements to one side of the array. to the end.
//order of positive elements and negative elements should not get changed.

#include<iostream>
using namespace std;

void swap(int *, int *);
void movenegative(int *, int);

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //what is the idea?
    //call a function to do the job anyways.
    movenegative(a,n);
    cout<<"The array after moving negative to the end"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void movenegative(int *arr, int n){
    //what is the idea?
    //consider some boundary cases-like what if all elements are negative-then ?
    //In one linear scan-we can find how many positive lements and negative lements are there.
    //let's do that first.
    int npos, nneg;
    npos=0;
    nneg=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            nneg++;
        }
        else{
            npos++;
        }
    }
    //ok, now we know the count of positive and negative elements.
    //with extra space complexity-it is easily doable.
   int newarr[n];
   int posindex=0;
   int negindex=npos;
   if(npos==n){
       return;
   }
   else if(nneg==n){
       return;
   }
   else{
       for(int i=0;i<n;i++){
           //o to npos-1 full positive and //npos to n-1 full negative.
           if(arr[i]>=0){
               newarr[posindex]=arr[i];
               posindex++;
           }
           else{
               newarr[negindex]=arr[i];
               negindex++;
           }
       }
       //now we have to copy back newarr elements in that order to arr.
       for(int i=0;i<n;i++){
           arr[i]=newarr[i];
       }
   }
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

