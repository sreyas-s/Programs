#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of array";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	for(int i=0;i<=(n-1);i++){
		if(a[i]<0){
			a[i]=-1*a[i];
			}
		else{
			continue;
			}
		}
	sort(a, a+n);
	cout<<"The required sorted array of squared elements of original array:"<<endl;
	for(int i=0;i<=(n-1);i++){
		cout<<a[i]*a[i]<<" ";
		}
	return 0;
	}

