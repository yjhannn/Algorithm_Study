#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);
    for(int i = 0; i < edge.size(); i++) {
        int from = edge[i][0];
        int to = edge[i][1];
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vector<int> distance(n+1, -1);
    distance[1] = 0;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        for(int i : graph[front]) {
            if(distance[i] == -1) {
                distance[i] = distance[front] + 1;
                q.push(i);
            }
        }
    }
    int mx = -1;
    for(int i = 0; i < distance.size(); i++) {
        if(mx < distance[i]) 
            mx = distance[i];
    }
    
    for(int i = 0; i < distance.size(); i++) {
        if(mx == distance[i])
            answer++;
    }
    
    return answer;
}