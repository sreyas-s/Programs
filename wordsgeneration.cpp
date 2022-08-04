#include<iostream>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int checkedgefun(char, char, string);
//given a word-find it's edge count-that can be a function here.
void edgecountfun(string);


int main(){
	string word="0011"; //2-uniform word.
	cout<<word<<" ";
        edgecountfun(word);
        bool value=next_permutation(word.begin(), word.end());
	while(value==1){
		cout<<word<<" ";
		edgecountfun(word);
		value=next_permutation(word.begin(), word.end());
		}
	return 0;
	}

void edgecountfun(string word){
	int n;
	n=word.size();
	int edgecount=0;
	set<char> s;
	for(int i=0;i<n;i++){
		s.insert(word[i]);
	}
	set<char>::iterator itr;
	//after that in set s we have all distinct elements.
	//move that into an array of size of set.
	int k=s.size();
	char letterarray[k];
	itr=s.begin();
	for(int i=0;i<k;i++){
		letterarray[i]=*itr;
		itr++;
		}
	//now we have an array of distinct letters in the word.
	//let's create an adjacency matrix of size k*k.
	int adj[k][k];
	//initialize adjacency matrix to be all 0's.
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
	    		adj[i][j]=0;
			}
		}
	//initialization of adjacency matrix done.
	//how to update the adjacency matrix for each pair.
	int val;
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			//letterarray[i] and letterarray[j] are the two vertices here.
	    		//we have to check whether an edge exists between them.
	    		//we can call a function here to check if given a pair and a word-does there exists an edge.
	    		val=checkedgefun(letterarray[i],letterarray[j],word);
	   		adj[i][j]=val;
	    		if(val==1){
	    			edgecount++;
	    			}
			}
		}
	//now, we have populated the adjacency matrix.
	//we have to count the edge counts.
	//print the adjacency matrix and print the edge count
	//cout<<"\n The adjacency matrix:"<<endl;
	//for(int i=0;i<k;i++){
	//	cout<<"\n";
	//	for(int j=0;j<k;j++){
	//		cout<<adj[i][j]<<"\t";
	//		}
	//	}
	edgecount=edgecount/2;	
	cout<<"\n The edge count is "<<edgecount<<endl;
}

int checkedgefun(char a, char b, string str){
	//ofcourse a and b are present in str.
	//remove all other characters from str other than a and b.
	//how to remove characters from string other than a and b.
	//otherwise we do not need to remove other characters-we just need to see the pattern of a's and b's in the string.
	//declare and initialize a new string.
	int flag=0;
	string strnew="";
	int m=str.size();
	if(a==b){
		return 0;
		}
	else{
		for(int i=0;i<m;i++){
			if(str[i]==a||str[i]==b){
				strnew=strnew+str[i];
				}
			else{
				continue;
				}
			}
		//so, we have the string strnew now.
		//the string strnew will tell if there is an edge or not.
		int s=strnew.size();
		for(int i=0;i<(s-1);i++){
			//basically strnew[i] should not be equal to strnew[i+1].
			if(strnew[i]!=strnew[i+1]){
				continue;
				}
			else{
				flag=1;
				break;
				}
			}
		if(flag==1){
			return 0;
			}
		else{
			return 1;
			}
		}
	}

	
//everything is correct except that self loops are being counted. from a vertex to itself-there is no edge.
//how to avoid that.
//we have to check if a==b, then-there is no edge.
//else-only check for everything else.	
	
		
	
	
	


