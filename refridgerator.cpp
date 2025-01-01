// another TSP problem 
// solution approach: backtracking (using DFS)
// run recursion on each customer
// returns when N customer visited or currentCost > minCost
// must update isVisited[i] = false; after each recursion call ends as this customer needs to be visited in the next call

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int officeX, officeY, homeX, homeY, customerX[10], customerY[10], N;

void backtrack(int currentCost, int currentX, int currentY, int customerCount, vector<bool> &isVisited, int &minCost){
    if(currentCost > minCost) return;
    
    if(customerCount == N){
        int lastCost = abs(currentX - homeX) + abs(currentY - homeY);
        minCost = min(minCost, currentCost + lastCost);
        return;
    }
    
    for(int i = 0; i<N; i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            int cost = currentCost + abs(currentX - customerX[i]) + abs(currentY - customerY[i]);
            backtrack(cost, customerX[i], customerY[i], customerCount + 1, isVisited, minCost);
            isVisited[i] = false;
        }
    }
}

int main(){
    int t = 1;
    
    while(t <= 10){
        cin >> N;
        vector<bool> isVisited(N, false);
        cin >> officeX >> officeY >> homeX >> homeY;
        
        for(int i = 0; i<N; i++){
            cin >> customerX[i] >> customerY[i]; 
        }
        int minCost = 999999;
        backtrack(0, officeX, officeY, 0, isVisited, minCost);
        cout << "# " << t << " " << minCost << endl;
        t++;
    }
    return 0;
}