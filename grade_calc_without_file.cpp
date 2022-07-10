#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string name;
	double mid, end, x;
	vector<double> hw;
	double grade=0;
	int ch, ch1;
	double hwmed=0;
	int vs;
	while(1){
		cout<<"Do you want to enter student details";
		cin>>ch;
		if(ch==1){
			cin>>name;
			cin>>mid;
			cin>>end;
			while(1){
				cout<<"Want to enter hw marks?";
				cin>>ch1;
				if(ch1==1){
					cin>>x;
					hw.push_back(x);
					}
				else{
					break;
					}
				}
			sort(hw.begin(), hw.end());
			vs=hw.size();
			if(vs%2==0){
				hwmed=(hw[vs/2] + hw[(vs/2)-1])/2;
				}
			else{
				hwmed=hw[vs/2];
				}
			grade=(0.4*mid)+(0.4*end)+(0.2*hwmed);
			cout<<"Hello "<<name<<", your final grade is "<<grade<<endl;
			}
			
		else{
			break;
			}
		}
	return 0;
	}

