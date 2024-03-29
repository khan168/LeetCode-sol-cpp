#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//approach : sorting to get common key for each anagram and storing that key with a vector<string>.
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        if (strs.size() == 1)
        {
            return {{strs[0]}};
        }
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            m[s].push_back(strs[i]);
        }
        for (auto j : m)
        {
            ans.push_back(j.second);
        }
        cout << 1;
        return ans;
    }
};

//run time but works for 107/111 cases
class Solution
{
public:
    bool isAna(string s, string t)
    {
        vector<int> word1(26, 0);
        vector<int> word2(26, 0);
        for (auto i : s)
        {
            word1[i - 'a']++;
        }
        for (auto i : t)
        {
            word2[i - 'a']++;
        }
        return word1 == word2;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        set<int> s;
        vector<vector<string>> ans;
        vector<string> subans;
        for (int i = 0; i < strs.size(); i++)
        {
            if (s.count(i))
                continue;
            subans = {};
            subans.push_back(strs[i]);
            s.insert(i);
            for (int j = i + 1; j < strs.size(); j++)
            {
                if (!s.count(j) && isAna(strs[i], strs[j]))
                {
                    subans.push_back(strs[j]);
                    s.insert(j);
                }
            }
            ans.push_back(subans);
        }
        cout << 1;
        return ans;
    }
};
