// 자동으로 정렬해주는 자료구조를 사용해야 시간안에 가능하다.
// 그러나 우선순위큐에는 인덱스로 접근하지 못한다.
// https://velog.io/@rhkswls98/%EB%B0%B1%EC%A4%80-1655-C-%EA%B0%80%EC%9A%B4%EB%8D%B0%EB%A5%BC-%EB%A7%90%ED%95%B4%EC%9A%94
// 최소힙과 최대힙으로 중앙값 구하는 방법
// 1. 최대힙의 크기는 최소힙의 크기보다 하나 더 크거나 같아야 합니다.
// 2. 최대힙의 최대 원소는 최소힙의 최소원소보다 작거나 같아야 합니다. (이 경우 두 top 스왑
// 위의 규칙을 지키면서 입력을 삽입하면 각 top은 가운데값에 가까운 값들이 오게된다.
// 최대힙꼬리 --- 최대힙front - 가운데값 - 최소힙front --- 최소힙꼬리

#include <iostream>
#include <queue>
using namespace std;

int main(){
    // init
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    int n;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;  // 최소힙.

    // logic
    cin >> n; max_pq.push(n); cout << n << endl;
    t--;

    while(t--){
        cin >> n;
        if(max_pq.size() > min_pq.size()) min_pq.push(n);
        else max_pq.push(n);

        if(max_pq.top() > min_pq.top()){
            int tmp = min_pq.top(); min_pq.pop();
            min_pq.push(max_pq.top());
            max_pq.pop(); max_pq.push(tmp);
        }

        cout << max_pq.top() << '\n';
    }
}