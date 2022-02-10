//Roll No: 001910501057
package assignment_1;
import java.util.*;

public class Student {
	public static void main(String[] args) {
		int[] mdays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int[] ldays = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int ch, n;
		String d1;
		boolean lp, fg = true;
		Scanner in = new Scanner(System.in);
		StudentRecord[] students = new StudentRecord[6];
		Course co = new Course();
		System.out.println("Courses are available for Graduation, PG and PhD with 3,2 and 1 seats respectively.");
		System.out.println("Enter 'G' for Graduation, 'PG' for PG and 'PhD' for PhD");
		for (int i = 0; i < 6; i++)
			students[i] = new StudentRecord();
		String choice1 = "YES";
		int k = 0;
		do {

			System.out.println("\nEnter the course name: ");
			String S = in.next();
			if (co.getCourse(S).equals("XX")) {
				System.out.println("Invalid course:");
				continue;
			}
			if (co.getSeat(S) > co.getSeatLimit(S)) {
				System.out.println("Seats for the course " + S + " is exhausted:");
				continue;
			}
			System.out.println("Enter the Record for student :" + (k + 1));
			students[k].setCourse(S);
			students[k].inputData();
			k++;
			System.out.println("Do you want to add another record (yes/no):");
			choice1 = in.next();
		} while ("YES".equalsIgnoreCase(choice1));
		n = k;
		System.out.println("Enter 1 to display Records of all STUDENTS:");
		System.out.println("Enter 2 to see the result of all STUDENTS:");
		ch = in.nextInt();
		switch (ch) {
		case 1:
			for (int i = 0; i < n; i++)
				students[i].displayAll();
			break;
		case 2:
			for (int i = 0; i < n; i++)
				students[i].resultBuild();
			break;
		default:
			System.out.println("Wrong choice:");
			break;
		}
		System.out.println(" Do you want to search by Admission Date(dd/mm/yyyy)? yes/no:");
		String choice = in.next();
		if ("YES".equalsIgnoreCase(choice)) {
			int d = 0, m = 0, y = 0;

			do {
				fg = true;
				int i = 0;
				int j = 0;

				String temp = "";
				System.out.println("Enter the admission date(dd/mm/yyyy):");
				d1 = in.next();
				while (d1.charAt(i) != '/' && i < d1.length()) {
					if (0 <= d1.charAt(i) - 48 && d1.charAt(i) - 48 <= 9) {
						temp = temp + d1.charAt(i);
						i++;
						j++;
					} else {
						System.out.println("Incorrect format:");
						i++;
						fg = false;
						break;
					}
				} // d extraction
					// System.out.println("Temp="+temp+"I="+i+"J="+j+"fg="+fg);
				if (fg == true && j <= 2 && d1.charAt(i) == '/' && j > 0) {
					j = 0;
					d = Integer.valueOf(temp);
					i = i + 1;
					temp = "";
					while (d1.charAt(i) != '/' && i < d1.length()) {
						if (0 <= d1.charAt(i) - 48 && d1.charAt(i) - 48 <= 9) {
							temp = temp + d1.charAt(i);
							i++;
							j++;
						} else {
							System.out.println("Incorrect format:");
							i++;
							// j++;
							fg = false;
							break;
						}
					} // m extraction
					m = Integer.valueOf(temp);
				}
				// System.out.println("Temp="+temp+"I="+i+"J="+j+"fg="+fg);

				if (fg == true && j <= 2 && d1.charAt(i) == '/' && j > 0 && m <= 12 && 1 <= m) {
					j = 0;
					// m = Integer.valueOf(temp);
					// System.out.println(d);
					i = i + 1;
					temp = "";
					while (i < d1.length()) {
						if (0 <= d1.charAt(i) - 48 && d1.charAt(i) - 48 <= 9) {
							temp = temp + d1.charAt(i);
							i++;
							j++;
						} else {
							System.out.println("Incorrect format:");
							fg = false;
							i++;
							break;
							// j++;

						}
					} // y extraction
				}
				// System.out.println("Temp="+temp+"I="+i+"J="+j+"fg="+fg);
				if (fg == true && j == 4) {
					y = Integer.valueOf(temp);
					fg = true;
				} // end of else of y
				else
					fg = false;
				if (fg == true) {
					if (y % 400 == 0)
						lp = true;
					else if (y % 100 == 0)
						lp = false;
					else if (y % 4 == 0)
						lp = true;
					else
						lp = false;

					if (lp == false) {
						if (d > mdays[m - 1] || d < 1) {
							System.out.println("Invalid d of a m:");
							fg = false;
						}
					} // non-lp y checking
					else {
						if (d > ldays[m - 1] || d < 1) {
							System.out.println("Invalid d of a m:");
							fg = false;
						}
					} // lp y checking
				} // checking for vaild date in months
			} while (fg == false);
			d1 = "";
			d1 = d + "/" + m + "/" + y;
			for (int i = 0; i < n; i++) {
				if (students[i].searchByAdmissionDate().equals(d1))
					students[i].displayAll();
			}

		}

		in.close();
	}
}

class Course {
	Course() {
		seats = new int[3];
		seats[0] = 0;
		seats[1] = 0;
		seats[2] = 0;
	}

	public String getCourse(String S) {
		for (int i = 0; i < 3; i++)
			if (S.equalsIgnoreCase(course[i])) {
				seats[i]++;
				return course[i];
			}
		return "XX";
	}

	public int getSeat(String S) {
		for (int i = 0; i < 3; i++) {
			if (S.equalsIgnoreCase(course[i]))
				return seats[i];
		}
		return -9;
	}

	public int getSeatLimit(String S) {
		for (int i = 0; i < 3; i++) {
			if (S.equalsIgnoreCase(course[i]))
				return fixSeat[i];
		}
		return -9;
	}

	private static String[] course = { "G", "PG", "PhD" };
	private static int[] fixSeat = { 3, 2, 1 };
	private int[] seats;
}

class StudentRecord {

	StudentRecord() {
		roll = 0;
		name = "";
		co = "";
		for (int i : marks)
			marks[i] = 0;
	}

	public String searchByAdmissionDate() {
		return (dte);
	}

	public void resultBuild() {
		int sum = 0;
		System.out.println("Name :" + name);
		System.out.println("Course :" + co);
		System.out.println("Roll Number :" + roll);
		System.out.println("------------------------------------------");
		for (int i = 0; i < 5; i++) {
			System.out.println("Subject " + (i + 1) + " " + marks[i]);
			sum += marks[i];
		}
		System.out.println("Total Marks: " + sum);
		System.out.println("Percentage: " + sum / 5);
		System.out.println("");
	}

	public void inputData() {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the name:");
		name = in.nextLine();
		System.out.println("Enter the roll number:");
		roll = in.nextInt();
		do {
			flag = true;
			int i = 0;
			int j = 0;
			String temp = "";
			System.out.println("Enter the admission date(dd/mm/yyyy):");
			dte = in.next();
			while (dte.charAt(i) != '/' && i < dte.length()) {
				if (0 <= dte.charAt(i) - 48 && dte.charAt(i) - 48 <= 9) {
					temp = temp + dte.charAt(i);
					i++;
					j++;
				} else {
					System.out.println("Incorrect format:");
					i++;
					flag = false;
					break;
				}
			} // day extraction
				// System.out.println("Temp="+temp+"I="+i+"J="+j+"flag="+flag);
			if (flag == true && j <= 2 && dte.charAt(i) == '/' && j > 0) {
				j = 0;
				day = Integer.valueOf(temp);
				i = i + 1;
				temp = "";
				while (dte.charAt(i) != '/' && i < dte.length()) {
					if (0 <= dte.charAt(i) - 48 && dte.charAt(i) - 48 <= 9) {
						temp = temp + dte.charAt(i);
						i++;
						j++;
					} else {
						System.out.println("Incorrect format:");
						i++;
						// j++;
						flag = false;
						break;
					}
				} // month extraction
				month = Integer.valueOf(temp);
			}
			// System.out.println("Temp="+temp+"I="+i+"J="+j+"flag="+flag);

			if (flag == true && j <= 2 && dte.charAt(i) == '/' && j > 0 && month <= 12 && 1 <= month) {
				j = 0;
				// month = Integer.valueOf(temp);
				// System.out.println(day);
				i = i + 1;
				temp = "";
				while (i < dte.length()) {
					if (0 <= dte.charAt(i) - 48 && dte.charAt(i) - 48 <= 9) {
						temp = temp + dte.charAt(i);
						i++;
						j++;
					} else {
						System.out.println("Incorrect format:");
						flag = false;
						i++;
						break;
						// j++;

					}
				} // year extraction
			}
			// System.out.println("Temp="+temp+"I="+i+"J="+j+"flag="+flag);
			if (flag == true && j == 4) {
				year = Integer.valueOf(temp);
				flag = true;
			} // end of else of year
			else
				flag = false;
			if (flag == true) {
				if (year % 400 == 0)
					leap = true;
				else if (year % 100 == 0)
					leap = false;
				else if (year % 4 == 0)
					leap = true;
				else
					leap = false;

				if (leap == false) {
					if (day > mdays[month - 1] || day < 1) {
						System.out.println("Invalid day of a month:");
						flag = false;
					}
				} // non-leap year checking
				else {
					if (day > ldays[month - 1] || day < 1) {
						System.out.println("Invalid day of a month:");
						flag = false;
					}
				} // leap year checking
			} // checking for vaild date in months
		} while (flag == false);
		dte = "";
		dte = day + "/" + month + "/" + year;
		System.out.println("Enter the marks:");
		for (int i = 0; i < 5; i++) {
			System.out.println("Enter the marks in Subject " + (i + 1));
			marks[i] = in.nextInt();
		}
	}

	public void setCourse(String S) {
		co = S;
	}

	public void displayAll() {
		System.out.println("Roll No. = " + roll + " Name= " + name + " Course =" + co);
		System.out.println("Admission date: " + dte);
		for (int i = 0; i < 5; i++) {
			System.out.println("Marks in Subject " + (i + 1) + "= " + marks[i]);
		}
		System.out.println("");
	}

	private int roll;
	private String name;
	private String co;
	private String dte;
	private boolean flag = true;
	private boolean leap;
	private int day;
	private int month;
	private int year;
	int[] marks = new int[5];
	int[] mdays = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int[] ldays = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
}

//Output:
//Courses are available for Graduation, PG and PhD with 3,2 and 1 seats respectively.
//Enter 'G' for Graduation, 'PG' for PG and 'PhD' for PhD

//Enter the course name: 
//g
//Enter the Record for student :1
//Enter the name:
//Ajay
//Enter the roll number:
//04
//Enter the admission date(dd/mm/yyyy):
//23/09/2020
//Enter the marks:
//Enter the marks in Subject 1
//90
//Enter the marks in Subject 2
//98
//Enter the marks in Subject 3
//97
//Enter the marks in Subject 4
//97
//Enter the marks in Subject 5
//91
//Do you want to add another record (yes/no):
//yes

//Enter the course name:
//PG
//Enter the Record for student :2
//Enter the name:
//Bijoy
//Enter the roll number:
//02
//Enter the admission date(dd/mm/yyyy):
//21/07/2020 
//Enter the marks:
//Enter the marks in Subject 1
//90
//Enter the marks in Subject 2
//91
//Enter the marks in Subject 3
//92
//Enter the marks in Subject 4
//93
//Enter the marks in Subject 5
//97
//Do you want to add another record (yes/no):
//98
//Enter 1 to display Records of all STUDENTS:
//Enter 2 to see the result of all STUDENTS:
//1
//Roll No. = 4 Name= Ajay Course =g
//Admission date: 23/9/2020
//Marks in Subject 1= 90
//Marks in Subject 2= 98
//Marks in Subject 3= 97
//Marks in Subject 4= 97
//Marks in Subject 5= 91

//Roll No. = 2 Name= Bijoy Course =PG
//Admission date: 21/7/2020
//Marks in Subject 1= 90
//Marks in Subject 2= 91
//Marks in Subject 3= 92
//Marks in Subject 4= 93
//Marks in Subject 5= 97

//Do you want to search by Admission Date(dd/mm/yyyy)? yes/no:
//no