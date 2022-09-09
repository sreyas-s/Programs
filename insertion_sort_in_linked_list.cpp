//insertion sort for single linked list.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertionfun(struct node **, int);
void print(struct node *);

int main(){
    struct node *head=NULL;
    int ch;
    int x;
    while(1){
        cout<<"Do you want to insert?"<<endl;
        cin>>ch;
        if(ch==1){
            cout<<"Enter the element to be inserted"<<endl;
            cin>>x;
            insertionfun(&head, x);
        }
        else{
            break;
        }
    }
    print(head);//print the linked list after sorting.
    return 0;
}

void insertionfun(struct node **headref, int x){
    int flag=0;
    struct node *p=new node();
    p->data=x;
    p->next=NULL;
    if(*headref==NULL){
        *headref=p;
    }
    else{
        //there is at least one node.
        struct node *temp=*headref;
        //let's imagine this is the second node getting added.
        //how do we deal with that?
        struct node *prev=NULL;
        if(x<(temp->data)){
            p->next=temp;
            *headref=p;
        }
        else{
            while(x>=(temp->data)){
                prev=temp;
                temp=temp->next;
                if(temp==NULL){
                    flag=1;
                    break;
                }
            }
            if(temp==NULL){
                //it means it has traversed till the end of the list. ending node is now prev.
                prev->next=p;
            }
            else{
                //it means it has stopped at some point before reaching the end of the list.
                //somewhere it found a node whose data is greater than the gonna be inserted node's data.
                p->next=prev->next;
                prev->next=p;
            }
        }
    }
}
//yes, the function is complete.

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

//SORTING SUCCESSFULL.
