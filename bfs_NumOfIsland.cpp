#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    queue<pair<int, int>> q;
    int island = 0;
    vector<vector<string>> grid = {
        {"0", "1", "0"},
        {"1", "1", "1"},
        {"0", "1", "0"}};
    vector<pair<int, int>> poss = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (grid[r][c] == "1")
            {
                q.push(make_pair(r, c));
                grid[0][0] = "0";
                while (!q.empty())
                {
                    int size = q.size();
                    for (int i = 0; i < size; ++i)
                    {
                        pair<int, int> cur = q.front();
                        for (auto p : poss)
                        {
                            int newr = q.front().first + p.first;
                            int newc = q.front().second + p.second;
                            if (0 > newr || newc < 0 || newc >= grid[0].size() || newr >= grid.size())
                            {
                                continue;
                            }
                            pair<int, int> newcur = make_pair(newr, newc);
                            if (grid[newr][newc] == "1")
                            {
                                q.push(newcur);
                                grid[newr][newc] = "0";
                            }
                        }
                        q.pop();
                    }
                }
                island++;
            }
        }
    }
    cout << island;
}