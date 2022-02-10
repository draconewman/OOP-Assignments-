//Roll No: 001910501057
import java.util.*;

public class wrapper
{
    private static int i; 

    public void input()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter integer: ");
        i = input.nextInt();        
    }

    public void basic_to_object()
    {
        Integer int_obj = Integer.valueOf(i);   //autoboxing. converting into Integer wrapper object
        System.out.print("Printing integer value as object: " + int_obj);
    }

    public void object_to_basic()
    {
        Integer int_obj = Integer.valueOf(i);  
        int iv = int_obj;   //unboxing
        System.out.print("Printing integer value as basic data type: " + iv);
    }

    public void basic_to_String()
    {
        String s = String.valueOf(i);
        System.out.print("Printing integer value as String: " + s);
    }

    public void String_to_object()
    {
        String s = String.valueOf(i);
        Object str_obj = s;
        System.out.print("Printing integer value as object: " + str_obj);
    }

    public void object_to_String()
    {
        String s = String.valueOf(i);
        Object str_obj = s;
        String ns = String.valueOf(str_obj);
        System.out.print("Printing integer value as String: " + ns);
    }

    public static void main(String args[])
    {
        wrapper n = new wrapper();
        Scanner input = new Scanner(System.in);
        int c;
        while(true)
        {
            System.out.println("\n");
            System.out.println("\n1. Input integer \n2. basic data type to object \n3. object to basic data type \n4. basic data type to String \n5. String to object \n6. object to String"); 
            System.out.print("Your Choice: ");
            c = input.nextInt();
            switch(c)
            {
                case 1:
                {
                    n.input();
                    break;
                }
                case 2:
                {
                    n.basic_to_object();
                    break;
                }
                case 3:
                {
                    n.object_to_basic();
                    break;
                }
                case 4:
                {
                    n.basic_to_String();
                    break;
                }
                case 5:
                {
                    n.String_to_object();
                    break;
                }
                case 6:
                {
                    n.object_to_String();
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
1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice: 1
Enter integer: 57



1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice: 2
Printing integer value as object: 57


1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice:
3
Printing integer value as basic data type: 57


1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice: 4
Printing integer value as String: 57


1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice: 5
Printing integer value as object: 57


1. Input integer
2. basic data type to object
3. object to basic data type
4. basic data type to String
5. String to object
6. object to String
Your Choice: 6
Printing integer value as String: 57
*/