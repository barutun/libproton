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
    ll n, m;
    std::vector<ll> k;
    std::cin >> n >> m;
    for (ll i = 0; i < n; ++i) {
        ll temp;
        std::cin >> temp;
        k.push_back(temp);
    }
    std::sort(k.begin(), k.end(), std::greater<ll>());
    return 0;
}