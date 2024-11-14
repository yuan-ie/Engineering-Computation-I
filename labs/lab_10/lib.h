#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cstdio>
#define LINE_SIZE 100
#define MAX_LINES 256

char *word_check(int argc, char **argv);
void num_lines(int argc, char **argv, int *option_key, int *num_flag);
char **file_list(int argc, char **argv, int *num_flag);
void check_for_word(char *file, char *word, int number, int line_count);