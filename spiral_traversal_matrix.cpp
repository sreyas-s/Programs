//spirally traverse a matrix.
#include<iostream>
using namespace std;

void spiralfun(int m, int n, int *arr){
    //arr array with dimensions m by n.
    //passing a 2d array as argument was in correct format?

    //there has to have a pattern-it repeatedly follows
    //when the loop has to stop-that also we have to know.
    //i=0.it will start. j=0 to m-1. then once that's done.
    //i will take the end value of j- and j remains same and i increases till m-1.
    //basically traversing through the boundaries.
    //may be 4 variables we can keep.
    int right, down, left, top;
    //initialize all these? right and left-rows. others-columns.
    right=n-1; 
    down=m-1; 
    left=0; 
    top=0; 
    int dir=0;//direction 0 indicating left to right. 1-top to down. 2-right to left .3-bottom to top
    //initializations done.
    //loop condition to give.
    while(top<=down && left<=right){
        if(dir==0){
            //it means left to right we have to traverse.
            //row is fixed-meaning .top is row value.
            for(int i=left;i<=right;i++){
                cout<<*((arr+(top*n))+i)<<" ";
                //cout<<a[top][i]<<" ";
                }
            //increment top to go to point to next row now.
            top+=1;
            }
        else if(dir==1){
            //it means-we have to traverse from top to down. row changes-column same.
            //what is the column?-right.
            for(int i=top;i<=down;i++){
                cout<<*((arr+(i*n))+right)<<" ";
                //cout<<a[i][right]<<" ";
                }
            //this column-we covered. decrement right pointer .
            right-=1;
            }
        else if(dir==2){
            //it means-we have to traverse from right to left.
            for(int i=right;i>=left;i--){
                //row is same-down.
                cout<<*((arr+(down*n))+i)<<" ";
                //cout<<a[down][i]<<" ";
                }
            //that row is fully covered.
            down-=1;
            }
        else if(dir==3){
            //it means-we have to traverse from down to top.
            for(int i=down;i>=top;i--){
                //column-same.left. row changing.
                cout<<*((arr+(i*n))+left)<<" ";
                //cout<<a[i][left]<<" ";
                }
            //this column is covered.
            left+=1;
            }
        dir=(dir+1)%4;
    }
    //how long this should get-repeated. what is the stopping condition.
}

int main(){
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    spiralfun(m,n, &(a[0][0]));
    return 0;
}

