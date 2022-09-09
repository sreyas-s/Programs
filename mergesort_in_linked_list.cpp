//write the merge sort for linked list.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertfun(struct node **, int);
void print(struct node *);
struct node * merger(struct node *, struct node *);
void mergesort(struct node **);

int main(){
    int n;
    struct node *head=NULL;
    int x;
    cout<<"How many elements"<<endl;
    cin>>n;
    cout<<"Enter them"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&head, x);
    }
    mergesort(&head);
    print(head);
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

void mergesort(struct node **headref){
    if(*headref==NULL || (*headref)->next==NULL){
        return;
    }
    else{
        //we have to split into two halves. and recursively apply merge sort on both of the list.
        //first we can get count of the list by traversing once.
        //then when count/2 node comes, we take that.
        struct node *list1;
        struct node *list2;
        //let's count elements in linked list.
        int count=0;
        struct node *temp=*headref;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        //now, we have the count.
        temp=*headref;
        list1=*headref;
        for(int i=1;i<(count/2);i++){
            temp=temp->next;
        }
       
        list2=temp->next;
        temp->next=NULL;
        mergesort(&list1);
        mergesort(&list2);
        *headref=merger(list1, list2);
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

