#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int *get_substring_frequencies(char *in_str, unsigned int in_str_len);
unsigned int *create_frequency_array(unsigned int size);
unsigned int calculate_triangle_index(unsigned int size, unsigned int i, unsigned int j);
unsigned int triangle(unsigned int n);
unsigned int neigh(unsigned int size, unsigned int i, unsigned int j);
void printf_tri_mat(unsigned int *mat, unsigned int sizex, unsigned int sizey);

int main(int argc, char const *argv[])
{
	const char *input_str = "baobab";

	unsigned int in_str_len = strlen((char *)input_str);
	unsigned int *freq_mat = get_substring_frequencies((char *)input_str, in_str_len);
}

unsigned int *get_substring_frequencies(char *in_str, unsigned int size)
{
	unsigned int i, j, idx;
	unsigned int frequency_arr[size];
	char current_substring[size + 1];
	unsigned int current_substring_size, first_match;
	// printf("triangle(%d) = %d\n", 0, triangle(0));

	current_substring[size] = '\0';

	for (i = 0; i < size; ++i)
	{
		current_substring_size = 0;
		first_match = 1;

		for (idx = 0, j = i + 1; j < size; ++j, ++idx)
		{
			// printf("if[%d] - %d\n", idx, in_str[idx] == in_str[j]);
			if (in_str[idx] == in_str[j])
			{
				frequency_arr[idx] = 1;
				current_substring[current_substring_size++] = in_str[idx];
				// printf("%c", in_str[idx]);

				if (idx > 0)
				{
					frequency_arr[idx] += frequency_arr[idx - 1];
				}
			}
			else
			{
				if (current_substring_size)
				{
					current_substring[current_substring_size] = '\0';
					printf("save_subs('%s')\n", current_substring);
					if (first_match)
					{
						first_match = 0;
						printf("save_subs('%s')\n", current_substring);
					}
				}
				// increment on saved subs

				frequency_arr[idx] = 0;
				current_substring_size = 0;
			}
		}
		if (current_substring_size)
		{
			current_substring[current_substring_size] = '\0';
			printf("save_subs('%s')\n", current_substring);
			if (first_match)
			{
				first_match = 0;
				printf("save_subs('%s')\n", current_substring);
			}
		}
		printf_tri_mat(frequency_arr, idx, 1);
	}

	return NULL;
}

unsigned int *create_frequency_array(unsigned int size)
{
	unsigned int i;
	unsigned int *frequency_arr = (unsigned int *)malloc(sizeof(unsigned int) * size);

	return frequency_arr;
}

unsigned int calculate_triangle_index(unsigned int size, unsigned int i, unsigned int j)
{
	int a = triangle(size - 1) - 1;
	int b = -(triangle(size - j + i) - 1);
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

void printf_tri_mat(unsigned int *mat, unsigned int sizex, unsigned int sizey)
{
	unsigned int i, j;
	unsigned int triangle_index;
	// printf("size = %d\n", sizex);

	for (i = 0; i < sizey; ++i)
	{
		for (j = 0; j < sizex; ++j)
		{
			printf("%2d ", mat[j]);
		}
		printf("\n");
	}
}

// https://covid.saude.gov.br/
// https://opendatasus.saude.gov.br/dataset/covid-19-vacinacao
// https://brasil.io/dataset/covid19/files/
// login? https://opendatasus.saude.gov.br/dataset/covid-19-vacinacao/resource/82743aa8-a77a-40d4-9bb6-6a733c5e57ee?inner_span=True
