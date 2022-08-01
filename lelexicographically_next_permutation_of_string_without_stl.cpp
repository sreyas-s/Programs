#include<iostream>
using namespace std;

void nextpermutationfun(string);
void swap(char *, char *);

int main(){
	string str;
	cout<<"Enter the string"<<endl;
	cin>>str;
	int n=str.size();
	nextpermutationfun(str);
	return 0;
	}

void nextpermutationfun(string s){
	//if array is sorted in descending order-then no next permutation possible.
	//else-find the next permutation.
	//first, we will do the if condition.
	int nextgreaterpos;
	int m=s.size();
	int pos;
	int count=0;
	int flag=0;
	int var1, var2;
	for(int i=0;i<(m-1);i++){
		if(s[i]>=s[i+1]){
			count++;
			}
		else{
			break;
			}
		}
	if(count==(m-1)){
		cout<<"No next permutation possible"<<endl;
		}
	else{
		//we have to find the next permutation.
		//we have to traverse the array from right to left.
		//find the first place where the ascending order is broken.
		//stop there.
		//we have to swap that element with the element which is nearest greater to it-on the right side of this element.
		//swap it.
		//After swapping-what to do?
		//reverse the string to right of it.(it here meaning the position at which we found the first ascending order break happened.)
		
		//following the steps now:
		//Traverse the array from right to left.
		for(int i=(m-1);i>=1;i--){
			//check where ascending order is getting broken.
			if(s[i]<=s[i-1]){
				continue;
				}
			else{
				//now you have reached a place where arr[i]>arr[i-1].
				//so, the position is i-1
				pos=i-1;
				break;
				}
			}
				//we have to swap this position pos element with an element which is nearest greatest to arr[pos].-nextgreaterpos
				//find next greater element of arr[i].
		if(pos+1==(m-1)){
			//next greater element for arr[i] is arr[i+1].
			nextgreaterpos=pos+1;
			}
		else{
			for(int j=(pos+2);j<=(m-1);j++){
				//we have to find arr[i] element's next greater element in this list.
				//here we are doing a linear scan-later we can optimize it and do binary search/scan.
				if(s[j]>s[pos]){
					continue;						
					}
				else{
					//It will come here when arr[pos]>arr[j]
					flag=1;
					var1=j;
					break;
					}
				}
			if(flag==0){
				//wif the flag value did not change it means that last element in array is next greater element for arr[i].
				nextgreaterpos=m-1;	
				}
			else{
				//(j-1)^th element is next greater element for arr[i].
				nextgreaterpos=var1-1;
				}
			}
		//so, now we have nextgreaterpos and i, swap arr[i] and arr[nextgreaterpos] now.
		swap(&s[pos], &s[nextgreaterpos]);
		//after swapping-what to do?
		//after the position i-whatever array elements where there we have to reverse it.
		//from i+1 to end array-we have to reverse.
		//how to reverse that?
		char temparray[(m-1)-pos];
		int temp=(m-1);
		for(int k=0;k<(m-1-pos);k++){
			temparray[k]=s[temp];
			temp--;
			}
		//so now we have reverse array in temparray.
		//now, we can copy temparray elements to array arr-from position i+1 to end.
		int index=0;
		for(int k=(pos+1);k<=(m-1);k++){
			s[k]=temparray[index];
			index++;
			}
		//so now whatever we have in array arr is the required thing.
		//print the array.
		cout<<"\n Next permutation for given string: "<<endl;
		cout<<s<<endl;
		}
	}		

void swap(char *a, char *b){
	char temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}
		
		

