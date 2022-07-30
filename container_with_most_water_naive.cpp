//given an integer array height of length n.

//n vertical lines are drawn

//endpoints of i^th line are (i,0) and (i, height[i]).

//we have to find the two lines that together with the x axis form a container- such that
//that container contains the most water.
//Return the maximum amount of water a container can store.

//what is the naive algo?

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of height array";
    cin>>n;
    int h[n];
    cout<<"Enter the array"<<endl;
    for(int i=0;i<=(n-1);i++){
        cin>>h[i];
    }
    //basically maximum area should be achieved.
    //try out all possible combos.
    //area between two lines i and j = min of their height * (j-i)
    int min;
    int area;
    int maxarea;
    int lineindex1, lineindex2;
    for(int i=0;i<=(n-1);i++){//i^th line
            for(int j=i+1;j<=(n-1);j++){//j^th line
                //basically these pointers are for height array?
                if(h[j]<=h[i]){
                    min=h[j];
                }
                else{
                    min=h[i];
                }
                area=(j-i)*min;
                if(j==1){
                    maxarea=area;
                    lineindex1=i;
                    lineindex2=j;
                }
                if(area>maxarea){
                     maxarea=area;
                     lineindex1=i;
                     lineindex2=j;
                    }
                else{
                    area=area;
                }
            }
        }
    cout<<"Maximum area is "<<maxarea<<" and the two lines are "<<lineindex1+1<<" and "<<lineindex2+1<<endl;
    return 0;
}
