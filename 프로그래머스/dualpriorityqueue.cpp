#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> s; // 자동 정렬되는 multiset 사용

    for (string op : operations) {
        if (op[0] == 'I') {
            int num = stoi(op.substr(2));
            s.insert(num);
        } 
        else if (!s.empty()) { // 삭제 연산 수행 전 비어있는지 확인
            if (op[2] == '1') { // 최댓값 삭제
                s.erase(prev(s.end())); // 가장 큰 원소 삭제
            } 
            else { // 최솟값 삭제
                s.erase(s.begin()); // 가장 작은 원소 삭제
            }
        }
    }

    if (s.empty()) return {0, 0}; // 비어있으면 [0, 0] 반환
    return {*prev(s.end()), *s.begin()}; // 최댓값과 최솟값 반환
}