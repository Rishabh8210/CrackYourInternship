class Solution {
    public int calculate(String s) {
        Stack<Character> operand = new Stack<Character>();
        Stack<Integer> number = new Stack<Integer>();
        Map<Character, Integer> priority = new HashMap<Character, Integer>();
        
        priority.put('/', 0);
        priority.put('*', 0);
        priority.put('+', 2);
        priority.put('-', 2);
        int res = 0;
        char[] sc = s.toCharArray();
        int num = 0;
        for(int i = 0 ; i < sc.length ; i++){
            if(sc[i] == ' '){
                continue;
            }else if(sc[i] > 57 || sc[i] < 48){
                number.push(num);
                num = 0;
                if(operand.size() == 0){
                    operand.push(sc[i]);
                }else{
                    while(operand.size() != 0 && priority.get(operand.peek()) <= priority.get(sc[i])){
                        int right = number.pop();
                        int left = number.pop();
                        res = getRes(operand.pop(), left, right);
                        number.push(res);
                    }
                    operand.push(sc[i]);
                }
            }else{
                num = num * 10 + Integer.parseInt(String.valueOf(sc[i]));
            }
        }
        number.push(num);
        while(operand.size() != 0){
            int right = number.pop();
            int left = number.pop();
            res = getRes(operand.pop(), left, right);
            number.push(res);
        }
        return number.pop();
    }
    
    private int getRes(char operand, int num1, int num2){
        if(operand == '/'){
            return num1 / num2;
        }
        if(operand == '*'){
            return num1 * num2;
        }
        if(operand == '+'){
            return num1 + num2;
        }
        return num1 - num2;
    }
}