//Roll No: 001910501057
package assignment_6;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;

class doctor
{
    String did, dname, specilist, appoint;
    void new_doctor()
    {
        Scanner input = new Scanner(System.in);
        System.out.print("id:-");
        did = input.nextLine();
        System.out.print("name:-");
        dname = input.nextLine();
        System.out.print("specilization:-");
        specilist = input.nextLine();
        System.out.print("work time:-");
        appoint = input.nextLine();
        
    }
    void doctor_info()
    {
        System.out.println(did + "\t" + dname + "  \t" + specilist + "     \t" + appoint);
    }
}
class patient
{
    String pname, disease, gender;
    int pid, age, bp, temp, ssn;
    private static final AtomicInteger count = new AtomicInteger(0);
    void new_patient()
    {
        Scanner input = new Scanner(System.in);
        pid = count.incrementAndGet();
        System.out.print("name:-");
        pname = input.nextLine();
        System.out.print("disease:-");
        disease = input.nextLine();
        System.out.print("gender:-");
        gender = input.nextLine();
        System.out.print("age:-");
        age = input.nextInt();
        System.out.print("blood_pressure:-");
        bp = input.nextInt();
        System.out.print("temparature:-");
        temp = input.nextInt();  
        System.out.print("social security number:-");
        ssn = input.nextInt();      
    }
    void patient_info()
    {
        System.out.println(pid + " \t" + pname + " \t" + disease + " \t" + gender + " \t" + age + " \t" + bp + " \t" + temp + " \t" + ssn);
    }
}

public class Hospital_Management
{
    public static void main(String args[])
    {
        String months[] = {
            "Jan",
            "Feb",
            "Mar",
            "Apr",
            "May",
            "Jun",
            "Jul",
            "Aug",
            "Sep",
            "Oct",
            "Nov",
            "Dec"
        };
        Calendar calendar = Calendar.getInstance();
        //System.out.println("--------------------------------------------------------------------------------");
        int count1 = 4, count2 = 0;
        System.out.println("\n--------------------------------------------------------------------------------");
        System.out.println("               *** Welcome to Hospital Information System ***");
        System.out.println("--------------------------------------------------------------------------------");
        System.out.print("Date: " + months[calendar.get(Calendar.MONTH)] + " " + calendar.get(Calendar.DATE) + " " + calendar.get(Calendar.YEAR));
        System.out.println("\t\t\t\t\t\tTime: " + calendar.get(Calendar.HOUR) + ":" + calendar.get(Calendar.MINUTE) + ":" + calendar.get(Calendar.SECOND));
        doctor[] d = new doctor[25];
        patient[] p = new patient[100];
    
        int i;
        for (i = 0; i < 25; i++)
            d[i] = new doctor();
        for (i = 0; i < 100; i++)
            p[i] = new patient();        

        d[0].did = "21";
        d[0].dname = "Dr. Danendra";
        d[0].specilist = "Psycho";
        d[0].appoint = "5-11AM";
        d[1].did = "32";
        d[1].dname = "Dr. Sayak";
        d[1].specilist = "Physician";
        d[1].appoint = "10-3AM";
        d[2].did = "17";
        d[2].dname = "Dr. Srilekha";
        d[2].specilist = "Surgeon";
        d[2].appoint = "8-2AM";
        d[3].did = "33";
        d[3].dname = "Dr. Urbee";
        d[3].specilist = "Ortho";
        d[3].appoint = "10-4PM";

        Scanner input = new Scanner(System.in);
        int choice, j, c1, status = 1, s1 = 1, s2 = 1;
        while (status == 1)
        {
            System.out.println("\n                                    MAIN MENU");
            System.out.println("-----------------------------------------------------------------------------------");
            System.out.println("1. Doctors     2. Patients");
            System.out.println("-----------------------------------------------------------------------------------");
            System.out.println("Your Choice: ");
            choice = input.nextInt();
            switch (choice)
            {
                case 1:
                    {
                        System.out.println("--------------------------------------------------------------------------------");
                        System.out.println("                      **DOCTOR SECTION**");
                        System.out.println("--------------------------------------------------------------------------------");
                        s1 = 1;
                        while (s1 == 1)
                        {
                            System.out.println("1. Add New Entry\n2. Existing Doctors List");
                            System.out.println("Your Choice: ");
                            c1 = input.nextInt();
                            switch (c1)
                            {
                                case 1:
                                    {
                                        d[count1].new_doctor();count1++;
                                        break;
                                    }
                                case 2:
                                    {
                                        System.out.println("--------------------------------------------------------------------------------");
                                        System.out.println("ID \t Name\t Specilist \t Timing");
                                        System.out.println("--------------------------------------------------------------------------------");
                                        for (j = 0; j < count1; j++)
                                        {
                                            d[j].doctor_info();
                                        }
                                        break;
                                    }
                            }
                            System.out.println("\nReturn to Back Press 1 and for Main Menu Press 0");
                            System.out.println("Your Choice: ");
                            s1 = input.nextInt();
                        }
                        break;
                    }
                case 2:
                    {
                        System.out.println("--------------------------------------------------------------------------------");
                        System.out.println("                     **PATIENT SECTION**");
                        System.out.println("--------------------------------------------------------------------------------");
                        s2 = 1;
                        while (s2 == 1)
                        {
                            System.out.println("1. Add New Entry\n2. Existing Patients List");
                            System.out.println("Your Choice: ");
                            c1 = input.nextInt();
                            switch (c1)
                            {
                                case 1:
                                    {
                                        p[count2].new_patient();count2++;
                                        break;
                                    }
                                case 2:
                                    {
                                        System.out.println("-------------------------------------------------------------------------------------------------");
                                        System.out.println("ID\tName\tDisease\tGender\tAge\tBlood Pressure\tTemparature\tSocial security number");
                                        System.out.println("-------------------------------------------------------------------------------------------------");
                                        for (j = 0; j < count2; j++) {
                                            p[j].patient_info();
                                        }
                                        break;
                                    }
                            }
                            System.out.println("\nReturn to Back Press 1 and for Main Menu Press 0");
                            System.out.println("Your Choice: ");
                            s2 = input.nextInt();
                        }
                        break;
                    }
                default:
                    {
                        System.out.println("Invalid Input!!");
                    }
            }
            System.out.println("\nReturn to MAIN MENU Press 1");
            System.out.println("Your Choice: ");
            status = input.nextInt();
        }
    }
}

//Output:
//--------------------------------------------------------------------------------
//             *** Welcome to Hospital Information System ***
//--------------------------------------------------------------------------------
//Date: Apr 11 2021                                               Time: 0:38:32

//                                   MAIN MENU
//-----------------------------------------------------------------------------------
//1. Doctors     2. Patients
//-----------------------------------------------------------------------------------
//Your Choice:
//1
//--------------------------------------------------------------------------------
//                      **DOCTOR SECTION**
//--------------------------------------------------------------------------------
//1. Add New Entry
//2. Existing Doctors List
//Your Choice:
//2
//--------------------------------------------------------------------------------
//ID       Name    Specilist       Timing
//--------------------------------------------------------------------------------
//21      Dr. Danendra    Psycho          5-11AM
//32      Dr. Sayak       Physician       10-3AM
//17      Dr. Srilekha    Surgeon         8-2AM
//33      Dr. Urbee       Ortho           10-4PM

//--------------------------------------------------------------------------------
//               *** Welcome to Hospital Information System ***
//--------------------------------------------------------------------------------
//Date: Apr 11 2021                                               Time: 0:50:20

//                                    MAIN MENU
//-----------------------------------------------------------------------------------
//1. Doctors     2. Patients
//-----------------------------------------------------------------------------------
//Your Choice:
//2
//--------------------------------------------------------------------------------
//                     **PATIENT SECTION**
//--------------------------------------------------------------------------------
//1. Add New Entry
//2. Existing Patients List
//Your Choice:
//1
//name:-Ajay
//disease:-Anemia
//gender:-male
//age:-22
//blood_pressure:-90
//temparature:-98
//social security number:-999

//Return to Back Press 1 and for Main Menu Press 0
//Your Choice:
//1
//1. Add New Entry
//2. Existing Patients List
//Your Choice:
//1
//name:-Keya
//disease:-Pneumonia
//gender:-female
//age:-23
//blood_pressure:-87 
//temparature:-100
//social security number:-767

//Return to Back Press 1 and for Main Menu Press 0
//Your Choice:
//1
//1. Add New Entry
//2. Existing Patients List
//Your Choice:
//2
//-------------------------------------------------------------------------------------------------
//ID      Name    Disease Gender  Age     Blood Pressure  Temparature     Social security number
//-------------------------------------------------------------------------------------------------
//1       Ajay    Anemia  male    22      90      98      999
//2       Keya    Pneumonia       female  23      87      100     767

