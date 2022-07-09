#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	int flag=0;
	int wordc=0;
	int prev_flag;
	getline(cin, str);
	int n=str.size();
	for(int i=0;i<=(n-1);i++){
		if(str[i]==' '||str[i]=='\t'){
			flag=0;
			}
		else{
			prev_flag=flag;
			if(prev_flag==0){
				wordc++;
				}
			flag=1;
			}
		}
	cout<<"Number of words: "<<wordc<<endl;
	return 0;
	}

