//itemlist.java
package assignment_2;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class Itemlist {

    private ArrayList<item> List;
    private Scanner sc = new Scanner(System.in);

    public Itemlist() {
        System.out.println("New Shop is being created.");
        List = new ArrayList<item>();
    }

    public int getSize() {
        return List.size();

    }

    private item search(long code) {
        Iterator<item> itr = List.iterator();
        item Item;
        while (itr.hasNext()) {
            Item = new item(itr.next());
            if (Item.getCode() == code) {
                return Item;
            }
        }
        return null;
    }

    public item search(String name) {
        Iterator<item> itr = List.iterator();
        item Item;
        while (itr.hasNext()) {
            Item = new item(itr.next());
            if (Item.getName() == name) {
                return Item;
            }
        }
        return null;
    }

    public void addItem() {
        long Code;
        String Name;
        double Rate;
        int Quantity;
        item found_Item;

        System.out.println("Enter Item code:");
        Code = sc.nextLong();
        found_Item = search(Code);
        if (found_Item == null) {
            System.out.println("Item name: ");
            Name = sc.next();
            System.out.println("Rate: ");
            Rate = sc.nextDouble();
            System.out.println("Quantity: ");
            Quantity = sc.nextInt();
            item aItem = new item(Name, Rate, Code, Quantity);
            List.add(aItem);
        } else if (found_Item != null) {
            System.out.println("Item exists.");
        }

    }

    public void updateStock(int t) {
        int choice, quantity;
        long code;
        double price;
        item found_Item;
        if(t==1) {
            System.out.println("1. Update quantity.");
            System.out.println("2. Update rate.");
            System.out.println("Your Choice: ");
            choice = sc.nextInt();
        }else{
            choice=1;
        }
        System.out.println("Enter Item code:");
        code = sc.nextLong();
        found_Item = search(code);
        if (found_Item == null) {
            System.out.println("Item not found!");
            return;
        }

        if (choice == 1) {

            System.out.println("Enter quantity: ");
            quantity = sc.nextInt();
            found_Item.setQuantity(found_Item.getQuantity() + quantity);
            System.out.println("\n Quantity updated.\n");
            System.out.println("Present quantity: " + found_Item.getQuantity());
        }

        else if (choice == 2) {

            System.out.println("Enter new price: ");
            price = sc.nextDouble();
            found_Item.setRate(price);
            System.out.println("\n Price updated.\n");
            System.out.println("Present Price: " + found_Item.getRate());
        }

        else {
            System.out.println("Invalid input!!");
            updateStock(2);
        }

    }

    public void display() {

        long code;
        item found_Item;

        System.out.println("Enter Item code: ");
        code = sc.nextLong();
        found_Item = search(code);
        if (found_Item == null) {
            System.out.println("Item not found!");
            return;
        }

        System.out.println(found_Item.toString());
    }

    public void issueItem() {
        int numberOfItem;
        long code;
        item found_Item;

        System.out.println("Enter Item code: ");
        code = sc.nextLong();
        found_Item = search(code);
        if (found_Item == null) {
            System.out.println("Item not found.");
            return;
        }

        System.out.println("Number of Items: ");
        numberOfItem = sc.nextInt();
        if (numberOfItem > found_Item.getQuantity()) {
            System.out.println("\nRequired number of Items not in stock\n\n");
            return;
        }

        else {
            System.out.println("\nCost of " + numberOfItem + " copies: "
                    + numberOfItem * found_Item.getRate());
            found_Item.setQuantity(found_Item.getQuantity() - numberOfItem);
        }
    }

    public double checkPrice(long code) {
        item found_Item = search(code);
        if (found_Item == null) {
            System.out.println("Item not found!");
            return 0.0;
        }

        else
            return found_Item.getRate();
    }
}