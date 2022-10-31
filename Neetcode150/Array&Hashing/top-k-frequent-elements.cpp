#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//function to sort the pairs according to second value in descending order
struct less_than_key
{
    inline bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return (p1.second > p2.second);
    }
};

/*
Through counting using map make pair of vector and sort pair according to second value in descending order
*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        vector<pair<int, int>> v;
        vector<int> ans;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        for (auto i : m)
        {
            v.push_back(make_pair(i.first, i.second));
        }
        sort(v.begin(), v.end(), less_than_key());
        for (auto i : v)
        {
            if (ans.size() < k)
                ans.push_back(i.first);
        }
        return ans;
    }
};

//approach 2:
//using max heap 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        vector<int> ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:m){ pq.push({i.second,i.first});}
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
