//program to print the postorder traversal iterative.

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
void postorderfun(struct node **);

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
  postorderfun(&root);
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
void postorderfun(struct node **rootref){
    //this function should print the postorder traversal of tree-iteratively.
    if(*rootref==NULL){
        cout<<"Tree empty"<<endl;
    }
    else{
        stack<node *> s1, s2;
        s1.push(*rootref);
        while(!s1.empty()){
            struct node *current=s1.top();
            s1.pop();
            s2.push(current);
            if(current->left!=NULL){
                s1.push(current->left);
            }
            if(current->right!=NULL){
                s1.push(current->right);
            }
        }
        //once stack1 has become empty-print stack2 elements from top to bottom-postorder traversal that is.
        while(!s2.empty()){
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
    }
}
