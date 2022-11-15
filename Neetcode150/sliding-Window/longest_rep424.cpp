#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.\

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.
*/

//Time complexity O(N*26)--> 26 for the search through the map which in worst case is all 26 characters.
//More optimized solution is O(N) -->Not expected in interview(Neetcode)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int i = 0, j = 0;
        int maxi = 1, ans = 0;
        map<char, int> m;
        for (int j = 0; j < n; j++)
        {
            int maxi = 0;
            m[s[j] - 'A']++;
            for (auto e : m)
            {
                maxi = max(e.second, maxi);
            }
            while ((j - i + 1) - maxi > k)
            {
                m[s[i] - 'A']--;
                i++;
                for (auto e : m)
                {
                    maxi = max(e.second, maxi);
                }
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};

int main(){
    string test_string = "ABABBBA";
    int test_k=1;
    Solution s = Solution();
    cout<<s.characterReplacement(test_string,test_k);
    //expected ans: 5
    return 0;
}