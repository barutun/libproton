#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes() std::cout << "Yes" << std::endl
#define No() std::cout << "No" << std::endl
#define Say(s) std::cout << s << std::endl
const ll MOD = 1000000007;
const ll INF = 1061109567;

template <class T>
using Grid = std::vector<std::vector<T>>;
void dfs_grid(const ll& start_tate, const ll& start_yoko, Grid<char>& grid_char, Grid<bool>& grid_seen)
{
    grid_seen[start_tate][start_yoko] = true;
    //grid_char[start_tate][start_yoko] = '#';  //'.'を虱潰しにしたい時に使う
    for (ll dx = -1; dx <= 1; ++dx) {
        for (ll dy = -1; dy <= 1; ++dy) {
            if (0 <= start_tate + dx && start_tate + dx < grid_seen.size() && 0 <= start_yoko + dy && start_yoko + dy < grid_seen[0].size()) {
                if (grid_seen[start_tate + dx][start_yoko + dy] == false && grid_char[start_tate + dx][start_yoko + dy] == '.') {
                    dfs_grid(start_tate + dx, start_yoko + dy, grid_char, grid_seen);
                }
            }
        }
    }
}
// libproton 1.1.2 dfs_grid
// dfsのgrid版。開始点を入力して再帰的にする。外部で用意したbool_grid_seenに訪問を記録(必要に応じて改変すべし)
// 判定or改変用にgrid_charがあり。'.'を探索する。このdfsをrepで全点に回すなどの使い道が考えられる
//以下実装例

int main()
{
    ll n, m;
    std::cin >> n >> m;
    Grid<char> S(n);
    for (ll i = 0; i < n; ++i) {  //N
        std::string temp;
        std::cin >> temp;
        for (auto c : temp) {  //M
            S[i].push_back(c);
        }
    }
    Grid<bool> seen(n, std::vector<bool>(m, false));
    dfs_grid(2, 1, S, seen);  //
    for (auto v : S) {        //N
        std::string temp;
        for (auto c : v) {  //M
            temp.push_back(c);
        }
        std::cout << temp << std::endl;
    }

    return 0;
}