#include "utility.h"
#include "filer.h"
#include "heapsort.h"
#include "columnsort.h"

int main() {
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(3);
  srand(int(time(NULL)));
  // Part 1
  // filer f;
  // f.makefile(100000, 32000, "a.txt");
  // f.makefile(100000, 32000, "b.txt");
  // f.makefile(100000, 32000, "c.txt");

  // Part 2
  // sorter s;
  // s.sort_file("a.txt", "a_sorted.txt");
  // s.sort_file("b.txt", "b_sorted.txt");
  // s.sort_file("c.txt", "c_sorted.txt");

  // Part 3
  filer f;
  f.makefile(100000, 32000, "Part1Data.txt");

  column_sort cs(10000, 50);
  sorter hs;
  cout << "R: 10000" << endl;
  cout << "S: 50" << endl;

  cout << "Trial 1" << endl;
  cout << "=======" << endl;
  cout << "Column Sort:" << endl;
  cs.sort("Part1Data.txt", "Results.txt");
  cout << "Heap Sort:" << endl;
  hs.sort_file("Part1Data.txt", "tmp.txt");
  cout << endl;

  cout << "Trial 2" << endl;
  cout << "=======" << endl;
  cout << "Column Sort:" << endl;
  cs.sort("Part1Data.txt", "Results.txt");
  cout << "Heap Sort:" << endl;
  hs.sort_file("Part1Data.txt", "tmp.txt");
  cout << endl;

  cout << "Trial 3" << endl;
  cout << "=======" << endl;
  cout << "Column Sort:" << endl;
  cs.sort("Part1Data.txt", "Results.txt");
  cout << "Heap Sort:" << endl;
  hs.sort_file("Part1Data.txt", "tmp.txt");

}