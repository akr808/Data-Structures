import java.io.*;  //Package Import.
class Node  {  //A class to represent a single node of a doubly linked list.
Node next;
Node prev;
Object Data;
  Node(Object val)
  {
          Data=val;
  }

}

class DoublyLinedList  {  //A class to implement the functions of a
doubly linked list.
        DoublyLinedList()
        {
        }
Node start=null;

int insert(Object val,int pos)  //A method to insert into a Doubly linked list.
{
        Node link=start;
        if(start!=null)
        {
                if(pos!=1)
                pos--;
        else
                {
                        Node n = new Node(val);
                        n.next = start;
                        start=n;
                        n.prev = null;
                        return 1;
                }
                while(pos>1&&link.next!=null)
                {
                        if(link.next!=null)
                        {
                                pos--;
                                link=link.next;         
                        }
                        else
                           break;

                }
                if((link.next==null&&pos==2)||pos==1)
                {
                        Node n = new Node(val);
                        if(link.next!=null)
                        {
                                n.prev = link.next.prev;
                                n.next = link.next;
                                link.next = n;
                                n.next.prev = n;
                                return 1;
                        }
                        else
                        {
                                link.next = n;
                                n.prev = link;
                                return 1;
                        }
                }
                else
                        return 0;
        }
        else
        {
                Node n = new Node(val);
                n.next=null;
                n.prev=null;
                start = n;
                return 1;
        }

}
Object delete(int pos) //A method to delete from a Doubly Linked List.
{
        pos--;
        Node link = start;
        while(pos>0&&link!=null)
        {
                if(link.next!=null)
                        {
                                link=link.next;
                                pos--;
                        }
                else
                        break;

        }
        if(pos>0)
                return (Object)null;
        else
        {
                Object data = link.Data;
                if(start!=link)
                {
                        link.prev.next = link.next;
                        link.next.prev = link.prev;
                }
                else
                        start=link.next;
                return data;
        }
}
void print()  //A method to print the current list at any instance.
{
        Node link = start;
        System.out.println("The current list contains the following elements:");
        while(link!=null)
        {
                System.out.println(link.Data);
                link=link.next;
        }
}
}

class Dlink {  //A Class to implement the Doubly Linked List.
public static void main(String args[])
 {
         InputStreamReader isr = new InputStreamReader(System.in);
         BufferedReader br = new BufferedReader(isr);
         DoublyLinedList dl;
         int pos=0;
         try
         {
                        dl = new DoublyLinedList();
                    do
             {
                System.out.println("1)Insert\n2)Delete\n3)Print List\n4)Exit");
                int ch=Integer.parseInt(br.readLine());  //A user friendly menu.
                switch(ch)
                {
                   case 1:  //Insert operation is being implemented in the Doubly Linked List.
                                                  System.out.println("Enter the Data to insert:");
                                                  Object data = br.readLine(); 
                                                  System.out.println("Enter the position at which to insert:");
                                                  pos = Integer.parseInt(br.readLine());
                                                  pos=dl.insert(data,pos);
                                                  if(pos==1)
                                                  {
                                                          System.out.println("Inserted successfully!!...");
                                                          dl.print();
                                                  }
                                                  else
                                                        System.out.println("Insertion failed!!...");
                          break;
                   case 2://Delete operation is being implemented in the Doubly Linked List.
                          System.out.println("Enter the location of the data to delete");
                          pos = Integer.parseInt(br.readLine());
                          Object del=dl.delete(pos);
                          if(del==null)
                                                                System.out.println("Invalid Location");
                                                  else
                                                  {
                                                          System.out.println("Deleted Successfully!!...");
                                                          System.out.println("The deleted Data is:"+del);
                                                          dl.print();
                                              }
                          break;
                   case 3://The list is being printed on request.
                                                  dl.print();
                                                  break;
                   case 4:
                          System.exit(0);
                   default:
                          System.out.println("Invalid Choice!!...");

                }
             }while(true);
         }
         catch(Exception e)
         {
                 System.out.println(e);
         }
 }

}