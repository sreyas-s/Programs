//program to check if a given string is palindrome or not.

//given the head of a single linked list, return true if it is a palindrome.

//let's say the data value in nodes are characters.

//what is the idea?
//Idea-1:

//1. We can form a string by traversing from left to right.
//2. Form another string by rev printing elements in list.
//3. compare the strings. if they are same-then palindrome. else-not.

#include<iostream>
using namespace std;

struct node{
    char data;
    struct node *next;
};

void insertfun(struct node **, char);
void checkpalfun(struct node **);
void revprintfun(struct node **, string *);

int main(){
    struct node *head=NULL;
    int n;
    cout<<"How many nodes you want to enter?"<<endl;
    cin>>n;
    char x;
    cout<<"Enter them:"<<endl;
    for(int i=0;i<n;i++){
	cin>>x;
        insertfun(&head,x);
    }
    //now, we have a linked list formed.
    //now, we should have a function to check if it is palindrome.
    checkpalfun(&head);
    return 0;
}

void insertfun(struct node **headref, char x){
    struct node *p=new node();
    p->data=x;
    p->next=NULL;
    if(*headref==NULL){
        *headref=p;
    }
    else{
        struct node *temp=*headref;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=p;
    }
}

void checkpalfun(struct node **headref){
    if(*headref==NULL){
        cout<<"Palindrome"<<endl;
        return;
    }
    else{
        string str;
        struct node *temp=*headref;
        while(temp!=NULL){
            str=str+(temp->data);
            temp=temp->next;
        }
        //now we have one string. we need one revstring also.
        //call a function to get string rev.
        cout<<str<<endl;
        string revstr;
        revprintfun(headref, &revstr);
        cout<<revstr<<endl;
        if(str==revstr){
            cout<<"Palindrome"<<endl;
        }
        else{
            cout<<"Not a palindrome"<<endl;
        }
    }
}

void revprintfun(struct node **headref, string *revstr){
    //this is gonna be a recursive function.
    struct node *temp=*headref;
    if(temp==NULL){
        return;
    }
    else{
        revprintfun(&(temp->next), revstr);
        *revstr=*revstr+(temp->data);
    }
}



