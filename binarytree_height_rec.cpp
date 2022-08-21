//program to compute the height of the tree.

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
};

void insertfun(struct node **, int);
int heightfun(struct node **);

int main(){
    struct node *root=NULL;
    //first we have to populate the binary tree.
    int n;
    cout<<"How many nodes you are entering"<<endl;
    cin>>n;
    int x;
    cout<<"Enter them"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&root, x);
    }
    //by this time-tree is populated.
    int h;
    h=heightfun(&root);
    cout<<"Height of the tree is "<<h<<endl;
    return 0;
}

void insertfun(struct node **rootref, int x){
    struct node *p=new node();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(*rootref==NULL){
        *rootref=p;
    }
    else{
        queue<node *> q;
        q.push(*rootref);
        while(!q.empty()){
            struct node *current=q.front();
            if(current->left==NULL){
                current->left=p;
                break;
            }
            if(current->right==NULL){
                current->right=p;
                break;
            }
            q.push(current->left);
            q.push(current->right);
            q.pop();
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
