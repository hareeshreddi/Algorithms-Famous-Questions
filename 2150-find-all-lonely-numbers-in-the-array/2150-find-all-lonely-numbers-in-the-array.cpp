class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int>s;
        for(const auto &p:nums) s[p]++;
        vector<int>ans;
        for(const auto &p:nums)
            if(s.find(p)!=s.end() && s[p]==1 && s.find(p-1)==s.end() && s.find(p+1)==s.end())
                ans.push_back(p);
        return ans;
    }
};