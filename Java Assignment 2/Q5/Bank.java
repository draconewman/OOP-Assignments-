//Roll No: 001910501057
import java.util.*;

class Bank
{
    private String id; //customer id
    private String name;    //customer name
    private long loan;   //current loan amount
    private long phno;  //phone number
    private long balance = 10000;   //In this program everyone has 10k balance by default
    private long credit_limit = 50000;
    private long r_credit_limit;    //r=remaining
    private long privileged_limit = 70000;
    private long r_privileged_limit;

    Scanner input = new Scanner(System.in);

    void initialize()
    {
        System.out.print("Enter customer id (For privilege start the id with p): ");
        id = input.nextLine();
        System.out.print("Enter customer name: ");
        name = input.nextLine();
        System.out.print("Enter current loan amount: ");
        loan = input.nextLong();
        System.out.print("Enter Phone number: ");
        phno = input.nextLong();
        System.out.println("New bank account has been created.");
    }

    void display()
    {
        System.out.println(id + "," + name + "," + balance);
    }

    void loan(String ID)
    {
        char n[] = ID.toCharArray();
        for (int i = 0; i < n.length; i++)
        {
            if('p' == n[0])
            {
                long amt;
                System.out.println("Enter the amount you want for loan: ");
                amt = input.nextLong();
                if(amt < privileged_limit)
                {
                    r_privileged_limit = privileged_limit - amt;
                    loan = loan + amt;
                    System.out.println("Your transaction is successful.");
                }
                else 
                {
                    System.out.println("Current loan amount exceeds the credit limit.");
                }   
            }
            else
            {
                long amt;
                System.out.println("Enter the amount you want for loan: ");
                amt = input.nextLong();
                if(amt < credit_limit)
                {
                        r_credit_limit = credit_limit - amt;
                        loan = loan + amt;
                        System.out.println("Your transaction is successful.");
                }
                else 
                {
                    System.out.println("Current loan amount exceeds the credit limit.");
                }   
            }
        }
        
    }

    boolean search(String ID)   //method to search a customer id
    {
        if(id == ID)
        {
            display();
            return(true);
        }
        return(true);
    }

    public void change()
    {
        Scanner J = new Scanner(System.in);
        System.out.print("Enter customer name: ");
        name = J.nextLine();
        System.out.print("Enter Phone number: ");
        phno = J.nextLong();
        System.out.println("New data has been saved.");
    }

    public void loan_details(String ID)
    {
        char n[] = ID.toCharArray();
        for (int i = 0; i < n.length; i++)
        {
            if('p' == n[0])
            {
                System.out.println("Your Credit limit: " + privileged_limit + "\nYour current loan amount: " + loan + "\nAmount of loan you can seek: " +  r_privileged_limit);
            }
            else
            {
                System.out.println("Your Credit limit: " + credit_limit + "\nYour current loan amount: " + loan + "\nAmount of loan you can seek: " +  r_credit_limit);
            }
        }                
    }
    //Main
    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);
        System.out.print("How many customer you want to add: ");
        int n = input.nextInt();
        Bank a[] = new Bank[n];
        for(int i=0; i<a.length; i++)
        {
            a[i] = new Bank();
            a[i].initialize();
        }

            int d;
            do{
                System.out.println("\n1. Display Accounts \n2. Search By Customer id \n3. Loan \n4. Change name, phone number \n5. Show loan details");
                    System.out.println("Your Choice: ");    d = input.nextInt();
                    switch (d) 
                    {
                        case 1:
                        {
                            for (int k = 0; k < a.length; k++) {
                                a[k].display();
                            }
                            break;
                        }
                        case 2:
                        {
                            Scanner I = new Scanner(System.in);
                            System.out.print("Enter Customer ID you want to search: ");
                            String ID = I.nextLine();
                            boolean found = false;
                            for (int k = 0; k < a.length; k++) 
                            {
                                found = a[k].search(ID);
                                if(found) 
                                {
                                    System.out.println("Search is successful. This account number exists.");
                                    break;
                                }
                            }
                            if (!found) 
                            {
                                System.out.println("Search Failed. Account does not exist.");
                            }
                            break;
                        }
                        case 3:
                        {
                            Scanner I = new Scanner(System.in);
                            System.out.print("Enter Customer ID: ");
                            String ID = I.nextLine();
                            boolean found = false;
                            for(int k = 0; k < a.length; k++)
                            {
                                found = a[k].search(ID);
                                if(found)
                                {
                                    a[k].loan(ID);
                                    break;
                                }
                            }
                            if(!found)
                            {
                                System.out.println("Search Failed. Account does not exist.");
                            }
                            break;
                        }
                        case 4:
                        {
                            Scanner I = new Scanner(System.in);
                            System.out.print("Enter Customer ID: ");
                            String ID = I.nextLine();
                            boolean found = false;
                            for(int k = 0; k < a.length; k++)
                            {
                                found = a[k].search(ID);
                                if(found)
                                {
                                    a[k].change();
                                    break;
                                }
                            }
                            if(!found)
                            {
                                System.out.println("Search Failed. Account does not exist.");
                            }
                            break;
                        }
                        case 5:
                        {
                            Scanner I = new Scanner(System.in);
                            System.out.print("Enter Customer ID: ");
                            String ID = I.nextLine();
                            boolean found = false;
                            for(int k = 0; k < a.length; k++)
                            {
                                found = a[k].search(ID);
                                if(found)
                                {
                                    a[k].loan_details(ID);
                                    break;
                                }
                            }
                            if(!found)
                            {
                                System.out.println("Search Failed. Account does not exist.");
                            }
                            break;
                        }
                        default :
                        {
                            System.out.print("Invalid Input!!");
                            return;
                        }
                    }
            }while(d!=5);
        }
    }

/*Output:
How many customer you want to add: 2
Enter customer id (For privilege start the id with p): 1
Enter customer name: Adam
Enter current loan amount: 20000
Enter Phone number: 001
New bank account has been created.
Enter customer id (For privilege start the id with p): p2
Enter customer name: Eve
Enter current loan amount: 30000
Enter Phone number: 002
New bank account has been created.

1. Display Accounts
2. Search By Customer id
3. Loan
4. Change name, phone number
5. Show loan details
Your Choice:
1
1,Adam,10000
p2,Eve,10000

1. Display Accounts
2. Search By Customer id
3. Loan
4. Change name, phone number
5. Show loan details
Your Choice:
2
Enter Customer ID you want to search: p2
Search is successful. This account number exists.

1. Display Accounts
2. Search By Customer id
3. Loan
4. Change name, phone number
5. Show loan details
Your Choice:
3
Enter Customer ID: p2
Enter the amount you want for loan: 
90000
Current loan amount exceeds the credit limit.
Enter the amount you want for loan:
40000
Your transaction is successful.

1. Display Accounts
2. Search By Customer id
3. Loan
4. Change name, phone number
5. Show loan details
Your Choice:
5
Enter Customer ID: p2
Your Credit limit: 70000
Your current loan amount: 60000
Amount of loan you can seek: 30000
Your Credit limit: 70000
Your current loan amount: 60000
Amount of loan you can seek: 30000
*/



                        
            
            

            