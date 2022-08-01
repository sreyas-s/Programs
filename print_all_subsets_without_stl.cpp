//generate all binary strings of length n.
//corresponding to each binary string generated -print the subset corresponding to it.

//program to generate all possible binary strings of length n.


#include<iostream>
using namespace std;

void generatesubsetfun(int *, int *, int, int);

int main(){
	int n;
	cout<<"Enter the size of array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the array elements"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	
	//every element has two choices-to be present in the string/array, or not to be present.
	int currindex=0;
	int currarray[n];
	//initialize currentarray to all 0s.
	for(int i=0;i<n;i++){
		currarray[i]=0;
		}
	generatesubsetfun(a, currarray, currindex, n);
	return 0;
	}

void generatesubsetfun(int *arr, int *currarray, int currindex, int n){
	int count=0;
	if(currindex==n){
		//it means it has processed the choices of all elements in array and reached n.
		//print the currarray.
		cout<<endl;
		//for(int i=0;i<n;i++){
		//	cout<<currarray[i]<<" ";
		//	}
		//Instead of printing the binary string here, we will print subset corresponding to it.
		for(int i=0;i<n;i++){
			if(currarray[i]==0){
				count++;
				continue;
				}
			else{
				cout<<arr[i]<<" ";
				}
			}
		if(count==n){
			cout<<"Empty Subset";
			}	
		}
	else{
		//first make currindex 0 and call for next index.
		currarray[currindex]=0;
		generatesubsetfun(arr, currarray, currindex+1, n);
		//now make currindex as 1 and call for next index.
		currarray[currindex]=1;
		generatesubsetfun(arr, currarray, currindex+1, n);
		}
	}
