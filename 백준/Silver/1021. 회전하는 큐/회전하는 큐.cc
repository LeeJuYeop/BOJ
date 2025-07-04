#include <iostream>
#include <queue>
using namespace std;

struct node{
    int value;
    int left;
    int right;
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<node> dic{};

    for(int i = 0 ; i < N ; i++){
        dic.push_back(node{i+1, i-1, i+1});
    }
    dic[0].left = N-1;
    dic[N-1].right = 0;

    int target[M];
    for(int i = 0 ; i < M ; i++){
        cin >> target[i];
    }

    int ans{0};
    int lcur{0};
    int rcur{0};
    int lcnt, rcnt;
    for(int i = 0 ; i < M ; i++){
        lcnt = 0;
        rcnt = 0;
        
        // lcur과 rcur 이동하며 counter 쌓기
        while(dic[lcur].value != target[i]){
            lcur = dic[lcur].left;
            lcnt++;
        }
        while(dic[rcur].value != target[i]){
            rcur = dic[rcur].right;
            rcnt++;
        }

        // cout << lcnt << endl;
        // cout << rcnt << endl;
        // lcnt와 rcnt 비교해서 ans에 추가
        if(lcnt < rcnt){ans += lcnt;}
        else{ans += rcnt;}

        // 노드 삭제진행
        int left = dic[lcur].left;
        int right = dic[lcur].right;
        dic[left].right = dic[lcur].right;
        dic[right].left = dic[lcur].left;
        lcur = right;
        rcur = right;
    }
    cout << ans << endl;
}

// 1 2 3 4 5 6 7 8 9 10
// 링크드 리스트 -> 어느 방향(완,오)이 최적인지 두 번 탐색필요
// 큐의 크기, 뽑아내는 수의 개수가 둘 다 50이하기 때문에 괜찮을 것 같다.
// 링크드 리스트가 맞아보인다. 요소의 삭제가 빈번하므로