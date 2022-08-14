#include<iostream>
#include<fstream>
using namespace std;

void checkbalancefun(char *, string, int *);

int main(){
	fstream myfile;
	myfile.open("programfile.txt", ios::in);
	char ch;
	string str="";
	if(myfile.is_open()){
		//if file is opened successfully, then..
		while(myfile.get(ch)){
			//read till end of file.
			//reading character by character.
			//basically we are only interested in parenthesis.
			if(ch=='('||ch==')'||ch=='{'||ch=='}'||ch=='['||ch==']'){
				str=str+ch;
				}
			else{
				continue;
				}
			}
		myfile.close();
		}
	else{
		cout<<"File not opened successfully"<<endl;
		}
	//now, it is back to our previous problem-we have a string of expression-we have to check if it is balanced or not.
	int n=str.size();
	char a[n];
	int top=-1;
	checkbalancefun(a, str, &top);
	return 0;
	}

void checkbalancefun(char *arr, string str, int *top){
	//traverse string and do push or pop from stack accordingly.
	int n=str.size();
	int flag=0;
	for(int i=0;i<n;i++){
		if(str[i]=='('||str[i]=='{'||str[i]=='['){
			//we have to push that character to stack -this time, because it is an opening bracket.
			*top+=1;
			arr[*top]=str[i];
			}
		else{
			//then it might be a closing bracket-in that case, we have to look at the top element of stack-and check if brackets are matching.
			//we can have an if-else-if ladder and check.
			if(str[i]==')'){
				if(*top!=-1){
					if(arr[*top]=='('){
						//proceed with pop-operation and continue.
						*top-=1;
						continue;
						}
					else{
						flag=1;
						break;
						}
					}
				else{
					//if stack is empty-and we see a closing bracket-
					flag=1;
					break;
					}
				}
			else if(str[i]=='}'){
				if(*top!=-1){
					if(arr[*top]=='{'){
						//proceed with pop-operation and continue.
						*top-=1;
						continue;
						}
					else{
						flag=1;
						break;
						}
					}
				else{
					//if stack is empty-and we see a closing bracket-
					flag=1;
					break;
					}
				}
			else if(str[i]==']'){
				if(*top!=-1){
					if(arr[*top]=='['){
						//proceed with pop-operation and continue.
						*top-=1;
						continue;
						}
					else{
						flag=1;
						break;
						}
					}
				else{
					//if stack is empty-and we see a closing bracket-
					flag=1;
					break;
					}
				}
			}
		}
	//at the end-stack should be empty.
	//if either flag is 1 or stack is not empty-it means-not balanced parenthesis-else it is balanced one.
	if(*top!=-1 || flag==1){
		cout<<"Not balanced"<<endl;
		}
	else{
		cout<<"Balanced"<<endl;
		}
	}

			
					
			

