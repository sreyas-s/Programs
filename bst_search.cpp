//insert nodes to binary search tree.
//building bst from the key values given.

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void insertfun(struct node **, int);
void inorder(struct node **);
void searchfun(struct node **, int);

int main(){
    struct node *root=NULL;
    int n;
    cout<<"How many nodes?"<<endl;
    cin>>n;
    cout<<"Enter them:"<<endl;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        insertfun(&root, x);
    }
    //print inorder and check sorted order.
    int s;
    cout<<"Enter the key you want to search for"<<endl;
    cin>>s;
    searchfun(&root, s);
    cout<<endl;
    cout<<"Inorder:"<<endl;
    inorder(&root);
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
        //the first node to enter will be root. second node onwards we have to compare value with root and traverse left or right
        int flag;
        struct node *temp=*rootref;
        struct node *prev;
        //may be run the below things in a loop.
        while(temp){
            if(x<=temp->data){
                //then we have to insert node p to the left of root.
                prev=temp;
                temp=temp->left;
                flag=0;
            }
            else{
                prev=temp;
                temp=temp->right;
                flag=1;
            }
        }
        //at the end of the loop, check value of flag.
        if(flag==1){
            //flag=1 means we have to put it in right.
            prev->right=p;
        }
        else{
            prev->left=p;
        }
    }
}

//we have to search for a key element.

void searchfun(struct node **rootref, int s){
    //searching for node with value s in bst.
    int flag=0;  
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        while(temp){
            if(temp->data==s){
                cout<<"Node found."<<endl;
                flag=1;
                return;
            }
            else if(s<(temp->data)){
                temp=temp->left;
                }
            else{
                temp=temp->right;
            }
        }
        if(flag==0){
            cout<<"Not found"<<endl;
        }
    }
}

//now, hopefully insertion has been done-let's do inorder.
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

