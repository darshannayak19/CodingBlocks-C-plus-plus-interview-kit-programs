#include<iostream>
using namespace std;
int kadane_algo(int arr[],int test)
{
int ms=0,cs=0;

for(int j=0;j<test;j++)
{
cs=cs+arr[j];
if(cs<0){
cs=0;
}
ms=max(cs,ms);

}
return ms;
}

void maxCircularSum(int a[], int n)
{
for(int j=0;j<n;j++) // input array elements shifted from kadane function to here because every time you enter kadane function
// , you were inputing elements in array which is wrong .
{
cin>>a[j];
}
int max_kadane = kadane_algo(a, n);
int max_wrap = 0, i;
for (i=0; i<n; i++)
{
max_wrap += a[i];
a[i] = -a[i];
}
max_wrap = max_wrap + kadane_algo(a, n);
int y = (max_wrap > max_kadane)? max_wrap: max_kadane;
cout<<y<<endl; // changes made
}

int main()
{
int n;
cin>>n;
int test[n];
for(int i=0;i<n;i++)
{
cin>>test[i];
int arr[test[i]];
 maxCircularSum(arr,test[i]);
//cout<<x;
}
return 0;
}
