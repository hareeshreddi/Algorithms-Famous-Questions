class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int k=arr.size(),ans=arr[0];
        stack<int>s1,s2;
        vector<int>left(k),right(k);//count of strict greater eles on left, non strict greater ele on right (use PLE & NLE Indexes respectively)
        for(int i=0;i<k;i++){//PLE Index 
            while(!s1.empty() && arr[s1.top()]>arr[i]) s1.pop();
            left[i]=s1.empty()?i+1:i-s1.top();
            s1.push(i);
        }
        for(int i=0;i<k;i++){//NLE Index
            while(!s2.empty() && arr[s2.top()]>arr[i]){
                const int k1=s2.top();s2.pop();
                right[k1]=i-k1;
            }
            s2.push(i);
        }
        while(!s2.empty()){
            right[s2.top()]=k-s2.top();s2.pop();
        }
        
        for(int i=0;i<k;i++) ans=max(ans,arr[i]*(right[i]+left[i]-1));
        return ans;
    }
};