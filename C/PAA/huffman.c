#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int *get_substring_frequencies(char *in_str, unsigned int in_str_len);
unsigned int *create_frequency_array(unsigned int size);
unsigned int calculate_triangle_index(unsigned int size, unsigned int i, unsigned int j);
unsigned int triangle(unsigned int n);
unsigned int neigh(unsigned int size, unsigned int i, unsigned int j);
void printf_tri_mat(unsigned int *mat, unsigned int size);

int main(int argc, char const *argv[])
{
	const char *input_str = "baobab";

	unsigned int in_str_len = strlen((char *)input_str);
	unsigned int *freq_mat = get_substring_frequencies((char *)input_str, in_str_len);

	printf_tri_mat(freq_mat, in_str_len);
}

unsigned int *get_substring_frequencies(char *in_str, unsigned int in_str_len)
{
	unsigned int i, j;
	unsigned int triangle_index;
	unsigned int *frequency_arr = create_frequency_array(in_str_len);
	// printf("triangle(%d) = %d\n", 0, triangle(0));

	for (i = 0; i < in_str_len; ++i)
	{
		for (j = i + 1; j < in_str_len; ++j)
		{
			triangle_index = calculate_triangle_index(in_str_len, i, j);
			printf("[%d, %d] = %d\n", i, j, triangle_index);
			if (in_str[i] == in_str[j])
			{
				frequency_arr[triangle_index] = 1;

				if (i > 0 && j > 0)
					frequency_arr[triangle_index] += frequency_arr[triangle_index - 1];
			}
			else
			{
				frequency_arr[triangle_index] = 0;
			}
		}
	}

	return frequency_arr;
}

unsigned int *create_frequency_array(unsigned int size)
{
	unsigned int i;
	unsigned int *frequency_arr = (unsigned int *)malloc(sizeof(unsigned int) * size * size);

	return frequency_arr;
}

unsigned int calculate_triangle_index(unsigned int size, unsigned int i, unsigned int j)
{
	int a = triangle(size - 1) - 1;
	int b = - (triangle(size - j + i) - 1);
	int c = i;

	// printf("------------\n");
	// printf("a = %d\n", a);
	// printf("b = %d\n", b);
	// printf("c = %d\n", c);

	// return	triangle(size - 1) - 1
	// 		- triangle(i)
	// 		- triangle(size - j) - 1;

	return a + b + c;
}

unsigned int triangle(unsigned int n)
{
	return (n * (n + 1.0)) / 2.0;
}

unsigned int neigh(unsigned int size, unsigned int i, unsigned int j)
{
	return size - j + i;
}

void printf_tri_mat(unsigned int *mat, unsigned int size)
{
	unsigned int i, j;
	unsigned int triangle_index;
	printf("size = %d\n", size);

	for (i = 0; i < size; ++i)
	{
		for (j = 0; j < size; ++j)
		{
			if (j > i)
			{
				triangle_index = calculate_triangle_index(size, i, j);
				printf("%2d ", mat[triangle_index]);
			}
			else
			{
				printf("%2d ", 0);
			}
		}
		printf("\n");
	}
}