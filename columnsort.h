#ifndef COLUMN_SORT_H
#define COLUMN_SORT_H

class column_sort
{
  public:
  column_sort(size_t r, size_t s);

  void sort(string input_file, string output_file);

  private:
  bool sort_check(short int* matrix);

  void unpack_file(string file_name, short int* matrix);

  void print_matrix(short int* matrix, size_t r, size_t c);

  size_t _r, _s;
};

#endif