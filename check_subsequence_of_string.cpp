//program to check if a given string is a substring of another string.

#include<iostream>
using namespace std;

void checkfun(string, string);

int main(){
    string str1, str2;
    cout<<"Enter the string"<<endl;
    cin>>str1;
    cout<<"Enter the string -which has to be checked if it is a subsequence"<<endl;
    cin>>str2;
    checkfun(str1, str2);
    return 0;
}

void checkfun(string str1, string str2){
    //what is the idea?
    //ae is a subsequence of abcde.
    //how to ensure that?
    int flag=0;
    int index=0;
    int count=0;
    int n1=str1.size();
    int n2=str2.size();
    if(n2>n1){
        cout<<"Not a subsequence"<<endl;
        return;
    }
    else{
        //if the sizes are valid-we come here for further inspection.
        //we traverse the tobecheked string and if we find
        for(int i=0;i<n2;i++){
            for(int j=index;j<n1;j++){

                if(str2[i]==str1[j]){
                    count++;
                    index=j;
                    break;//break from inner loop so that we can carry on with next character in the string.    
                }
                else{
                    continue;
                }
            }
        }
        if(count==n2){
            cout<<"Yes, it is a subsequence."<<endl;
        }
        else{
            cout<<"Not a subsequence"<<endl;
        }
    }
}
