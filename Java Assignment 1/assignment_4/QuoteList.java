//QuoteList.java
package assignment_4;
import java.io.*;
import java.util.*;

public class QuoteList implements Serializable
{
    ArrayList<Quote> quotes =null;
    QuoteList(){
        quotes = new ArrayList<>();
    }
    
    void addDefaults(){
        quotes.add(new Quote("Thinking is the hardest work there is,\nwhich is probably the reason so few engage in it.","Henry Ford"));
        quotes.add(new Quote("I’m a great believer in luck,\nand I find the harder I work, the more I have of it.","Thomas Jefferson"));
        quotes.add(new Quote("Satisfaction lies in the effort, not in the attainment.","Mahatma Gandhi"));
        quotes.add(new Quote("Success is no accident. It is hard work, perseverance, learning,\nstudying, sacrifice and most of all, love of \nwhat you are doing or learning to do","Pele"));
        quotes.add(new Quote("If you look at what you have in life, you'll always have more.\nIf you look at what you don't have in life, you'll never have enough.","Oprah Winfrey"));
        quotes.add(new Quote("Spread love everywhere you go. Let no one ever come to you without leaving happier.","Mother Teresa"));
        quotes.add(new Quote("It always seems impossible until it's done","Nelson Mandela"));
        quotes.add(new Quote("Tell me and I forget. Teach me and I remember. Involve me and I learn.","Benjamin Franklin"));
        quotes.add(new Quote("The best and most beautiful things in the world cannot be seen or even touched - they must be felt with the heart","Helen Keller"));
        quotes.add(new Quote("In the end, it's not the years in your life that count. It's the life in your years.","Abraham Lincoln"));
        quotes.add(new Quote("Talent is cheaper than table salt.\nWhat separates the talented individual from the successful one\nis a lot of hard work..","Stephen King"));
        quotes.add(new Quote("The greatest glory in living lies not in never falling,\nbut in rising every time we fall","Nelson Madela"));
        quotes.add(new Quote("Do not go where the path may lead,\ngo instead where there is no path and leave a trail.","Ralph Waldo Emerson"));
        quotes.add(new Quote("Life is never fair, and perhaps it is a good thing for most of us that it is not","Oscar Wilde"));
        quotes.add(new Quote("In three words I can sum up everything I've learned about life: it goes on.","Robert Frost"));
    }
    
    private int pickRandom(){
        Random rand = new Random();
        return rand.nextInt(quotes.size());
    }
    
    void addQuote(){
        Quote q = new Quote();
        q.addQuote();
        quotes.add(q);
    }
    
    
    void showQuote(){
       int t = pickRandom();
       Quote q = quotes.get(t);
       q.showQuote();
    }
}
