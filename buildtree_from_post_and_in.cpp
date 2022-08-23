//given inorder and postorder-compute preorder and build tree.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * createnode(int);
struct node * buildtree(int *, int *, int, int, int);
int findpos(int *, int, int, int);
void preorder(struct node **);
void inorder(struct node **);
void postorder(struct node **);

int main(){
    int n;
    cout<<"Number of nodes in the tree?"<<endl;
    cin>>n;
    int post[n];
    int in[n];
    cout<<"Enter the postorder traversal:"<<endl;
    for(int i=0;i<n;i++){
        cin>>post[i];
    }
    cout<<"Enter the inorder traversal:"<<endl;
    for(int i=0;i<n;i++){
        cin>>in[i];
    }
    //we have got the inputs required to work for finding the tree corresponding to it.
    struct node *root=NULL;
    root=buildtree(post, in, 0, n-1, n);//0 is the start and n-1 is the ending position-for searching in in array.
    //after building the tree-we can do the postorder traversal.
    cout<<"\n Post order traversal of this tree:"<<endl;
    postorder(&root);
    cout<<"\n Pre order traversal of this tree:"<<endl;
    preorder(&root);
    cout<<"\n Inorder traversal of this tree:"<<endl;
    inorder(&root);
    return 0;
}

struct node * createnode(int x){
    struct node *p=new node();
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

struct node * buildtree(int *post, int *in, int start, int end, int n){ //understand the recursive function-more well.
    //this start and end indicates the traversal start and end positions at the inorder array.
    if(start>end){
        return NULL;
    }
    static int index=n-1; //static int is important.-without that it wont work.
    int curr=post[index];
    index--;
    struct node *ptr=createnode(curr);
    //now, we have to build the left subtree and right subtree of this node.
    //find the position of curr in inorder.
    //call function for that.
    if(start==end){
        return ptr;
    }
    int pos;
    pos=findpos(in, start, end, curr);
    ptr->right=buildtree(post, in, pos+1, end, n);
    ptr->left=buildtree(post, in, start, pos-1, n);
    return ptr;
}

int findpos(int *in, int start, int end, int curr){
    //we have to search for curr in the in array.
    for(int i=start;i<=end;i++){
        if(in[i]==curr){
            return i;
            break;
        }
        else{
            continue;
        }
    }
    return -1;
}
void preorder(struct node **rootref){
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

