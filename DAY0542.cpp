// 836. Rectangle Overlap
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // tricky but try to start with pen paper and take 2 lines overlapping and extend that to rectangles
        return (rec1[0] < rec2[2] &&   // left edge of rec1 is left of right edge of rec2
                rec2[0] < rec1[2] &&   // right edge of rec1 is right of left edge of rec2
                rec1[1] < rec2[3] &&   // bottom edge of rec1 is below top edge of rec2
                rec2[1] < rec1[3]);    // top edge of rec1 is above bottom edge of rec2
    }
};
