//Roll No: 001910501057
import java.util.*;

public class Q7{

	public static void main(String[] args)
	throws InterruptedException
	{
		// Object of a class that has both produce()
		// and consume() methods
		final PC pc = new PC();
	
		// Create producer thread
		Thread t1 = new Thread(new Runnable() {
			@Override
			public void run()
			{
				try {
					pc.produce();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});

		// Create consumer thread
		Thread t2 = new Thread(new Runnable() {
			@Override
			public void run()
			{
				try {
					pc.consume();
				}
				catch (InterruptedException e) {
					e.printStackTrace();
				}
			}
		});

		// Start both threads
		t1.start();
		t2.start();

		// t1 finishes before t2
		t1.join();
		t2.join();
	}

	// This class has a list, producer(adds items to list) and consumer(removes items).
	public static class PC {
		
		// Create a list shared by producer and consumer
		// Size of list is 2.
		LinkedList<Integer> list = new LinkedList<>();
		int capacity = 1;
		
		// Function called by producer thread
		public void produce() 
        throws InterruptedException
		{
			int value = 0;
			while (true) {
				synchronized (this)
				{
					// producer thread waits while list is full 
					while (list.size() == capacity)
						wait();
					System.out.println("Producer produced: "
									+ value);

					// to insert the jobs in the list
					list.add(value++);
					notify();
					Thread.sleep(1000);
				}
			}
		}

		// Function called by consumer thread
		public void consume() throws InterruptedException
		{
			while (true) {
				synchronized (this)
				{
					// consumer thread waits while list is empty		
					while (list.size() == 0)
						wait();

					// to retrive the ifrst job in the list
					int val = list.removeFirst();
					System.out.println("Consumer consumed: "
									+ val);
					notify();
					Thread.sleep(1000);
				}
			}
		}		
	}	
}

/*Output:

Producer produced-0
Producer produced-1
Consumer consumed-0
Consumer consumed-1
Producer produced-2
Producer produced-3
Consumer consumed-2
Consumer consumed-3
Producer produced-4
Producer produced-5
Consumer consumed-4
Consumer consumed-5
Producer produced-6
Producer produced-7
Consumer consumed-6
Consumer consumed-7
Producer produced-8
Producer produced-9
Consumer consumed-8
Consumer consumed-9
Producer produced-10
Producer produced-11
Consumer consumed-10
Consumer consumed-11

*/