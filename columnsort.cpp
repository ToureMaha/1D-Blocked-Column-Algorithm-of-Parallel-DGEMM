#include "utility.h"
#include "columnsort.h"
#include "heapsort.h"
#include "timer.h"

column_sort::column_sort(size_t r, size_t s)
: _r(r), _s(s) {}

void column_sort::print_matrix(short int* matrix, size_t r, size_t c)
{
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      printf("% 5d ", matrix[r*j+i]);
    }
    printf("\n");
  }
}

void column_sort::sort(string input_file, string output_file)
{
  short int matrix[_s*_r];
  unpack_file(input_file, matrix);

  Timer t;

  // Sort
  // Step 1: sort each column
  sorter s;
  for (int i=0; i<_s; i++) {
    s.heap_sort(matrix+(i*_r), _r);
  }

  // Step 2: Transpose the matrix
  int k=0;
  short int transpose[_s*_r];
  for (int i=0; i<_r; i++) {
    for (int j=0; j<_s; j++) {
      transpose[j*_r+i] = matrix[k++];
    }
  }

  // Step 3: Sort the Transpose matrix
  for (int i=0; i<_s; i++) {
    s.heap_sort(transpose+(i*_r), _r);
  }

  // Step 4: Untranspose
  k = 0;
  for (int i=0; i<_r; i++) {
    for (int j=0; j<_s; j++) {
      matrix[k++] = transpose[j*_r+i];
    }
  }

  // Step 5: Sort the new columns
  for (int i=0; i<_s; i++) {
    s.heap_sort(matrix+(i*_r), _r);
  }

  // Step 6: Shift the values down r/2 positions
  short int shifted[(_s+1)*_r];
  int shift = _r/2;
  for (int i=0; i<_s; i++) {
    for (int j=0; j<_r; j++) {
      shifted[i*_r+j+shift] = matrix[i*_r+j];
    }
  }
  for (int i=0; i<shift; i++) {
    shifted[i] = -32766;
    shifted[_s*_r+shift+i] = 32767;
  }

  // Step 7: sort the columns
  for (int i=0; i<_s+1; i++) {
    s.heap_sort(shifted+(i*_r), _r);
  }

  // Step 8: unshift
  for (int i=0; i<_s; i++) {
    for (int j=0; j<_r; j++) {
      matrix[i*_r+j] = shifted[i*_r+j+shift];
    }
  }

  for (int i=0; i<_s; i++) {
    s.heap_sort(matrix+(i*_r), _r);
  }


  cout << "CPU time to sort: " << t.elapsed_time() << " seconds" << endl;

  if (sort_check(matrix) != true) {
    cout << "Sorting Failed." << endl;
    return;
  }

  // Write to file
  ofstream opf(output_file);
  for (int i=0; i<_s; i++) {
    for (int j=0; j<_r; j++) {
      opf << matrix[i*_r+j] << endl;
    }
  }
  opf.close();
}

void column_sort::unpack_file(string file_name, short int* matrix)
{
  fstream f;
  f.open(file_name, ios::in);
  int i=0;
  if (f.is_open()) {
    string inp;
    while (getline(f, inp)) {
      if (i >= _r*_s) {
        return;
      }
      if (is_number(inp)) {
        matrix[i++] = stoi(inp);
      }
    }
  }
  f.close();
}

bool column_sort::sort_check(short int* matrix)
{
  for (int i=0; i<_r*_s-1; i++) {
    if (matrix[i] > matrix[i+1]) {
      return false;
    }
  }
  return true;
}
