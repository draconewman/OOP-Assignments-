//Roll No: 001910501057
package assignment_3;
import java.util.Scanner;
class Parentheses {
    public static void main(String args[])
    {
    Scanner in = new Scanner(System.in);
    System.out.println("Enter the input string: \n");
    String s = in.nextLine();
    in.close();
    int size = s.length();
    Stack st = new Stack(size);
    for (char a : s.toCharArray()) {
        if(a==')'){
            if( st.peek()=='(')
                st.pop();
            else
            {
                System.out.println("false, not balanced");
                break;
            }
        }
        else if(a==']'){
            if( st.peek()=='[')
                st.pop();
            else
            {
                System.out.println("false, not balanced");
                break;
            }
        }
        else if(a=='}'){
            if( st.peek()=='{')
                st.pop();
            else
            {
                System.out.println("false, not balanced");
                break;
            }
        }
        else if (a=='('|| a=='{'|| a=='['){
            st.push(a);
        }
    }
    if(st.isEmpty()==true)
        System.out.println("true, balanced");
    else
        System.out.println("false, not balanced");
}
}
//Output:
//Enter the input string: 

//(){}[]
//( pushed into stack
//( popped out of stack
//{ pushed into stack
//{ popped out of stack
//[ pushed into stack
//[ popped out of stack
//true, balanced

//Enter the input string: 

//({})[){][[
//( pushed into stack
//{ pushed into stack
//{ popped out of stack
//( popped out of stack
//[ pushed into stack
//false, not balanced
//false, not balanced