//read a text file and remove all duplicate words from file.
//basically keep the distinct ones and remove the rest.
//we can create a new file and copy distinct words into that file.

//think of very naive algo first.

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main(){
	fstream myfile;
	string str;
	vector<string> v;
	myfile.open("inpfile.txt", ios::in);
	if(myfile.is_open()){
		while(myfile>>str){
			v.push_back(str);
			}
		myfile.close();
		}
	else{
		cout<<"File did not open successfully"<<endl;
		}
	//now we have vector of words from file.
	int n=v.size();
	string word[n];
	for(int i=0;i<=(n-1);i++){
		word[i]=v[i];
		}
	for(int i=0;i<=(n-1);i++){
		cout<<word[i]<<" ";
		}
	if(n!=0){
	//now we have an array of strings.
		int index=1;
		//create another array of strings of same size.
		string wordfinal[n];
		wordfinal[0]=word[0];
		int count=1;
		int cmpcount;
		for(int i=1;i<=(n-1);i++){
			cmpcount=0;
			for(int j=i-1;j>=0;j--){
				if(word[i]==word[j]){
					//means we have to keep the first occurence and delete next ones.
					//remove word[i] and break. basically.
					break;
					}
				else{
					cmpcount++;
					
					}
				}
			if(cmpcount==i){
				//then we can add that word to new array as it succeeded as a distinct element by comparing it with prev ones.
				wordfinal[index]=word[i];
				index++;
				count++;
				}
			}
		cout<<"\n after removing duplicate words"<<endl;	
		for(int i=0;i<=(count-1);i++){
			cout<<wordfinal[i]<<" ";
			}
		
	}
	else{
		//if no word was there, then what to do?
		cout<<"No words in file"<<endl;
		
		}
				
	
	return 0;
	}

		
