#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <math.h>
#include <numeric>
#include <cassert>
#include <stack>
#include <cstring>
#include <climits>

typedef long long ll;
typedef unsigned long ull;

#define interface struct
#define zx3f 1061109567

typedef signed char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

struct Pos
{
    int x;
    int y;
};

string base64chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

string encode_base64(string s)
{
    string res;
    int i = 0;
    int j = 0;
    while (i < s.size())
    {
        int a = s[i++],
            b = s[i++],
            c = s[i++];

        // 00000000 00000000 00000000
        res += base64chars[a >> 2];                         // 앞에서 6비트
        res += base64chars[((a & 0b11) << 4) | (b >> 4)];   // 2비트 + 4비트
        res += base64chars[((b & 0b1111) << 2) | (c >> 6)]; // 4비트 + 2비트
        res += base64chars[c & 0b111111];                   // 뒤에서 6비트
    }
    if (s.size() % 3 == 2)
    {
        res[res.length() - 1] = '=';
    }
    else if (s.size() % 3 == 1)
    {
        res[res.length() - 1] = '=';
        res[res.length() - 2] = '=';
    }
    return res;
}

string decode_base64(string s)
{
    string res;
    int i = 0;
    int j = 0;
    while (i < s.size())
    {
        int a = base64chars.find(s[i++]),
            b = base64chars.find(s[i++]),
            c = base64chars.find(s[i++]),
            d = base64chars.find(s[i++]);

        // 00000000 00000000 00000000
        res += (a << 2) | (b >> 4);            // 6비트 + 2비트
        res += ((b & 0b1111) << 4) | (c >> 2); // 4비트 + 4비트
        res += ((c & 0b11) << 6) | (d);        // 2비트 + 6비트
    }
    if (s[s.size() - 1] == '=') // padding
    {
        res.pop_back();
    }
    if (s[s.size() - 2] == '=') // padding
    {
        res.pop_back();
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    string res = encode_base64(s);
    cout << res << endl;
    cout << decode_base64(res) << endl;
}