typedef long long ll;

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