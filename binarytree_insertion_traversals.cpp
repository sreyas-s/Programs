//program to populate a binary tree and once populated-traverse it.

#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void insertfun(struct node **, int);
void levelorder(struct node **);
void preorder(struct node **);
void inorder(struct node **);
void postorder(struct node **);

int main(){
    struct node *root=NULL;
    int n;
    cout<<"Entering how many values"<<endl;
    cin>>n;
    int x;
    cout<<"Enter them"<<endl;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&root, x);
    }
    //let's assume that-by this time tree is populated.
    //now, let's print the level order traversal of the tree.
    cout<<"Level order traversal:"<<endl;
    levelorder(&root);
    cout<<"\n Pre-order traversal:"<<endl;
    preorder(&root);
    cout<<"\n In-order traversal:"<<endl;
    inorder(&root);
    cout<<"\n Post-order traversal:"<<endl;
    postorder(&root);
    return 0;
}

void insertfun(struct node **rootref, int x){
    //when called this function to insert a node with value x by traversing level order.
    struct node *p=new node();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    if(*rootref==NULL){
        *rootref=p;
    }
    else{
        //we have to make a queue. initially add root to queue.
        queue<node *> q;
        q.push(*rootref);
        while(!q.empty()){
            struct node *current=q.front();
            if(current->left==NULL){
                current->left=p;
                return;
                }
            if(current->right==NULL){
                    current->right=p;
                    return;
                }
            q.push(current->left);
            q.push(current->right);
            q.pop();
        }
    }
}
               
void levelorder(struct node **rootref){
    if(*rootref==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    else{
        queue<node *> q1;
        q1.push(*rootref);
        while(!q1.empty()){
            struct node *current=q1.front();
            cout<<current->data<<" ";
            if(current->left!=NULL){
                q1.push(current->left);
            }
            if(current->right!=NULL){
                q1.push(current->right);
            }
            q1.pop();
        }
    }
}

void preorder(struct node **rootref){
    //gonna be a recursive function.
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        cout<<temp->data<<" ";
        preorder(&(temp->left));
        preorder(&(temp->right));
    }
}

void inorder(struct node **rootref){
    //gonna be a recursive function.
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        inorder(&(temp->left));
        cout<<temp->data<<" ";
        inorder(&(temp->right));
    }
}

void postorder(struct node **rootref){
    //gonna be a recursive function.
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        postorder(&(temp->left));
        postorder(&(temp->right));
        cout<<temp->data<<" ";
    }
}
