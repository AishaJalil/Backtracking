#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze

bool isValid(int x, int y, int maze[N][N], int visited[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] != -1 && !visited[x][y]);
}

bool findPath(int x, int y, int maze[N][N],int visited[N][N]) {
    // If the current cell is the destination (middle cell), return true
    if (x == 2 && y == 2) {
        return true;
    }

    // Get the allowed number of steps from the current cell
    int steps = maze[x][y];

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Try moving right
    for (int i = 1; i <= steps; i++) {
        if (isValid(x, y + i, maze, visited)) {
            if (findPath(x, y + i, maze, visited)) {
                return true;
            }
        }
    }

    // Try moving down
    for (int i = 1; i <= steps; i++) {
        if (isValid(x + i, y, maze, visited)) {
            if (findPath(x + i, y, maze, visited)) {
                return true;
            }
        }
    }

    // Mark the current cell as unvisited (backtracking)
    visited[x][y] = 0;

    return false;
}

int main() {
    int maze[N][N] = {
        {2, 2, 4, 4, 3},
        {3, 4, 3, 2, 2},
        {1, 1, 0, 3, 2},
        {3, 2, 2, 1, 2},
        {3, 3, 4, 3, 1}
    };

    int visited[N][N]={0};
    
    if (findPath(0, 0, maze, visited)) {
        cout << "Path found!\n";
    } else {
        cout << "No path found.\n";
    }

    return 0;
}

