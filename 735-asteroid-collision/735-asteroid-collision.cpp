class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        s.reserve(asteroids.size());
        s.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(!s.empty()){
                if(asteroids[i]>0 || s.back()<0)
                    s.push_back(asteroids[i]);
                else{
                    bool f=false;
                    while(!s.empty()){
                        if(s.back()<0){f=true;break;}
                        else if(-asteroids[i]>s.back()){s.pop_back();f=true;}
                        else if(-asteroids[i]<s.back()) {f=false;break;}
                        else{s.pop_back();f=false;break;}
                    }
                    if(f) s.push_back(asteroids[i]);
                }
            } else
                s.push_back(asteroids[i]);
        }
        return s;
    }
};