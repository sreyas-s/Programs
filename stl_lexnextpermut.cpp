#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array of integers";
	for(int j=0;j<=(n-1);j++){
		cin>>a[j];
		}
	bool val;
	val=next_permutation(a, a+n);
	if(val==0){
		cout<<"No next permutation";
		}
	else{
		for(int j=0;j<=(n-1);j++){
			cout<<a[j];
		}
	}
	return 0;
	}
