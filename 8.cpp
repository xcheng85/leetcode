class Solution {
public:
    int myAtoi(string str) {
    int sign = 1, base = 0, i = 0;
    while (str[i] == ' ') { i++; }
    if (str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i] == '-'); 
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {

// 2147483648 is INT_MAX
// INT_MAX / 10 = 214748364 + 7 max 

        if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            if (sign == 1) return INT_MAX;
            else return INT_MIN;
        }
        base  = 10 * base + (str[i++] - '0');
    }
    return base * sign;
    }
};