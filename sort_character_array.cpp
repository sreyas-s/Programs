//given all lowercase characters.
//basically, sorting a character array of all lower case characters.


#include<iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter the size of character array";
	cin>>n;
	char a[n];
	cout<<"Enter the string"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
		}
	int countarray[26];
	//initialize countarray to be 0.
	for(int i=0;i<26;i++){
		countarray[i]=0;
		}
	//there can be maximum 26 characters.
	//we can implement count sort here.
	//traverse through the caharacter array and update count array.
	for(int i=0;i<=(n-1);i++){
		countarray[a[i]-'a']++;
		}
	//updated the countarray.
	//now traverse countarray and do accordingly.
	int count;
	for(int i=0;i<26;i++){
		if(countarray[i]==0){
			continue;
			}
		else{
			count=countarray[i];
			for(int j=0;j<count;j++){
				cout<<(char)('a'+i);
				}
			}
		}
	return 0;
	}

