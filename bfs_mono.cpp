#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes() std::cout << "Yes" << std::endl
#define No() std::cout << "No" << std::endl
#define Say(s) std::cout << s << std::endl
const ll MOD = 1000000007;
const ll INF = 1061109567;
// 頂点のindexが1変数で表せるグラフなら使えます
using Graph = std::vector<std::vector<ll>>;
Graph make_graph(const ll& num_points, const ll& num_sides, const std::vector<std::vector<ll>>& side_pairs)
{
    Graph G(num_points);
    for (ll i = 0; i < num_sides; ++i) {
        G[side_pairs.at(i).at(0)].push_back(side_pairs.at(i).at(1));
        //G[side_pairs.at(i).at(1)].push_back(side_pairs.at(i).at(0)); //無向グラフ
    }
    return G;
}

std::vector<ll> graph_rabel(100, -1);  //100には頂点数を入れる。下のdfsは再帰なので外で定義する必要あり。
std::queue<ll> graph_queue;

void bfs_mono(const Graph& bfs_G, const ll& start_point, std::vector<ll>& bfs_rabel)
{
    std::queue<ll> bfs_queue;
    bfs_rabel[start_point] = 0;
    bfs_queue.push(start_point);
    while (!bfs_queue.empty()) {
        ll bfs_v = bfs_queue.front();  // キューから先頭頂点を取り出す
        bfs_queue.pop();

        // v から辿れる頂点をすべて調べる
        for (ll bfs_nv : bfs_G[bfs_v]) {
            if (bfs_rabel[bfs_nv] != -1)
                continue;  // すでに発見済みの頂点は探索しない

            // 新たな白色頂点 nv について距離情報を更新してキューに追加する
            bfs_rabel[bfs_nv] = bfs_rabel[bfs_v] + 1;
            bfs_queue.push(bfs_nv);
        }
    }
}

int main()
{
    ll n, m;
    std::cin >> n >> m;
    std::vector<std::vector<ll>> pair;
    for (ll i = 0; i < m; ++i) {
        std::vector<ll> temp_v;
        ll temp_1, temp_2;
        std::cin >> temp_1 >> temp_2;
        temp_v.push_back(temp_1);
        temp_v.push_back(temp_2);
        pair.push_back(temp_v);
    }
    Graph G = make_graph(n, m, pair);
    std::vector<ll> t_graph_rabel(n, -1);  //100には頂点数を入れる。下のdfsは再帰なので外で定義する必要あり。
    bfs_mono(G, 0, t_graph_rabel);
    for (int v = 0; v < n; ++v)
        std::cout << v << ": " << t_graph_rabel[v] << std::endl;
    return 0;
}
//libproton 1.1.0 make_graph
//num_pointsは頂点数,num_sidesは辺数,side_pairsはvector::vector<ll>に相当するものを入力してください。
//ただし二つ目のvectorは二つの要素しかないことを想定している
//グラフ型(G[index]に頂点indexから直接行ける点の列挙が入っている)を返す
//graphのiteratorが1次元の時しか対応していない

//libproton 1.1.3 bfs_mono
//graphのiteratorが1次元の時しか対応していない
//bfs_GにはGraph型を, start_pointには探索開始点を, dfs_rabrlには頂点数の大きさを持った配列を入れてください。
//返す値はない。bfs_rabelが訪問済みでstart_pointからの手数に切り替わっているはず。やりたい動作は使用時に関数中に追記してください。