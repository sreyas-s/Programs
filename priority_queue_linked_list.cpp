//priority queue using linked list.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void insertfun(struct node **, struct node **, int);
void deletefun(struct node **, struct node **);
void peekfun(struct node **, struct node **);
void displayfun(struct node **, struct node **);

int main(){
    struct node *front=NULL;//here front means head of the list.
    struct node *rear=NULL;
    //now, let's say we are implementing the ascending priority queue-elt with lesser value-higher priority.
    //we have to implement three basic operations of P.Q
    int ch;
    int x; //dataitem
    while(1){
        cout<<"Enter the choice: \n 1. Insert \n 2. Delete \n 3. Peek \n 4. Display Queue from front to rear \n 5. Exit \n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter the item"<<endl;
                    cin>>x;
                    insertfun(&front, &rear, x);
                    break;
            case 2: deletefun(&front, &rear);
                    break;
            case 3: peekfun(&front, &rear);
                    break;
            case 4: displayfun(&front, &rear);
                    break;
            case 5: return 0;
            default: cout<<"Invalid choice"<<endl;
        }
    }
    return 0;
}
//now, write the functions.

void insertfun(struct node **frontref, struct node **rearref, int x){
  //  int flag=0;
    struct node *p=new node();
    p->data=x;
    p->next=NULL;
    if(*frontref==NULL){
        *frontref=p;
        *rearref=p;
    }
    else{
        //if exactly 1 element only is there. then?
        if(*frontref==*rearref){
            struct node *temp=*frontref;
            //compare temp->data and p->data.
            if(temp->data >= p->data){
                //means-p should come before temp.
                p->next=temp;
                *frontref=p;
            }
            else{
                temp->next=p;
                *rearref=p;
            }
        }
        else{
            //at least two elements are there in the queue when it comes here.
            struct node *temp=*frontref;
            struct node *prev=NULL;
            if(p->data < temp->data){
                p->next=temp;
                *frontref=p;
            }
            else{
                while(p->data >= temp->data){
                    prev=temp;
                    temp=temp->next;
                    if(temp==NULL){
                      //  flag=1;
                        break;
                    }
                }
              //  cout<<"\n prev node data: "<<prev->data<<endl;
                //after this while loop, we stop at a point where we can insert node p.
                if(temp==NULL){
                    //if temp became null, it means we traversed whole list.
                    prev->next=p;
                    *rearref=p;
                }
                else{
                    //if we did not stop the while loop because temp became NULL.
                    p->next=prev->next;
                    prev->next=p;
                }
            }
        }
    }
}







void deletefun(struct node **frontref, struct node **rearref){
    if(*frontref==NULL){
        cout<<"Queue Underflow"<<endl;
    }
    else{
        //means at least one element is there.
        //if only one element is there, then
        if(*frontref==*rearref){
            *frontref=(*frontref)->next;
            *rearref=(*rearref)->next;
        }
        else{
            *frontref=(*frontref)->next;
        }
    }
}

void peekfun(struct node **frontref, struct node **rearref){
    if(*frontref==NULL){
        cout<<"Queue is empty. Nothing to peek at."<<endl;
    }
    else{
        cout<<"Front element in the queue is "<<(*frontref)->data<<endl;
    }
}

void displayfun(struct node **frontref, struct node **rearref){
    if(*frontref==NULL){
        cout<<"Queue is empty."<<endl;
    }
    else{
        struct node *temp=*frontref;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
}
