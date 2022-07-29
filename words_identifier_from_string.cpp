#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
	string str;
	cout<<"Enter the string"<<endl;
	getline(cin, str);
	vector<string> v;
	string word="";
	int n=str.size();
	for(int i=0;i<=(n-1);i++){
		if(str[i]==' '||str[i]=='\t'){
			if(word!=""){
				v.push_back(word);
				word="";
				}
			}
		else{
			word=word+str[i];
			}
		}
	if(word!=""){
		v.push_back(word);
		}
	//now if we are not wrong, we have identified all the words from string and stored in the vector.
	vector<string>::iterator i;
	cout<<"\n The words in string: "<<endl;
	for(i=v.begin();i<v.end();i++){
		cout<<*i<<" ";
		}
	return 0;
	}

			
			
