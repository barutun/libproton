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

std::vector<bool> graph_seen(100, false);  //100には頂点数を入れる。下のdfsは再帰なので外で定義する必要あり。

void dfs_mono(const Graph& dfs_G, const ll& start_point, std::vector<bool>& dfs_seen)
{
    dfs_seen[start_point] = true;             // start_point を訪問済にする
    for (auto next_v : dfs_G[start_point]) {  // start_point から行ける各頂点 next_v について
        if (dfs_seen[next_v])
            continue;                       // next_v が探索済だったらスルー
        dfs_mono(dfs_G, next_v, dfs_seen);  // 再帰的に探索
    }
}

int main()
{
    return 0;
}
//libproton 1.1.0 make_graph
//num_pointsは頂点数,num_sidesは辺数,side_pairsはvector::vector<ll>に相当するものを入力してください。
//ただし二つ目のvectorは二つの要素しかないことを想定している
//グラフ型(G[index]に頂点indexから直接行ける点の列挙が入っている)を返す
//graphのiteratorが1次元の時しか対応していない

//libproton 1.1.0 dfs_mono
//graphのiteratorが1次元の時しか対応していない
//dfs_GにはGraph型を, start_pointには探索開始点を, dfs_seenには頂点数の大きさを持った配列を入れてください。
//返す値はない。dfs_seenが訪問済みでtrueに切り替わっているはず。やりたい動作は使用時に関数中に追記してください。