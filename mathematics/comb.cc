/**
 * 快速幂
 * @return b^e % mod
 * O(log e)
 */
ll pow_mod(ll b, ll e, int mod = 998244353) {
    ll r = 1;
    b %= mod;
    while (e) {
        if (e & 1) r = r * b % mod;
        b = b * b % mod;
        e >>= 1;
    }
    return r;
}

vector<int> fac, invfac;

void init(int n) {
    if ((int)fac.size() > n) return;
    fac.resize(n + 1);
    invfac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
    invfac[n] = pow_mod(fac[n], mod - 2);
    for (int i = n - 1; i >= 0; i--) {
        invfac[i] = 1LL * invfac[i + 1] * (i + 1) % mod;
    }
}

// C(n, r)
ll C(int n, int r) {
    if (r < 0 || r > n) return 0;
    return 1LL * fac[n] * invfac[r] % mod * invfac[n - r] % mod;
}
