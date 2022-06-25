#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    string intToRoman(int num) {
        map<int,string> mapa={{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
        string ans="";
        auto it = mapa.rbegin();
        while(it!=mapa.rend()){
            int t= num/(it->first);
            if(t>0){
               while(t--){
                ans+=it->second;
                
                } 
                num=num%it->first;
            }
            
            
            it++;
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
