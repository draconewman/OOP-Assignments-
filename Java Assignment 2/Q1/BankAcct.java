//Roll No: 001910501057
import java.util.Scanner;

public class BankAcct
{
private float balance, interest_rate;            
private int number; //account number

public void initialize()
{
  Scanner input = new Scanner(System.in);
  System.out.print("Enter Balance: ");
  balance = input.nextFloat();
  System.out.print("Enter Account number: ");
  number = input.nextInt();
  System.out.print("Enter Interest rate: ");
  interest_rate = input.nextFloat();
  System.out.println("New bank account has been created.");
}

public void change_interest_rate()
{
  Scanner input = new Scanner(System.in);
  System.out.print("Enter New Interest Rate: ");
  interest_rate = input.nextFloat();
  System.out.println("New Interest Rate has been saved.");
}

public void deposit() 
  {
  Scanner input = new Scanner(System.in);
  System.out.print("Enter Account Number for deposit: ");
  number = input.nextInt();
  int amount;
  System.out.print("Enter amount: ");
  amount = input.nextInt();
  balance = balance + balance*interest_rate + amount; 
  System.out.println("Your transaction is successful.");          
  }

public void withdraw() 
  {
  Scanner input = new Scanner(System.in);
  System.out.print("Enter Account Number for withdraw: ");
  number = input.nextInt();
  int amount;
  System.out.print("Enter amount: ");
  amount = input.nextInt();
  if(amount>balance)
    System.out.println("Your entered amount is lower than your current balance.");  
  else
    balance -= amount;  
  System.out.println("Your transaction is successful.");  
  }

public void display() 
  {
    System.out.println("Current Balance in account number " + number + " is " + balance);
  }

boolean search(int ID)   //method to search a customer id
  {
      if(number == ID)
      {
          display();
          return(true);
      }
      return(true);
  }

//Main
public static void main(String args[])
  {
    Scanner input = new Scanner(System.in);
    System.out.print("How many customer you want to add: ");
        int p = input.nextInt();
        BankAcct n[] = new BankAcct[p];
        for(int i=0; i<n.length; i++)
        {
            n[i] = new BankAcct();
            n[i].initialize();
        }
    
    int c;
    do{
      System.out.println("\n");
      System.out.println("\n1. Display Accounts \n2. Change interest rate \n3. Deposit \n4. Withdraw \n5. Display current Balance");
      System.out.println("Your Choice: ");
      c = input.nextInt();
      switch(c)
      {
        case 1:
        {
          for (int k = 0; k < n.length; k++) 
          {
            n[k].display();
          }
          break;
        }
        case 2:
        {
          Scanner I = new Scanner(System.in);
          System.out.print("Enter account number you want to search: ");
          int ID = I.nextInt();
          boolean found = false;
          for (int k = 0; k < n.length; k++) 
          {
              found = n[k].search(ID);
              if(found) 
              {
                n[k].change_interest_rate();
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
          System.out.print("Enter account number you want to search: ");
          int ID = I.nextInt();
          boolean found = false;
          for (int k = 0; k < n.length; k++) 
          {
              found = n[k].search(ID);
              if(found) 
              {
                n[k].deposit(); 
                break;
              }
          }
          if (!found) 
          {
              System.out.println("Search Failed. Account does not exist.");
          }
          break;
        }
        case 4:
        {
          Scanner I = new Scanner(System.in);
          System.out.print("Enter account number you want to search: ");
          int ID = I.nextInt();
          boolean found = false;
          for (int k = 0; k < n.length; k++) 
          {
              found = n[k].search(ID);
              if(found) 
              {
                n[k].withdraw(); 
                break;
              }
          }
          if (!found) 
          {
              System.out.println("Search Failed. Account does not exist.");
          }
          break;
        }
        case 5:
        {
          Scanner I = new Scanner(System.in);
          System.out.print("Enter account number you want to search: ");
          int ID = I.nextInt();
          boolean found = false;
          for (int k = 0; k < n.length; k++) 
          {
              found = n[k].search(ID);
              if(found) 
              {
                n[k].display();  
                break;
              }
          }
          if (!found) 
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
    }while(c!=5);
  }
}

/*Output:
How many customer you want to add: 2
Enter Balance: 20000
Enter Account number: 01
Enter Interest rate: 0.5
New bank account has been created.
Enter Balance: 30000
Enter Account number: 02
Enter Interest rate: 0.1
New bank account has been created.



1. Display Accounts
2. Change interest rate
3. Deposit
4. Withdraw
5. Display current Balance
Your Choice:
1
Current Balance in account number 1 is 20000.0
Current Balance in account number 2 is 30000.0



1. Display Accounts
2. Change interest rate
3. Deposit
4. Withdraw
5. Display current Balance
Your Choice:
2
Enter account number you want to search: 01
Current Balance in account number 1 is 20000.0
Enter New Interest Rate: 0.6
New Interest Rate has been saved.



1. Display Accounts
2. Change interest rate
3. Deposit
4. Withdraw
5. Display current Balance
Your Choice:
3
Enter account number you want to search: 01
Current Balance in account number 1 is 20000.0
Enter Account Number for deposit: 01
Enter amount: 1000 
Your transaction is successful.



1. Display Accounts
2. Change interest rate
3. Deposit
4. Withdraw
5. Display current Balance
Your Choice:
4
Enter account number you want to search: 02
Enter Account Number for withdraw: 02
Enter amount: 5000
Your transaction is successful.



1. Display Accounts
2. Change interest rate
3. Deposit
4. Withdraw
5. Display current Balance
Your Choice:
5
Enter account number you want to search: 01
Current Balance in account number 5000 is 28000.0
*/