#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.clear();
    int count=0;
    //we have to make sure we see n # symbols.
    int degree=0;
    int flag=0;
    //considering a legit input,
    char ch;
    while(cin>>ch){
        if(ch=='#'){
            if((degree%2)!=0){
                flag=1;
                break;
                }
            count++;
            degree=0;
        }
        else{
            degree++;
        }
        if(count==n){
            break;
        }
    }
    if(flag==1){
        cout<<"false";
    }
    else{
        cout<<"true";
    }
    return 0;
}

