#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the array"<<endl;
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	bool val=next_permutation(a, a+n);
	if(val==1){
		//print the array.
		for(int i=0;i<=(n-1);i++){
			cout<<a[i]<<" ";
			}
		}
	else{
		cout<<"No next permutation possible lexicographically"<<endl;
		}
	return 0;
	}
