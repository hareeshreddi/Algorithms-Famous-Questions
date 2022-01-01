class TicTacToe {
public:
    vector<int>r,c;
    int n1,d,rd;
    TicTacToe(int n) {
        r.resize(n,0);
        c.resize(n,0);
        d=0;
        rd=0;
    }
    
    int move(int row, int col, int player) {
        int cur;
        if(player==1) cur=1;
        else cur=-1;
        if(row==col) d+=cur;
        if(col+row+1==c.size()) rd+=cur;
        r[row]+=cur,c[col]+=cur;
        if(abs(r[row])==r.size() || abs(c[col])==r.size() || abs(d)==r.size() || abs(rd)==r.size())
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */