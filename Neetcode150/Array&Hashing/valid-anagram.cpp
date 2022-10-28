#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//approach 1
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> word1(26, 0);
        vector<int> word2(26, 0);
        for (auto i : s)
        {
            word1[i - 'a']++;
        }
        for (auto i : t)
        {
            word2[i - 'a'] += 1;
        }
        return word1 == word2;
    }
};

//approach 2 -> Sorting
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
