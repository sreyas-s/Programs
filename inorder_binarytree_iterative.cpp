//program to print the inorder traversal iterative.

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
void inorderfun(struct node **);

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
  inorderfun(&root);
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
void inorderfun(struct node **rootref){
    //this function should print the inorder traversal of tree-iteratively.
    if(*rootref==NULL){
        cout<<"Tree empty"<<endl;
    }
    else{
        stack<node *> s;
        struct node *current=*rootref;
        while(1){
            if(current!=NULL){
                s.push(current);
                current=current->left;
            }
            else{
                //it will come here when current is null.
                if(s.empty()){
                    break;
                }
               //current is null when it comes here. make current as top most in stack.
                current=s.top();
                cout<<current->data<<" ";
                current=current->right;
                s.pop();
            }
        }
    }
}

