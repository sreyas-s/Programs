#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int tonumfun(string);

int main(){
	string str;
	cout<<"Enter the Column Title"<<endl;
	cin>>str;
	int num=tonumfun(str);
	cout<<"Column number is "<<num<<endl;
	return 0;
}

int tonumfun(string str){
	int n=str.size();
	string startstring;
	for(int i=0;i<n;i++){
		startstring=startstring+"A";
		}
	int number;
	number=0;
	//first find the difference from str to startstring.
	int difference=1;
	int index;
	if(str!=startstring){
		for(int i=0;i<n;i++){
			if(str[i]!=startstring[i]){
				index=i;
				break;
				}
			else{
				continue;
				}
			}
		//so from the index point onwards difference starts.
		//26^((n-1)-index)*(str[index]-A) + ..the same for index values staring from index till n-1.
		for(int i=index;i<=(n-1);i++){
			difference=difference+(pow(26, n-1-i)*(str[i]-startstring[i]));
			}
		//now, we have difference.
		for(int i=1;i<=(n-1);i++){
			number+=pow(26,i);
			}
		number+=difference;
		return number;
		}
	else{
		for(int i=1;i<=(n-1);i++){
			number+=pow(26,i);
			}
		number+=1;
		return number;
		}
	}

	
