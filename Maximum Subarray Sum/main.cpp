#include <bits/stdc++.h>
using namespace std;


int maxsubarrsum(int arr[],int n){
	int cs=0;
	int ms= INT_MIN;

	for(int i=0;i<n;i++){
		cs = cs+arr[i];
		if(cs<0){
			cs=0;
		}
		ms=max(cs,ms);
	}
	return ms;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
    int maxsum = maxsubarrsum(arr,n);
	cout<<maxsum<<endl;
	}
    return 0;
}
