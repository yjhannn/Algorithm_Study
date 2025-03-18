#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first == p2.first)
        return p1.second < p2.second;
    else
        return p1.first > p2.first;
}

bool cmp1(pair<string, int> p1, pair<string, int> p2) {
    return p1.second > p2.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> genre_sum; // 장르, 재생횟수 합
    unordered_map<string, vector<pair<int, int>>> music; // 장르, 재생횟수, 곡 번호
    for(int i = 0; i < genres.size(); i++) {
        genre_sum[genres[i]] += plays[i];
        music[genres[i]].push_back(make_pair(plays[i], i));
    }
    for(auto &it : music) {
        sort(it.second.begin(), it.second.end(), cmp);
    }
    vector<pair<string, int>> v(genre_sum.begin(), genre_sum.end());
    sort(v.begin(), v.end(), cmp1);
    for(auto it : v) {
        for(int i = 0; i < music[it.first].size(); i++) {
            answer.push_back(music[it.first][i].second);
            if(i >= 1) break;
        }
    }
    return answer;
}