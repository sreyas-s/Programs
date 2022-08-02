#include<iostream>
using namespace std;

int main(){
	int m,n;
	cout<<"Enter number of rows of first matrix"<<endl;
	cin>>m;
	cout<<"Enter number of columns of first matrix"<<endl;
	cin>>n;
	int a[m][n];
	int p,q;
	cout<<"Enter number of rows of second matrix"<<endl;
	cin>>p;
	cout<<"Enter number of columns of second matrix"<<endl;
	cin>>q;
	int b[p][q];
	if(n==p){
		cout<<"Enter the first matrix of size "<<m<<" * "<<n<<endl;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				}
			}
		cout<<"\n Enter the second matrix of size "<<p<<" * "<<q<<endl;
		for(int i=0;i<p;i++){
			for(int j=0;j<q;j++){
				cin>>b[i][j];
				}
			}
		//read the two matrices.
		//now we have to multiply the two matrices and store result in another matrix.
		//resultant matrix size will be?
		//first matrix row size by second matrix column size.
		int c[m][q];
		int sum=0;
		//do we have to initialize this array to be all 0s?-no need.
		//for each i,j position from two matrices we add.
		for(int i=0;i<m;i++){
			for(int j=0;j<q;j++){
				//here we are computing the (i,j)^th entry for resultant matrix c.
				//c[i][j] is the dot product of ith row of a and jth column of b.
				//c[0][1]=a[0].b[0]+a[1].b[1]+..
				c[i][j]=0;
				for(int k=0;k<n;k++){
					c[i][j]=c[i][j]+a[i][k]*b[k][j];
					}
				}
			}
		//now, multiplication is done.
		//display the matrix now.
		cout<<"\nThe resultant matrix after multiplication: "<<endl;
		for(int i=0;i<m;i++){
			cout<<"\n";
			for(int j=0;j<q;j++){
				cout<<c[i][j]<<"\t";
				}
			}
		}
	else{
		cout<<"Matrix Multiplication not possible as dimensions are different"<<endl;
		}
	
	return 0;
	}

