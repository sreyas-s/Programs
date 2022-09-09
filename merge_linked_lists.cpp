//merge two sorted linked list.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertfun(struct node **, int);
void print(struct node *);
struct node * merger(struct node *, struct node *);

int main(){
    struct node *head1=NULL; //for first linked list-sorted
    struct node *head2=NULL; //for second linked list-sorted
    struct node *head3=NULL; //for the gonna be merger sorted list.
    int n,m,x;
    cout<<"How many elts entering for first sorted linked list?"<<endl;
    cin>>n;
    cout<<"How many elts entering for second sorted linked list?"<<endl;
    cin>>m;
    cout<<"Enter first linked list-sorted"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&head1, x);
    }
    cout<<"Enter second linked list-sorted"<<endl;
    for(int i=0;i<m;i++){
        cin>>x;
        insertfun(&head2, x);
    }
    head3=merger(head1, head2);
    print(head3);
    return 0;
}

void insertfun(struct node **headref, int x){
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

void print(struct node *headref){
    if(headref==NULL){
        cout<<"List is empty"<<endl;
    }
    else{
        struct node *temp=headref;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}

struct node *merger(struct node *headref1, struct node *headref2){
    //we have two linked lists given which are sorted.
    //how to convert the two pointer algorithm we used for arrays to heere.
    struct node *temp1=headref1;
    struct node *temp2=headref2;
    struct node *temp3=NULL;
    //struct node *prev1=NULL;
    //struct node *prev2=NULL;
    if(temp1==NULL){
        return temp2;
    }
    if(temp2==NULL){
        return temp1;
    }
    //it will come here when both of them have one element at least.
    while(temp1!=NULL && temp2!=NULL){
        //this while loop can break if at least one of them points to NULL.
        if(temp1->data <= temp2->data){
            insertfun(&temp3, temp1->data);//will insert at the end of the list.
          //  prev1=temp1;
            temp1=temp1->next;
        }
        else{
            insertfun(&temp3, temp2->data);
           // prev2=temp2;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL){
        //what if all temp2 is finished but temp1 is remaining.
        insertfun(&temp3, temp1->data);
       // prev1=temp1;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        //what if all temp2 is finished but temp1 is remaining.
        insertfun(&temp3, temp2->data);
        //prev2=temp2;
        temp2=temp2->next;
    }
    return temp3;
}

