//program to find the min and max element in bst.
//idea?
//ofcourse doing inorder we get sorted order and thus min and max.
//other than that any idea?
//min element will be leftmost and max elemnet will be rightmost.



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
void minmaxfun(struct node **);

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
    cout<<endl;
    minmaxfun(&root);
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

void minmaxfun(struct node **rootref){
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        int mini;
        while(temp){
            mini=temp->data;
            temp=temp->left;
        }
        cout<<"Min elt is "<<mini<<endl;
        temp=*rootref;
        int maxi;
        while(temp){
            maxi=temp->data;
            temp=temp->right;
        }
        cout<<"Max elt is "<<maxi<<endl;
    }
}

