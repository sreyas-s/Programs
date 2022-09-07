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
    //create a temporary array of size n.
    int temp[n];
    //when we left shift by d elements.
    //so, the last element in the new array will be (last elt in orig array + d)%n. -worked.
    //or alternatively, first elt in new array will be (first elt in orig array-d)%n.?-check this.-no it didnt work.
    for(int i=n-1;i>=0;i--){
        temp[i]=arr[(i+d)%n];
    }
    //now, compy temp array to arr.
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
