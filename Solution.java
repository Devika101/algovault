public import java.util.Stack;

public class Solution{
    public static boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();

        for (char ch : s.toCharArray()) {
           
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } 
          
            else if (ch == ')' || ch == '}' || ch == ']') {
                if (stack.isEmpty()) return false;

                char top = stack.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            } 
            else {
                
                return false;
            }
        
        }
          return stack.isEmpty();
    }
} {
    
}
