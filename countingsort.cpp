#include<iostream>
using namespace std;

void countfun(int *, int);

int main(){
	int n;
	cout<<"Enter the size of the array";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	countfun(a, n);
	cout<<"The sorted array: "<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]<<" ";
		}
	return 0;
	}

void countfun(int *arr, int n){
	int max;
	//first we have to find the maximum element in the array.
	//then we have to declare an array of size max+1.
	max=arr[0];
	for(int i=1;i<=(n-1);i++){
		if(arr[i]>max){
			max=arr[i];
			}
		else{
			continue;
			}
		}
	int countarray[max+1];
	//now again we have to do linear scan of orig array arr and update the countarray.
	//before that we can initialize countarray all values as 0.
	for(int i=0;i<=max;i++){
		countarray[i]=0;
		}
	//initialization of countarray done.
	int x;
	for(int i=0;i<=(n-1);i++){
		x=arr[i];
		countarray[x]=countarray[x]+1;
		}
	//now, countarray has been updated.
	//now, depending on the countarray values we have to update in the orig array so that it will be sorted.
	//traverse the countarray now, and update the orig array arr.
	int index=0;
	for(int i=0;i<=max;i++){
		if(countarray[i]==0){
			continue;
			}
		else{
			while(countarray[i]!=0){
				arr[index]=i;
				index++;
				countarray[i]--;
				}
			}
		}
	//now, the array should be sorted.
	}
