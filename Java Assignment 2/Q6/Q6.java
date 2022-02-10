//Roll No: 001910501057
import java.util.*;

abstract class Person{
	private String name;
	public String getName() {
		return name;
	}
	public void setName(String n) {
		name=n;
	}
	
	private long phNo;
	public void setPhNo(long p) {
		phNo=p;
	}
	public long getPhNo() {
		return phNo;
	}
	
	private String email;
	public String getEmail() {
		return email;
	}
	public void setEmail(String e) {
		email=e;
	}
	
	private int premiseNo;
	private String street;
	private String city;
	private int pin;
	private String state;
	
	Person(String n,long ph,String e,int pn,String str,String c,int p,String st)
	{
		name=n;
		phNo=ph;
		email=e;
		premiseNo=pn;
		street=str;
		city=c;
		pin=p;
		state=st;
	}
	Person(){};
	
	public void getAdress() {
		System.out.println("PREMISE NUMBER = "+premiseNo);
		System.out.println("STREET= "+street);
		System.out.println("CITY = "+city);
		System.out.println("PIN = "+pin);
		System.out.println("STATE = "+state);
	}
	public void setAddress(int pn,String str,String c,int p,String st) {
		premiseNo=pn;
		street=str;
		city=c;
		pin=p;
		state=st;
	}	
}

class Student extends Person{
	private static int roll=0;
	public void setRoll(int r) {
		roll=r;
	}
	public int getRoll() {
		return roll;
	}
	
	private String course;
	public void setCourse(String c) {
		course=c;
	}
	public String getCourse() {
		return course;
	}
	
	public Student(String n,long ph,String e,int pn,String str,String ci,int p,String st,String c) {
		super(n,ph,e,pn,str,ci,p,st);
		course=c;
		roll++;
		System.out.println("ROLL OF THE STUDENT "+ roll);
	}	
	
	public void showDetails() {
		System.out.println("---STUDENT---");
		System.out.println("ROLL = "+roll);
		System.out.println("NAME = "+getName());
		System.out.println("COURSE = "+course);
		System.out.println("PHONE NUMBER = "+getPhNo());
		System.out.println("EMAIL = "+getEmail());
		System.out.println("ADDRESS = ");
		getAdress();
	}
	
	
}

class Faculty extends Person{
	private static int empId=0;
	public int getEmpId() {
		return empId;
	}
	
	private String dept;
	public void setDept(String d) {
		dept=d;
	}
	public String getDept() {
		return dept;
	}
	
	private String Specialisation;
	public void setSpecialisation(String s) {
		Specialisation=s;
	}
	public String getSpecialisation() {
		return Specialisation;
	}
	
	public Faculty(String n,long ph,String e,int pn,String str,String ci,int p,String st,String d,String s) {
		super(n,ph,e,pn,str,ci,p,st);
		dept=d;
		Specialisation=s;
		empId++;
		System.out.println("YOUR EMPLOYEE ID = "+empId);
	}
	
	public void showDetails() {
		System.out.println("---FACULTY---");
		System.out.println("EMPLOYEE ID = "+empId);
		System.out.println("NAME = "+getName());
		System.out.println("DEPARTMENT = "+dept);
		System.out.println("SPECIALISATION = "+Specialisation);
		System.out.println("PHON NUMBER = "+getPhNo());
		System.out.println("EMAIL = "+getEmail());
		System.out.println("ADDRESS = ");
		getAdress();
	}	
}

public class Q6{
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		ArrayList<Student> sl=new ArrayList<>();
		ArrayList<Faculty> fl=new ArrayList<>();
		
		Student s;
		Faculty f;
		
		while(true) {
			System.out.println("ENTER 1 TO ADD STUDENT ");
			System.out.println("ENTER 2 TO ADD FACULTY ");
			System.out.println("ENTER 3 TO CHANGE STUDENT'S ADDRESS ");
			System.out.println("ENTER 4 TO CHANGE FACULTY'S ADDRESS ");
			System.out.println("ENTER 5 TO SEE STUDENT'S DETAILS ");
			System.out.println("ENTER 6 TO SEE FACULTY'S DETAILS ");
			System.out.println("ENTER 7 TO EXIT ");
			System.out.print("YOUR CHOICE... ");
			
			int check=sc.nextInt();
			
			switch(check) {
			case 1:{
				sc.nextLine();
				System.out.println("ENTER NAME ");
				String n=sc.nextLine();
				System.out.println("ENTER PHONE NUMBER");
				long ph=sc.nextLong();
				sc.nextLine();
				System.out.println("ENTER EMAIL ");
				String e=sc.nextLine();
				sc.nextLine();
				System.out.println("ENTER ADDRESS: ");
				System.out.println("ENTER  PREMISE NUMBER ");
				int pn=sc.nextInt();
				sc.nextLine();
				System.out.println("ENTER STREET NAME ");
				String str=sc.nextLine();
				System.out.println("ENTER CITY NAME ");
				String ci=sc.nextLine();
				System.out.println("ENTER PIN ");
				int p=sc.nextInt();
				sc.nextLine();
				System.out.println("ENTER STATE ");
				String st=sc.nextLine();
				System.out.println("ENTER COURSE OF THE STUDENT ");
				String c=sc.nextLine();
				s=new Student(n,ph,e,pn,str,ci,p,st,c);
				sl.add(s);
				break;
			}

			case 2:{
				sc.nextLine();
				System.out.println("ENTER NAME ");
				String n=sc.nextLine();
				System.out.println("ENTER PHONE NUMBER");
				long ph=sc.nextLong();
				sc.nextLine();
				System.out.println("ENTER EMAIL ");
				String e=sc.nextLine();
				System.out.println("ENTER ADDRESS: ");
				System.out.println("ENTER  PREMISE NUMBER ");
				int pn=sc.nextInt();
				sc.nextLine();
				System.out.println("ENTER STREET NAME ");
				String str=sc.nextLine();
				System.out.println("ENTER CITY NAME ");
				String ci=sc.nextLine();
				System.out.println("ENTER PIN ");
				int p=sc.nextInt();
				sc.nextLine();
				System.out.println("ENTER STATE ");
				String st=sc.nextLine();
				System.out.println("ENTER DEPARTMENT OF THE EMPLOYEE ");
				String d=sc.nextLine();
				System.out.println("ENTER SPECIALISATION OF THE EMPLOYEE ");
				String sp=sc.nextLine();
				f=new Faculty(n,ph,e,pn,str,ci,p,st,d,sp);
				fl.add(f);
				break;			
			}
			
			case 3:{
			
				
				System.out.println("ENTER ROLL OF THE STUDENT ");
				int r=sc.nextInt();
				
				for(Student stemp:sl) {
					if(stemp.getRoll()==r) {
						System.out.println("ENTER ADDRESS: ");
						System.out.println("ENTER  PREMISE NUMBER ");
						int pn=sc.nextInt();
						sc.nextLine();
						System.out.println("ENTER STREET NAME ");
						String str=sc.nextLine();
						System.out.println("ENTER CITY NAME ");
						String ci=sc.nextLine();
						System.out.println("ENTER PIN ");
						int p=sc.nextInt();
						sc.nextLine();
						System.out.println("ENTER STATE ");
						String st=sc.nextLine();
						
						stemp.setAddress(pn,str,ci,p,st);
					}
					else System.out.println("STUDENT NOT FOUND IN THE DATABASE");
				}
				
				break;
			}
			
			case 4:{
			
				
				System.out.println("ENTER EMPLOYEE ID ");
				int eId=sc.nextInt();
				
				for(Faculty ftemp:fl) {
					if(ftemp.getEmpId()==eId) {
						System.out.println("ENTER ADDRESS: ");
						System.out.println("ENTER  PREMISE NUMBER ");
						int pn=sc.nextInt();
						sc.nextLine();
						System.out.println("ENTER STREET NAME ");
						String str=sc.nextLine();
						System.out.println("ENTER CITY NAME ");
						String ci=sc.nextLine();
						System.out.println("ENTER PIN ");
						int p=sc.nextInt();
						sc.nextLine();
						System.out.println("ENTER STATE ");
						String st=sc.nextLine();
						
						ftemp.setAddress(pn,str,ci,p,st);
					}
					else System.out.println("FACULTY NOT FOUND IN THE DATABASE");
				}
				
				break;
			}

			case 5:{
				System.out.println("ENTER ROLL OF THE STUDENT ");
				int r=sc.nextInt();
				
				boolean flag= false;
				for(Student stemp:sl) {
					if(stemp.getRoll()==r) {
						stemp.showDetails();
						flag= true;
						break;
					}
				}
				
				if(!false)
					System.out.println("STUDENT NOT FOUND IN THE DATABASE");
				break;
			}			
			
			case 6:{

				System.out.println("ENTER EMPLOYEE ID ");
				int eId=sc.nextInt();
				
				boolean flag=false;
				for(Faculty ftemp:fl) {
					if(ftemp.getEmpId()==eId) {
						ftemp.showDetails();
						flag=true;
						break;
					}
				
				}
				
				if(!flag)
					 System.out.println("FACULTY NOT FOUND IN THE DATABASE");
				break;
			}
			
			case 7:{
				return;
			}		
			}
			}
		}
	}

/*Output:
ENTER 1 TO ADD STUDENT 
ENTER 2 TO ADD FACULTY 
ENTER 3 TO CHANGE STUDENT'S ADDRESS 
ENTER 4 TO CHANGE FACULTY'S ADDRESS 
ENTER 5 TO SEE STUDENT'S DETAILS    
ENTER 6 TO SEE FACULTY'S DETAILS    
ENTER 7 TO EXIT 
YOUR CHOICE... 1
ENTER NAME 
Ajay
ENTER PHONE NUMBER
001
ENTER EMAIL 
ajay01@gmail.com

ENTER ADDRESS:        
ENTER  PREMISE NUMBER 
900
ENTER STREET NAME 
Lake Street
ENTER CITY NAME 
Kolkata
ENTER PIN 
700007
ENTER STATE 
West Bengal
ENTER COURSE OF THE STUDENT 
CSE
ROLL OF THE STUDENT 1
ENTER 1 TO ADD STUDENT 
ENTER 2 TO ADD FACULTY 
ENTER 3 TO CHANGE STUDENT'S ADDRESS 
ENTER 4 TO CHANGE FACULTY'S ADDRESS 
ENTER 5 TO SEE STUDENT'S DETAILS    
ENTER 6 TO SEE FACULTY'S DETAILS    
ENTER 7 TO EXIT 
YOUR CHOICE... 2
ENTER NAME 
Bijoy
ENTER PHONE NUMBER
002
ENTER EMAIL 
bijoy02@gmail.com
ENTER ADDRESS: 
ENTER  PREMISE NUMBER
200
ENTER STREET NAME 
Park Street
ENTER CITY NAME 
Kolkata
ENTER PIN 
700009
ENTER STATE 
West Bengal
ENTER DEPARTMENT OF THE EMPLOYEE 
ETCE
ENTER SPECIALISATION OF THE EMPLOYEE 
PhD
YOUR EMPLOYEE ID = 1
ENTER 1 TO ADD STUDENT
ENTER 2 TO ADD FACULTY
ENTER 3 TO CHANGE STUDENT'S ADDRESS
ENTER 4 TO CHANGE FACULTY'S ADDRESS
ENTER 5 TO SEE STUDENT'S DETAILS
ENTER 6 TO SEE FACULTY'S DETAILS
ENTER 7 TO EXIT
YOUR CHOICE... 5
ENTER ROLL OF THE STUDENT 
1
---STUDENT---
ROLL = 1
NAME = Ajay
COURSE = CSE
PHONE NUMBER = 1
EMAIL = ajay01@gmail.com
ADDRESS =
PREMISE NUMBER = 900
STREET= Lake Street
CITY = Kolkata
PIN = 700007
STATE = West Bengal
STUDENT NOT FOUND IN THE DATABASE
ENTER 1 TO ADD STUDENT
ENTER 2 TO ADD FACULTY
ENTER 3 TO CHANGE STUDENT'S ADDRESS
ENTER 4 TO CHANGE FACULTY'S ADDRESS
ENTER 5 TO SEE STUDENT'S DETAILS
ENTER 6 TO SEE FACULTY'S DETAILS
ENTER 7 TO EXIT
YOUR CHOICE... 6
ENTER EMPLOYEE ID 
1
---FACULTY---
EMPLOYEE ID = 1
NAME = Bijoy
DEPARTMENT = ETCE
SPECIALISATION = PhD
PHON NUMBER = 2
EMAIL = bijoy02@gmail.com
ADDRESS =
PREMISE NUMBER = 200
STREET= Park Street
CITY = Kolkata
PIN = 700009
STATE = West Bengal
*/