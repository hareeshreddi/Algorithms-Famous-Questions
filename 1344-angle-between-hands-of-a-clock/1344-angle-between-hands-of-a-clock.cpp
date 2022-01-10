class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans=0.0;
        ans+=(hour%12)*30+((double)minutes/60)*30;
        ans-=(minutes*6); 
        if(ans<0) ans=-ans;
        if(ans>180) ans=360-ans;
        return ans;
    }
};