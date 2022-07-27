//we are given two input files. have to read both files and identify common words in both of them.

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int main(){
	fstream myfile;
	string word1, word2;
	string str;
	vector<string> v1, v2;
	myfile.open("file1.txt", ios::in);
	if(myfile.is_open()){
		while(myfile>>word1){
			v1.push_back(word1);
			}
		myfile.close();
		}
	else{
		cout<<"Not able to open file1"<<endl;
		}
	myfile.open("file2.txt", ios::in);
	if(myfile.is_open()){
		while(myfile>>word2){
			v2.push_back(word2);
			}
		myfile.close();
		}
	else{
		cout<<"Not able to open file2"<<endl;
		}
	//now we have two vectors v1 and v2 which have all the words present in files 1 and 2.
	//now we can verify that by printing the vector elements by iterating over it.
	int n1, n2;
	n1=v1.size();
	n2=v2.size();
	int count=0;
	//now after verifying the vectors-we can cross check for similarity.
	cout<<"Common words are :"<<endl;
	for(int i=0;i<=(n1-1);i++){
		for(int j=0;j<=(n2-1);j++){
			if(v1[i]==v2[j]){
				count++;
				cout<<v1[i]<<" ";
				}
			else{
				continue;
				}
			}
		}
	if(count==0){
		cout<<"No common words found."<<endl;
		}
	return 0;
}
	

