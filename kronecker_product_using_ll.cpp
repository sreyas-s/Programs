#include<iostream>
using namespace std;

struct matrix{
	int rownumber;
	int columnnumber;
	float value;
	struct matrix *next;
	};


struct matrix * createnode(); //returns a newly created matrix node.
struct matrix * read_matrix(int, int); //this function read the elements of matrix and construct a linked list.
float get_element(struct matrix *, int, int); //this function returns the element at the given position in the matrix.
void end(struct matrix **, int, int, float); //this function inserts given element at the end of the linked list.
void print(struct matrix *, int, int);



int main(){
	struct matrix *head1=NULL;
	struct matrix *head2=NULL;
	int n1,m1; //n is number of rows. m is number of columns. for the first matrix.
	cin>>n1>>m1;
	head1=read_matrix(n1,m1);
	int n2, m2;//number of rows and columns for the second matrix.
	cin>>n2>>m2;
	head2=read_matrix(n2,m2);
	//at this point, we have two linked lists representing two matrices-ready.
	//so far, so good.
	//now, we have to compute the product and store in a 2d array.
	//with the row number of resultant matrix, we can get to know, that entry corresponds to which row number of second matrix
	//with the column number of resultant matrix, we can get to know, that entry corresponds to which column number of second matrix
	int f_rows=n1*n2;
	int f_cols=m1*m2;
	float f_adj[f_rows][f_cols];
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			for(int k=0;k<n2;k++){
				for(int l=0;l<m2;l++){
					f_adj[(i*n2)+k][(j*m2)+l]=get_element(head1, i,j) * get_element(head2, k,l);
					}
				}
			}
		}
	//now, we have to print the final result.
	cout<<"The resultant matrix: "<<endl;
	for(int i=0;i<f_rows;i++){
		for(int j=0;j<f_cols;j++){
			cout<<f_adj[i][j]<<" ";
			}
		cout<<"\n";
		}
	return 0;
}

struct matrix *createnode(){
	struct matrix *p=new matrix();
	return p;
	}

float get_element(struct matrix *ll, int row_pos, int col_pos){
	//from the linked list, we have to 
	int flag=0;
	struct matrix *temp=ll;
	while(temp->rownumber!=row_pos || temp->columnnumber!=col_pos){
		temp=temp->next;
		}
	return temp->value;
	}

void end(struct matrix **ll, int row_pos, int col_pos, float val){
	//it is given as double pointer because we are gonna make changes to this linked list by adding node at the end of the list.
	struct matrix *temp=*ll;
	struct matrix *p=createnode();
	p->rownumber=row_pos;
	p->columnnumber=col_pos;
	p->value=val;
	p->next=NULL;
	if(*ll==NULL){
		*ll=p;
		}
	else{
		while(temp->next!=NULL){
			temp=temp->next;
			}
		temp->next=p;
		}
	}

void print(struct matrix *ll, int nrows, int ncolumns){
	//information given is -a matrix in linked list fromat and its head pointer along with information about number of rows and number of columns.
	//it is stored in a row major order.
	float adj[nrows][ncolumns];
	struct matrix *temp=ll;
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncolumns;j++){
			adj[i][j]=temp->value;
			temp=temp->next;
			}
		}
	//now, we just need to print this matrix.
	for(int i=0;i<nrows;i++){
		for(int j=0;j<ncolumns;j++){
			cout<<adj[i][j]<<"\t";
			}
		cout<<"\n";
		}
	}

struct matrix *read_matrix(int n, int m){
	//we have to create a node.
	//get_element -not using here.
	//we have read n and m. so nm entries are being followed we have to read each entry.
	struct matrix *q=NULL;
	int row_pos, col_pos;
	float val;
	for(int i=0;i<n*m;i++){
		cin>>row_pos>>col_pos;
		cin>>val;
		//now, we have created a node for linked list.
		//we have to add this node at the end of the linked list.
		end(&q, row_pos, col_pos, val);
		}
	//this function has to return the head of the first linked list if am not wrong-how to get that?
	return q;
	}

//for each entry of matrix1, do scalar multiplication with matrix 2 and save entries may be in a linked list.-nnooooooo.

	
		




	
