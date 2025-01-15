// solution approach : recursion(using dfs)
// create adjList using unordered_map
// run dfs starting from each node
// save path for each minCost
// use pop_back on path o/w multiple cycles will be added simultaneously
// update global minPath with path for every currentCost+currentNode < minCost 
// lastly sort the minPath

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> minPath;

void dfs(int currentNode, int currentCost, vector<int> &path, unordered_map<int, vector<int>> &adjList, vector<bool>&isVisited, int &minCost){
    if(currentCost > minCost) return;
    
    path.push_back(currentNode);
    isVisited[currentNode] = true;
    
    for(int neighbor : adjList[currentNode]){
        if(!isVisited[neighbor]){
            dfs(neighbor, currentCost+currentNode, path, adjList, isVisited, minCost);
        }else{
            // while(path[0]!=neighbor){
            //     path.erase(path.begin());
            // }
            if(currentCost+currentNode < minCost){
                minCost = currentCost+currentNode;
                minPath = path;
            }
        }
    }
    isVisited[currentNode] = false;
    path.pop_back();
}

int main(){
    cin >> N >> M;

    unordered_map<int, vector<int>> adjList;
    int u, v;
    
    for(int i = 0; i<M; i++){
            cin >> u >> v;
            adjList[u].push_back(v); 
    }
    
    int minCost = 9999999;
    for(int i = 1; i<=N; i++){
        vector<bool> isVisited(N+1, false);
        vector<int> path;
        dfs(i, 0, path, adjList, isVisited, minCost);
    }
    
    sort(minPath.begin(), minPath.end());
    
    for(int item : minPath){
        cout << item << " ";
    }
    return 0;
}