// SpaceShip.c
#include<stdio.h>

int Case;
int N;
int Board[101][5];
int Max;
void readCase() {
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) for (j = 0; j < 5; j++)
		scanf("%d", &Board[i][j]);
}
void go(int row, int col, int life, int score) {
	if (row < 0) {
		if (score > Max)
			Max = score;
		return;
	}
	if (life > 0 && life < 6)
		life--;
	if (1 == Board[row][col])
		score++;
	else if (2 == Board[row][col]) {
		if (0 == life) {
			if (score > Max)
				Max = score;
			return;
		}
		else if (6 == life)
			life--;
	}
	if (col - 1 >= 0)
		go(row - 1, col - 1, life, score);
	go(row - 1, col, life, score);
	if (col + 1 < 5)
		go(row - 1, col + 1, life, score);
}
void solveCase() {
	Max = 0;
	Board[N][2] = 0;
	//go(N - 1, 1, 6, 0);
	go(N, 2, 6, 0);
	//go(N - 1, 3, 6, 0);
}
void printCase() {
	printf("#%d %d\n", Case, Max);
}
int main() {
	int T;
	freopen("SpaceShip_input.txt", "r", stdin);
	freopen("SpaceShip_output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
