//counting sort.

//range of values.

//elts are within this range.
//find min and max once by traversing the array.
//if min is less than 0- add all numbers in array by min and make min 0. and find max again.
//store that min value-in that case and output final niumbers accordingly after subtracting that.


#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;
    int mini, maxi;
    int a[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mini=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<mini){
            mini=a[i];
        }
        else{
            continue;
        }
    }
    //now, we have the mini value.
    maxi=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>maxi){
            maxi=a[i];
        }
        else{
            continue;
        }
    }
    //now, we have the maxi value.
    if(mini<0){
        //then store mini somehwere or no need.
        for(int i=0;i<n;i++){
            a[i]+=-mini;
        }
        //now, mini is 0.
        //now, new maxi will be maxi +-mini.
        maxi=maxi+-mini;
        int exarray[maxi+1];
        //initialize that array with all 0s.
        for(int i=0;i<maxi+1;i++){
            exarray[i]=0;
        }
        //now, traverse the original array a, and update exarray accordingly.
        for(int i=0;i<n;i++){
            exarray[a[i]]+=1;
        }
        //updation done.
        //now, traverse the exarray and get our final sorted array.
        int index=0; //index for traversing in new sorted order.
        for(int i=0;i<maxi+1;i++){
            if(exarray[i]==0){
                continue;
            }
            else{
                //it comes here when we have at least one occurence of i.
                while(exarray[i]>0){
                    a[index]=i+mini;
                    index++;
                    exarray[i]--;
                }
            }
        }
        //now, may be we can print the sorted array.
        cout<<"Array after sorting: "<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    else{
        //if minimum value is >=0.
        //then do the normal stuff.
        int exarray[maxi+1];
        //initialize that array with all 0s.
        for(int i=0;i<maxi+1;i++){
            exarray[i]=0;
        }
        //now, traverse the original array a, and update exarray accordingly.
        for(int i=0;i<n;i++){
            exarray[a[i]]+=1;
        }
        //updation done.
        //now, traverse the exarray and get our final sorted array.
        int index=0; //index for traversing in new sorted order.
        for(int i=0;i<maxi+1;i++){
            if(exarray[i]==0){
                continue;
            }
            else{
                //it comes here when we have at least one occurence of i.
                while(exarray[i]>0){
                    a[index]=i;
                    index++;
                    exarray[i]--;
                }
            }
        }
        //now, may be we can print the sorted array.
        cout<<"Array after sorting: "<<endl;
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}

