// 장르별 재생 수를 알아야 하므로 um_total에 기록하기.(장르:총재생수)
// um_total은 벡터라이즈하여 sort함수와 커스텀정렬규칙함수로 정렬해준다.
// 위와 동시에 장르별 top2를 계속해서 추적하기 위해 우선순위큐를 value로 하는 um_top(장르:우선순위큐<재생수, idx> 운용한다.
// um_total 장르:총재생수
// um_top : 장르:재생수나열우선순위큐<재생수, idx>
// O(N)


#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        return a.second < b.second;
    }
};

bool cmp_gen(const pair<string,int> &a, const pair<string,int> &b){
    return a.second > b.second;
}


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um_total;
    unordered_map<string, priority_queue<pair<int, int>, vector<pair<int,int>>, cmp>> um_top;
    
    // 1. 장르별 총재생수 um 및 장르별 재생수 top곡 um 채우기
    for(int i = 0 ; i < genres.size() ; i++){
        um_total[genres[i]] += plays[i];
        
        um_top[genres[i]].push(make_pair(i, plays[i]));
    }
    
    // 2. 장르별 총재생수 um을 벡터화하여 sort하기
    vector<pair<string, int>> sorted_total(um_total.begin(), um_total.end());
    sort(sorted_total.begin(), sorted_total.end(), cmp_gen);
    
    // 3. 높은 총재생수의 장르순으로 top2 answer에 넣기
    for(auto &gen : sorted_total){
        answer.push_back(um_top[gen.first].top().first);
        um_top[gen.first].pop();
        if(!um_top[gen.first].empty()){
            answer.push_back(um_top[gen.first].top().first);
        }
    }
    
    return answer;
}