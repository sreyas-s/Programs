//program to find the zig zag traversal of a binary tree.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node *left=NULL;
    struct node *right=NULL;
};

void insertfun(struct node **, int);
void zigzagfun(struct node **);

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
    //we have to find the traversal zig-zag manner.
    cout<<"The zig-zag traversal is: "<<endl;
    zigzagfun(&root);
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

void zigzagfun(struct node **rootref){
    //do level order as usual.
    if(*rootref==NULL){
        cout<<"Tree empty"<<endl;
        return;
    }
    else{
        int level=0;
        int nodec=0;
        vector<int> v;
        vector<int>::iterator itr;
        queue<node *> q;
        q.push(*rootref);
        while(!q.empty()){
           if(level%2==0){
               nodec=q.size();
               while(nodec>0){
                   struct node *curr=q.front();
                    //normally how do we do level order traversal.
                   v.push_back(curr->data);
                   if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                   if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                    q.pop();
                    nodec--;
               }
               //print the elements in the vector.
               //and then erase it.
             //  int vs=v.size();
               for(itr=v.begin();itr!=v.end();itr++){
                   cout<<*itr<<" ";
               }
               v.clear();
               level++;
           }
           else{
               nodec=q.size();
               while(nodec>0){
                   struct node *curr=q.front();
                    //normally how do we do level order traversal.
                   v.push_back(curr->data);
                   if(curr->left!=NULL){
                        q.push(curr->left);
                    }
                   if(curr->right!=NULL){
                        q.push(curr->right);
                    }
                    q.pop();
                    nodec--;
               }
               //print elements in vector in reverse.
               //then erase the vector.
               for(itr=v.end()-1;itr>=v.begin();itr--){
                   cout<<*itr<<" ";
               }
               v.clear();
               level++;
           }
        }
    }
}

