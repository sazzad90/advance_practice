// solution approach : recursion(using dfs)
// use loop inside dfs for starting from each balloon
// calculate currentCost in either of 3 ways
// erase current balloon, then dfs call, insert afterwards 
// returns when the balloons becomes size of 1

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

void dfs(int currentCost, vector<int> balloons, int &maxCost){
    if(balloons.size() == 1){
        currentCost += balloons[0];
        maxCost = max(maxCost, currentCost);
        return;
    }
    
    for(int index = 0;  index<balloons.size(); index++){
        int temp;
        if(index == 0){
            temp = balloons[index+1] + currentCost;
        }else if(index == balloons.size()-1){
            temp = balloons[index-1] + currentCost;
        }else{
            temp = (balloons[index-1] * balloons[index+1]) + currentCost;
        }
        int balloon = balloons[index];
        balloons.erase(balloons.begin() + index);
        dfs(temp, balloons, maxCost);
        balloons.insert(balloons.begin() + index, balloon);
    }     
}

int main(){
    cin >> N;
    vector<int> balloons(N);
    
    for(int i = 0; i<N; i++){
        cin >> balloons[i];
    }
    
    int maxCost = -1;
    dfs(0, balloons, maxCost);
    
    cout << maxCost;
    return 0;
}
