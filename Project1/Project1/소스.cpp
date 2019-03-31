#include <stdio.h>

int** make_arr(int **arr, int n);
void free_arr(int **arr, int n);
void input_num(int **arr, int n);
void print_arr(int **arr, int n);

int main() {
	int row_n;
	int num;
	int **arr = NULL;


	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &row_n);
		arr = make_arr(arr, row_n);
		input_num(arr, row_n);
		printf("#%d\n", i + 1);
		print_arr(arr, row_n);
		free_arr(arr, row_n);
	}

	return 0;
}

int** make_arr(int **arr, int n) {
	arr = new int*[n + 2];
	for (int i = 0; i < n + 2; i++)
		arr[i] = new int[n + 2];

	for (int i = 0; i < n + 2; i++)
		for (int j = 0; j < n + 2; j++) {
			if (i == 0 || i == n + 1)
				arr[i][j] = 1;
			else if (j == 0 || j == n + 1)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
		}

	return arr;
}

void free_arr(int **arr, int n) {

	for (int i = 0; i < n + 2; i++)
		delete[]arr[i];

	delete[]arr;

	return;
}

void input_num(int **arr, int n) {
	int x = 1, y = 1;
	int dx = 0, dy = 1;
	int number = 0;
	int rota = 0;

	while (1) {
		if (number++ == n * n)
			break;

		arr[x][y] = number;

		if (arr[x + dx][y + dy] != 0) {
			int t = dx;
			dx = dy; 
			dy = t;
			if (++rota % 2 == 0) {
				dx = -dx;
				dy = -dy;
			}
		}

		x += dx; y += dy;
		
	}
	return;
}

void print_arr(int **arr, int n) {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < n + 1; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return;
}