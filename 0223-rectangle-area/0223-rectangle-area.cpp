class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = abs(ax1-ax2)*abs(ay1-ay2);
        int area2 = abs(bx1-bx2)*abs(by1-by2);
        if((bx1 >= ax2) or (by1 >= ay2) or (ax1 >= bx2) or (ay1 >= by2))
            return area1 + area2;
        int comX1 = max(ax1, bx1), comY1 = max(ay1, by1);
        int comX2 = min(ax2, bx2), comY2 = min(ay2, by2);
        int comArea = abs(comX1 - comX2)*abs(comY1 - comY2);
        return area1 + area2 - comArea;
    }
};