#include <bits/stdc++.h>
using namespace std;

// Bubble Sort: O(n^2), stable
void bubbleSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void bubblesort(vector<int>& a){
	int n = (int)a.size();
	for (int i = 0; i<n-1; i++){
		bool swapped = false;
		for (int j = 0; j < n - 1 - i; j++){
			if(a[j]>a[j+1]){
				swap(a[j], a[j+1]);
				swapped = true;
			}
		}
		if(!swapped) break;
	}
}
// Selection Sort: O(n^2), not stable (usually)
void selectionSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 0; i < n - 1; i++) {
        int mn = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[mn]) mn = j;
        }
        swap(a[i], a[mn]);
    }
}

// Insertion Sort: O(n^2), stable
void insertionSort(vector<int>& a) {
    int n = (int)a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Merge Sort: O(n log n), stable
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    vector<int> tmp;
    tmp.reserve(r - l + 1);

    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp.push_back(a[i++]);
        else tmp.push_back(a[j++]);
    }
    while (i <= m) tmp.push_back(a[i++]);
    while (j <= r) tmp.push_back(a[j++]);

    for (int k = 0; k < (int)tmp.size(); k++) {
        a[l + k] = tmp[k];
    }
}

// Quick Sort: avg O(n log n), not stable
int partitionHoare(vector<int>& a, int l, int r) {
    int pivot = a[l + (r - l) / 2];
    int i = l - 1, j = r + 1;
    while (true) {
        do { i++; } while (a[i] < pivot);
        do { j--; } while (a[j] > pivot);
        if (i >= j) return j;
        swap(a[i], a[j]);
    }
}
void quickSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int p = partitionHoare(a, l, r);
    quickSort(a, l, p);
    quickSort(a, p + 1, r);
}

static void printVec(const vector<int>& a) {
    for (int x : a) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> a = {5, 1, 4, 2, 8};
    vector<int> b = a, c = a, d = a, e = a;

    bubblesort(b);
    selectionSort(c);
    insertionSort(d);
    mergeSort(e, 0, (int)e.size()-1);

    quickSort(a, 0, (int)a.size()-1);

    cout << "quick: "; printVec(a);
    cout << "bubble: "; printVec(b);
    cout << "selection: "; printVec(c);
    cout << "insertion: "; printVec(d);
    cout << "merge: "; printVec(e);
}