# ♞ Knight's Tour - DSA Project

This repository contains a C++ implementation of the **Knight's Tour** problem using **backtracking** and a **linked list** to track the knight's path. It was developed as part of a lab assignment for the Data Structures and Algorithms course.

---

## 📌 Problem Statement

Given an `N x N` chessboard with a knight placed at the first cell, the task is to move the knight such that it visits every cell exactly once, following the rules of knight movement in chess.

---

## 🧠 Approach

The Knight can move in **eight possible directions**. We use a **backtracking** algorithm to explore all possible knight moves recursively while marking visited positions. If we reach a dead end, we backtrack and try another path.

A **linked list** is used to keep track of the knight’s path.

---

## 🖼️ Visualization Idea

- A knight can move in eight directions from any cell.
- From corners, only 2 directions are possible.
- Start from any cell, and attempt to cover all other cells using valid knight moves.
- If a cell is already visited or invalid, backtrack.

---

## 🧮 Algorithm

1. Initialize a linked list to track the path.
2. Define a recursive function to:
   - Mark the current cell as visited.
   - Append it to the path.
   - Recur for all 8 possible moves.
   - Backtrack if no further move is possible.
3. Stop when all cells are visited.

---

## 💻 Code Implementation

```cpp
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
    int yMoves[] = {-2, -1, 1, 2, 2, 1, -1, -2};

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
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = -1;
}

int main() {
    initBoard();

    int startX = 0, startY = 0;
    board[startX][startY] = 0;

    Node* head = new Node;
    head->x = startX;
    head->y = startY;
    head->next = NULL;

    if (!solveKnightTour(startX, startY, 1, head)) {
        cout << "No solution found.";
    }

    return 0;
}
