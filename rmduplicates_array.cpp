#include<iostream>
using namespace std;

//do the same question taking input from file also.

int main(){
	int n;
	cout<<"Enter the size of the array";
	cin>>n;
	if(n==0){
		cout<<"It is an empty array. ";
		}
	else{
		int a[n];
		cout<<"Enter the array elements";
		for(int i=0;i<=(n-1);i++){
			cin>>a[i];
			}
		int temp=a[0];
		int i=0; //pointer i value updates when next distinct element appears.
		for(int j=1;j<=(n-1);j++){
			if(temp==a[j]){
				continue;
				}
			else{
				i=i+1;
				temp=a[j];
				a[i]=a[j];
				}
			}
		cout<<"The output array after removing duplicates: "<<endl;
		for(int k=0;k<=i;k++){
			cout<<a[k]<<" ";
			}
		}
		return 0;
	}
	


