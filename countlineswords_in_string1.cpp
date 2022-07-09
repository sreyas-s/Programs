#include<iostream>
using namespace std;

int main(){
	char ch;
	int linec=0;
	int wordc=0;
	int charc=0;
	int flag=0;
	int prev_flag;
	while(cin.get(ch)){
		if(ch=='\n'){
			linec++;
			flag=0;
			}
		else{
			if(ch==' ' || ch=='\t'){
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
		charc++;
		}
	cout<<"Number of lines: "<<linec<<endl;
	cout<<"Number of words: "<<wordc<<endl;
	cout<<"Number of characters: "<<charc<<endl;
	return 0;
	}

