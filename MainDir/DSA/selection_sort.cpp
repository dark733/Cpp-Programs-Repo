//selection sort
#include<iostream>
using namespace std;

//main function
int main(){
	int n;
	cout<<"enter number of elements";
	cin>>n;

	//empty array
	int arr[n];

	//array input
	for(int i=0;i<n;i++){
		cout<<"Enter element-";
		cin>>arr[i];
	}

	//selection sort sorting algorithm

	//i loop(outer loop) i<n-1 (works till second last element)
	//iterates 1 time and waits for inner loop to complete
	for(int i=0;i<n-1;i++){
		//j loop(inner loop) i<n(works till last element)
		//iterates after outer loop has completed 1 iterartion and then does iteration fully
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[i]){
				//temporary variable for storing value during swap
				int temp=arr[j];
				arr[j]=arr[i];
				arr[i]=temp;

			}
		}

	}
	//print array
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}cout<<endl;
	
}