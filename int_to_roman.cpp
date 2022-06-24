#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
public:
    string intToRoman(int num)
    {
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

        return ans;
    }
};

int main()
{
    Solution mysol = Solution();
    // testcase1:3 Expected Output III
    cout << mysol.intToRoman(3);
    // testcase1:58 Expected Output LVIII
    // testcase1:1994 Expected Output MCMXCIV
}
