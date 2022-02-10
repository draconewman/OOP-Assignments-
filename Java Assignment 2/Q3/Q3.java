//Roll No: 001910501057
import java.util.*;

public class Q3
{
    private static String s; 

    public void input()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter String: ");
        s = input.nextLine();        
    }

    public void a_occurences(String s)
    {        
        char n[] = s.toCharArray();
        int count = 0;
        for (int i = 0; i < n.length; i++)
        {
            if('a' == n[i])   count++;
        }
        System.out.println("'a' occurences = " + count + " times");       
    }

    public void and_occurences(String s)
    {
        String word = "and";
        String n[] = s.split(" ");
        int count = 0;
        for (int i = 0; i < n.length; i++)
        {
            if(word.equals(n[i]))   count++;
        }
        System.out.println("'and' occurences = " + count + " times");
    }

    public void The(String s)
    {
        String word = "The";
        String n[] = s.split(" ");
        if(word.equals(n[0]))
        {
            System.out.print("It starts with 'The'.");
        }
        else
        {
            System.out.print("It does not start with 'The'.");
        }
    }

    public void Char_Array(String s)
    {
        char[] c = s.toCharArray();
        for(int i = 0; i < c.length; i++)
        {
            System.out.println(c[i]);
        }
    }

    public void Token(String s)
    {
        String[] t = s.split(" ");
        for(String ans : t)
        {
            System.out.println(ans);
        }
    }

    public static void main(String args[])
    {
        Q3 q3 = new Q3();
        Scanner input = new Scanner(System.in);
        int c;
        while(true)
        {
            System.out.println("\n");
            System.out.println("\n1. Input String \n2. 'a' occurences \n3. 'and' occurences \n4. whether it starts with 'The' or not \n5. put the String into an array of characters \n6. display the tokens"); 
            System.out.print("Your Choice: ");
            c = input.nextInt();
            switch(c)
            {
                case 1:
                {
                    q3.input();
                    break;
                }
                case 2:
                {
                    q3.a_occurences(s);
                    break;
                }
                case 3:
                {
                    q3.and_occurences(s);
                    break;
                }
                case 4:
                {
                    q3.The(s);
                    break;
                }
                case 5:
                {
                    q3.Char_Array(s);
                    break;
                }
                case 6:
                {
                    q3.Token(s);
                    break;
                }
                default:
                {
                    System.out.print("Invalid Input!!");
                    return;
                }
            }
        }
    }
}

/*Output:
1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 1
Enter String: The tree and sea are amazing



1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 2
'a' occurences = 5 times



1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 3
'and' occurences = 1 times



1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 4
It starts with 'The'.


1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 5
T
h
e

t
r
e
e

a
n
d

s
e
a

a
r
e

a
m
a
z
i
n
g



1. Input String
2. 'a' occurences
3. 'and' occurences
4. whether it starts with 'The' or not
5. put the String into an array of characters
6. display the tokens
Your Choice: 6
The
tree
and
sea
are
amazing
*/
