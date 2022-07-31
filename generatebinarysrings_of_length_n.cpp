//program to generate all possible binary strings of length n.


#include<iostream>
using namespace std;

void generatebin(int *, int, int);

int main(){
	int n;
	cout<<"Enter the size of binary array"<<endl;
	cin>>n;
	//every element has two choices-to be present in the string/array, or not to be present.
	int currindex=0;
	int currarray[n];
	//initialize currentarray to all 0s.
	for(int i=0;i<n;i++){
		currarray[i]=0;
		}
	generatebin(currarray, currindex, n);
	return 0;
	}

void generatebin(int *currarray, int currindex, int n){
	if(currindex==n){
		//it means it has processed the choices of all elements in array and reached n.
		//print the currarray.
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<currarray[i]<<" ";
			}
		}
	else{
		//first make currindex 0 and call for next index.
		currarray[currindex]=0;
		generatebin(currarray, currindex+1, n);
		//now make currindex as 1 and call for next index.
		currarray[currindex]=1;
		generatebin(currarray, currindex+1, n);
		}
	}
