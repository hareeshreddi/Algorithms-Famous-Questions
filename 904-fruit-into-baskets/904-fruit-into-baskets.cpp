class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>counter;
        int ans=1;
        for(int j=0,i=0;j<fruits.size();j++){
            counter[fruits[j]]++;
            while(counter.size()>2){
                counter[fruits[i]]--;
                if(!counter[fruits[i]]) counter.erase(fruits[i]);
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};