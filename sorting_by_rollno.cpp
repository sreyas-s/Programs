#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct student{
    int rollno;
    string name;
    string id;
};

bool comp(struct student, struct student);

int main(){
    //we can create a vector of struct student.
    vector<struct student> v;
    struct student s;
    int r;
    string n;
    string i;
    while(cin){
        cin>>r;
        s.rollno=r;
        cin>>n;
        s.name=n;
        cin>>i;
        s.id=i;
        v.push_back({s.rollno, s.name, s.id});
    }
    vector<struct student>::iterator itr;
    //for(itr=v.begin();itr!=v.end();itr++){
      //  cout<<(*itr).rollno<<endl;
    //}
    //sort the vector v-using comparator.
    sort(v.begin(), v.end(), comp);
    //after sorting-we need to print.
    for(itr=v.begin();itr!=v.end();itr++){
       cout<<(*itr).rollno<<" "<<(*itr).name<<" "<<(*itr).id<<endl;
    }
    return 0;
}

bool comp(struct student s1, struct student s2){
    if(s1.rollno<s2.rollno){
        return true;
    }
    else{
        return false;
    }
}

