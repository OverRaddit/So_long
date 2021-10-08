#ifndef DYNAMIC_ARRAY_H
# define DYNAMIC_ARRAY_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_vector
{
	int		size;		// 배열에 담긴 자료개수(다음으로 추가될 인덱스이기도함)
	int		capacity;	// 현재 배열의 크기
	char	**arr;		// 나는 char*의 주소를 저장할 배열을 담을 것이다.
}				t_vector;

t_vector	*vec_init();
int	append(t_vector *vec, char *add);
void	arr_free(t_vector *vec);

#endif
