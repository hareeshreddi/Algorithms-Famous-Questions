class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7,ans=0,k=arr.size();
        stack<int>s1,s2;
        vector<int>left(k),right(k);//count of strictly greater eles on left, non strict greater ele on right (use PLE & NLE Indexes respectively)
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
        for(int i=0;i<k;i++){
            // cout<<left[i]<<" and "<<right[i]<<"\n";
            const int r = (long)(left[i]*right[i])*arr[i]%mod;
            ans=(ans+r)%mod;
        }
        return ans;
    }
};
//[1,5,6,5,4]
//left ==> [1,1,1,2,4]
//right ==> [5,3,1,1,1]