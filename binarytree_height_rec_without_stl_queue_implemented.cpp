//program to compute the height of the tree.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
};

struct qnode{
    struct node *ptr;
    struct qnode *next;
};

//have to write functions for insertion(push), accessing front element(front()) and for deleting element(pop()),

void push(struct qnode **, struct node *);
void pop(struct qnode **);
struct node * front(struct qnode **);
bool empty(struct qnode **);

void insertfun(struct node **, int, struct qnode **);
int heightfun(struct node **);

int main(){
    struct node *root=NULL;
    struct qnode *head=NULL;
    //first we have to populate the binary tree.
    int n;
    cout<<"How many nodes you are entering"<<endl;
    cin>>n;
    int x;
    cout<<"Enter them"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&root, x, &head);
    }
    //by this time-tree is populated.
    int h;
    h=heightfun(&root);
    cout<<"Height of the tree is "<<h<<endl;
    return 0;
}

//all queue functions have been defined.

void insertfun(struct node **rootref, int x, struct qnode **headref){
    struct node *p=new node();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(*rootref==NULL){
        *rootref=p;
    }
    else{
        //we have to use the queue we have implemented. we have to access the functions also.
        //queue<node *> q;
        //q.push(*rootref);
        push(headref,*rootref);
       // bool val=empty(headref);
        while(!empty(headref)){
            struct node *current=front(headref);
            if(current->left==NULL){
                current->left=p;
                break;
            }
            if(current->right==NULL){
                current->right=p;
                break;
            }
            push(headref,current->left);
            push(headref,current->right);
            pop(headref);
        }
    }
}

int heightfun(struct node **rootref){
    if(*rootref==NULL){
        return -1;
    }
    else{
        int h1, h2, ht;
        struct node *temp=*rootref;
        h1=heightfun(&(temp->left));
        h2=heightfun(&(temp->right));
        if(h1>=h2){
            ht=h1;
        }
        else{
            ht=h2;
        }
        return ht+1;
    }
}
   
//implement queue on our own and use queue.
//here we are implementing queue of pointers to node.

void push(struct qnode **headref, struct node *x){
    struct qnode *p=new qnode();
    p->ptr=x;
    p->next=NULL;
    if(*headref==NULL){
        *headref=p;
    }
    else{
        //there is at least one node.
        //we insert in the beginning.
        p->next=*headref;
        *headref=p;
    }
}

void pop(struct qnode **headref){
    //we have to delete the element at the end. (because it is queue.)
    if(*headref==NULL){
        return;
    }
    else{
        //there is at least one element.
        //delete from beginning.
        struct qnode *temp=*headref;
        if(temp->next==NULL){
            //that means we have only element-that is head.
            *headref=NULL;
            return;
        }
        else{
            //if at least two elements are there-then?
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            //loop will stop when temp->next->next is NULL.
            //make temp->next as NULL.
            temp->next=NULL;
        }
    }
}
struct node *front(struct qnode **headref){
    //front element is the last element in the list here.
    if(*headref==NULL){
        return NULL;
    }
    else{
        struct qnode *temp=*headref;
        if(temp->next==NULL){
            return temp->ptr;
        }
        else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            return temp->ptr;
        }
    }
}

bool empty(struct qnode **headref){
    //for checking if queue is empty or not.
    if(*headref==NULL){
        return true;
    }
    else{
        return false;
    }
}
