/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int ans=0;
        for(int i=1;i<n;i++)
            if(!knows(i,ans)) ans=i;
        for(int i=0;i<n;i++)
            if(i==ans) continue;
            else if(!knows(i,ans)||knows(ans,i))
                return -1;
        return ans;
    }
};