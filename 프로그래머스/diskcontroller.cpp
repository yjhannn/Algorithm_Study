#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // 두 번째 값 기준으로 오름차순 정렬
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    int current = 0;
    int size = jobs.size();
    int i = 0;
    while(1) {
        if(i >= size && pq.empty()) { // i가 다 돌았을 때, 우선순위 큐안의 작업물 끝났을 때
            break;
        }
        while(i < size && current >= jobs[i][0]) {
            pq.push(make_pair(jobs[i][0], jobs[i][1]));
            i++;
        }
        if(!pq.empty()) {
            int start = pq.top().first;
            current += pq.top().second;
            answer += (current - start);
            pq.pop();
        }
        else
            current = jobs[i][0];
    }
    answer /= size;
    
    return answer;
}