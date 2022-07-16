#include<iostream>
using namespace std;

void selectionfun(int *, int);
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
	selectionfun(a, n);
	cout<<"The sorted array"<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]<<" ";
		}
	return 0;
	}

void selectionfun(int arr[], int n){
	int index;
	int min;
	for(int i=0;i<=(n-2);i++){
		//doing linear scan for each iteration.
		min=arr[i];
		index=i;
		for(int j=(i+1);j<=(n-1);j++){
			if(arr[j]<min){
				min=arr[j];
				index=j;
				}
			else{
				continue;
				}
			}
		//now we have found i^th min (really i+1 ^th min.)
		//now we have to swap values.
		//swap(&min, &arr[i]); //the problem here is that, min and arr[i] will get swapped but min is arr[j] for some j. in array two elements have to be swapped.
		//find the j for which min=arr[j].	
		swap(&arr[index], &arr[i]);
	}
}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}

