#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> q;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    
    for(int i = 0; i < scoville.size(); i++) {
        q.push(scoville[i]);
    }
    while(q.size() > 1) {
        if(q.top() >= K) {
            return answer;
        }
        answer++;
        int first_lowest = q.top(); q.pop();
        int second_lowest = q.top(); q.pop();
        int new_val = first_lowest + (second_lowest * 2);
        q.push(new_val);
        
    }
    return (q.top() >= K) ? answer : -1;
}