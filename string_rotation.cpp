//program to check if one string is a rotation of another string.

#include<iostream>
using namespace std;

int main(){
    string str1;
    cout<<"Enter the first string"<<endl;
    cin>>str1;
    string str2;
    cout<<"Enter the second string"<<endl;
    cin>>str2;
    int flag=0;
    string temp;
    string substr="";
    temp=str1+str1;
    //temp is a concatenation of str1 with itself.
    //now we can check if str2 is a substring of temp-to see if these strings are rotations.
    //how to check if str2 is a substring of temp?
    int n2=str2.size();
    int n1=str1.size();
    cout<<temp<<endl;
    if(n1!=n2){
        cout<<"Not rotations."<<endl;
    }
    else{
        //check if str2 is a substring of temp.
        //temp is of size 2*n1 or 2*n2.
        for(int i=0;i<n2;i++){
            for(int j=0;j<n2;j++){
                substr=substr+temp[i+j];
            }
            if(substr==str2){
                cout<<"Yes, they are rotations."<<endl;
                flag=1;
                break;
            }
            else{
                substr="";
                continue;
            }
        }
        if(flag==0){
            cout<<"Not rotations."<<endl;
        }
    }
    return 0;
}
