import java.util.*;
public class ProducerConsumer 
{
	public static LinkedList<Integer> storage = new LinkedList<>();
	public static int capacity;
	public void Produce() throws InterruptedException
	{
		while(true)
		{
			Random randomize = new Random();
			synchronized(this)
			{
				while(storage.size()==capacity)
				{
					wait();
				}
				int value=randomize.nextInt(50);
				storage.add(value);
				System.out.println("Producer Produced Value: "+value);
				notify();
				Thread.sleep(10000);
				
				
			}
		}
		
	}
	public void Consume() throws InterruptedException
	{
		while(true)
		{
			synchronized(this)
			{
				while(storage.size()==0)
				{
					wait();
				}
				int value=storage.removeFirst();
				System.out.println("Consumer Consumed Value: "+value);
				notify();
				Thread.sleep(10000);
				
				
			}
		}
		
	}
	public static void main(String[] args) throws InterruptedException
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the capacity of the storage");
		capacity = input.nextInt();
		ProducerConsumer obj=new ProducerConsumer();
		Thread t1=new Thread(new Runnable()
				{
					public void run()
					{
						try 
						{
							obj.Produce();
						}
						catch(InterruptedException e1)
						{
							e1.printStackTrace();
						}
					}
				});
		Thread t2=new Thread(new Runnable()
		{
			public void run()
			{
				try 
				{
					obj.Consume();
				}
				catch(InterruptedException e2)
				{
					e2.printStackTrace();
				}
			}
		});
		t1.start();
		t2.start();
		t1.join();
		t2.join();
	}
}
