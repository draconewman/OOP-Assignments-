//Roll No: 001910501057
package assignment_4;
import java.io.*;
import java.util.*;

public class Main
{
    static void quoteWrite(QuoteList ql)throws IOException{
        File f = new File("C:\\Users\\acer\\Downloads\\java_assignmments\\assignment_4\\quotes.ser");
        FileOutputStream fop = new FileOutputStream(f);
        ObjectOutputStream obs = new ObjectOutputStream(fop);
        
        try{
            obs.writeObject(ql);
        }catch(IOException e){
        System.out.println(e.getMessage());
        }
        finally{
            obs.close();
            fop.close();
        }
    }
    
    static QuoteList quoteRead()throws IOException,ClassNotFoundException{
       File f = new File("C:\\Users\\acer\\Downloads\\java_assignmments\\assignment_4\\quotes.ser");
       FileInputStream fip = new FileInputStream(f);
       ObjectInputStream obs = new ObjectInputStream(fip); 
       QuoteList ql= null;
       try{
            ql = (QuoteList)obs.readObject();
        }catch(IOException e){
            System.out.println(e.getMessage());
        }
        catch(ClassNotFoundException e){
            System.out.println(e.getMessage());
        }
        finally{
            obs.close();
            fip.close();
            return ql;
        }
        
    }
    
    public static void main(String[] args)throws IOException,ClassNotFoundException{
            QuoteList ql= null;
            File f = new File("C:\\Users\\acer\\Downloads\\java_assignmments\\assignment_4\\quotes.ser");
            //for first time
            if(!f.exists()){
                ql = new QuoteList();
                ql.addDefaults();
                quoteWrite(ql);
            }
            //for second and successive calls.
            else{
                ql = quoteRead();
            }
            
            Scanner sc= new Scanner(System.in);
            int choice;
            while(true){
                System.out.print('\u000C');
                System.out.println("\nChoices: \n 1. Add quote\n 2. Display Quote");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();
                switch(choice){
                case 1:
                    ql.addQuote();
                    sc.nextLine();
                    sc.nextLine();
                    break;
                case 2:
                    ql.showQuote();
                    sc.nextLine();
                    sc.nextLine();
                    break;
                default:
                    System.out.println("Do you want to quit(Y/N)?");
                    char c = sc.next().charAt(0);
                        c = Character.toLowerCase(c);
                        if(c == 'y')
                        { //before leaving the program, store the current state.
                            quoteWrite(ql);
                            System.exit(0);}
                }
            }
    }
}

//Choices:         
// 1. Add quote    
// 2. Display Quote
//Enter your choice: 2
//Today's quote is:
//If you look at what you have in life, you'll always have more.
//If you look at what you don't have in life, you'll never have enough.
//                                        by: Oprah Winfrey