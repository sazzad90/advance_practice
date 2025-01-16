#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>


using namespace std;

int N, M;

bool canReachGoal(vector<vector<int>> &matrix, int jump){
    queue<vector<int>> q;
    q.push({N-1, 0});

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    visited[N-1][0] = true;

    while(!q.empty()){
        auto temp = q.front();
        q.pop();

        int r = temp[0], c = temp[1];

        if(matrix[r][c] == 3) return true;
        // left
        if(c-1 >= 0){
            int row = r, col = c - 1;
            if(!visited[row][col] && matrix[row][col] != 0){
                visited[row][col] = true;
                q.push({row, col});
            }
        }

        // right
        if(c+1 < M){
            int row = r, col = c + 1;
            if(!visited[row][col] && matrix[row][col] != 0){
                visited[row][col] = true;
                q.push({row, col});
            }
        }

        // up + down
        for(int k = 1; k<=jump; k++){
            // up
            int rowUp = r - k, col = c;
            if(rowUp >= 0){
                if(!visited[rowUp][col] && matrix[rowUp][col] != 0){
                    visited[rowUp][col] = true;
                    q.push({rowUp, col});
                }
            }
            // down
            int rowDown = r + k;
            if(rowDown < N){
                if(!visited[rowDown][col] && matrix[rowDown][col] != 0){
                    visited[rowDown][col] = true;
                    q.push({rowDown, col});
                }
            }
        }
    }
    return false;
}

int main(){
    cin >> N >> M;
    vector<vector<int>> matrix(N, vector<int>(M));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> matrix[i][j];
        }
    }
    int ans = -1;
    int low = 0, high = N-1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(canReachGoal(matrix, mid)){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}