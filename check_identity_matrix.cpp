#include<iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter number of rows of matrix"<<endl;
	cin>>m;
	cout<<"Enter number of columns of matrix"<<endl;
	cin>>n;
	int a[m][n];
	int flag=0;
	//for a matrix to be an identity matrix-what are all the conditions?
	//it has to be a square matrix?
	//and all principal diagonal entries should be 1- i.e (i,i) entries and all otehrs should be 0s.
	if(m==n){
		//check for 1s and 0s
		//check for 0s
		cout<<"Enter the matrix of size "<<m<<" * "<<n<<endl;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				}
			}
		for(int i=0;i<n;i++){
			if(a[i][i]==1){
				continue;
				}
			else{
				flag=1;
				break;
				}
			}
		if(flag==0){
			//check for 0s 
			//check if all elements except principal diagonal elements are 1.
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					if(i!=j){
						//check if a[i][j]==0.
						if(a[i][j]==0){
							continue;
							}
						else{
							flag=1;
							break;
							}
						}
					else{
						continue;
						}
					}
				}
				if(flag==1){
					cout<<"Not an Identity matrix"<<endl;
					}
				else{
					cout<<"Given matrix is an Identity matrix"<<endl;
					}
				}
		else{
			cout<<"Not an Identity matrix"<<endl;
			}
		
		}
	else{
		cout<<"Not an Identity matrix"<<endl;
		}
	
	return 0;
	}




