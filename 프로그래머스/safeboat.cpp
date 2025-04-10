#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0, last = people.size() - 1;
    sort(people.begin(), people.end());
    while(start <= last) {
        if(people[last] + people[start] <= limit) {
            start++;
        }
        last--;
        answer++;
    }
    
    return answer;
}