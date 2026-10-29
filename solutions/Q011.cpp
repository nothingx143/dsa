#include <iostream>
#include <algorithm>
using namespace std;

#define MOD 1000000007
long long fact[200005], invFact[200005];

#define NCR(n, r) (r < 0 || r > n ? 0LL : fact[n] * invFact[r] % MOD * invFact[n - r] % MOD)

#define PWR(b, e, res) { \
    long long _b = b, _e = e; res = 1; \
    while (_e) { \
        if (_e & 1) res = (res * _b) % MOD; \
        _b = (_b * _b) % MOD; \
        _e >>= 1; \
    } \
}

#define SOLVE { \
    long long n, l, r; cin >> n >> l >> r; \
    long long k = min(r - n, 1LL - l); \
    long long ans = (k % MOD) * (n % 2 == 0 ? NCR(n, n / 2) : (2 * NCR(n, n / 2)) % MOD) % MOD; \
    long long ck = k + 1; \
    while (1) { \
        long long cp = max(0LL, min(n, l + ck - 1)); \
        long long cm = max(0LL, n - max(0LL, r - ck)); \
        if (cp + cm > n) break; \
        long long rem = n - cp - cm; \
        if (n % 2 == 0) { \
            long long req = n / 2 - cp; \
            if (req < 0 || req > rem) break; \
            ans = (ans + NCR(rem, req)) % MOD; \
        } else { \
            long long w = 0, q1 = n / 2 - cp, q2 = (n + 1) / 2 - cp; \
            if (q1 >= 0 && q1 <= rem) w = (w + NCR(rem, q1)) % MOD; \
            if (q2 >= 0 && q2 <= rem) w = (w + NCR(rem, q2)) % MOD; \
            if (!w) break; \
            ans = (ans + w) % MOD; \
        } \
        ck++; \
    } \
    cout << ans << "\n"; \
}

void prep_fact() {
    int N = 200000, i;
    fact[0] = 1;
    for(i = 1;i <= N;i++) fact[i] = fact[i - 1] * i % MOD;
}

void prep_inv() {
    int N = 200000, j = N;
    long long invN;
    PWR(fact[N], MOD - 2, invN);
    invFact[N] = invN;
    while (j > 0) {
        invFact[j - 1] = invFact[j] * j % MOD;
        j--;
    }
}

int main() {
    prep_fact();
    prep_inv();
    int t;
    cin >> t;
    while(t--) SOLVE
    return 0;
}
