#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int n, m;

bool dfs(vector<vector<int>> &grid, vector<vector<int>> &dp, vector<vector<bool>> &visited, int r, int c){
    if(r == n-1 && c == 0) return true;
    if(dp[r][c] != -1)  return true;

    int temp = INT_MAX;
    visited[r][c] = true;

    for(int i = c-1; i >= 0; i--){ // left
        if(grid[r][i] == 0) break;
        if(!visited[r][i] && dfs(grid, dp, visited, r, i)){
            temp = min(temp, dp[r][i]);
        }
    }

    for(int i = c+1; i < m; i++){ //right
        if(grid[r][i] == 0) break;
        if(!visited[r][i] && dfs(grid, dp, visited, r, i)){
            temp = min(temp, dp[r][i]);
        }
    }

    for(int i = r-1; i >= 0; i--){ // up
        if(grid[i][c] == 0) continue;
        if(!visited[i][c] && dfs(grid, dp, visited, i, c)){
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
        else if(dp[i][c] != INT_MAX && dp[i][c] != -1){
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
    }

    for(int i = r+1; i < n; i++){ // down
        if(grid[i][c] == 0) continue;
        if(!visited[i][c] && dfs(grid, dp, visited, i, c)){
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
        else if(dp[i][c] != INT_MAX && dp[i][c] != -1){
            temp = min(temp, max(dp[i][c], abs(r-i)));
        }
    }

    dp[r][c] = temp;
    return temp != INT_MAX;
}

int main(){
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m,-1));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int x, y;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> grid[i][j];
            if(grid[i][j] == 3){
                x = i;
                y= j;
            }
        }
    }

    dp[n-1][0] = 0;
    dfs(grid, dp, visited, x, y);
    cout << dp[x][y] << endl;
    return 0;
}
 