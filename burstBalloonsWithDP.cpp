// solution approach : recursion(using dfs + dp)
// take ballon vector with padding 1 on both sides
// take 2D dp matrix initialized with -1
// implement bottom up approach of bursting
// if range is overlapped ie- i > j for that case cost 0 is returned
// if any cell is visited, ie- bursting cost for that combination of ballon is stored previously, so that is returned as dp[i][j]
// cost of particular ballon burst is stored in dp after calculation of maxPoints
// and lastly that cost is returned

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int dfs(int i, int j, vector<int> &ballon, vector<vector<int>> &dp){
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    int maxPoints = -1;
    for(int index = i; index<=j; index++){
        int points;
        if(i-1 == 0 && j+1 == N+1){
            points = ballon[index] + dfs(i, index-1, ballon, dp) + dfs(index+1, j, ballon, dp);
        }else{
            points = ballon[i-1] * ballon[j+1] + dfs(i, index-1, ballon, dp) + dfs(index+1, j, ballon, dp);
        }
        maxPoints = max(maxPoints, points);
    }
    dp[i][j] = maxPoints;
    return dp[i][j];
}
int main(){
    cin >> N;
    vector<int> ballon(N+2, 1);
    
    for(int i = 1; i<=N; i++){
        cin >> ballon[i];
    }
    
    vector<vector<int>> dp(N+2, vector<int>(N+2, -1));
    
    int maxPoints = dfs(1, N, ballon, dp);
    cout << maxPoints;
}