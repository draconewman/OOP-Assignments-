//Roll No: 001910501057
import java.util.Scanner;

public class Metric
{
    private double km, mile;   //km = Kilometre

    public void km_to_mile()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Kilometre: ");
        km = input.nextDouble();
        mile = 1.5*km;
        System.out.println(km + " Kilometre = " + mile + " Mile");
    }

    public void mile_to_km()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Mile: ");
        mile = input.nextDouble();
        km = mile/1.5;
        System.out.println(mile + " Mile = " + km + " Kilometre");
    }

    public static void main(String args[])
    {
        Metric m = new Metric();
        Scanner input = new Scanner(System.in);
        int c;
        while(true)
        {
            System.out.println("\n");
            System.out.println("\n1. Kilometre to Mile conversion \n2. Mile to Kilometre conversion");
            System.out.print("Your Choice: ");
            c = input.nextInt();
            switch(c)
            {
                case 1:
                {
                    m.km_to_mile();
                    break;
                }
                case 2:
                {
                    m.mile_to_km();
                    break;
                }
                default:
                System.out.print("Invalid Input!!");
                return;
            }
        }
    }
}

/*Output:
1. Kilometre to Mile conversion
2. Mile to Kilometre conversion
Your Choice: 1
Enter Kilometre: 10
10.0 Kilometre = 15.0 Mile



1. Kilometre to Mile conversion
2. Mile to Kilometre conversion
Your Choice: 2
Enter Mile: 10
10.0 Mile = 6.666666666666667 Kilometre
*/
