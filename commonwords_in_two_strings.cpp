#include<iostream>
#include<string>
#include<vector>
#include<iterator>
using namespace std;

int main(){
	string str1, str2;
	cout<<"Enter the first string"<<endl;
	getline(cin, str1);
	cout<<"Enter the second string"<<endl;
	getline(cin, str2);
	vector<string> v1, v2;
	int n1, n2;
	n1=str1.size();
	n2=str2.size();
	string word="";
	for(int i=0;i<=(n1-1);i++){
		if(str1[i]==' '||str1[i]=='\t'){
			if(word!=""){
				v1.push_back(word);
				word="";
				}
			}
		else{
			word=word+str1[i];
			}
		}
	if(word!=""){
		v1.push_back(word);
		}
	word="";
	for(int i=0;i<=(n2-1);i++){
		if(str2[i]==' '||str2[i]=='\t'){
			if(word!=""){
				v2.push_back(word);
				word="";
				}
			}
		else{
			word=word+str2[i];
			}
		}
	if(word!=""){
		v2.push_back(word);
		}
	
	//now, we have two vectors v1 and v2, where-in we have stored words from two strings.
	//next aim is to find out the common words.
	//first, we will do the naive and then will try to do it efficiently.
	cout<<"\n Common words:"<<endl;
	int count=0;
	vector<string>::iterator i1, i2;
	for(i1=v1.begin();i1<v1.end();i1++){
		for(i2=v2.begin();i2<v2.end();i2++){
			if(*i1==*i2){
				count++;
				cout<<*i1<<" ";
				}
			else{
				continue;
				}
			}
		}
	if(count==0){
		cout<<"No common words"<<endl;
		}
		
	return 0;
	}

	
	
			
