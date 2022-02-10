//Indexing.java
package assignment_5;
import java.io.*;
import java.util.*;

public class Indexing
{
    HashMap<String,ArrayList<Integer>> index = null;
    String filename = null;
    int line_number;
    String[] sentences;
    String[] words;
    
    Indexing(String filename){
    this.filename = filename;
    index = new HashMap<>();
    line_number = 1;
    sentences = null;
    words = null;
    }
    
    private void createIndex(String[] words,int line_number)
    {
        ArrayList<Integer> al = null;
        for(String w: words)
        {
            //Removes all the characters except letters.
            String s = "\0";
            for(int i=0;i<w.length();i++)
                {
                    if(Character.isLetter(w.charAt(i)) || Character.isDigit(w.charAt(i)))
                        s+= w.charAt(i);
                }
            s = s.trim();
            w = s.toLowerCase();
            //If key not found, add it to Map. Otherwise add line number to the previous index.
            if(!index.containsKey(w))
            {
                index.put(w,new ArrayList<Integer>());
            }
            al = index.get(w);
            al.add(line_number);
        }
    }
    
    void sepRateWords()throws IOException
    {
        File f = new File(filename);
        Scanner sf = new Scanner(f);
        String line= null;
         if(!f.exists())
        {System.out.println("File does not exist");
            return;}
        while(sf.hasNextLine())
        {  line = sf.nextLine();
           words = line.split("\\s");
           //for(String w: words)
              // System.out.println(w);
           createIndex(words,line_number);
           line_number++;
        }
    }
    
    void findWord(){
        ArrayList<Integer> al = null;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the word whose indexes are to be found: ");
        String word = sc.nextLine();
        word = word.trim();
        word = word.toLowerCase();
        if(index.containsKey(word))
        {System.out.println("\""+word+"\" is found in the line: " );
            al = index.get(word);
            for(int i=0;i<al.size();i++)
                System.out.println(al.get(i));
        }
        else{
            System.out.println("Word was not found in the file");
        }
    }
    
    void displayAll(){
        ArrayList<Integer> al = null;
        for(String word : index.keySet())
        {  al = index.get(word);
            System.out.print("\""+word+"\" is found in the line: ");
             for(int i=0;i<al.size();i++)
                 System.out.print(al.get(i)+" ");
            System.out.print("\n");
        }
    }
}

