class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>s;
        s.reserve(asteroids.size());
        s.push_back(asteroids[0]);
        for(int i=1;i<asteroids.size();i++){
            if(s.empty() || asteroids[i]>0 || s.back()<0)
                s.push_back(asteroids[i]);
            else{
                //keep popping +ve ele's which are less than -asteroids[i]
                while(!s.empty()&&s.back()>0&&-asteroids[i]>s.back()) s.pop_back();
                if(s.empty()||s.back()<0) s.push_back(asteroids[i]);
                else if(asteroids[i]+s.back()==0) s.pop_back();
            }
        }
        return s;
    }
};