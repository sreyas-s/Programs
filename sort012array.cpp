#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the array size"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int count0, count1, count2;
    count1=count2=count0=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            count0++;
        }
        else if(a[i]==1){
            count1++;
        }
        else if(a[i]==2){
            count2++;
        }
    }
    //now update the array a using our information.
    for(int i=0;i<count0;i++){
        a[i]=0;
    }
    for(int i=count0;i<(count0+count1);i++){
        a[i]=1;
    }
    for(int i=count0+count1;i<count0+count1+count2;i++){
        a[i]=2;
    }
    cout<<"The sorted array:"<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

