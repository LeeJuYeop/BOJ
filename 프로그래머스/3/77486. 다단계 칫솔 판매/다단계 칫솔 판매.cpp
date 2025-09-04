// 구조적인 특성상, 루트가 아닌 리프부터 최종정산이 정해진다.
// 리프노드부터 최종정산을 시작(부모에 10% 때주기)해서 루트까지 타고올라가자.
// 다행히 다음 조건이 있다. 
// enroll 에 등장하는 이름은 조직에 참여한 순서에 따릅니다.
// enroll 등장순서의 역순부터 최종정산을 마치면, 계산이 꼬이지 않고 리프부터 최종정산이 가능하다.
// 일단 seller를 순회하며 unordered_map에 이름-총판매액 을 등록한다.
// * seller 에는 같은 이름이 중복해서 들어있을 수 있습니다. *
// 그 후 enroll의 역순부터 unordered_map에 등록된 총판매엑에서 10%를 referral에 등록된 이름에 떼준다.

// 잘못생각했다.
// 예시에서 tod가 200원을 번 것을 생각할 때(위에서 4번째 그림)
// tod 180최종정산끝, jaimie+20원
// jaimie 18 정산끝, mary +2원
// 이 때 이 2원은 10%가 1원을 넘지 않아 더 위로 올라가지 않지만, emily나 edward에서 온 돈과 합쳐서 계산하면
// 올라갈 여지가 발생한다. 예를들어 11 + 2 + 7 이라고할 때
// 문제에서 위로 가는 금액은 1이지만(11에서 1원, 2에서 0원, 7에서 0원)
// 내가 한 방식에서는 2가 된다(합이 20이 되고 이를 다시 10으로 나누면 2원이 올라감)

// 결론은 seller-amount 를 중심으로 하나하나 계산해줘야한다.
// 부모를 기억하는 노드로 트리를 만들어야할듯?
// 10%가 1원 이상인 경우 계속해서 타고타고 올라가서 result um에 더해준다.
// 시간복잡도는?
// 최악의 경우는 편향트리고, 10,000명이 일직선으로 이어져있지만
// amount범위는 1~100이므로 100원~10,000원인데 10,000원이면 1000 100 10 1 이니까 4번 타고 올라간다
// 한 10,000번 올라가는것도아니고 최대 4번인니까 여기는 신경안써도 되고
// 판매 데이터 개수(N) 따라가니 O(N)

// 신경쓰이는 것은 아래 조건
// seller 에는 같은 이름이 중복해서 들어있을 수 있습니다.
// 1900원과 100원을 팔았을 때 남는돈은  1710 + 10 일까 200 일까? 아마 전자이겠지?

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, string> parent; // 자식-부모를 쌍으로 저장하는 um.
unordered_map<string, int> total; // 총정산액을 기록하는 um.

void fee(string name, int money){
    // 넘어온 돈이 10원 이상이면 위로 세금을 전달하고 나머지를 가진다.
    if(money >= 10){
        int a = ((money / 10) * 10) / 10;
        int b = money - a;
        
        fee(parent[name], a);
        total[name] += b;
    }
    // 넘어온 돈이 10원 미만이면 10%가 1원을 넘지 않으므로 모두 가진다.
    else{
        total[name] += money;
    }
    
    return;
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    
    // um에 자식-부모 로 저장한다.
    for(int i = 0 ; i < enroll.size() ; i++){
        parent[enroll[i]] = referral[i];
    }
    
    // seller-amount 배열을 돌며 정산을 한다.
    for(int i = 0 ; i < seller.size() ; i++){
        fee(seller[i], amount[i]*100);
    }
    
    // total을 result에 옮긴다
    for(int i = 0 ; i < enroll.size() ; i++){
        answer.push_back(total[enroll[i]]);
    }
    
    return answer;
}