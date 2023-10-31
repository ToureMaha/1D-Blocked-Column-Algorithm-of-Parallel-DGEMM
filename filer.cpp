#include "utility.h"
#include "filer.h"

void filer::makefile(int n, int range, string file_name) {
  ofstream f(file_name);
  for (int i=0; i<n; i++) {
    f << next_number(range) << endl;
  }
  f.close();
}

int filer::next_number(int range) {
  return rand() % (range + 1);
}