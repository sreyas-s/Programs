#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	fstream myfile;
	string current;
	char ch;
	int linec=0;
	int wordc=0;
	int charc=0;
	myfile.open("input8.txt", ios::in);
	if(myfile.is_open()){
		while(getline(myfile, current)){
			linec=linec+1;
			}
		myfile.close();
		}
	else{
		cout<<"File not able to open";
		}
	
	cout<<"Number of lines: "<<linec<<endl;
	myfile.open("input8.txt", ios::in);	
	if(myfile.is_open()){
		while(myfile>>current){
			wordc=wordc+1;
			}
		myfile.close();
		}
	else{
		cout<<"File not able to open";
		}
	cout<<"Number of words: "<<wordc<<endl;
	myfile.open("input8.txt", ios::in);
	if(myfile.is_open()){
		while(myfile.get(ch)){
			charc=charc+1;
			}
		myfile.close();
		}
	else{
		cout<<"File not able to open";
		}
	
	cout<<"Number of characters: "<<charc<<endl;
			
	return 0;
	}

