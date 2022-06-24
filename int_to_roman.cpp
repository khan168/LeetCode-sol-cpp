
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// bool compare(string s1, string s2)
// {
//     return s1.size() < s2.size();
// }

int main()
{
    int num = 32;
    map<int, string> mapa = {{1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};
    string ans = "";
    while (num != 0)
    {
        auto c = mapa.rbegin();
        while (c != mapa.rend())
        {
            if (c->first <= num)
            {
                num -= c->first;
                ans += c->second;
                break;
            }
            c++;
        }
    }

    cout << ans;
}
