//A program to implement a Circular Queue using an array.
//A circular Queue sacrifices a memory location to use all the other
locations optimally.
import java.io.*;
class CircularQueue   {   //A class to represent the data structure of
Circular Queue.
  int front=-1,rear=-1,n=5;
  Object arr[]=new Object[n];
  CircularQueue()
  {

  }
  void insert(Object val)  //A method to insert an element into the
Circular Queue.
  {
          if(front==(rear+1)%n)//Checking if the circular queue is full.
           System.out.println("Queue full...\nCannot Insert...");
          else  //If not full, inserting the element.
          {
                  if(front==-1)
                  {
                    front++;
                    rear++;
                  }
                  arr[rear]=val;
                  rear=(rear+1)%n;
                  System.out.println("Inserted successfully...!!");
          }
  }
  Object delete()  //A method to delete an element from the Circular Queue.
  {
          if(rear==front)  //Checking if the Queue is empty or not.
                return (Object)null;
          else  //If the Queue is not empty, then removing an element.
          {
                  Object val=arr[front];
                  front=(front+1)%10;
                  return val;
          }
  }
}
class ImplementCircularQueue  {  //A class to implement the circular queue.
public static void main(String args[])
  {
  CircularQueue s=new CircularQueue();  //An instance of the circular Queue.
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader br = new BufferedReader(isr);
    try
  {
               do
             {
                System.out.println("1)Insert\n2)Delete\n3)Exit");  //A
user friendly menu.
                int ch=Integer.parseInt(br.readLine());
                switch(ch)
                {
                   case 1:  //Insert operation is being implemented in
the Circular Queue.
                          System.out.println("Enter the element to Insert:");
                          s.insert((Object)br.readLine());
                          break;
                   case 2://Delete operation is being implemented in
the Circular Queue.
                          Object o=s.delete();
                          if(o!=null)
                                {
                                        System.out.print("Deleted
Successfully!!...\nThe data removed is: ");
                                        System.out.println(o);
                                }
                          else
                               System.out.println("Queue
empty...!!\nCannot delete...");
                          break;
                   case 3:
                          System.exit(0);
                   default:
                          System.out.println("Invalid Choice!!...");

                }
             }while(true);
                 }
                catch(Exception e)  //Catching all the exceptions
                {
                        System.out.println(e);
                }
  }
}