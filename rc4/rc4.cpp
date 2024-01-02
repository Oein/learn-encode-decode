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

// 2byte
using Byte = unsigned short;

vector<Byte> rc4_key_from_string(string key)
{
    // 0, 1, 2, ..., 255
    vector<Byte> S(256);

    for (Byte i = 0; i < 256; i++)
        S[i] = i;

    // Key Scheduling Algorithm
    Byte j = 0;
    for (Byte i = 0; i < 256; i++)
    {
        j = (j + S[i] + key[i % key.size()]) % 256;

        swap(S[i], S[j]);
    }

    return S;
}

string rc4_encrypt(string plaintext, string key)
{
    // Key Scheduling Algorithm
    vector<Byte> S = rc4_key_from_string(key);

    // Pseudo Random Generation Algorithm

    unsigned long read_index = 0;

    Byte i = 0;
    Byte j = 0;

    string res = "";

    // plaintext가 끝날 때까지 반복한다
    while (read_index < plaintext.size())
    {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;

        swap(S[i], S[j]);

        Byte K = S[(S[i] + S[j]) % 256];

        res += (char)(plaintext[read_index] ^ K);

        read_index++;
    }

    return res;
}

// XOR을 사용하기 때문에 암호화와 복호화가 같다.
string rc4_decrypt(string ciphertext, string key)
{
    return rc4_encrypt(ciphertext, key);
}

string hexBase = "0123456789ABCDEF";
string encodeHex(string s)
{
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        res += hexBase[s[i] >> 4];
        res += hexBase[s[i] & 0b1111];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string key = "my awesome key";
    string plaintest = "hello world! this is my awesome rc4 algorithm!";
    string encrypted = rc4_encrypt(plaintest, key);
    cout << encodeHex(encrypted) << "\n";
    string decrypted = rc4_decrypt(encrypted, key);
    cout << decrypted;
    assert(plaintest == decrypted);
}