class Solution {
public:
    bool isSquareNum(int num) {
        int s = (int) sqrt(num);
        return s * s == num;
    }
    int numSquares(int n) 
    {
        /*
            If n is a perfect square, the answer is 1. 
            If n can be written as the sum of two squares, the answer is 2. 
            If n is of the form 4^k(8m+7), the answer is 4. 
            Otherwise, the answer is 3.
        */
        if (isSquareNum(n)) {
            return 1;
        }

        for (int i = 1; i * i <= n; i++) {
            if (isSquareNum(n - i * i)) {
                return 2;
            }
        }
        while (n % 4 == 0) {
            n /= 4;
        }

        if (n % 8 == 7) {
            return 4;
        }


        return 3;

        
    }
};