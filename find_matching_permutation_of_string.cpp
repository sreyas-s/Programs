#include<iostream>
#include<string>
using namespace std;

void findmatchfun(string [], int, string);
int checkmatchfun(string, string);

int main(){
	string pattern;
	int n;
	cout<<"How many words you are entering"<<endl;
	cin>>n;
	string words[n];
	cout<<"Enter the words"<<endl;
	for(int i=0;i<n;i++){
		cin>>words[i];
		}
	//now we have the collection of words in array of strings.
	cout<<"Enter the pattern"<<endl;
	cin>>pattern;
	//now we have got all the input required from user.
	//the job left is to find if there are matching words in array corresponding to pattern entered.
	//let's call a function to do that job.
	findmatchfun(words, n, pattern);
	return 0;
	}

void findmatchfun(string words[], int n, string pattern){
	
	int val;
	int flag=0;
	//traverse through the string array.
	for(int i=0;i<n;i++){
		//words[i] is any bijection of pattern-we have to find out.
		//so may be we can call another function to check if words[i] is a match of pattern.
		val=checkmatchfun(words[i], pattern);
		if(val==1){
			flag=1;
			cout<<words[i]<<" ";
			}
		else{
			continue;
			}
		}
	if(flag==0){
		//means -no matching word has been found.
		cout<<"No matching words found in the list"<<endl;
	}
		
}

int checkmatchfun(string str, string pattern){
	//this is the job left now.
	//checking if str is a match for pattern.
	//what are the conditions that we can put-size of the words should be same. number of distinct letters in both should be same.
	//thinking of maintaining two character arrays-one for the pattern and one for the map.
	//have to check if map is matching with the word given.
	int flag=0;
	int k=pattern.size();
	char maparray[k];
	//initialize it with 0s?
	for(int i=0;i<k;i++){
		maparray[i]=0;
		}	
	//str is the word.
	int s=str.size();
	if(s!=k){
		//if sizes are not matching-then definitely not a match.
		return 0;
		}
	else{
		//now, its time to populate the maparray.
		int i=0;
		maparray[i]=str[i];
		//for further elts-we have to check if pattern[i] is any elt that has appeared before. if so-we have to check it's corresponding map.
		for(i=1;i<k;i++){
			//check if pattern [i] has come before.
			for(int j=i-1;j>=0;j--){
				if(pattern[i]==pattern[j]){
					//then what?
					//that means that character has appeared before also.
					//at the j^th place.
					//now we have to check if maparray[j] is same as str[i].
					if(maparray[j]==str[i]){
						//then all good.
						//write maparray[i] as str[i].
						flag=1;
						maparray[i]=str[i];
						break;//break from inner for loop.
						}
					else{
						//then -not a match.
						return 0;
						}
					}
				else{
					continue;
					}
				}
			if(flag==0){
				//it means it has not found character previously.
				//before doing the below step-we need to ensure that str[i] elt has not occured before in maparray so far.
				//till i-1 from 0 we need to check.
				for(int l=(i-1);l>=0;l--){
					if(maparray[l]==str[i]){
						//then it is an indication that it is not a match.
						return 0;
						}
					else{
						continue;
						}
					}
				//if we reached here, then we can do the below step.
				maparray[i]=str[i];
				}
			}
		//if it reaches here-then we can return 1.
		return 1;
		}
	}
			
