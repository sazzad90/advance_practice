// solution approach : recursion(using dfs)
// set spots as visited vector and start from 1 index
// run dfs on each combination of gates visit
// base case : swipe the gates when men count becomes zero and returns when both men count becomes zero + last gate is visited
// calculate leftCost using findLeft spot and rightCost using findRight spot
// take the minimum cost and pass it to following recursion with minimizing men count and setting visited true
// retain prev value of men count by incrementing and visited to false after corresponding recursion

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int loc[4], men[4];
int minCost = 9999999;

int findLeft(int loc, vector<bool> &visited){
    for(int i = loc; i>0; i--){
        if(!visited[i]) return i;
    }
    return 9999999;
}

int findRight(int loc, vector<bool> &visited){
    for(int i = loc+1; i<=N; i++){
        if(!visited[i]) return i;
    }
    return 9999999;
}

void dfs(int x, int y, int z, int currGate, int currCost, vector<bool> &visited){
    if(men[currGate] == 0){
        if(currGate == x) currGate = y;
        else if(currGate == y) currGate = z;
        else{
            minCost = min(minCost, currCost);
            return;
        }
    }
    
    int leftPos = findLeft(loc[currGate], visited);
    int rightPos = findRight(loc[currGate], visited);
    
    int leftCost = 1 + abs(loc[currGate] - leftPos);
    int rightCost = 1 + abs(loc[currGate] - rightPos);
    
    if(leftCost < rightCost){
        men[currGate]--;
        visited[leftPos] = true;
        dfs(x,y,z,currGate,currCost+leftCost,visited);
        men[currGate]++;
        visited[leftPos] = false;
    }else{
        men[currGate]--;
        visited[rightPos] = true;
        dfs(x,y,z,currGate,currCost+rightCost,visited);
        men[currGate]++;
        visited[rightPos] = false;
    }
}

int main(){
    cin >> N;
    
    for(int i = 1; i<=3; i++) cin >> loc[i];
    for(int i = 1; i<=3; i++) cin >> men[i];

    vector<bool> visited(N+1, false);
    
    dfs(1,2,3,1,0,visited);
    dfs(1,3,2,1,0,visited);
    dfs(2,1,3,2,0,visited);
    dfs(2,3,1,2,0,visited);
    dfs(3,2,1,3,0,visited);
    dfs(3,1,2,3,0,visited);
    
    cout << minCost;
    return 0;
}