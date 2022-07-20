#include<iostream>
using namespace std;

int binaryfun(int *, int, int, int);

int main(){
	int n,x;
	int index;
	cout<<"Enter the size of array";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	cout<<"Enter the element to be searched";
	cin>>x;
	index=binaryfun(a, 0, n-1, x);
	if(index==-1){
		cout<<"Element "<<x<<" not found in the array"<<endl;
		}
	else{
		cout<<"Element "<<x<<" found at index "<<index<<" in the array"<<endl;
		}
	return 0;
	}

int binaryfun(int *arr, int beg, int end, int x){
	//this is going to be an iterative function.
	while(beg<=end){
		int mid=(beg+end)/2;
		if(x==arr[mid]){
			return mid;
			}
		else if(x>arr[mid]){
			beg=mid+1;
			}
		else{
			end=mid-1;
			}
		}
	return -1;
	}

	
