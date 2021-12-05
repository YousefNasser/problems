#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
#define DrSlidez ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
#define Files freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define pi 3.14159265
#define mod 1000000007
#define pb push_back
#define INF LONG_LONG_MAX
#define sz 1000000000


int main() {
    DrSlidez

    /*
     * Link: https://codeforces.com/contest/1594/problem/B
     *
     * Let's assume that N = 3
     *   Special Number    | K -> K(base 2)
     *     0     -> 1      | 1 -> 0001
     *     1     -> 3      | 2 -> 0010
     *     0 + 1 -> 4      | 3 -> 0011
     *     2     -> 9      | 4 -> 0100
     *     0 + 2 -> 10     | 5 -> 0101
     *
     * So the pattern is no matter what N equals
     * the Kth number binary representation still
     * holds the exact same sequence to the special
     * number intended, so all what we need to do
     * is to convert K to its binary representation
     * and sum the powers of N to the 1 bits.
     */

    ll t, n, k, pw, ans; cin >> t;
    while (t--) {
        cin >> n >> k;
        pw = 1, ans = 0;

        // iterating from 0 till 30 as the problem limit is 10e9
        for (int i = 0; i < 31; i++) {

            /* instead of converting to binary, checking bit by it
              * by shifting 1 to the left i times then &ing it with K */
            if (k & (1 << i)) {
                ans = (ans + pw) % mod;
            }

            /* Increasing the power by 1, then Modding it to avoid overflow */
            pw *= n;
            pw %= mod;
        }
        cout << ans << '\n';
    }

    return 0;
}