// solution approach: bfs (using queue)
// use loop for -1 0 +1 to check adjacent positions
// if 2 and bomb is not used, then update that position with currentRow 
// if 2 and bomb is used, then check if bomb_used - newRow <= 4 which ensures updating upto 5 rows
#include <bits/stdc++.h>
using namespace std;

int N;

void bfs(int row, int col, vector<vector<int>> &matrix, int &totalScore){
    queue<vector<int>> q;
    q.push({0, row, col, -1});
    
    while(!q.empty()){
        auto qItem = q.front();
        int score = qItem[0], row = qItem[1], col = qItem[2], bomb_used = qItem[3];
        q.pop();
        
        totalScore = max(score, totalScore);
        for(int i = -1; i<=1; i++){
            int newRow = row - 1, newCol = col + i;
            if(newRow < 0 || newCol < 0 || newCol > 4) continue;
            
            if(matrix[newRow][newCol] <= 1){
                q.push({score+matrix[newRow][newCol], newRow, newCol, bomb_used});
            }else{
                if(bomb_used == -1){
                    q.push({score, newRow, newCol, newRow});
                }else if(bomb_used - newRow <= 4){
                    q.push({score, newRow, newCol, bomb_used});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    
    for(int k = 1; k<=t; k++){
        cin >> N;
        vector<vector<int>> matrix(N, vector<int>(5));
        
        for(int i = 0; i<N;i++){
            for(int j = 0; j<5;j++){
                cin >> matrix[i][j];
            }
        }
        
        int totalScore = 0;
        bfs(N, 2, matrix, totalScore);
        
        cout << "#" << k << " " << totalScore << endl;
    }
    return 0;
}
