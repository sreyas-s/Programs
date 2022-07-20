#include<iostream>
using namespace std;

int binaryfun(int *,int, int, int);

int main(){
	int n, x;
	int index;
	cout<<"Enter the array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	//here we are searching for an element in the array.
	cout<<"Enter the element to be searched";
	cin>>x;
	//call for function.
	index=binaryfun(a,0,n-1,x);
	if(index==-1){
		cout<<"Element "<<x<<" not found in the array"<<endl;
		}
	else{
		cout<<"Element "<<x<<" found at index "<<index<<" in the array"<<endl;
		}
	return 0;
	}

int binaryfun(int *arr, int beg, int end, int x){
	//we have been given a sorted array arr
	//compare with middle elt and accordingly go to left half or right half.
	//we have to repeatedly do this till what point?
	//what is the stopping point?
	//what if the starting index and ending index are same-that is fine.
	//we can do till that point.
	//ending index and starting index should not cross.
	while(beg<=end){
		int mid;
		mid=(beg+end)/2;
		if(x==arr[mid]){
			return mid;
			}
		else if(x>arr[mid]){
			return binaryfun(arr, mid+1, end, x);
			}
		else{
			return binaryfun(arr, beg, mid-1, x);
			}
	}
	
	return -1;//if elt has not been found in array
}
	
	
	
