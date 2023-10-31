#include "utility.h"
#include "heapsort.h"
#include "timer.h"

void sorter::sort_file(string input_file, string output_file) {
  vector<short int> v = extract_integers(input_file);
  int n = v.size();
  short int arr[n];
  for (int i=0; i<n; i++) {
    arr[i] = v[i];
  }

  Timer t;
  heap_sort(arr, n);
  cout << "CPU time to sort: " << t.elapsed_time() << " seconds" << endl;

  ofstream f(output_file);
  for (int i=0; i<n; i++) {
    f << arr[i] << endl;
  }
  f.close();
}

void sorter::heapify(short int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < n && arr[l] > arr[largest]) {
    largest = l;
  }
  if (r < n && arr[r] > arr[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

void sorter::heap_sort(short int arr[], int n) {
  for (int i=n / 2 - 1; i >= 0; i--) {
    heapify(arr, n, i);
  }
  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
  }
}

vector<short int> sorter::extract_integers(string input_file) {
  vector<short int> arr;
  fstream f;
  f.open(input_file, ios::in);
  if (f.is_open()) {
    string inp;
    while (getline(f, inp)) {
      if (is_number(inp)) {
        arr.push_back(stoi(inp));
      }
    }
  }
  return arr;
}

bool sorter::sort_check(short int arr[], int n) {
  for (int i=0; i<n-1; i++) {
    if (arr[i] > arr[i+1]) {
      return false;
    }
  }
  return true;
}