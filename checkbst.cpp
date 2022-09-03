#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

bool checkbst(struct node **, int, int);
void insertionfun(struct node **, int);

int main(){
    struct node *root=NULL;
    int n;
    cout<<"Number of nodes?"<<endl;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insertionfun(&root, x);
    }
    //at this level-tree is populated.
    bool val;
    val=checkbst(&root, INT_MIN, INT_MAX);
    if(val){
        cout<<"BST"<<endl;
    }
    else{
        cout<<"Not BST"<<endl;
    }
    return 0;
}

void insertionfun(struct node **rootref, int x){
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
            struct node *curr=q.front();
            if(curr->left==NULL){
                curr->left=p;
                return;
            }
            if(curr->right==NULL){
                curr->right=p;
                return;
            }
            q.push(curr->left);
            q.push(curr->right);
            q.pop();
        }
    }
}

bool checkbst(struct node **rootref, int minvalue, int maxvalue){
    //left subtree has to be bst and rightsubtree has to be bst.
    //also leftsubtree elts less than or equal to root node and right subttree elts greater than rootnode.
    //struct node *temp=*rootref;
    struct node *temp=*rootref;
    if(temp==NULL){
        return true;
    }
    else{
        if((temp->data > minvalue)  && (temp->data < maxvalue) &&
        checkbst(&(temp->left), minvalue, temp->data ) && checkbst(&(temp->right), temp->data, maxvalue)){
            //for the left child lower bound wont change.maxvalue is?
            return true;
        }
        else{
            return false;
        }
    }
}

/*
//now write other two functions.

bool checklesser(struct node **temp, int d){
    //traverse through the entire rooted at the node temp.
    //and if check all elts value is less than d.
    if(*temp==NULL){
        return true;
    }
    else{
        if((((*temp)->data)<=d) && checklesser(&((*temp)->left), d) && checklesser(&((*temp)->right), d)){
            return true;
        }
        else{
            return false;
        }
    }
}

bool checkgreater(struct node **temp, int d){
    //traverse through the entire rooted at the node temp.
    //and if check all elts value is less than d.
    if(*temp==NULL){
        return true;
    }
    else{
        if((((*temp)->data)>d) && checkgreater(&((*temp)->left), d) && checkgreater(&((*temp)->right), d)){
            return true;
        }
        else{
            return false;
        }
    }
}
*/

