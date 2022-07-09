#include<iostream>
#include<fstream>
using namespace std;

int main(){
	fstream myfile;
	int linec=0;
	int wordc=0;
	int charc=0;
	char ch;
	int flag,prev_flag;
	//when we will detect a word?
	flag=0;//indicates currently whitespace is seen. 0 to 1 is a word count.
	myfile.open("input9.txt", ios::in);
	if(myfile.is_open()){
		while(myfile.get(ch)){
			charc++;
			if(ch=='\n'){
				linec++;
				flag=0;
				}
			else{
				if(ch==' '||ch=='\t'){
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
			}
		myfile.close();
	}
	cout<<"Number of lines: "<<linec<<endl;
	cout<<"Number of words: "<<wordc<<endl;
	cout<<"Number of characters: "<<charc<<endl;
	return 0;
}
	
