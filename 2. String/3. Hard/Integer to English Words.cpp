class Solution {
public:
    string numberToWords(int num) {
        if(num == 0) return "Zero";
        stack<string> st;
        unordered_map<int, string> ump = {
            {1, "One"},           {2, "Two"},
            {3, "Three"},         {4, "Four"},
            {5, "Five"},          {6, "Six"},
            {7, "Seven"},         {8, "Eight"},
            {9, "Nine"},          {10, "Ten"},
            {11, "Eleven"},       {12, "Twelve"},
            {13, "Thirteen"},     {14, "Fourteen"},
            {15, "Fifteen"},      {16, "Sixteen"},
            {17, "Seventeen"},    {18, "Eighteen"},
            {19, "Nineteen"},     {20, "Twenty"},
            {30, "Thirty"},       {40, "Forty"},
            {50, "Fifty"},        {60, "Sixty"},
            {70, "Seventy"},      {80, "Eighty"},
            {90, "Ninety"},        {100, "Hundred"},
            {1000, "Thousand"},   {100000, "Lakh"},
            {1000000, "Million"}, {100000000, "Billion"}};

        long long sum = 0;
        int i = 1;
        int thousand = 0, million = 0, once = 0;



        while (num != 0) {
            int rem = num % 10;
            if (i == 1) {
                once = rem;
                st.push(ump[rem]);
            } else if (i == 2) {
                int temp = rem * 10 + once;
                if (temp >= 11 && temp < 20) {
                    st.pop();
                    st.push(ump[temp]);
                } else {
                    int temp = rem * 10;
                    st.push(ump[temp]);
                }
            } else if (i == 3) {
                if (rem != 0) {
                    st.push("Hundred");
                    st.push(ump[rem]);
                }
            } else if (i == 4) {
                
                if (rem != 0) {
                    thousand = rem;
                    st.push("Thousand");
                    st.push(ump[rem]);
                }

            } else if (i == 5) {
                if(rem != 0){
                    int temp = rem * 10 + thousand;
                    if(thousand == 0){
                        st.push("Thousand");
                        thousand = 1;
                    }
                    if(temp >= 11 && temp < 20){
                        st.pop();
                        st.push(ump[temp]);
                    }else{
                        int temp = rem * 10;
                        st.push(ump[temp]);
                    }
                }
            } else if (i == 6) {
                if (rem != 0) {
                    if(thousand == 0) st.push("Thousand");
                    st.push("Hundred");
                    st.push(ump[rem]);
                }

            } else if (i == 7) {
                million = rem;
                if(rem != 0){
                    st.push("Million");
                    st.push(ump[rem]);
                }
            } else if(i == 8){
                if(rem != 0){
                    int temp = rem * 10 + million;
                    if(million == 0){
                        st.push("Million");
                        million = 1;
                    }
                    if(temp >= 11 && temp < 20){
                        st.pop();
                        st.push(ump[temp]);
                    }else{
                        int temp = rem * 10;
                        st.push(ump[temp]);
                    }
                }
            } else if (i == 9) {
                if (rem != 0) {
                    if(million == 0) st.push("Million");
                    st.push("Hundred");
                    st.push(ump[rem]);
                }
            }
            else if(i == 10){
                if(rem != 0){
                    st.push("Billion");
                    st.push(ump[rem]);
                }
            }
            // cout << i << " " << num << " " << sum << " " << rem << endl;
            i++;
            num /= 10;
        }
        string ans = "";
        while (!st.empty()) {
            if(st.top() != ""){
                ans += st.top();
                ans += " ";
            }
            // cout << st.top() << "-";
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};