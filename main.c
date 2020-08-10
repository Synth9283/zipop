#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#define HELP "Usage: zipop -s [size] -c [count] [options] -o [filename]"

void helpMenu();
void generate(unsigned int size, unsigned int count, char *dir, unsigned int verbose);

int main(int argc, char **argv) {
  int option;
  unsigned int verbose = 0, size = 0, count = 0, dirBool = 0;
  char *dir = NULL;
  while ((option = getopt(argc, argv, "hs:c:v::o:")) != -1) {
    switch (option) {
      case 'h':
        helpMenu();
        return 0;
      case 's':
        size = atoi(optarg);
        break;
      case 'c':
        count = atoi(optarg);
        break;
      case 'v':
        verbose++;
        break;
      case 'o':
        dir = optarg;
        dirBool++;
        break;
      default:
        printf("%s\n", HELP);
        exit(1);
    }
  }
  if (size && count && dirBool) generate(size, count, dir, verbose);
  else printf("%s\n", HELP);
  

  return 0;
}

void helpMenu() {
  puts("zipop: A cli tool made in C that allows you to generate a massively compressed file\n");
  puts("\tUsage: zipop -s [size] -c [count] [options] -o [filename]\n");
  puts("\t-h\tPrints this help menu");
  puts("\t-s\tSize of the compressed file");
  puts("\t-v\tVerbose");
  puts("\t-o\tOutput Directory\n");
  printf("\tExample: zipop -s 5 -c 10 -v -o example.bz2\n\n");
}

void generate(unsigned int size, unsigned int count, char *dir, unsigned int verbose) {
  char command[70];
  if (verbose) snprintf(command, 70, "dd if=/dev/zero bs=%uG count=%u | bzip2 -cv > %s", size, count, dir);
  else snprintf(command, 70, "dd if=/dev/zero bs=%uG count=%u | bzip2 -c > %s", size, count, dir);
  printf("%s\n", command);
  system(command);
}

