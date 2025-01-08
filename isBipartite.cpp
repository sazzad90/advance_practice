// solution approach : recursion(using dfs)
// set color array to -1 as unvisited
// run dfs on each node if it is not visited and set it's color value to 0
// inside dfs; check if the neighbor is unvisited or not
// if unvisited; set the alternate color than parent and run dfs(set failure propagation on this dfs call, it will stop recursion whenever hits any false)
// if visited and same color; return false as it is not bipartite
// return true lastly

// leetcode 785. Is Graph Bipartite?

class Solution {
public:
    bool dfs(int currentNode, vector<vector<int>>& graph, vector<int> &color){
        for(int neighbor : graph[currentNode]){
            if(color[neighbor] == -1){
                color[neighbor] = 1 - color[currentNode];
                if(!dfs(neighbor, graph, color)) return false;
            }else if(color[currentNode] == color[neighbor]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i<graph.size(); i++){
            if(color[i] == -1){
                color[i] = 0;
                if(!dfs(i, graph, color)){
                    return false;
                }
            }
        }
        return true;
    }
};