//given a number-check if it is palindrome.

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;
    //find out how many digits it have?
    //find out the digits.
    int count=0;
    int temp=n;
    int revnum=0;
    while(temp!=0){
        count++;
        temp=temp/10;
    }
    cout<<"Number of digits: "<<count<<endl;
    temp=n;
    //so, we got the number of digits of the number.
    while(temp!=0){
        revnum=revnum+(temp%10)*pow(10, count-1);
        count--;
        temp=temp/10;
    }
    cout<<"Reverse of number: "<<revnum<<endl;
    if(revnum==n){
        cout<<"Palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }
    return 0;
}

