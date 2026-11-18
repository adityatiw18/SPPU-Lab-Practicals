
#include <bits/stdc++.h>
using namespace std;

// Normal Lomuto partition
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

// Deterministic Quick Sort
void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& a, int low, int high) {
    if (low < high) {

        int randomIndex = low + rand() % (high - low + 1);

        swap(a[randomIndex], a[high]);

        int p = partition(a, low, high);

        randomizedQuickSort(a, low, p - 1);
        randomizedQuickSort(a, p + 1, high);
    }
}

int main() {
    srand(time(0));

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;

    quickSort(a, 0, n - 1);
    randomizedQuickSort(b, 0, n - 1);

    cout << "Deterministic Quick Sort: ";
    for (int x : a) cout << x << " ";

    cout << "\nRandomized Quick Sort: ";
    for (int x : b) cout << x << " ";

    return 0;
}
