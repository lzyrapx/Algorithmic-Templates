using i128 = __int128_t;
void print(i128 x) {
    if (x == 0) {
        cout << 0 << "\n";
        return;
    }
    string s;
    while (x > 0) {
        s += (char)('0' + (int)(x % 10));
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}