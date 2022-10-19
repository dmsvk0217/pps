#include <iostream>
#include <vector>

using namespace std;

vector<int> target;
int target_i = 0;
vector<char> res;
vector<int> st;
int st_i = 1;
int n;

void input()
{
    cin >> n;
    for (int a, i = 0; i < n; i++)
    {
        scanf("%d", &a);
        target.push_back(a);
    }
}

void solve()
{
    while (target_i != n)
    {
        if (st.empty())
        {
            st.push_back(st_i);
            res.push_back('+');
            st_i++;
        }

        if (target[target_i] > st.back())
        {
            st.push_back(st_i);
            st_i++;
            res.push_back('+');
        }
        else if (target[target_i] == st.back())
        {
            st.pop_back();
            target_i++;
            res.push_back('-');
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        printf("%c\n", res[i]);
    }
}

int main()
{
    input();
    solve();
    return 0;
}
