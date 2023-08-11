#include<bits/stdc++.h>
#include <iostream>
using namespace std;

const int N=1e5+7;
int nums[N];

void merge(int l, int r, int mid)
{
	int l_size = mid-l+1;
	int L[l_size + 1];
	int r_size = r - mid;
	int R[r_size + 1];
	for(int i=l,j=0; i<=mid; i++,j++)
		L[j] = nums[i];
	for(int i=mid+1,j=0; i<=r; i++,j++)
		R[j] = nums[i];
	L[l_size] = INT_MIN;
	R[r_size] = INT_MIN;
	int left=0,right=0;
	for(int i=l; i<=r; i++)
	{
		if(L[left] >= R[right])
		{
			nums[i] = L[left];
			left++;
		}
		else
		{
			nums[i] = R[right];
			right++;
		}
	}
}

void mergeSort(int l , int r){
	if(l==r)
		return;
	int mid = (l+r)/2;
	mergeSort(l, mid);
	mergeSort(mid+1, r);
	merge(l, r, mid);
}


int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
      cin >> nums[i];
    }
    mergeSort(0,n-1);
    for (int i = 0; i < n; i++)
    {
      cout << nums[i] << " ";
    }
    return 0;
}
