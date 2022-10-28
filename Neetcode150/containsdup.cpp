class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) == s.end())
            {
                s.insert(nums[i]);
            }
            else
            {
                if (s.count(nums[i]))
                {
                    return true;
                }
                else
                {
                    s.insert(nums[i]);
                }
            }
        }
        return false;
    }
};