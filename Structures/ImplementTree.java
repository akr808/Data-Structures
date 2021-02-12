import java.io.*;  //Import the Input Output package
class Node   {  //A class Node to represent an element of the tree.
Node left,right;  //A Binary search tree has two branches-Left branch and right branch.
int data;
}


class BinaryTree   {  //A class to Implement the basic functions of a binary tree.
int val=0;
Node  insert(Node val,Node link)  //A recursive method to insert an element into the tree.
     {
        if(link!=null)
         {
         if(link.data>val.data)
             {
               if(link.left==null)
                   link.left=val;
               else
                   insert(val,link.left);
             }
          else if(link.data<val.data)
            {
               if(link.right==null)
                   link.right=val;
               else
                insert(val,link.right);
            }
          else
             {
              System.out.println("Numbers can't be equal....\nError...");
              System.exit(0);
             }
        }
        return link;
     }
      Node insertNode(int val,Node link)//The  main method calls the insert() method through this method.
     {
       Node n= new Node();
       n.data=val;
       if(link!=null)
              return(insert(n,link));
       else
            {
                n.data=val;
                return n;
            }
     }
     //The following three methods are used to traverse the tree.
    
   void preorder(Node link)  //A method to traverse the tree in preorder.
      {
        if(link!=null)
         {
                System.out.println(link.data);
                preorder(link.left);
                preorder(link.right);
         }
      }
   void inorder(Node link)  //A method to traverse the tree in inorder.
      {
        if(link!=null)
            {
                inorder(link.left);
                System.out.println(link.data);
                inorder(link.right);
            }
      }
   void postorder(Node link)  //A method to traverse the tree in postorder.
      {
        if(link!=null)
           {
                postorder(link.left);
                postorder(link.right);
                System.out.println(link.data);
           }
      }
   
   Node deleteNode(Node link,int del)
      {
          Node p1,p2;
          if(link!=null)
          {
          if(link.data==del)
          {
              if(link.left==link.right)
                        return null;
              else if(link.left==null)
              {
                  p1=link.right;
                  return p1;
              }
              else if(link.right==null)
              {
                  p1=link.left;
                  return p1;
              }
              else
              {
                  p2=link.right;
                  p1=link.right;
                  while(p1.left!=null)
                    p1=p1.left;
                  p1.left=link.left;
                  return p2;
              }
          }
          if(link.data<del)
            link.left=deleteNode(link.right,del);
          else
            link.left=deleteNode(link.left,del);
        }
        else
                System.out.println("Deletion failed!!\nData not found!!...");
        return link;
      }
}

class ImplementTree  {  // A class to implement the tree and its properties.
public static void main(String args[])  //The main method.
   {
     InputStreamReader isr=new InputStreamReader(System.in);
     BufferedReader br=new BufferedReader(isr);
      Node start=null;
     try  //The 'try' block.
     {
     BinaryTree bst=new BinaryTree();
     int ch=0,c=0;
       do  //A use friendly menu to do as per the users requirement.
         {
           System.out.println("1)Insert\n2)Traverse\n3)Delete\n4)Exit");
           ch=Integer.parseInt(br.readLine());
           switch(ch)
             {
               case 1:
                   int val;
                   System.out.println("Enter the data to add to the tree:");
                        val=Integer.parseInt(br.readLine());
                        start=bst.insertNode(val,start);
                        break;
               case 2:
                    if(start==null)
                                     {
                                            System.out.println("Tree Empty!!...");
                                            break;
                                     }
                     do
              {

                System.out.println("1)Preorder traversal\n2)Inorder Traversal\n3)Postorder traversal\n4)Exit ot main menu");
                        c=Integer.parseInt(br.readLine());
                        switch(c)
                           {
                              case 1:
                                        System.out.println("Preorder Traversal:");
                                        bst.preorder(start);
                                        break;
                              case 2:
                                        System.out.println("Inorder Traversal:");
                                        bst.inorder(start);
                                        break;
                              case 3:
                                        System.out.println("Postorder Traversal:");
                                        bst.postorder(start);
                                        break;
                              case 4:
                                        break;
                              default:
                                System.out.println("Invalid choice");
                           }
                        if(c==4)
                             break;
                      }while(c!=4);
                      break;
                case 3:
                        if(start!=null)
                        {
                            System.out.println("Enter the value to delete:-");
                            int del=Integer.parseInt(br.readLine());
                            start=bst.deleteNode(start,del);
                            break;
                        }
                        else
                            System.out.println("No tree to delete...");
                case 4:
                        break;
             }
         }while(ch!=4);

    }
    catch(Exception e)  //The 'catch' block.
        {
                System.out.println(e);
        }
   }
 }