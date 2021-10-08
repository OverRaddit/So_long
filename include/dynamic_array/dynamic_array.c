#include "dynamic_array.h"

char	**get_arr(int capacity)
{
	char	**arr;

	//printf("get_arr 연산을 수행합니다.\n");
	arr = (char **)malloc(sizeof(char *) * capacity);
	return (arr);
}

void	arr_free(t_vector *vec)
{
	int		i;

	i = 0;
	while(i < vec->size)
	{
		free(vec->arr[i++]);
	}
}

void	copy_arr(char **dest, char **src, int n)
{
	int i;

	//printf("copy_arr 연산을 수행합니다.\n");
	i = -1;
	while(++i < n)
	{
		dest[i] = src[i];
	}
}

t_vector	*vec_init()
{
	t_vector *vec;

	//printf("init 연산을 수행합니다.\n");
	vec = (t_vector *)malloc(sizeof(t_vector *) * 1);
	if (!vec)
		return (0);
	vec->size = 0;
	vec->capacity = 10;
	// 이부분 malloc 골치아픔
	vec->arr = get_arr(vec->capacity);
	if (!(vec->arr))
	{
		free(vec);
		return (0);
	}
	return (vec);
}

int	append(t_vector *vec, char *add)
{
	char	**new;

	//printf("Append 연산을 수행합니다.\n");
	// 현재 배열이 FULL일 경우
	if (vec->size == vec->capacity)
	{
		//printf("용량이 다 찼습니다. 추가로 메모리를 할당합니다.\n");
		new = get_arr(vec->capacity * 2);
		if (!new)
			return (-1);
		copy_arr(new, vec->arr, vec->size);
		free(vec->arr);
		vec->arr = new;
		vec->capacity *= 2;
	}
	vec->arr[vec->size++] = add;
	return (0);
}

/*
int main(){
	t_vector *vec;

	vec = vec_init();
	for(int i=0;i<20;i++)
	{
		append(vec, "a");
	}

	// debug
	for(int i=0;i<20;i++)
	{
		printf(">[%d]%s\n", i, vec->arr[i]);
	}
}
*/
