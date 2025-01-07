// solution approach : matching pattern for each row
// pattern counts are saved incrementally if -----
// 1. cnt <= k ; this much flips are possible
// 2. (k - cnt)%2 == 0 ; even difference is possible cause if '1's are flipped even times it will remain same
// finally max count of same pattern is the required number of flips

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int N, M, k;

int calculateFlips(vector<vector<int>> &matrix){
    unordered_map<string, int> patterns;
                                                
    for(int i = 0; i<N; i++){
        string pattern = "";
        int cnt = 0;
        for(int j = 0; j<M; j++){
            if(matrix[i][j] == 0){
                pattern += "1";
                cnt++;
            }else{
                pattern += "0";
            }
        }
        if(cnt <= k && (k-cnt)%2 == 0){
            patterns[pattern]++;
        }
    }
    
    int maxFlips = 0;
    for(auto &pattern : patterns){
        maxFlips = max(maxFlips, pattern.second);
    }
    return maxFlips;
}

int main(){
    cin >> N >> M >> k;
    vector<vector<int>> matrix(N, vector<int>(M));
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin >> matrix[i][j];
        }
    }
    
    cout << calculateFlips(matrix);
    return 0;
}