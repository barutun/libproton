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
ll binary_search(const T& binary_key, const std::vector<T>& binary_vec)
{
    //libproton 1.0.0
    //鍵値とvectorを入力されたら鍵値より大きいか等しいギリギリのindexをlong longで返す
    //もし反対が良ければbinary_search_rev()を使ってください
    //vectorは必ず昇順でsortしてから入力すること,Tには鍵値,vectorの型名を代入
    //binary_search<ll>(binary_key,binary_vec);
    ll bin_ng = -1;
    ll bin_ok = (ll)binary_vec.size();
    while (std::abs(bin_ok - bin_ng) > 1) {
        ll bin_mid = (bin_ok + bin_ng) / 2;
        if (binary_vec[bin_mid] >= binary_key)
            bin_ok = bin_mid;
        else
            bin_ng = bin_mid;
    }
    return bin_ok;
}

template <class T>
ll binary_search_rev(const T& binary_key, const std::vector<T>& binary_vec)
{
    //libproton 1.0.0
    //鍵値とvectorを入力されたら鍵値より小さいかと等しいギリギリのindexをlong longで返す
    //もし反対が良ければbinary_search()を使ってください
    //vectorは必ず昇順でsortしてから入力すること,Tには鍵値,vectorの型名を代入
    //binary_search_rev<ll>(binary_key,binary_vec);
    ll bin_ok = -1;
    ll bin_ng = (ll)binary_vec.size();
    while (std::abs(bin_ok - bin_ng) > 1) {
        ll bin_mid = (bin_ok + bin_ng) / 2;
        if (binary_vec[bin_mid] <= binary_key)
            bin_ok = bin_mid;
        else
            bin_ng = bin_mid;
    }
    return bin_ok;
}


int main()
{
    ll n, m;
    std::vector<ll> k;
    std::cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        ll temp;
        std::cin >> temp;
        k.push_back(temp);
    }
    std::sort(k.begin(), k.end());
    Say(binary_search<ll>(m, k));
    Say(binary_search_rev<ll>(m, k));
    return 0;
}