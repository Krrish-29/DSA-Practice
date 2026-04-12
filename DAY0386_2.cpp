// 3899. Angles of a Triangle
class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        const double PI=3.14159265358979323846;
        if(sides[0]+sides[1]<=sides[2]||sides[1]+sides[2]<=sides[0]||sides[0]+sides[2]<=sides[1]) return {};
        sort(sides.begin(),sides.end());
        int a=sides[0],b=sides[1],c=sides[2];
        double A=acos((b*b+c*c-a*a)/(2.0*b*c))*(180.0)/PI;
        double B=acos((a*a+c*c-b*b)/(2.0*a*c))*(180.0)/PI;
        double C=acos((b*b+a*a-c*c)/(2.0*b*a))*(180.0)/PI;
        return {A,B,C};
    }
};