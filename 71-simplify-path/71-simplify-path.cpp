class Solution {
public:
    string simplifyPath(string path) {
        string ans="";
        deque<string>dq;
        string temp="";
        for(int i=0;i<=path.length();i++){
            //first condition required to handle special case /c & /c/..
            if(i!=path.length()&&path[i]!='/') temp.push_back(path[i]);   
            else{
                if(temp==""||temp=="."){}
                else if(temp==".."){
                    if(!dq.empty()) dq.pop_back();
                } else{
                    dq.push_back(temp);
                }
                temp="";
            }
        }
        while(!dq.empty()){
            ans.push_back('/');
            ans+=dq.front();
            dq.pop_front();
        }
        return ans.empty()?"/":ans;
    }
};