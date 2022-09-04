#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(string, string);

int main(){
	vector<string> v;
	string str;
	while(cin){
		cin>>str;
		if(str=="0.0.0.0"){
			break;
			}
		v.push_back(str);
		}
	//we have an array of strings now.
	sort(v.begin(), v.end(), comp);
	vector<string>::iterator itr;
	for(itr=v.begin();itr!=v.end();itr++){
		cout<<*itr<<" ";
		}
	return 0;
	}

bool comp(string v1, string v2){
	//define the comparison between two strings.
	//find out the first number.
	string str1;
	string str2;
	int ns1,ns2;
	int num1, num2;
	ns1=v1.size();
	ns2=v2.size();
	for(int i=0;i<ns1;i++){
		if(v1[i]=='.'){
			break;
			}
		else{
			str1=str1+v1[i];
			}
		}
	for(int i=0;i<ns2;i++){
		if(v2[i]=='.'){
			break;
			}
		else{
			str2=str2+v2[i];
			}
		}
	//now, in str1 and str2 we have two numbers.
	num1=stoi(str1);
	num2=stoi(str2);
	if(num1<=num2){
		return true;
		}
	else{
		return false;
		}
	}
		
