#ifndef PUSH_SWAP_C
#define PUSH_SWAP_C

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "cardinal_num/cardinal_num.h"

t_status check_args(int argc, char **argv);
int *make_ordinal_array(int argc, char **argv);
void print_ordinal_array(int *ordinal_array, size_t array_size);
void print_cardinal_array(t_cardinal_num *cardinal_array, size_t array_size);
void err();

#endif