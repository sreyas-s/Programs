//Given a decimal number. convert that number to binary.

#include<iostream>
#include<cmath>
using namespace std;

int tobinfun(int);

int main(){
	int n;
	cout<<"Enter the decimal number"<<endl;
	cin>>n;
	int bin;
	bin=tobinfun(n);
	cout<<"The binary number corresponding to decimal number "<<n<<" is "<<bin<<endl;
	return 0;
	}

int tobinfun(int n){
	//how do we normally convert dec to bin.
	//solve an example and generate algo.
	int temp=n;
	int rem;
	int ans=0;
	int count=1;
	while(temp!=0){
		rem=temp%2;
		ans=ans+(rem*count);
		count=count*10;
		temp=temp/2;
		}
	return ans;
	}

		
