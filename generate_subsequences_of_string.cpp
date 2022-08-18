//print all subsequences of a string.
#include<iostream>
using namespace std;

void generatesubseqfun(string, int *, int);

int main(){
    string str;
    cout<<"Enter the string";
    cin>>str;
    //current index
    //current string/array.
    int n=str.size();
    //make an array of size n.
    //currarray of size n-and initialize it to all 0s.
    //basically generate all binary strings of length n.
    //correspondingly we will generate subsequences also.
    int currarray[n];
    for(int i=0;i<n;i++){
        currarray[i]=0;
    }
    //initialization-done.
    int currindex=0;
    generatesubseqfun(str, currarray, currindex);
    return 0;
}

void generatesubseqfun(string str, int *currarray, int currindex){
    //print elements when currindex reaches n.(that is, it when it has processed all choices of elements in string)
    int flag=0;
    int n=str.size();
    string subseq="";
    if(currindex==n){
        //it means it has processed all elements.
        for(int i=0;i<n;i++){
            if(currarray[i]==1){
                flag=1;
                subseq=subseq+str[i];
                }
            else{
                continue;
                }
            }
        if(flag==0){
            cout<<"Empty string"<<endl;
            }
        else{
            cout<<subseq<<endl;
            }
        }
        else{
            //in the else part, that is here-write the generic part.
            currarray[currindex]=0;
            generatesubseqfun(str, currarray, currindex+1);
            currarray[currindex]=1;
            generatesubseqfun(str, currarray, currindex+1);
        }
    }

