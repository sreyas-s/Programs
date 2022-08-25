#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

void insertfun(struct node **, int);
void kthinorder(struct node **, int);
void inorder(struct node **, int *);

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
    int k;
    cout<<"Enter value of k"<<endl;
    cin>>k;
    int countnodes=0;
    inorder(&root, &countnodes);
    if(k>countnodes||k<0){
        cout<<"Not possible"<<endl;
    }
    else{
        kthinorder(&root, k);
    }
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

void inorder(struct node **rootref, int *cn){
    if(*rootref==NULL){
        return;
    }
    else{
        struct node *temp=*rootref;
        inorder(&(temp->left), cn);
        (*cn)++;
        inorder(&(temp->right), cn);
    }
}

void kthinorder(struct node **rootref, int k){
    //we have to do iterative inorder.
    if(*rootref==NULL){
        return;
    }
    else{
        vector<int> v;
        stack<node *> s;
        int counter=0;
        int nodec;
        struct node *curr=*rootref;
        counter++;
        while(1){
            if(curr){
                s.push(curr);
                curr=curr->left;
            }
           
            else{
                //at this time-curr is null.
                nodec=s.size();
                if(nodec==0){
                    break;
                }
                curr=s.top();
                v.push_back(curr->data);
                curr=curr->right;
                s.pop();
            }
        }
        vector<int>::iterator itr;
        itr=v.begin()+k-1;
        cout<<k<<"^th smallest elt: "<<*itr<<endl;
    }
}

