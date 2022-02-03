class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(const auto &i:tasks) ++freq[i-'A'];
        sort(freq.begin(),freq.end());
        int f_max=freq[25]-1,idle_time=f_max*n;
        for(int i=24;i>=0&&freq[i]&&idle_time>0;--i){
            idle_time-=min(freq[i],f_max);
        }
        idle_time=max(0,idle_time);
        return tasks.size()+idle_time;
    }
};