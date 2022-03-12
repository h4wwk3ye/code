/*
				C++
				encoding: UTF-8
				Last Modified: 24/Sep/20 08:13:11 PM
*/

#include <bits/stdc++.h>
#ifdef H4wk3ye
#	include <prettypr.hpp>
#endif

using namespace std;

#define int int64_t

template < typename T > void print (const T& t) {
	cout << t << '\n';
}

template < typename T, typename U, typename... ARGS >
void print (const T& t, const U& u, const ARGS&... args) {
	cout << t << ' ';
	print (u, args...);
}

// https://www.geeksforgeeks.org/number-swaps-sort-adjacent-swapping-allowed/

int merge (int arr[], int temp[], int left, int mid, int right) {
	int inv_count = 0;

	int i = left; /* i is index for left subarray*/
	int j = mid;  /* i is index for right subarray*/
	int k = left; /* i is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right)) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else {
			temp[k++] = arr[j++];

			/* this is tricky -- see above explanation/
			  diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
	 (if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
	 (if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

/* An auxiliary recursive function that sorts the input
   array and returns the number of inversions in the
   array. */
int _mergeSort (int arr[], int temp[], int left, int right) {
	int mid, inv_count = 0;
	if (right > left) {
		/* Divide the array into two parts and call
		  _mergeSortAndCountInv() for each of the parts */
		mid = (right + left) / 2;

		/* Inversion count will be sum of inversions in
		   left-part, right-part and number of inversions
		   in merging */
		inv_count = _mergeSort (arr, temp, left, mid);
		inv_count += _mergeSort (arr, temp, mid + 1, right);

		/*Merge the two parts*/
		inv_count += merge (arr, temp, left, mid + 1, right);
	}

	return inv_count;
}

/* This function sorts the input array and returns the
   number of inversions in the array */
int countSwaps (int arr[], int n) {
	int temp[n];
	return _mergeSort (arr, temp, 0, n - 1);
}

int32_t main () {
	ios_base::sync_with_stdio (false), cin.tie (nullptr);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		int arr[n];
		for (size_t i = 0; i < n; i++)
			cin >> arr[i];

		int inv = countSwaps (arr, n);

		int y = (n * (n - 1)) / 2 - 1;

		print (inv <= y ? "YES" : "NO");
	}
	return 0;
}