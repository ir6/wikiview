#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
  long offset = -1;
  long b = 0;
  char* page_beg = "<page>";
  char* title_beg = "<title>";
  int title_beg_len = strlen (title_beg);
  char* title_end = "</title>";

  char* line = NULL;
  size_t len = 0;
  while (getline (&line, &len, stdin) > 0) {
    if (offset == -1) {
      char* line_s = strstr (line, page_beg);
      if (line_s) {
	offset = b + (line_s - line);
      }
    } else {
      char* line_s1 = strstr (line, title_beg);
      if (line_s1) {
	line_s1 += title_beg_len;
	line[strstr (line_s1, title_end) - line] = 0;
	printf ("0x%010lX %s\n", offset, line_s1);
	offset = -1;
      }
    }
    b += strlen (line);
  }
  free (line);
  return 0;
}
