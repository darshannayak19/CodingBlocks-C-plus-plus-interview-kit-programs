#include <bits/stdc++.h>
using namespace std;

int main()
{
    int maximum=0;
    int cumsum=0;
    int arr[1000];
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cumsum=cumsum+arr[i];
        if(cumsum<0){
            cumsum=0;
        }
        maximum=max(cumsum,maximum);
    }
    cout<<"maximum is:"<<maximum<<endl;
    return 0;
}
/*#include <bits/stdc++.h>
using namespace std;
// Standard Kadane's algorithm to find maximum subarray sum
int kadane(int array[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    for (int i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + array[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

//function to find maximum circular subarray sum
int MaxSumCircular(int array[], int n)
{
    //Max subarray sum in the given array
    int kadane_sum = kadane(array, n);
    //wrap_sum is sum of all elements in the array
    int wrap_sum = 0;
    //find sum of all elements in the array
    //invert signs of all elements in the array
    for (int i=0; i<n; i++)
    {
        wrap_sum += array[i];
        array[i] = -array[i];
    }
    //update wrap_sum by add to new Max subarray sum
    wrap_sum = wrap_sum + kadane(array, n);
    //Return the maximum of them
    if(wrap_sum > kadane_sum)
    {
      return wrap_sum;
    }
    else
    {
      return kadane_sum;
    }
}

//Main function
int main()
{
    int input_array[] = {7, 9, -11, -2, 2, 7, -1, 6};
    int size = sizeof(input_array)/sizeof(int);
    cout<<"Maximum circular subarray sum: "<<MaxSumCircular(input_array,size)<<endl;
    return 0;
}
