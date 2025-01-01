// solution approach: bfs(using queue)
// create direction vector
// check for bidirectional flow through pipes
// check if isVisited
// check upto max length capacity of endoscope
// update totalLength only for any valid move of endoscope

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

int N, M, R, C, L;

vector<vector<int>> direction = {
    // left, right, up, down
    {0,0,0,0},
    {1,1,1,1},
    {0,0,1,1},
    {1,1,0,0},
    {0,1,1,0},
    {0,1,0,1},
    {1,0,0,1},
    {1,0,1,0}
};

void bfs(vector<vector<int>> &pipes, int &totalLength) {
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    queue<vector<int>> q;
    q.push({R, C, 1}); // x, y, currentLength
    isVisited[R][C] = true;

    while (!q.empty()) {
        auto pipe = q.front();
        q.pop();

        int row = pipe[0], col = pipe[1], currentLength = pipe[2];
        int directionIndex = pipes[row][col];

        if (currentLength < L) {
            for (int i = 0; i < 4; i++) {
                if (direction[directionIndex][i] == 1) {
                    if (i == 0 && col - 1 >= 0 && !isVisited[row][col - 1] && direction[pipes[row][col - 1]][1] == 1) { // left
                        q.push({row, col - 1, currentLength + 1});
                        isVisited[row][col - 1] = true;
                        totalLength++;
                    } else if (i == 1 && col + 1 < M && !isVisited[row][col + 1] && direction[pipes[row][col + 1]][0] == 1) { // right
                        q.push({row, col + 1, currentLength + 1});
                        isVisited[row][col + 1] = true;
                        totalLength++;
                    } else if (i == 2 && row - 1 >= 0 && !isVisited[row - 1][col] && direction[pipes[row - 1][col]][3] == 1) { // up
                        q.push({row - 1, col, currentLength + 1});
                        isVisited[row - 1][col] = true;
                        totalLength++;
                    } else if (i == 3 && row + 1 < N && !isVisited[row + 1][col] && direction[pipes[row + 1][col]][2] == 1) { // down
                        q.push({row + 1, col, currentLength + 1});
                        isVisited[row + 1][col] = true;
                        totalLength++;
                    }
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> N >> M >> R >> C >> L;
        vector<vector<int>> pipes(N, vector<int>(M));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> pipes[i][j];
            }
        }

        int totalLength = 1;
        bfs(pipes, totalLength);
        cout << totalLength << endl;
    }
    return 0;
}
