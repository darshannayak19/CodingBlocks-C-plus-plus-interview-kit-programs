// Aggrasive Cows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

bool canPlacecows(int stalls[], int n, int c, int min_sep) {
    int last_cows = stalls[0];

    int cnt = 1;

    for (int i = 0; i < n; i++)
    {
        if (stalls[i]-last_cows>=min_sep)
        {
            last_cows = stalls[i];
            cnt++;
            if (cnt==c)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int stalls[] = { 1,2,4,8,9 };
    int n = 5;
    int cows = 3;
    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int ans = 0;
    while (s<=e)
    {
        int mid = (s + e) / 2;
        bool cowsRakhPaye = canPlacecows(stalls, n, cows, mid);
    
    if (cowsRakhPaye) {
        ans = mid;
        s = mid + 1;
    }
    else
    {
        e = mid - 1;
    }


   }
    cout << ans << endl;
    return 0;
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
