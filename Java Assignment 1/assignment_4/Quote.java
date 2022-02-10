//Quote.java
package assignment_4;
import java.io.*;
import java.util.*;

class Quote implements Serializable
{
    String quote,author;
    Quote(){
        quote =null;
        author = null;
    }
    
    Quote(String q,String a)
    {
        quote = new String(q);
        author = new String(a);
    }
    
    void addQuote(){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter quote: ");
        quote = sc.nextLine();
        System.out.print("Enter author's name: ");
        author = sc.nextLine();
    }
    
    void showQuote(){
        System.out.println("Today's quote is:");
        System.out.println(quote);
        System.out.print("\t\t\t\t\tby: "+author);
    }
}
