import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
public class ByteStream
{

	public static void main(String[] args) 
	{
		//Enter the directory you wish to view the output
		int ch;
		String inputLocation = "Input.txt";
		String outputLocation = "Output.txt";
		FileInputStream f1 = null;
		FileOutputStream f2 = null;
		try
		{
			f1=new FileInputStream(inputLocation);
			f2=new FileOutputStream(outputLocation);
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
