class Solution {
public:
    string decodeString(string s) {
        string cur="",k="";
        stack<string>stk;
        for(int i=0;i<s.length();i++)
        {
            if(isdigit(s[i]))
                k+=s[i];
            else if(isalpha(s[i]))
                cur+=s[i];
            else if(s[i]=='['){
                stk.push(cur);
                stk.push(k);
                cur="",k="";
            } else{
                int num=stoi(stk.top());stk.pop();
                string prev=stk.top();stk.pop();
                string p=""; for(int i=0;i<num;i++) p+=cur;
                cur=prev+p;
            }
            // cout<<"cur::"<<cur<<"\n";
        }
        return cur;
    }
};