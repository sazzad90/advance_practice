// solution approach: recursion(using dfs)
// jump levels or difficulty levels are used from 0->N
// for each jump level dfs is implemented to find out the destination; if found return cause that will be minimum level
// left or right moves were made by 1 step each time
// up or down moves are made from 1->jump level to find out the destination for each scenerio
// isVisited is used to keep track for visited rock points
// and boundaries are checked to avoid segmentation fault

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> rocks;

void dfs(int row, int col, int jump, bool &isReached, vector<vector<bool>> &isVisited) {
    if (row < 0 || row >= N || col < 0 || col >= M || isVisited[row][col] || rocks[row][col] == 0) {
        return; // Out of bounds or visited or invalid cell
    }

    if (rocks[row][col] == 3) {
        isReached = true;
        return;
    }

    isVisited[row][col] = true;

    // Move left
    dfs(row, col - 1, jump, isReached, isVisited);
    if (isReached) return;

    // Move right
    dfs(row, col + 1, jump, isReached, isVisited);
    if (isReached) return;

    // Move up with jump
    for (int i = 1; i <= jump; i++) {
        dfs(row - i, col, jump, isReached, isVisited);
        if (isReached) return;
    }

    // Move down with jump
    for (int i = 1; i <= jump; i++) {
        dfs(row + i, col, jump, isReached, isVisited);
        if (isReached) return;
    }
}

int main() {
    cin >> N >> M;
    rocks.resize(N, vector<int>(M)); // Initialize the `rocks` vector with size N x M

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> rocks[i][j];
        }
    }

    bool isReached = false;
    for (int jump = 0; jump <= N; jump++) { // Incrementally increase the jump distance
        vector<vector<bool>> isVisited(N, vector<bool>(M, false));
        dfs(N - 1, 0, jump, isReached, isVisited);

        if (isReached) {
            cout << jump << endl;
            break;
        }
    }

    return 0;
}
