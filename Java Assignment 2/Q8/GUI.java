//Roll No: 001910501057
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class GUI{
	static ArrayList<Employee> 
	e=new ArrayList<Employee>();
	static JFrame jf;
	static JButton b7;
	static JComboBox cb;
	static JPanel jp1,jp2,jp3,jp4,jp5,jp6,jp7;
	static JLabel l1,l2,l3,l4,l5,l6;
    static JTextField tf7,tf1,tf2,tf3,tf4,tf5,tf6;

	public static void main(String[] args) {
		JFrame j=new JFrame();
		JPanel jp=new JPanel();
		jp.setSize(1000,1000);
		j.setSize(1920,1080);
		JButton b1=new JButton("Enter new Employee Details");
		b1.addActionListener(new ListenerNewEmployee());
		jp.add(b1);
		j.add(jp);
		JButton b2=new JButton("Show Employee Details");
		b2.addActionListener(new showListener1());
		jp.add(b2);
		j.add(jp,BorderLayout.CENTER);
		j.setVisible(true);
	}

	static class showListener1 implements ActionListener{
		public void actionPerformed(ActionEvent z) {
			jf=new JFrame();
			JPanel jp=new JPanel();
			//JPanel jp2=new JPanel();
			jf.setSize(1000,500);
			tf7=new JTextField(50);
			jp.add(tf7);
			jf.add(jp);
			b7=new JButton("SEARCH (by Empcode)");
			b7.addActionListener(new showListener2());
			jp.add(b7);
			jf.add(jp);
			jf.setVisible(true);
		}
	}
	
	static class showListener2 implements ActionListener{
		public void actionPerformed(ActionEvent z) {
			int u=0;
			for(Employee x:e)
			{
				if(x.ecode.equals(tf7.getText()))
				{
					jf=new JFrame();
					JPanel jp=new JPanel();
					jf.setSize(1000,100);
					JLabel jl1,jl2,jl3,jl4,jl5;
					jl1=new JLabel("Name: "+x.name);
					jl2=new JLabel("Employee Code: "+x.ecode);
					jl3=new JLabel("Salary: "+x.salary);
					jl4=new JLabel("Grade: "+x.dcode);
					jl5=new JLabel("Department Code: "+x.grade);
					jp.add(jl1);jp.add(jl2);jp.add(jl3);jp.add(jl4);jp.add(jl5);
					jf.add(jp);
					jf.setVisible(true);
					u++;
					break;
				}
			}
			if(u==0)
			{
				JOptionPane.showMessageDialog(null, "Invalid Employee Code","Error Message",JOptionPane.ERROR_MESSAGE);
			}
		}
	}
	
	static class ListenerNewEmployee implements ActionListener{
		public void actionPerformed(ActionEvent z) {
			JFrame j=new JFrame();			
			j.setLayout(new FlowLayout());
			jp1=new JPanel();
			l1=new JLabel("Name");
			jp1.add(l1);
			tf1=new JTextField(100);
			jp1.add(tf1);
			j.add(jp1);			
			jp2=new JPanel();
			l2=new JLabel("Employee Code");
			jp2.add(l2);
			tf2=new JTextField(100);
			jp2.add(tf2);
			j.add(jp2);			
			jp3=new JPanel();
			l3=new JLabel("Basic Salary");
			jp3.add(l3);
			tf3=new JTextField(100);
			jp3.add(tf3);
			j.add(jp3);			
			jp4=new JPanel();
			String [] s= {"Officer","Assistant Manager","Branch Manager","Chief Manager","Assistant General Manager"};
			cb=new JComboBox(s);
			cb.setEditable(false);
			cb.setBorder(BorderFactory.createTitledBorder("Choose Department"));
			jp4.add(cb);
			j.add(jp4);		
			jp5=new JPanel();
			l5=new JLabel("Grade(A/B/C)");
			jp5.add(l5);
			tf5=new JTextField(100);
			jp5.add(tf5);
			j.add(jp5);			
			j.setSize(1900,1900);
			j.setVisible(true);		
			jp6=new JPanel();
			JButton jb1=new JButton("Save");
			jb1.addActionListener(new save());
			JButton jb2=new JButton("Clear");
			jp6.add(jb1);jp6.add(jb2);
			j.add(jp6);
		}
	}

	static class save implements ActionListener{
		public void actionPerformed(ActionEvent z) {
			int u=0;
			for(Employee x:e)
			{
				if(x.ecode.equals(tf2.getText()))
				{u++;break;}
			}
			if(u==1)
			{
				JOptionPane.showMessageDialog(null, "Invalid Employee Code","Error Message",JOptionPane.ERROR_MESSAGE);
			}
			else
			{
				if(0==JOptionPane.showConfirmDialog(null, "Do you want to continue?","Confirmation",JOptionPane.YES_OPTION))
				{
					Employee emp=new Employee(tf1.getText(),tf2.getText(),tf3.getText(),(String)cb.getSelectedItem(),tf5.getText());
					e.add(emp);
				}
			}
		}
	}
}
 
 class Employee{
	String name;
	String ecode;
	int salary;
	String grade;
	String dcode;
	Employee(String a,String b,String c,String d,String e)
	{
		name=a;
		ecode=b;
		salary=Integer.parseInt(c);
		grade=d;
		dcode=e;
	}
}

