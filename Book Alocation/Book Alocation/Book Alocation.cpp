// Book Alocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min) {
	int studentUsed = 1;
	int pages_reading = 0;

	for (int i = 0; i < n; i++)
	{
		if (pages_reading+arr[i]>curr_min)
		{
			studentUsed++;
			pages_reading = arr[i];
			if (studentUsed>m)
			{
				return false;
			}
		}
		else
		{
			pages_reading += arr[i];
		}
	}
}

int findPages(int arr[], int n, int m) {
	int sum = 0;

	if (n<m)
	{
		return -1;
	}
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	int s = arr[n - 1];
	int e = sum;
	int ans = INT_MAX;
	while (s<=e)
	{
		int mid = (s + e) / 2;

		if (isPossible(arr,n,m,mid))
		{
			ans = min(ans, mid);
			e = mid - 1;
		}
		else
		{
			s = mid + 1;
		}
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;

		int arr[1000];
		for (int  j = 0; j < n; j++)
		{
			cin >> arr[j];
		}
		cout << findPages(arr, n, m)<<endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
