#include <stdio.h>
#define size 10000
int grid[size][size], visited[size][size];
int N, M, X, Y, L;
int T, Case, Ans;
int front, rear;
typedef struct pointStruct
{
    int x, y, dist;
}Point;
Point Queue[size * size];
void initQueue()
{
    front = rear = 0;
}
int isEmpty()
{
    return (front == rear);
}
void push(int x, int y, int dist)
{
    Queue[rear].x = x;
    Queue[rear].y = y;
    Queue[rear].dist = dist;
    rear++;
}
Point pop()
{
    return Queue[front++];
}
void init()
{
    int i, j;
    for (i = 0; i < N; i++) for (j = 0; j < M; j++)
    {
        visited[i][j] = grid[i][j] = 0;
    }
}
void readcase()
{
    int i, j;
    scanf("%d %d %d %d %d", &N, &M, &X, &Y, &L);
    init();
    for (i = 0; i < N; i++) for (j = 0; j < M; j++)
        scanf("%d", &grid[i][j]);
}
int checkUp(int x, int y)
{
    if(1 == grid[x][y] || 2 == grid[x][y] || 4 == grid[x][y] || 7 == grid[x][y])
        return 1;
    return 0;
}
int checkDown(int x, int y)
{
    if(1 == grid[x][y] || 2 == grid[x][y] || 5 == grid[x][y] || 6 == grid[x][y])
        return 1;
    return 0;
}
int checkLeft(int x, int y)
{
    if(1 == grid[x][y] || 3 == grid[x][y] || 6 == grid[x][y] || 7 == grid[x][y])
        return 1;
    return 0;
}
int checkRight(int x, int y)
{
    if(1 == grid[x][y] || 3 == grid[x][y] || 4 == grid[x][y] || 5 == grid[x][y])
        return 1;
    return 0;
}
void solvecase()
{
    Ans = 0;
    initQueue();
    
    if(grid[X][Y])
    {
        push(X, Y, 1);
        visited[X][Y] = 1;
        Ans++;
    }
    while(!isEmpty())
    {
        Point point;
        point = pop();
        if (point.dist == L)
            return;
        if (point.x - 1 >= 0 && !visited[point.x - 1][point.y] && checkUp(point.x, point.y) && checkDown(point.x - 1, point.y))
        {
            visited[point.x - 1][point.y] = 1;
            push(point.x - 1, point.y, point.dist + 1);
            Ans++;
        }
        if (point.x + 1 < N && !visited[point.x + 1][point.y] && checkDown(point.x, point.y) && checkUp(point.x + 1, point.y))
        {
            visited[point.x + 1][point.y] = 1;
            push(point.x + 1, point.y, point.dist + 1);
            Ans++;
        }
        if (point.y - 1 >= 0 && !visited[point.x][point.y - 1] && checkLeft(point.x, point.y) && checkRight(point.x, point.y - 1))
        {
            visited[point.x][point.y - 1] = 1;
            push(point.x, point.y - 1, point.dist + 1);
            Ans++;
        }
        if (point.y + 1 < M && !visited[point.x][point.y + 1] && checkRight(point.x, point.y) && checkLeft(point.x, point.y + 1))
        {
            visited[point.x][point.y + 1] = 1;
            push(point.x, point.y + 1, point.dist + 1);
            Ans++;
        }
    }
}
void printcase()
{
    printf("%d\n", Ans);
}
int main()
{
    scanf("%d", &T);
    for (Case = 1; Case <= T; Case++)
    {
        readcase();
        solvecase();
        printcase();
    }
    return 0;
}
