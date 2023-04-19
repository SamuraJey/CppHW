#include <iostream>
#include <cstring>

using namespace std;

int cache[31][31];

int count_palindromes(string& s, int start, int end) {
    if (start > end) return 1;
    if (cache[start][end] != -1) return cache[start][end];

    int count = 0;
    if (s[start] == s[end]) {
        count += count_palindromes(s, start+1, end-1);
    }
    count += count_palindromes(s, start+1, end);
    count += count_palindromes(s, start, end-1);
    count -= count_palindromes(s, start+1, end-1);

    cache[start][end] = count;
    return count;
}

int main() {
    string s;
    cin >> s;

    memset(cache, -1, sizeof(cache));

    int count = count_palindromes(s, 0, s.length()-1);
    cout << count - 1 << endl;

    return 0;
}
