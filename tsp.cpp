// solution approach: recursion
// explore all possible ways to visit from one city to another for(int i = 1; i<n; i++)
// try to keep track of visited cities   visited[i] = true; ......visited[i] = false;
// use backtrack to calculate minCost at the last city   if(cityLeft == 0)


#include <bits/stdc++.h>
using namespace std;
int n;

void backtrack(int x, int currentCost, int cityLeft, vector<vector<int>> &matrix, vector<bool> &visited, int &minCost){
    if(currentCost > minCost) return;

    if(cityLeft == 0){
        minCost = min(minCost, (currentCost+matrix[x][0]));
        return;
    }   
    for(int i = 1; i<n; i++){
        if(!visited[i]){
            visited[i] = true;
            backtrack(i, currentCost+matrix[x][i], cityLeft-1, matrix, visited, minCost);  
            visited[i] = false;
        }
    }
    return;
}
    
int main() {
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;   
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<bool> visited(n, false);
        
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n;j++){
                cin >> matrix[i][j];
            }
        }
        int minCost = 9999999;
        backtrack(0, 0, n-1,matrix, visited, minCost);      
        cout << minCost << endl;
    }
    return 0;
}
