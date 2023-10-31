#ifndef FILER_H
#define FILER_H

class filer
{
  public:
  void makefile(int n, int range, string file_name);
  //precondition: n, range, and file_name have
  //been set;
  //postcondition: n random integers in the range 0-range,
  //inclusive, have been written to a file named file_name,
  //one per line;

  private:
  int next_number(int range);
  //precondition: range has been set to a nonnegative value
  //postcondition: returns a random integer in the range
  //0-range, inclusive
};

#endif //FILER_H