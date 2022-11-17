#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
567. Permutation in String
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Time Complexity-> O(n) + O(26)--> O(n)  
*/

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s2.size() < s1.size())
            return false;
        vector<int> v1(26, 0); 
        vector<int> v2(26, 0);
        for (int i = 0; i < s1.size(); i++)
        {
            v1[s1[i] - 'a']++;
            v2[s2[i] - 'a']++;
        }
        int m = 0;
        for (int i = 0; i < 26; i++)
        {
            if (v1[i] == v2[i])
                m++;
        }
        int i = 0;
        if (m == 26)
            return true;
        for (int j = s1.size(); j < s2.size(); j++)
        {
            int index = s2[j] - 'a';
            v2[index]++;
            if (v2[index] == v1[index])
                m++;
            else if (v2[index] == v1[index] + 1)
                m--;
            index = s2[i] - 'a';
            v2[index]--;
            if (v2[index] == v1[index])
                m++;
            else if (v2[index] + 1 == v1[index])
                m--;
            i++;
            if (m == 26)
                return true;
        }
        return false;
    }
};

int main()
{
    string s1 = "fe";
    string s2 = "abdef";
    Solution s = Solution();
    cout << s.checkInclusion(s1,s2);
    // expected ans: 1
    return 0;
}