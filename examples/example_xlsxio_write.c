#include <stdlib.h>
#include <stdio.h>
#include "xlsxio_write.h"

const char* filename = "example.xlsx";

int main (int argc, char* argv[])
{
  xlsxiowriter handle;
  //remove the destination file first if it exists
  unlink(filename);
  //open .xlsx file for writing
  if ((handle = xlsxiowrite_open(filename)) == NULL) {
    fprintf(stderr, "Error creating .xlsx file\n");
    return 1;
  }
  //write data
  int i;
  for (i = 0; i < 1000; i++) {
    xlsxiowrite_add_cell_string(handle, "Test");
    xlsxiowrite_add_cell_string(handle, "A b  c   d    e     f");
    xlsxiowrite_add_cell_string(handle, "&% <test> \"'");
    xlsxiowrite_add_cell_string(handle, NULL);
    xlsxiowrite_add_cell_int(handle, i);
    xlsxiowrite_add_cell_datetime(handle, time(NULL));
    xlsxiowrite_add_cell_float(handle, 3.1415926);
    xlsxiowrite_next_row(handle);
  }
  //close .xlsx file
  xlsxiowrite_close(handle);
  return 0;
}