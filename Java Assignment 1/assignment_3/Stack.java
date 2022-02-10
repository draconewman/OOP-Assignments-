//Stack.java
package assignment_3;

class Stack {
    static int MAX = 100;
    int top;
    char[] arr;
    Stack(){
        arr = new char[MAX];
        top=-1;
    }
    Stack(int n){
        MAX = n;
        arr = new char[MAX];
        top=-1;
    }
    boolean isEmpty()
    {
        return (top < 0);
    }
    boolean push(char x)
    {
        if (top >= (MAX - 1)) {
            System.out.println("Stack Overflow!");
            return false;
        }
        else {
            arr[++top] = x;
            System.out.println(x + " pushed into stack");
            return true;
        }
    }
 
    char pop()
    {
        if (top < 0) {
            System.out.println("Stack Underflow!");
            return 0;
        }
        else {
            char x = arr[top--];
            System.out.println(x + " popped out of stack");
            return x;
        }
    }

    char peek()
    {
        if (top < 0) {
            System.out.println("Stack Underflow!");
            return 0;
        }
        else {
            char x = arr[top];
            return x;
        }
    }
}

