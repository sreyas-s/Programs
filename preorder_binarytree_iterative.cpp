//program to print the preorder traversal iterative.

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void insertfun(struct node **, int);
void preorderfun(struct node **);

int main(){
  struct node *root=NULL;
  int n;
  cout<<"How many nodes?"<<endl;
  cin>>n;
  int x;
  cout<<"Enter them"<<endl;
  for(int i=0;i<n;i++){
      cin>>x;
      insertfun(&root, x);
  }
  preorderfun(&root);
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
void preorderfun(struct node **rootref){
    //we have to print the preorder traversal of the tree in iterative manner.
    if(*rootref==NULL){
        cout<<"Tree is empty"<<endl;
        return;
    }
    else{
        stack<node *> s;
        s.push(*rootref);
        while(!s.empty()){
            //look at the top of stack-and push its right child first if existing-and push if its left child if existing-and
            //if both left and right child-null then it is a leaf node.-so we have to pop that element.
            struct node *curr=s.top();
            s.pop();
            cout<<curr->data<<" ";
            if(curr->right!=NULL){
                s.push(curr->right);
            }
            if(curr->left!=NULL){
                s.push(curr->left);
            }
        }
    }
}
