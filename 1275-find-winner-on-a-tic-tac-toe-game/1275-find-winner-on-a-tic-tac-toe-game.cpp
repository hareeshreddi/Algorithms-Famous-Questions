class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int c=moves.size();
        int rows[3]={0},cols[3]={0},d1=0,d2=0;
        bool b=true;
        for(const vector<int> &v:moves){
            if(b){
                rows[v[0]]++;
                cols[v[1]]++;
                if(v[0]==v[1]) d1++;
                if(v[0]+v[1]==2) d2++;
            } else{
                rows[v[0]]--;
                cols[v[1]]--;
                if(v[0]==v[1]) d1--;
                if(v[0]+v[1]==2) d2--;   
            }
            b=!b;
        }
        for(int i=0;i<3;i++){
            if(d1==3||d2==3) return "A";
            else if(d1==-3||d2==-3) return "B";
            if(rows[i]==3||cols[i]==3) return "A";
            else if(rows[i]==-3||cols[i]==-3) return "B";
        }
        return c==9?"Draw":"Pending";
    }
};