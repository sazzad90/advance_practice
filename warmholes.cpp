// solution approach : recursion(using dfs)
// setting point and warmhole as struct
// trying all possible ways to reach destination using dfs and looping over warmholes
// pruning several ways where currentCost + finalDistance > minCost for optimization
// and must consider on the "BI-DIRECTIONAL" property of warmholes

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

struct Point{
    int x, y;
};
Point source, destination;

struct Warmhole{
    Point enter, exit;
    int cost;
};

int calculateDistance(Point source, Point destination){
    int x = abs(source.x - destination.x);
    int y = abs(source.y - destination.y);
    return x + y;
}

void calculateMinCost(Point source, int currentCost, Point finalDestination, vector<Warmhole> &warmholes, vector<bool> &isVisited, int &minCost){
    int finalDistance = calculateDistance(source, finalDestination);
    if(currentCost + finalDistance >= minCost) return;
    
    minCost = min(minCost, currentCost+finalDistance);
    
    for(int i = 0; i<N; i++){
        if(!isVisited[i]){
            isVisited[i] = true;
            // for bidirectional property
calculateMinCost(warmholes[i].exit, currentCost+calculateDistance(source, warmholes[i].enter)+warmholes[i].cost, finalDestination, warmholes, isVisited, minCost);
calculateMinCost(warmholes[i].enter, currentCost+calculateDistance(source, warmholes[i].exit)+warmholes[i].cost, finalDestination, warmholes, isVisited, minCost);
            isVisited[i] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--){
        cin >> N;
        
        cin >> source.x >> source.y >> destination.x >> destination.y;
        
        vector<Warmhole> warmholes(N);
        for(int i = 0; i<N; i++){
            cin >> warmholes[i].enter.x >> warmholes[i].enter.y >> warmholes[i].exit.x >> warmholes[i].exit.y >> warmholes[i].cost;
        }
        
        vector<bool> isVisited(N, false);
        int minCost = 9999999;
        calculateMinCost(source, 0, destination, warmholes, isVisited, minCost);
        cout << minCost << endl;
    }
    return 0;
}
