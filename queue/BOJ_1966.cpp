#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int check[10] = {0};

int get_max(){
    int max = 0;
    for (int i = 0; i < 10; i++)
        if (check[i] > 0) max = i;
    
    return max;
}

void max_init(int max){
    check[max]--;
    return ;
}

int main(){
    int T;
    cin >> T;
    for (int t = 0; t < T; t++){
        queue<pair<int, int>> q;
        int n, target, count = 1;

        for (int i = 0; i < 10; i++)
        {
            check[i] = 0;
        }

        scanf("%d %d", &n, &target);
        for (int x, i = 0; i < n; i++){
            scanf("%d", &x);
            check[x]++;
            if (i == target)q.push({x, 1});
            else q.push({x, 0});
        }

        while (!q.empty()){
            if (q.front().first == get_max()){
                if (q.front().second == 1){ // target이면
                    printf("%d\n", count);
                    break;
                }
                else{
                    q.pop();
                    count++;
                    max_init(get_max());
                }
            }else{
                pair<int, int> temp = q.front();
                q.pop();
                q.push(temp);
            }
        }
    }
    return 0;
}
