import java.awt.*;
import java.awt.event.*;
import java.io.IOException;
import java.io.FileWriter;
public class Test 
{
	public void AWT_GUI()
	{
		//Enter the directory you wish to view the output
		String location = "C:/Users/jerin/Desktop/Resume_Information.txt";
		
		Frame f=new Frame();
		
		f.setTitle("Resume Details");
		
		//Components
		
		Label l0 = new Label("Enter the details:",Label.LEFT);
		l0.setBounds(25,50,300,40);
		l0.setFont(new Font("Times New Roman",Font.BOLD,20));
		f.add(l0);
		
		Font newFont1 = new Font("Times New Roman",Font.PLAIN,13);
		
		Label l1 = new Label("First Name:");
		l1.setBounds(25,100,125,20);
		l1.setFont(newFont1);
		f.add(l1);
		TextField t1 = new TextField();
		t1.setBounds(25,125,425,20);
		f.add(t1);
		
		Label l2 = new Label("Last Name:");
		l2.setBounds(25,165,125,20);
		l2.setFont(newFont1);
		f.add(l2);
		TextField t2 = new TextField();
		t2.setBounds(25,190,425,20);
		f.add(t2);
		
		Label l3 = new Label("Contact Number:");
		l3.setBounds(25,230,125,20);
		l3.setFont(newFont1);
		f.add(l3);
		TextField t3 = new TextField();
		t3.setBounds(25,255,425,20);
		f.add(t3);
		
		Label l4 = new Label("Home Address:");
		l4.setBounds(25,295,125,20);
		l4.setFont(newFont1);
		f.add(l4);
		TextArea t4 = new TextArea();
		t4.setBounds(25,320,425,80);
		f.add(t4);
		
		Label l5 = new Label("E-mail ID:");
		l5.setBounds(25,420,125,20);
		l5.setFont(newFont1);
		f.add(l5);
		TextField t5 = new TextField();
		t5.setBounds(25,445,425,20);
		f.add(t5);
		
		Label l6 = new Label("Date of Birth:");
		l6.setBounds(25,485,125,20);
		l6.setFont(newFont1);
		f.add(l6);
		TextField t6 = new TextField();
		t6.setBounds(25,510,25,20);
		f.add(t6);
		Choice c1 = new Choice();
		c1.add("January");
		c1.add("February");
		c1.add("March");
		c1.add("April");
		c1.add("May");
		c1.add("June");
		c1.add("July");
		c1.add("August");
		c1.add("September");
		c1.add("October");
		c1.add("November");
		c1.add("December");
		c1.setBounds(60,510,100,20);
		f.add(c1);
		Choice c2 = new Choice();
		c2.add("2005");
		c2.add("2004");
		c2.add("2003");
		c2.add("2002");
		c2.add("2001");
		c2.add("2000");
		c2.add("1999");
		c2.add("1998");
		c2.add("1997");
		c2.add("1996");
		c2.add("1995");
		c2.setBounds(170,510,100,20);
		f.add(c2);
		
		Label l7 = new Label("Educational Qualification:");
		l7.setBounds(25,550,200,20);
		l7.setFont(newFont1);
		f.add(l7);
		Choice t7 = new Choice();
		t7.add("High School(Still Studying)");
		t7.add("Under Graduate");
		t7.add("Under Graduate(Still Studying)");
		t7.add("Post Graduate");
		t7.add("PhD");
		t7.setBounds(25,575,425,20);
		f.add(t7);
		
		Label l8 = new Label("Other Achievements:");
		l8.setBounds(25,615,125,20);
		l8.setFont(newFont1);
		f.add(l8);
		TextField t8 = new TextField();
		t8.setBounds(25,640,425,20);
		f.add(t8);
		
		Button b = new Button("Submit");
		b.setBounds(200,680,80,30);
    		f.add(b);
		
    		//Frame Details
		f.setSize(500,725);
		Color newColor1 = new Color(97,226,167);
		f.setBackground(newColor1);
		f.setLayout(null);
		f.setResizable(false);
		f.setVisible(true);
		
		//Events
		
		b.addActionListener(new ActionListener() 
		{
			public void actionPerformed(ActionEvent e)
			{
				String s1 = "First Name: "+t1.getText();
				String s2 = "Last Name: "+t2.getText();
				String s3 = "Contact Number: "+t3.getText();
				String s4 = "Home Address: "+t4.getText();
				String s5 = "E-mail ID: "+t5.getText();
				String s6 = "Date of Birth: "+t6.getText()+" "+c1.getSelectedItem()+","+c2.getSelectedItem();
				String s7 = "Educational Qualification: "+t7.getSelectedItem();
				String s8 = "Other Achievements: "+t8.getText();
				
				//Writing data in text file
				FileWriter f1 = null;
				try
				{
					f1 = new FileWriter(location,true);
				}
				catch(IOException e1)
				{
					e1.printStackTrace();
				}
				try
				{
					f1.write("\n-----Resume Details-----\n\n");
					f1.write(s1+"\n");
					f1.write(s2+"\n");
					f1.write(s3+"\n");
					f1.write(s4+"\n");
					f1.write(s5+"\n");
					f1.write(s6+"\n");
					f1.write(s7+"\n");
					f1.write(s8+"\n");
				}
				catch(IOException e2)
				{
					e2.printStackTrace();
				}
				try
				{
					f1.close();
				}
				catch(IOException e3)
				{
					e3.printStackTrace();
				}
				
			}
		});
		
		f.addWindowListener(new WindowAdapter()
		{
			public void windowClosing(WindowEvent e)
			{
				f.dispose();
			}
		});
		
	}

	public static void main(String[] args) 
	{
		Test obj=new Test();
		obj.AWT_GUI();
	}

}
