#include<iostream>
using namespace std;

void maxsumfun(int *, int);

int main(){
	int n;
	cout<<"Enter the array size";
	cin>>n;
	int a[n];
	cout<<"Enter the array";
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	//now we have the array.
	//call function which will find the starting and ending index and sum of subarray having maxsum.
	maxsumfun(a, n);
	return 0;
	}

void maxsumfun(int *arr, int n){
	//starting at 0^th index -go till (n-1)^th index and check for all possible subarrays starting at these points.
	int max,sum;
	int si,fi;
	int globalmax;
	int global_si, global_fi;
	si=0;
	fi=0;
	int realmax;
	int real_si, real_fi;
	//int maxarray[n];
	for(int i=0;i<=(n-1);i++){
		max=arr[i];
		sum=arr[i];
		//next loop should start from i+1.
		for(int j=i+1;j<=(n-1);j++){
			sum=sum+arr[j];
			if(sum>max){
				max=sum;
				si=i;
				fi=j;
				}
			else{
				continue;
				}
			}
		if(i==0){
			globalmax=max;
			global_si=si;
			global_fi=fi;
			}
		else{
			if(globalmax>max){
				realmax=globalmax;
				real_si=global_si;
				real_fi=global_fi;
				}
			else{
				realmax=max;
				real_si=si;
				real_fi=fi;
				}
			}
		}
	
	cout<<"The maximum sum is "<<realmax<<endl;
	cout<<"The starting index is "<<real_si<<" and ending index is "<<real_fi<<endl;
	}
	
		
			
