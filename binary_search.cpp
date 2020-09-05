#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define Yes() std::cout << "Yes" << std::endl
#define No() std::cout << "No" << std::endl
#define Say(s) std::cout << s << std::endl
const ll MOD = 1000000007;
const ll INF = 1061109567;

int main()
{
    auto binary_search = [&](const auto& binary_key, const auto& binary_vec) {
        ll bin_ok = (ll)binary_vec.size();
        ll bin_ng = -1;
        while (std::abs(bin_ok - bin_ng) > 1) {
            ll bin_mid = (bin_ok + bin_ng) / 2;
            if (binary_vec[bin_mid] >= binary_key)
                bin_ok = bin_mid;
            else
                bin_ng = bin_mid;
        }
        if (bin_ok == (ll)binary_vec.size())
            --bin_ok;
        return bin_ok;
    };

    auto binary_search_rev = [&](const auto& binary_key, const auto& binary_vec) {
        ll bin_ok = -1;
        ll bin_ng = (ll)binary_vec.size();
        while (std::abs(bin_ok - bin_ng) > 1) {
            ll bin_mid = (bin_ok + bin_ng) / 2;
            if (binary_vec[bin_mid] <= binary_key)
                bin_ok = bin_mid;
            else
                bin_ng = bin_mid;
        }
        if (bin_ok == -1)
            ++bin_ok;
        return bin_ok;
    };
    return 0;
}
//libproton 1.1.0 binary_search()
//鍵値とvectorを入力されたら鍵値より大きいか等しいギリギリのindexをlong longで返す
//もし反対が良ければbinary_search_rev()を使ってください
//binary_vecは必ず昇順でsortして,型をbinary_keyに合わせたstd::vectorかstd::arrayで入力すること,
//binary_search(binary_key,binary_vec);
//全部鍵値を下回るとsize()が出力されてstd::out_of_rangeするのでこの場合size()-1を出力します

//libproton 1.1.0 binary_search_rev()
//鍵値とvectorを入力されたら鍵値より大きいか等しいギリギリのindexをlong longで返す
//もし反対が良ければbinary_search()を使ってください
//binary_vecは必ず昇順でsortして,型をbinary_keyに合わせたstd::vectorかstd::arrayで入力すること,
//binary_search_rev(binary_key,binary_vec);
//全部鍵値を上回ると-1が出力されてstd::out_of_rangeするのでこの場合0を出力します

/*
https://qiita.com/drken/items/97e37dd6143e33a64c8c
を参考にしただけです
*/