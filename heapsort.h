#ifndef HEAPSORT_H
#define HEAPSORT_H

class sorter
{
  public:
  void sort_file(string input_file, string output_file);
  //precondition:
  //input_file is the name of an existant file of integers
  //with one per line, each integer < 32768
  //postcondition:
  //output_file contains the sorted numbers in input_file

  void heap_sort(short int arr[], int n);
  //sorts arr

  private:
  void heapify(short int arr[], int n, int i);
  //precondition:
  //arr, n, and i have been set
  //postcondition:
  //arr is a valid min-heap

  vector<short int> extract_integers(string input_file);
  //return a vector of integers contained in input_file

  bool sort_check(short int arr[], int n);
  //return true if the array is sorted. false otherwise.
};

#endif