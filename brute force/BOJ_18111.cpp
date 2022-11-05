#include <iostream>

using namespace std;

int main(){
    int n, m, b;
    int input[500][500]={0,};
    int sum = 0, min=987654321, h_index=0;
    int in_ground = 0, out_ground = 0;

    //input
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &input[i][j]);
        }
    }

    //solved
    for (int h = 0; h <= 256; h++){
        sum = 0, in_ground = 0, out_ground = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(h - input[i][j] > 0){
                    sum += (h - input[i][j]); // 땅을 심어야하는 경우
                    in_ground += h - input[i][j];
                }
                if (h - input[i][j] < 0)
                {
                    sum += (input[i][j] - h)*2; // 땅을 파야하는 경우
                    out_ground += input[i][j] - h;
                }
            }
        }
        if(in_ground<=out_ground+b && min >= sum){
            min = sum;
            h_index = h;
        }
    }
    printf("%d %d", min, h_index);
    return 0;
}
