#ifndef CARDINAL_NUM_H
#define CARDINAL_NUM_H

#include "../libft/libft.h"

typedef struct s_cardinal_num
{
	int num;
	int index;
} t_cardinal_num;

t_cardinal_num *make_cardinal_num_array(int argc, char **argv);
void sort_cardinal_num_array(t_cardinal_num *cardinal_num_array, size_t array_size);

#endif
