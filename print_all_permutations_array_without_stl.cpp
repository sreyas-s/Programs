//sort the array
//Then apply nextpermutation function -make it have a return value.
//till val becomes 0-do nextpermutation and print array.

#include<iostream>
using namespace std;

int nextpermutationfun(int *, int, int);
void swap(int *, int *);
void quickfun(int *, int, int);
int partfun(int *, int, int);
void swap1(int *, int *);

int main(){
	int n;
	//bool val;
	cout<<"Enter the size of the array"<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter the array"<<endl;
	for(int i=0;i<=(n-1);i++){
		cin>>a[i];
		}
	//now, we have to sort the array.
	quickfun(a, 0, n-1);
	//now we have the sorted array.
	do{
		//print the array
		cout<<endl;
		for(int i=0;i<n;i++){
			cout<<a[i]<<" ";
			}		
		}
	while(nextpermutationfun(a, 0, n-1));
	return 0;
	}

int nextpermutationfun(int *arr, int beg, int end){
	//if array is sorted in descending order-then no next permutation possible.
	//else-find the next permutation.
	//first, we will do the if condition.
	int nextgreaterpos;
	int pos;
	int count=0;
	int flag=0;
	int var1, var2;
	for(int i=beg;i<=(end-1);i++){
		if(arr[i]>=arr[i+1]){
			count++;
			}
		else{
			break;
			}
		}
	if(count==(end-beg)){
		return 0;
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
		for(int i=end;i>=(beg+1);i--){
			//check where ascending order is getting broken.
			if(arr[i]<=arr[i-1]){
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
		if(pos+1==end){
			//next greater element for arr[i] is arr[i+1].
			nextgreaterpos=pos+1;
			}
		else{
			for(int j=(pos+2);j<=end;j++){
				//we have to find arr[i] element's next greater element in this list.
				//here we are doing a linear scan-later we can optimize it and do binary search/scan.
				if(arr[j]>arr[pos]){
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
				nextgreaterpos=end;	
				}
			else{
				//(j-1)^th element is next greater element for arr[i].
				nextgreaterpos=var1-1;
				}
			}
		//so, now we have nextgreaterpos and i, swap arr[i] and arr[nextgreaterpos] now.
		swap(&arr[pos], &arr[nextgreaterpos]);
		//after swapping-what to do?
		//after the position i-whatever array elements where there we have to reverse it.
		//from i+1 to end array-we have to reverse.
		//how to reverse that?
		int temparray[end-pos];
		int temp=end;
		for(int k=0;k<(end-pos);k++){
			temparray[k]=arr[temp];
			temp--;
			}
		//so now we have reverse array in temparray.
		//now, we can copy temparray elements to array arr-from position i+1 to end.
		int index=0;
		for(int k=(pos+1);k<=end;k++){
			arr[k]=temparray[index];
			index++;
			}
		//so now whatever we have in array arr is the required thing.
		//print the array.
		//cout<<"\n Next permutation for given array: "<<endl;
		//for(int i=beg;i<=end;i++){
		//	cout<<arr[i]<<" ";
		//	}
		return 1;
		}
	}		

void swap(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}
		
void quickfun(int *arr, int beg, int end){
	int p;
	//what is the base case for stopping the recursion
	if(beg<end){
		p=partfun(arr, beg, end);
		quickfun(arr, beg, p-1);
		//arr[p] is at its correct place.
		quickfun(arr, p+1, end);
		}
	}

int partfun(int *arr, int beg, int end){
	int pivot=arr[end];
	//pivot is the last element in the array.
	int count=beg;
	for(int i=beg;i<=end;i++){
		if(arr[i]>pivot){
			continue;
			}
		else{
			swap1(&arr[count], &arr[i]);
			count++;
			}
		}
	//final value of the count gives the final index of the pivot element. 
	//or is it (count-1)?
	return count-1;
	}

void swap1(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	}

			

