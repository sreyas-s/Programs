//reverse a linked list in groups.

//we have to have a global head -

//we have to have multiple local heads?


#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};


void insertfun(struct node **, int);
void revgroupfun(struct node **, int);
void displayfun(struct node **);


int main(){
    
    struct node *head=NULL;
    int ch,n;
    while(1){
        cout<<"Want to insert?"<<endl;
        cin>>ch;
        if(ch==1){
            cout<<"Enter element"<<endl;
            cin>>n;
            insertfun(&head, n);
        }
        else{
            break;
        }
    }
    int k;
    cout<<"Enter group size"<<endl;
    cin>>k;
    revgroupfun(&head, k);
    cout<<"After reversing in groups"<<endl;
    displayfun(&head);
    return 0;
}

void insertfun(struct node **headref, int n){
    struct node *p=new node();
    p->data=n;
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

void revgroupfun(struct node **headref, int k){
    //k is the group size.
    //we have to count the number of nodes in the list first.
    int count=0;
    if(*headref==NULL){
        count=0;
    }
    else{
        struct node *temp=*headref;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
    }
    //so, at this point-we have the count of number of nodes that are there in the list.
    int groups;
    //groups variable will store how many groups are there.
    //have to check if count is a multiple of k.
    if(count % k ==0){
       groups=count/k; 
    }
    else{
        groups=(count/k)+1;
    }
    //so, at this point-we also know number of groups that are going to be there.
    //declare array for storing pointers for head of each group and last node of each group.
    struct node * headarray[groups];
    struct node * lastarray[groups]; 
    
    struct node *currentone=*headref;
    struct node *prev=NULL;
    struct node *nextone=NULL;
    
    for(int i=0;i<groups;i++){
        //In each group, there are at most. k elements.
        //whatever is the currentone-will be lastnode of this group after reversal.
        lastarray[i]=currentone;
        for(int j=0;j<k;j++){
            if(currentone==NULL){
                break;
            }
            else{
                nextone=currentone->next;
                currentone->next=prev;
                prev=currentone;
                currentone=nextone;
            }
        }
        headarray[i]=prev;
        //currently currentone and nextone are pointing to next element after prev.
        //again initialize prev=NULL.
        prev=NULL;
    }
    //for each group-we found out head node and last node.
    //now, we have to connect them.
    *headref=headarray[0];
    for(int i=0;i<groups;i++){
        lastarray[i]->next=headarray[i+1];
        }
    lastarray[groups-1]->next=NULL;
}

void displayfun(struct node **headref){
    if(*headref==NULL){
        cout<<"Empty list"<<endl;
    }
    else{
        struct node *temp=*headref;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
