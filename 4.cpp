#include <stdio.h>
#define N  10

typedef enum
{
	ANSWER_EXIST,
	NO_ANSWER,
} error_t;

char const* GetErrorString(error_t error)
{
	char *a[] = {
		"ANSWER_EXIST\n",
		"NO_ANSWER\n",
	};
	return a[error];
}

error_t reportError(error_t error)
{
	printf("ERROR: %s", GetErrorString(error));
	return error;
}

int bsearch(int array[], int x, error_t *error)
{
	for (int i = 0; i < N; ++i)
	{
		if (array[i] > x)
		{
			return i;
		}
	}
	*error = NO_ANSWER;
}


int main()
{
	error_t error = ANSWER_EXIST;
	int array[N] = { 1, 2, 2, 4, 5, 6, 6, 7, 8, 9 };
	int answer_index, x = 13;

	answer_index = bsearch(array, x, &error);
	if (error == ANSWER_EXIST)
		printf("%i\n", answer_index);
	else
		reportError(error);
	return 0;
}