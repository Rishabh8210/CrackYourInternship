class Solution {
public:
    string intToRoman(int num) {
        string singleDig[] = {"",  "I",  "II",  "III",  "IV",
                              "V", "VI", "VII", "VIII", "IX"};
        string doubleDig[] = {"",  "X",  "XX",  "XXX",  "XL",
                              "L", "LX", "LXX", "LXXX", "XC"};
        string trippleDig[] = {"",  "C",  "CC",  "CCC", "CD",
                               "D", "DC", "DCC", "DCCC", "CM"};
        string fourthDig[] = {"", "M", "MM", "MMM"};

        return fourthDig[num/1000] + trippleDig[(num%1000)/100] + doubleDig[(num%100)/10] + singleDig[num%10];
    }
};