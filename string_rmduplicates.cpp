#include<iostream>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string";
	getline(cin, str);
	//now we have to scan the string once and wherever a letter or character is getting repeated we have to avoid it.
	//str can be thought of as array of characters also.
	//find the size of string first.
	int n=str.size();
	if(n==0){
		cout<<"Empty string";
		}
	else{
		//now we got the number of characters present in string.
		//now we have to do linear scan and maintain pointers.
		int temp=str[0];
		int i=0;
		for(int j=1;j<=(n-1);j++){
			if(temp==str[j]){
				continue;
				}
			else{
				i=i+1;
				temp=str[j];
				str[i]=str[j];
				}
			}
		cout<<"The string after removing duplicates:"<<endl;
		for(int k=0;k<=i;k++){
			cout<<str[k];
			}
		}
		return 0;
	}
