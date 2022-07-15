#include<iostream>
using namespace std;

void swap(int *, int *);
void insertfun(int *, int);

int main(){
	int n;
	cout<<"Enter the array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	insertfun(a,n);
	cout<<"The sorted array"<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]<<" ";
		}
	return 0;
	}

void insertfun(int arr[], int n){
	int i=0;
	int j=1;
	//pointer i points to element which is in last position of sorted elts.
	//pointer j points to element which marks the beginning od unsorted elts list.
	//so, the loop should run until j points to n.
	//value of i is always 1 less than value of j.
	int k;
	while(j<n){
		if(arr[j]>arr[i]){
			j++;
			i++;
			continue;
			}
		else{
			//arr[j]<arr[i]
			//then we have to swap them and check again with prev element.
			swap(&arr[i], &arr[j]);
			k=i;
			while(k>0){
				if(arr[k-1]>arr[k]){
					swap(&arr[k-1], &arr[k]);
					k--;
					}
				else{
					break;
					}
				}
			i++;
			j++;
			}
		}
	}

void swap(int *a, int *b){
	//basically we have to swap two elements.
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}

	
				
