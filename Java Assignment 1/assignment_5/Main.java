//Roll No: 001910501057
package assignment_5;
import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)throws IOException{
        Indexing it = new Indexing("\\C:\\Users\\acer\\Downloads\\java_assignmments\\assignment_5\\Sample.txt");
        it.sepRateWords();
        Scanner sc = new Scanner(System.in);
        int choice;
        while(true){
                System.out.print('\u000C');
                System.out.println("\nChoices:\n1. Display indexes of a particular word\n2. Display All indexes");
                System.out.print("Enter your choice: ");
                choice = sc.nextInt();
                switch(choice){
                case 1:
                    it.findWord();
                    sc.nextLine();
                    sc.nextLine();
                    break;
                case 2:
                    it.displayAll();
                    sc.nextLine();
                    sc.nextLine();
                    break;
                default:
                    System.out.println("Do you want to quit(Y/N)?");
                    char c = sc.next().charAt(0);
                        c = Character.toLowerCase(c);
                        if(c == 'y')
                        { //before leaving the program, store the current state.
                            System.exit(0);}
                }
            }
        
    }
}

//Output:
//Choices:
//1. Display indexes of a particular word
//2. Display All indexes
//Enter your choice: 1
//Enter the word whose indexes are to be found: codes
//"codes" is found in the line: 
//6

//Choices:
//1. Display indexes of a particular word
//2. Display All indexes
//Enter your choice: 2
//"how" is found in the line: 3 
//"codes" is found in the line: 6
//"books" is found in the line: 7
//"notes" is found in the line: 8
//"are" is found in the line: 4
//"there" is found in the line: 2
//"classes" is found in the line: 9
//"007" is found in the line: 11
//"hello" is found in the line: 1
//"you" is found in the line: 5
//"fun" is found in the line: 9 9 10
