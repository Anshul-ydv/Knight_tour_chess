#include <iostream>
using namespace std;
#define N 8
int board[N][N];
struct Node {
int x, y;
Node* next;
};
bool isSafe(int x, int y) {
return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}
void printPath(Node* head) {
Node* ptr = head;
while (ptr != NULL) {
cout << "(" << ptr->x << ", " << ptr->y << ") -> ";
ptr = ptr->next;
}
}
bool solveKnightTour(int x, int y, int moveCount, Node* head) {
if (moveCount == N * N) {
printPath(head);
return true;
}
int xMoves[] = {1, 2, 2, 1, -1, -2, -2, -1};
int yMoves[] = {-2,-1,1,2,2,1,-1,-2};
for (int i = 0; i < 8; i++) {
int nextX = x + xMoves[i];
int nextY = y + yMoves[i];
if (isSafe(nextX, nextY)) {
board[nextX][nextY] = moveCount;
Node* newNode = new Node;
newNode->x = nextX;
newNode->y = nextY;
newNode->next = head;
head = newNode;
if (solveKnightTour(nextX, nextY, moveCount + 1, head)) {
return true;
}
board[nextX][nextY] = -1;
head = head->next;
delete newNode;
}
}
return false;
}
void initBoard() {
for (int i = 0; i < N; i++) {
for (int j = 0; j < N; j++) {
board[i][j] = -1;
}
}
}
int main() {
initBoard();
int startX = 0, startY = 0;
board[startX][startY] = 0;
Node* head = new Node;
head->x = startX;
head->y = startY;
head->next = NULL;
if (!solveKnightTour(startX, startY, 1, head))
{
cout << "No solution found.";
}
return 0;
}
