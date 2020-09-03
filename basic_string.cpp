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
    std::string n;
    std::cin >> n;
    std::vector<char> c;
    for (auto v : n) {
        c.push_back(v);
    }
    for (auto v : c) {
        Say(v);
    }
    return 0;
}