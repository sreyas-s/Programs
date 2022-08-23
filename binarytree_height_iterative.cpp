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
int heightfun(struct node **);

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
  int h;
  h=heightfun(&root);
  cout<<"\n Height of the tree: "<<h<<endl;
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
    //we have to count number of levels and decrease 1.
    if(*rootref==NULL){
        return -1;
    }
    else{
        queue<node *> q;
        q.push(*rootref);
        int height=-1;
        int nodec=0;
        while(!q.empty()){
            height++;
            struct node *current=q.front();
            nodec=q.size();
            while(nodec>0){
                //finishing one level of nodes here.
                q.pop();
                nodec--;
                if(current->left!=NULL){
                    q.push(current->left);
                }
                if(current->right!=NULL){
                    q.push(current->right);
                }
            }
        }
        return height;
    }
}
