#include <iostream>
#include <vector>

using namespace std;

int n,target_high;
vector<int> tree;

void input(){
    scanf("%d %d", &n, &target_high);
    for(int x,i=0; i<n; i++){
        scanf("%d", &x);
        tree.push_back(x);
    }
    return ;
}
// longlong 이어야 하는 이유
// 1백개의 나무가 모두 10억m이고, 목표가 1m라면, 
// 처음 이분탐색시 middle=5억일때 5억*백만의 값이 sum에 들어가게 된다.
int check(long long middle){
    long long sum=0; 
    for(int i=0; i<n; i++){
        if(tree[i] > middle){
            sum += tree[i] - middle;
        }
    }
    return sum >= target_high;
}

void solve(){
    long long high = 1000000000; // 10억
    long long low = 0;
    long long middle = 0;

    while(high != low){
        middle = (high + low + 1) / 2;
        if(check(middle)){ // 목표 이상의 나무를 구할 수 있을 경우 -> 톱의 높이를 더 올려야함. middle은 포함한 채로
            low = middle;
        }else{
            high = middle - 1;
        }
    }
    printf("%lld\n", high);
    return ;
}

int main(){
    input();
    solve();
    return 0;
}
