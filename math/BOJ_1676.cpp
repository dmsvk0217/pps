#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int a=0, b=0, c=0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        int num = i;

        while(num%10 == 0){
            num /= 10;
            a++;
        }
        while(num%5 == 0){
            num /= 5;
            b++;
        }
        while(num%2 == 0){
            num /= 2;
            c++;
        }
    }
    count = a + min(b, c);
    cout << count << "\n";
}
