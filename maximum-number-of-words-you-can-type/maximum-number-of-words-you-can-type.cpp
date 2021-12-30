class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int b[26]={0},ans=0;
        for(auto s:brokenLetters) b[s-'a']++;
        for(int i=0;i<text.size();i++)
        {
            bool r=true;
            while(i<text.size() && text[i]!=' '){
                if(r&& b[text[i]-'a']>0) r=false;
                i++;
            }
            if(r) ++ans;
        }
        return ans;
    }
};