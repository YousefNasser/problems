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
#define sz 1000005

int t, n;
int arr[sz], back[sz], front[sz];

int main() {

    /*
     * Link: https://codeforces.com/gym/101532/problem/G
     *
     * A Magical Index is an index which is bigger than every
     * number before it and smaller than every number after it.
     *
     * So the idea is to keep track of what is the biggest number
     * leading to every index, and what is the smallest number
     * after every index till the end of the array.
     */

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        back[1] = arr[1];
        front[n] = arr[n];

        for (int i = 2; i <= n; i++) {
            if (arr[i] > back[i - 1])
                back[i] = arr[i];
            else
                back[i] = back[i - 1];
        }

        for (int i = n - 1; i != 0; i--) {
            if (arr[i] < front[i + 1])
                front[i] = arr[i];
            else
                front[i] = front[i + 1];
        }

        int ans = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] >= back[i - 1]) {
                if (arr[i] <= front[i + 1])
                    ans++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}

