#include <cstdlib>
#include <iostream>
using namespace std;

bool findPath(int** maze, int x, int y, int** sol, int n);
void print(int** maze, int n);

void SolveMaze(int** maze, int n) {
    // Allocation of a new matrix for the solution of the maze
    int** sol = new int*[n];
    for (int i = 0; i < n; i++) {
        sol[i] = new int[n];
    }

    // Initializing all indexes to 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sol[i][j] = 0;
        }
    }
    

    bool pathFound = findPath(maze, 1, n - 1, sol, n);

    if (!pathFound) {
        cout << "Solution of maze not found...\n";
    } else {
        cout << "Solution of maze exists...\n";
        print(sol, n);
    }

    // Free memory for the solution matrix
    for (int i = 0; i < n; i++) {
        delete[] sol[i];
    }
    delete[] sol;
}

bool isInBoundOrUnblock(int** maze, int x, int y, int n) {
    if (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 0)
        return true;
    return false;
}

bool findPath(int** maze, int x, int y, int** sol, int n) {
    if (x == n - 2 && y == 0) {
        sol[x][y] = 1;
        return true;
    }

    if (isInBoundOrUnblock(maze, x, y, n) == true) {
        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (findPath(maze, x + 1, y, sol, n) == true)
            return true;
        if (findPath(maze, x - 1, y, sol, n) == true)
            return true;
        if (findPath(maze, x, y + 1, sol, n) == true)
            return true;
        if (findPath(maze, x, y - 1, sol, n) == true)
            return true;

        sol[x][y] = 0;
    }
    return false;
}

void print(int** maze, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, temp;

    cout << "Enter size of matrix.\n";
    cin >> n;

    int** maze = new int*[n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp = rand() % 5;
            if (temp < 3)
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }
    maze[1][n - 1] = 0; // Starting point
    maze[n - 2][0] = 0; // Ending point
    cout << "Maze ....\n\n";
    print(maze, n);
    SolveMaze(maze, n);

    // Free memory for the maze
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
    }
    delete[] maze;

    return 0;
}
