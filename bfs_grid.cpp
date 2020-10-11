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
void bfs_grid(const ll& start_tate, const ll& start_yoko, Grid<char>& grid_char, Grid<ll>& grid_rabel)
{
    std::queue<std::array<ll, 2>> bfs_queue;
    grid_rabel[start_tate][start_yoko] = 0;
    //grid_char[start_tate][start_yoko] = '#';  //'.'を虱潰しにしたい時に使う
    bfs_queue.push({start_tate, start_yoko});
    while (!bfs_queue.empty()) {
        std::array<ll, 2> temp_array = bfs_queue.front();
        bfs_queue.pop();
        for (ll dx = -1; dx <= 1; ++dx) {
            for (ll dy = -1; dy <= 1; ++dy) {
                if (0 <= temp_array[0] + dx && temp_array[0] + dx < grid_rabel.size() && 0 <= temp_array[1] + dy && temp_array[1] + dy < grid_rabel[0].size()) {
                    if (grid_rabel[temp_array[0] + dx][temp_array[1] + dy] != -1 && grid_char[temp_array[0] + dx][temp_array[1] + dy] == '.') {
                        grid_rabel[temp_array[0] + dx][temp_array[1] + dy] = grid_rabel[temp_array[0]][temp_array[1]] + 1;
                        bfs_queue.push({temp_array[0] + dx, temp_array[1] + dy});
                    }
                }
            }
        }
    }
}
// libproton 1.1.3 bfs_grid
// bfsのgrid版。開始点を入力してqueueする。外部で用意したgrid_rabelに開始点を記録(必要に応じて改変すべし)
// 判定or改変用にgrid_charがあり。'.'を探索する。
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
    Grid<ll> rabel(n, std::vector<ll>(m, -1));
    bfs_grid(2, 1, S, rabel);  //
    for (auto v : S) {         //N
        std::string temp;
        for (auto c : v) {  //M
            temp.push_back(c);
        }
        std::cout << temp << std::endl;
    }

    return 0;
}