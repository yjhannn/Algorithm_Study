#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
typedef long long ll;
ll n, atk, t, a, h, ans, ret;

int main() {
    cin >> n >> atk;
    vector<tuple<ll, ll, ll>> rooms(n);

    for (int i = 0; i < n; i++) {
        cin >> t >> a >> h;
        rooms[i] = {t, a, h};
    }

    ll left = 1, right = 1e18, ans = right;

    while (left <= right) {
        ll mid = (left + right) / 2;
        ll cur_hp = mid;
        ll cur_atk = atk;
        bool dead = false;

        for (int i = 0; i < n; i++) {
            ll t, a, h;
            tie(t, a, h) = rooms[i];

            if (t == 1) {
                // 몬스터
                ll turns_to_kill = (h + cur_atk - 1) / cur_atk;
                ll turns_to_die = turns_to_kill - 1;
                cur_hp -= a * turns_to_die;
                if (cur_hp <= 0) {
                    dead = true;
                    break;
                }
            } else {
                // 포션
                cur_atk += a;
                cur_hp = min(mid, cur_hp + h);
            }
        }

        if (dead) left = mid + 1;
        else {
            ans = mid;
            right = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}