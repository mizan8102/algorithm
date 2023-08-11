#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    int x;
    cin >> x;
    int l = 0;
    int r = n - 1;
    int count=0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] == x)
        {
            l = mid;
            count++;
            l = mid + 1;
        }
        else if (a[mid] < x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    count > 1 ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}