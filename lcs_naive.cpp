//we are given two strings.
//return the length of their longest common subsequence. if there is no common subsequence, return 0.


//naive algorithm will be to first generate all subsequences of first string. and compare each of them with list of subsequences of
//let's first implement naive algorithm.

//generating subsequences of first string and storing in an array- that is the first task.

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void gensubsequence1(int, int *, string);
void gensubsequence2(int, int *, string);
vector<string> v1, v2, v3;

int main(){
    string str1, str2;
   
    cout<<"Enter the first string"<<endl;
    cin>>str1;
    cout<<"Enter the second string"<<endl;
    cin>>str2;
    int n1,n2;
    n1=str1.size();
    n2=str2.size();
    //a subsequence of a string is where some characters are present and some not-order matters.
    //its equivalent to generating subsets of a set/array.
    int curr=0;//current index.
    int currarray[n1];
    for(int i=0;i<n1;i++){
        currarray[i]=0;//initialization.
    }
   // int sub1size=pow(2,n1);
   // int sub2size=pow(2, n2);
   // string sub1[sub1size];
  //  string sub2[sub2size];
   // sub1[0]="";
  //  sub2[0]="";
   // int index=1;
    gensubsequence1(curr, currarray, str1);
    vector<string>::iterator itr, itr2;
   // for(itr=v1.begin();itr!=v1.end();itr++){
     //   cout<<*itr<<endl;
    //}
    int currarray2[n2];
    for(int i=0;i<n2;i++){
        currarray2[i]=0;//initialization.
    }
    curr=0;
    gensubsequence2(curr, currarray2, str2);  
    for(itr=v1.begin();itr!=v1.end();itr++){
        for(itr2=v2.begin();itr2!=v2.end();itr2++){
            if(*itr==*itr2){
                v3.push_back(*itr);
            }
            else{
                continue;
            }
        }
    }
    for(itr=v3.begin();itr!=v3.end();itr++){
        cout<<*itr<<endl;
    }
    //find max length string.
    vector<int> m;
    int ms;
    string s;
    for(itr=v3.begin();itr!=v3.end();itr++){
        s=*itr;
        ms=s.size();
        m.push_back(ms);
    }
    //now we have vector m having sizes of common subsequences.
    //find max in that array.
    int maxi;
    int vs=m.size();
    maxi=m[0];
    for(int i=1;i<vs;i++){
        if(m[i]>maxi){
            maxi=m[i];
        }
        else{
            continue;
        }
    }
    cout<<"max: "<<maxi<<endl;
   
    return 0;
}

void gensubsequence1(int curr_index, int *curr_array, string str){
   int n=str.size();
   string str_new;
   if(curr_index==n){
       for(int i=0;i<n;i++){
           if(curr_array[i]==0){
               continue;
           }
           else{
               str_new+=str[i];
           }
        }
        v1.push_back(str_new);
   }
   else{
       curr_array[curr_index]=0;
       gensubsequence1(curr_index+1, curr_array, str);
       curr_array[curr_index]=1;
       gensubsequence1(curr_index+1, curr_array, str);
   }
}

void gensubsequence2(int curr_index, int *curr_array, string str){
   int n=str.size();
   string str_new;
   if(curr_index==n){
       for(int i=0;i<n;i++){
           if(curr_array[i]==0){
               continue;
           }
           else{
               str_new+=str[i];
           }
        }
        v2.push_back(str_new);
   }
   else{
       curr_array[curr_index]=0;
       gensubsequence2(curr_index+1, curr_array, str);
       curr_array[curr_index]=1;
       gensubsequence2(curr_index+1, curr_array, str);
   }
}

//now, we have v1 and v2.
