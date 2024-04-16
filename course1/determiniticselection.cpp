#include <bits/stdc++.h>
#include<iostream>
#include<ostream>

using namespace std;

int findmedian(int arr[], int n) {
	sort(arr, arr+n);
	return arr[n/2];
}

void swap(int arr[], int a, int b) {
    int temp = arr[b];
    arr[b] = arr[a];
    arr[a] = temp;
}

int partition(int arr[], int l, int r, int p) {
	int index;
	for (index = l+1; index <=r; index++) {
		if (arr[index] == p) {
			break;
		}
	}
	swap(arr, l, index);
	int pivot = arr[l];
	int i = l+1;
	for (int j = l+1; j <=r; j++) {
		if (arr[j] <= pivot) {
			swap(arr, i, j);
			i++;
		}
	}
	swap(arr, l, i-1);
	return i-1;
}

int dselect(int arr[], int l, int r, int i) {
	if (r == l) return arr[l];
	int n = r-l+1;
	int numGroups = ceil(n/5);
	int j, median[numGroups];
	for (j = 0; j < n/5; j++) {
		median[j] = findmedian(arr+l+j*5, 5);
	}
	if (j*5 < n) {
		median[j] = findmedian(arr+l+j*5, n%5);
		j++;
	}
	int medofmed = j == 1 ? median[j-1] : dselect(median, 0, j-1, j/2);
	int pos = partition(arr, l, r, medofmed);
	int k = pos-1+1;
	if (i == k) return arr[pos];
	else if (i < k) return dselect(arr, l, pos -1, i);
	else return dselect(arr, pos + 1, r, i-k);
}

int main() {
	int arr[] = {12, 3, 5, 7, 4, 19, 26, 30, 63, 38}; 
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "(value of) ith<10> order statistic w D-select: " << dselect(arr, 0, arr_size-1, 10);
	cout << "\nith<3> order statistic w D-select: " << dselect(arr, 0, arr_size-1, 3);
	cout << "\nith<1> order statistic w D-select: " << dselect(arr, 0, arr_size-1, 1);
	cout << "\n";
	return 0;
}
