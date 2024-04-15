#include<bits/stdc++.h>

using namespace std;





int merge(int arr[], int l, int m, int r) {
        int n1 = m -l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
	unsigned int ret = 0;

        for (int i = 0; i < n1; i++)
                L[i] = arr[l+i];

        for (int i = 0; i < n2; i++)
                R[i] = arr[m+1+i];

        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
                if (L[i] <= R[j]) {
                        arr[k++] = L[i++];
                }
                else {
                        arr[k++] = R[j++];
			ret += m -i;
                }
        }
        while (i < n1) {
                arr[k++] = L[i++];
        }
        while (j < n2) {
                arr[k++] = R[j++];
        }
	return ret;
}

unsigned int piggyback(int arr[], int l, int r) {
	unsigned int ret = 0;
	if (r > l) {
		int m = (r-l)/2 + l;
		ret += piggyback(arr, l, m);
		ret += piggyback(arr, m+1, r);
		ret += merge(arr, l,m ,r);	
	}
	return ret;
}


int main() {
	int arrSz = 100000;
	int arr[arrSz];

	ifstream fn("IntegerArray.txt");
	string str;
	int i = 0;
	while (getline(fn, str)) {
		arr[i++] = stoi(str);
	}

	cout << "inversions:" << piggyback(arr, 0, arrSz) << "\n";
	return 0;
}
