// 최소신장트리문제. 크루스칼 알고리즘(UF)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[101];
int sizes[101];

bool cmp(vector<int>& a, vector<int>& b){
    return a[2] < b[2];
}

int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v){
    int x = parent[u];
    int y = parent[v];
    if(x != y){
        if(sizes[x] > sizes[y]) swap(x, y);
        parent[x] = y;
        sizes[y] += sizes[x];
    }
}

void make_set(int n){
    for(int i = 0 ; i < n ; i++){
        parent[i] = i;
        sizes[i] = 1;
    }
}


int solution(int n, vector<vector<int>> costs) {
    // init
    int answer = 0;
    make_set(n);
    sort(costs.begin(), costs.end(), cmp);      // 가중치 오름차순 정렬
    
    // logic
    int cnt = 0;
    for(auto v : costs){
        if(Find(v[0]) == Find(v[1])) continue;
        
        Union(v[0], v[1]);
        answer += v[2];
        cnt++;
        
        if(cnt == n-1) break;
    }
    
    return answer;
}