class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> hsh;
        hsh[1000] = "M";
        hsh[900] = "CM";
        hsh[500] = "D";
        hsh[400] = "CD";
        hsh[100] = "C";
        hsh[90] = "XC";
        hsh[50] = "L";
        hsh[40] = "XL";
        hsh[10] = "X";
        hsh[9] = "IX";
        hsh[5] = "V";
        hsh[4] = "IV";
        hsh[1] = "I";

        int d[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ret = "";
        for (int i=0; i<13; ++i) {
            while (num - d[i] >= 0) {
                num -= d[i];
                ret += hsh[d[i]]; 
            }
        }
        return ret;
    }
};
