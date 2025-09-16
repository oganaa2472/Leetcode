class Solution {
public:
    int steinGCD(int a, int b) {
    if (a == b) return a;
    if (a == 0) return b;
    if (b == 0) return a;

    // Both even
    if ((a & 1) == 0 && (b & 1) == 0)
        return steinGCD(a >> 1, b >> 1) << 1;

    // a even, b odd
    else if ((a & 1) == 0)
        return steinGCD(a >> 1, b);

    // a odd, b even
    else if ((b & 1) == 0)
        return steinGCD(a, b >> 1);

    // Both odd
    else if (a > b)
        return steinGCD((a - b) >> 1, b);
    else
        return steinGCD((b - a) >> 1, a);
}
    bool isReachable(int targetX, int targetY) {
        int g = steinGCD(targetX,targetY);
        return (g & (g - 1)) == 0;
    }
};