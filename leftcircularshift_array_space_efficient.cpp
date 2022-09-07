//left curcular shift the array by d positions.

#include<iostream>
using namespace std;

void leftshift(int *, int, int);

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //now, we got the array.
    int d;
    cin>>d;
    leftshift(a, n, d);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void leftshift(int *arr, int n, int d){
    //create a temp variable.
    int temp;
    for(int i=0;i<d;i++){
        //basically since we are doing d left shifts.
        //each time, take the first elt in array. store in temp variable. and shift every element to
        //its left by one pos.-O(n) time.
        temp=arr[0];
        for(int j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
}
