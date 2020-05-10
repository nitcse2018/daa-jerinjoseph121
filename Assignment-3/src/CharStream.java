import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class CharStream 
{

	public static void main(String[] args) 
	{
		//Enter the directory you wish to view the output
		int ch;
		String inputLocation = "Input.txt";
		String outputLocation = "Output.txt";
		FileReader f1 = null;
		FileWriter f2 = null;
		try
		{
			f1=new FileReader(inputLocation);
			f2=new FileWriter(outputLocation);
			while((ch=f1.read())!=-1)
				f2.write(ch);
			f1.close();
			f2.close();
		}
		catch(IOException e)
		{
			e.printStackTrace();
		}

	}

}
