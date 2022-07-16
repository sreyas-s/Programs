#include<iostream>
using namespace std;

void bubblefun(int *, int);
void swap(int *, int *);

int main(){
	int n;
	cout<<"Enter the array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	//now, call the function which will do the sorting.
	bubblefun(a, n);
	cout<<"The sorted array:"<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]<<" ";
		}
	return 0;
	}

void bubblefun(int *arr, int n){
	cout<<n<<endl;
	int count;
	while(1){
		//have to do linear scan and compare adjacent elements.
		//this is one linear scan. that is not enough.
		for(int k=0;k<=(n-2);k++){
			if(arr[k]<=arr[k+1]){
				continue;
				}
			else{
				swap(&arr[k], &arr[k+1]);
				count++;
				}
			}
		if(count==0){
			break;
			}
		else{
			count=0;
			continue;
			}
		}
	}

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}

