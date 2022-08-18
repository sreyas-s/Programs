//deleting an element from array.
#include<iostream>
using namespace std;

void deletefun(int *, int *, int);

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cout<<"Enter the element to be deleted from the array"<<endl;
    cin>>x;
    deletefun(a,&n,x);
    cout<<"Resultant array"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

void deletefun(int *arr, int *n, int x){
    int index=0;
    int flag=0;
    for(int i=0;i<*n;i++){
        if(arr[i]==x){
            index=i;
            flag=1;
            break;
        }
        else{
            continue;
        }
    }
    if(flag==1){
        //element x is found in the array and is present at index.
        //so, now index position onwards till n-2 position in the array should have value of their nxt adres
        //do we have to change the size of array?
        for(int i=index;i<=((*n)-2);i++){
            arr[i]=arr[i+1];
        }
        *n=(*n)-1;
    }
    else{
        //cannot delete as that element is not present.
        return;
    }
}
