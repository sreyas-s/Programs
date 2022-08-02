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
	if((m==p) && (n==q)){
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
		//now we have to add the two matrices and store result in another matrix.
		//matrix addition is possible only when both matrices have same dimension?
		int c[m][n];
		//do we have to initialize this array to be all 0s?-no need.
		//think about how to add two matrices-we add element by element.
		//for each i,j position from two matrices we add.
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				c[i][j]=a[i][j]+b[i][j];
				}
			}
		//now, addition is done.
		//display the matrix now.
		cout<<"\nThe resultant matrix after addition: "<<endl;
		for(int i=0;i<m;i++){
			cout<<"\n";
			for(int j=0;j<n;j++){
				cout<<c[i][j]<<"\t";
				}
			}
		
		}
	else{
		cout<<"Matrix addition not possible as dimensions are different"<<endl;
		}
	
	return 0;
	}

