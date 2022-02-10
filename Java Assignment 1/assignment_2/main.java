//Roll No: 001910501057
package assignment_2;
import java.util.Scanner;
public class main {

    public static void main(String[] args) {

        char choice;
        Itemlist Shop = new Itemlist();
        Scanner sc = new Scanner(System.in);
        int type;
        System.out.print("Enter 1 for SEO\nEnter 2 for SK\nYour Choice: ");
        type = sc.nextInt();
        System.out.println("_____ITEM_____");
        do {
            if(type==1) {
                System.out.println("1. Add items");
                System.out.println("2. Issue item");
                System.out.println("3. Update item list");
                System.out.println("4. Display item details");
                System.out.println("5. Check price for a item");
                System.out.println("6. Exit");
                System.out.println("Your Choice: ");
                choice = sc.next().charAt(0);
                switch (choice) {
                    case '1':
                        Shop.addItem();
                        break;

                    case '2':
                        Shop.updateStock(1);
                        break;

                    case '3':
                        Shop.issueItem();
                        break;

                    case '4':
                        Shop.display();
                        break;

                    case '5':

                        System.out.println("Item price: "
                                + Shop.checkPrice(inputCode()));

                    case '6':
                        System.out.println("Thank you.\n");
                        System.exit(0);
                        break;
                }
            }
            else if(type==2){
                    System.out.println("1. Add items");
                    System.out.println("2. Issue item");
                    System.out.println("3. Update quantity");
                    System.out.println("4. Display item details");
                    System.out.println("5. Check price for a item");
                    System.out.println("6. Exit");
                    System.out.println("Your Choice: ");
                    choice = sc.next().charAt(0);
                    switch (choice) {
                        case '1':
                            Shop.addItem();
                            break;

                        case '2':
                            Shop.updateStock(2);
                            break;

                        case '3':
                            Shop.issueItem();
                            break;

                        case '4':
                            Shop.display();
                            break;

                        case '5':

                            System.out.println("Item Price: "
                                    + Shop.checkPrice(inputCode()));

                        case '6':
                            System.out.println("Thank you\n");
                            System.exit(0);
                            break;
                    }
            }
        } while (true);
    }
        public static long inputCode() {
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter Item code: ");
            if (sc.hasNextLong()) {
                return sc.nextLong();
            } else {
                System.out.println("Invalid Input!!");
                return 0;
            }

        }
}

//Output:
//New Shop is being created.
//Enter 1 for SEO
//Enter 2 for SK
//Your Choice: 1
//_____ITEM_____
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//1
//Enter Item code:
//02
//Item name: 
//Laptop
//Rate: 
//50
//Quantity: 
//10
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//1
//Enter Item code:
//01
//Item name: 
//Monitor
//Rate: 
//40
//Quantity: 
//5
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//2
//1. Update quantity.
//2. Update rate.
//Your Choice:
//1
//Enter Item code:
//01
//Enter quantity: 
//7

// Quantity updated.

//Present quantity: 12
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//3
//Enter Item code: 
//02
//Number of Items: 
//7

//Cost of 7 copies: 350.0
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//4
//Enter Item code: 
//02
//item_code: Lap10
//Item [name=Laptop, rate=50.0, code=2, quantity=10, item_code=Lap10]
//1. Add items
//2. Issue item
//3. Update item list
//4. Display item details
//5. Check price for a item
//6. Exit
//Your Choice:
//5
//Enter Item code:
//01
//Item price: 40.0
//Thank you.