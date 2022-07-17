#include<iostream>
using namespace std;

void quickfun(int *, int, int);
int partfun(int *, int, int);
void swap(int *, int *);

int main(){
	int n;
	cout<<"Enter the size of the array";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	quickfun(a, 0, n-1);
	cout<<"The sorted array: "<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]<<" ";
		}
	return 0;
	}

void quickfun(int *arr, int beg, int end){
	int p;
	//what is the base case for stopping the recursion
	if(beg<end){
		p=partfun(arr, beg, end);
		quickfun(arr, beg, p-1);
		//arr[p] is at its correct place.
		quickfun(arr, p+1, end);
		}
	}

int partfun(int *arr, int beg, int end){
	int pivot=arr[end];
	//pivot is the last element in the array.
	int count=beg;
	for(int i=beg;i<=end;i++){
		if(arr[i]>pivot){
			continue;
			}
		else{
			swap(&arr[count], &arr[i]);
			count++;
			}
		}
	//final value of the count gives the final index of the pivot element. 
	//or is it (count-1)?
	return count-1;
	}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}

