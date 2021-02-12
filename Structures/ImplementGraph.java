import java.io.*;
class LinkList   {  //This class represents an element of a linked list.
int data;
LinkList next;
}

class Edge  {
        int weight,start,end;
        void assign(int start,int end,int weight)
        {
                this.weight = weight;
                this.start = start;
                this.end = end;
        }
}
class Vertex  {  //This class represents a vertex of the Graph.
String weight;
boolean isVisited;
  Vertex(String weight)
  {
  this.weight = weight;
  isVisited = false;
  }
  void printVertex()
  {
    System.out.println(weight);
  }
}
class LinkedQueue   {  //A class to implement a Queue using a linked list.
    LinkList start=null;
    void insert(int val)  // A method to insert into the Queue.
    {
        LinkList l= new LinkList();
        if(l==null)
            {
                    System.out.println("Memory allocation failed!...\nProgram cannot proceed...");
                    System.exit(0);
            }
        l.next=start;
        l.data=val;
        start=l;
    }
    int remove()  // A method to remove into the Queue.
    {
        if(start!=null)
        {
            if(start.next!=null)
            {
                int val;
                LinkList temp=start;
                while(temp.next.next!=null)
                temp=temp.next;
                val=temp.next.data;
                temp.next=null;
                return val;
            }
            else
            {
                int val=start.data;
                start=null;
                return val;
            }
        }
        else
            return -1;
    }
}

class Graph   {   //A class to represent a Graph.
    int vertexCount,vertexUsed,Edgecount,ListCount;
    Vertex v[];  //A list of vertexes of the Graph.
    boolean Matrix[][]; //Represents the Adjacency Matrix.
    Edge e[];
    int EdgeMatrix[][];
    int ListVertex[];
    Graph(int vertexCount)  //The Constructor.
    {
       this.vertexCount = vertexCount;
       v = new Vertex[vertexCount];
       vertexUsed = 0;
       Matrix = new boolean[vertexCount][vertexCount];
       e  = new Edge[2*vertexCount];
       EdgeMatrix = new int[vertexCount][vertexCount];
       ListVertex = new int[vertexCount];
    }
    int addVertex(String weight)  //A method to add a Vertex to the Graph.
    {
        if(vertexUsed<vertexCount)
        {
            v[vertexUsed] = new Vertex(weight);
            vertexUsed++;
            return 1;
        }
        return 0;
    }
    boolean addEdge(int start, int end,int weight)  //A method to add an Edge to the Graph.
    {
        if(Matrix[start][end] == true)
            return false;
        Matrix[start][end] = true;
        Matrix[end][start] = true;
        e[Edgecount] = new Edge();
        e[Edgecount++].assign(start,end,weight);
        EdgeMatrix[start][end] = weight;
        EdgeMatrix[end][start] = weight;
        return true;
    }
    boolean removeEdge(int start,int end)  //A method to remove an Edge from the Graph.
    {
        if(Matrix[start][end] == false)
            return false;
        Matrix[start][end] = false;
        Matrix[end][start] = false;
        return true;
    }

    void removeVertex(int location)  //A method to remove a Vertex from the Graph.
    {
        for(int i = location;i<vertexUsed;i++)
            v[i] = v[i+1];
        for(int i = location;i<vertexUsed;i++)
            {
                for(int j = 0;j<vertexUsed;j++)
                    Matrix[i][j] = Matrix[i+1][j];
            }
        for(int i = location;i<vertexUsed;i++)
            {
                for(int j = 0;j<vertexUsed;j++)
                    Matrix[j][i] = Matrix[j][i+1];
            }
        vertexUsed--;
    }
    void printMatrix()  //A method to print the Adjacency Matrix.
    {
        for(int i = -2;i<vertexUsed;i++)
        {
                        if( i == -1)
                        {
                                for(int j = 0;j<vertexUsed*6;j++)
                                {
                                        if(j == 0)
                                                System.out.print("\t\t");
                                        System.out.print("-");
                                }
                                System.out.println("\n\n");
                                continue;
                        }
            for(int j = 0;j<vertexUsed;j++)
            {
                                if(i == -2)
                                {
                                        if(j == 0)
                                                System.out.print("*\t\t");
                                        System.out.print(v[j].weight+"\t");
                                }
                                else
                                {
                                        if(j == 0)
                                                System.out.print(v[i].weight+"\t|\t");                         
                                        if(Matrix[i][j] == true)
                                                System.out.print("1\t");
                                        else
                                                System.out.print("0\t");
                                }
            }
            if(i>=0)
            System.out.println("\n\t|\n");
            else
            System.out.println("\n");
        }
    }
    void printEdge()  //A method to print the Adjacency Matrix.
    {
        for(int i = -2;i<vertexUsed;i++)
        {
                        if( i == -1)
                        {
                                for(int j = 0;j<vertexUsed*6;j++)
                                {
                                        if(j == 0)
                                                System.out.print("\t\t");
                                        System.out.print("-");
                                }
                                System.out.println("\n\n");
                                continue;
                        }
            for(int j = 0;j<vertexUsed;j++)
            {
                                if(i == -2)
                                {
                                        if(j == 0)
                                                System.out.print("*\t\t");
                                        System.out.print(v[j].weight+"\t");
                                }
                                else
                                {
                                        if(j == 0)
                                                System.out.print(v[i].weight+"\t|\t");                         
                                        if(Matrix[i][j] == true)
                                                System.out.print(EdgeMatrix[i][j]+"\t");
                                        else
                                                System.out.print(EdgeMatrix[i][j]+"\t");
                                }
            }
            if(i>=0)
            System.out.println("\n\t|\n");
            else
            System.out.println("\n");
        }
    }
    int findLocation(String location) //A method to find a Vertex.
    {
        for(int i = 0;i<vertexUsed;i++)
        {
            if(v[i].weight.length()!=location.length())
                continue;
            else
            {
                int j;
                for(j = 0;j<location.length();j++)
                {
                    if(v[i].weight.charAt(j) != location.charAt(j))
                    break;

                }
            if(j==location.length())
                return i;
            }
        }
        return -1;
    }
    void DFT(int s,int ch)  //A method to print the Depth First Traversal.
    {
        if(vertexUsed!=0)
        {
            v[s].isVisited = true;
            if(ch == 1)
                                v[s].printVertex();
                        else
                        {
                                System.out.println("ListCount="+ListCount);
                                ListVertex[++ListCount] = s;
                        }
            for(int i = 0;i<vertexUsed;i++)
            {
                if(Matrix[s][i] == true && v[i].isVisited == false)
                {
                    DFT(i,ch);
                                }
            }
        }
        else
        {
            System.out.println("No Graph!!...");
            return;
        }
    }

    void BFT(int s,int ch)  //A method to print the Breadth First Traversal.
    {
        if(vertexUsed!=0)
        {
            LinkedQueue q = new LinkedQueue();
            v[s].isVisited = true;
            q.insert(s);
            int x = q.remove();
            while(true)
            {
                if(x!= -1)
                {
                                        if(ch == 1)
                    v[x].printVertex();
                    else
                                                ListVertex[++ListCount] = x;
                    for(int i = 0;i<vertexUsed;i++)
                    {
                        if(Matrix[x][i] == true && v[i].isVisited == false)
                        {
                            q.insert(i);
                            v[i].isVisited = true;
                        }
                    }
                    x = q.remove();
                }
                else
                    break;
            }
        }
        else
        {
            System.out.println("No Graph!!...");
            return;
        }
    }
int partition(int  p,int r) // A method to partition the list.
{
int left,right;
left = p;
right = r;
Edge pivotElement;
pivotElement = e[p];
right = r;
while(left < right)
{
        while(left<Edgecount&&e[left].weight <= pivotElement.weight)
                left++;
        while(right>=p&&e[right].weight > pivotElement.weight)
                right--;
        if(left < right)
                swap(left,right);
}
e[p] = e[right];
e[right] = pivotElement;
return right;
}
void sortEdge(int p,int r) //The recursive Quick Sort Algorithm.
{
       if(p<r)
       {
               int q=partition(p,r);  //finding the partion(Dividing the List)
               sortEdge(p,q-1);//Conquring the left Partition(Sorting
left partition)
               sortEdge(q+1,r);//Conquring the left Partition(Sorting
right partition)
       }
}
        void swap(int x,int y)
        {
                Edge temp = e[x];
                e[x] = e[y];
                e[y] = temp;
        }
    boolean findCycle(int i,int j,int edge)
    {
                ListCount = -1;
                resetVisited();
                BFT(i,0);
                resetVisited();
                for(int x = 0;x<=ListCount;x++)
                {
                        if(v[ListVertex[x]].weight == v[j].weight)
                                return true;
                }
                return false;
        }       
        int sumEdge()
        {
                int sum = 0;
                for(int i = 0;i<Edgecount;i++)
                        sum+=e[i].weight;
                return sum;
        }
    void resetVisited()  //A method to reset the Visited history of
all the Vertex of the Graph.
    {
        for(int i = 0;i<vertexUsed;i++)
            v[i].isVisited = false;
    }   
}
class ImplementKruskal  {
        Graph g,MST;
          ImplementKruskal(Graph g)
          {
                  this.g = g;
                  MST = new Graph(g.vertexCount);
          }
          void Algorithm()
          {

                        g.resetVisited();
                        g.sortEdge(0,g.Edgecount-1);
                        for(int i = 0;i<g.vertexUsed;i++)
                                MST.addVertex(g.v[i].weight);
                        for(int i= 0;i<g.Edgecount;i++)
                        {
                                if(MST.findCycle(g.e[i].start,g.e[i].end,g.Edgecount) == true);
                                else
                                        MST.addEdge(g.e[i].start,g.e[i].end,g.e[i].weight);
                        }
                        System.out.println("The Edge Matrix of The MST is:");
                        MST.printEdge();
                        System.out.println("The Adjacency Matrix of The MST is:");
                        MST.printMatrix();
                        System.out.println("The Weight of the Original tree is :"+g.sumEdge());
                        System.out.println("The weight of the MST is: "+MST.sumEdge());
                        System.out.println("Kruskal's Algorithm Implemented Successfully!!...");
          }
}

class ImplementPrims  {
        Graph g,MST;
        ImplementPrims(Graph g)
        {
                this.g = g;
                g.sortEdge(0,g.Edgecount-1);
                MST = new Graph(g.vertexCount);
        }
                Edge findMin()
                {
                        Edge min = null;
                        MST.BFT(0,1);
                        g.sortEdge(0,g.Edgecount-1);
                        for(int  i = 0;i<g.Edgecount;i++)
                        {
                                        if(MST.findLocation(g.v[g.e[i].start].weight)
==-1&&MST.findLocation(g.v[g.e[i].end].weight) !=-1)
                                        {
                                                return g.e[i];
                                        }
                                        else if(MST.findLocation(g.v[g.e[i].end].weight)
==-1&&MST.findLocation(g.v[g.e[i].start].weight) !=-1)
                                        {       
                                                return g.e[i];
                                        }
                                        else
                                                continue;

                        }
                        return null;
                }
        void Algorithm()
        {
                        MST.addVertex(g.v[g.e[0].start].weight);
                        MST.addVertex(g.v[g.e[0].end].weight);
                        MST.addEdge(g.e[0].start,g.e[0].end,g.e[0].weight);
                        while(g.vertexUsed > MST.vertexUsed)
                        {
                                Edge min = findMin();
                                if( min != null)
                                {
                                        if(MST.findLocation(g.v[min.start].weight) ==-1)
                                                MST.addVertex(g.v[min.start].weight);
                                                if(MST.findLocation(g.v[min.end].weight) == -1)
                                                MST.addVertex(g.v[min.end].weight);
                                        MST.addEdge(min.start,min.end,min.weight);
                                }
                        }                       
                        System.out.println("The Edge Matrix of The MST is:");
                        MST.printEdge();
                        System.out.println("The Adjacency Matrix of The MST is:");
                        MST.printMatrix();
                        System.out.println("The Weight of the Original tree is :"+g.sumEdge());
                        System.out.println("The weight of the MST is: "+MST.sumEdge());
                        System.out.println("Prim's Algorithm Implemented Successfully!!...");
        }
}
class Dijkstras  {
        Dijkstras()
        {
        }       
}
class ImplementGraph  {  //A class to implement a Graph.
    public static void main(String args[]) throws Exception //The main Method.
    {
        InputStreamReader isr  = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(isr);
        Graph g;
        int vertexCount;
  // try  //The begining of the Try block.
        {
        System.out.println("Enter the count of the maximum vertices of
the graph:");
        vertexCount = Integer.parseInt(br.readLine());
        g = new Graph(vertexCount); //Object creation.
        int ch,c;
        do
        {
            System.out.println("1)Add Vertex\n2)Add Edge"); //A user-friendly menu to read the user's choice.
            System.out.println("3)Remove Edge\n4)Remove Vertex\n5)Adjacenency Matrix\n6)Edge Matrix\n7)DFT\n8)BFT\n9)MST\n10)Exit");
            ch = Integer.parseInt(br.readLine());
            switch(ch)
            {
                case 1: //Adding a vertex.
                        System.out.println("Enter the weight of the new Vertex:");
                        String weight = br.readLine();
                        if(g.findLocation(weight)==-1)
                        {
                            int res = g.addVertex(weight);
                            if(res == 0)
                                System.out.println("Vertex creation failed!!..");
                            else
                                System.out.println("Vertex created successfully!!...");
                        }
                        else
                            System.out.println("Vertex creation failed!!..\nDuplicate Element!!..");
                        break;
                case 2://Adding a edge.
                        String start,end;
                        System.out.println("Enter the starting vertex of the edge:");
                        start = br.readLine();
                        if(g.findLocation(start)!=-1)
                        {
                            System.out.println("Enter the ending vertex of the edge:");
                            end = br.readLine();
                            if(g.findLocation(end)!=-1)
                            {
                                                                System.out.println("Enter the Weight of the Edge:");
                                                                weight = br.readLine();
                                boolean res = g.addEdge(g.findLocation(start),g.findLocation(end),Integer.parseInt(weight));
                                if(res == true)
                                    System.out.println("Edge created successfully!!...");
                                else
                                    System.out.println("Edge already present!!...");
                            }
                            else
                            {
                                System.out.println("Edge creation failed!!...");
                                System.out.println("The vertex " + "\"" + end+ "\" not found");
                            }
                        }
                        else
                        {
                            System.out.println("Edge creation failed!!...");
                            System.out.println("The vertex "+"\""+start+"\" not found");
                        }
                        break;
                case 3://Removing a Edge.
                        System.out.println("Enter the starting vertex of the edge to remove:");
                        start = br.readLine();
                        System.out.println("Enter the ending vertex of the edge to remove:");
                        end = br.readLine();
                        if(g.findLocation(start)!=-1 && g.findLocation(end)!=-1)
                        {
                            boolean res = g.removeEdge(g.findLocation(start),g.findLocation(end));
                            if(res == true)
                                System.out.println("Edge removed successfully!!...");
                            else
                                System.out.println("Cannot remove as Edge not preesent!!...");
                        }
                        else
                            System.out.println("Removing Edge failed!!...");
                        break;
                case 4://Removing a vertex.
                        System.out.println("Enter the name of the vertex to remove");
                        String remove = br.readLine();
                        if(g.findLocation(remove) != -1)
                        {
                            g.removeVertex(g.findLocation(remove));
                            System.out.println("Vertex removed successfully!!...");
                        }
                        break;
                case 5://Printing the Adjacency matrix.
                        System.out.println("The Adjacency Matrix representation of the Graph is:");
                        g.printMatrix();
                        break;
                case 6:
                        System.out.println("The Edge Matrix representation of the Graph is:");
                        g.printEdge();
                        break;
                case 7://Printing the Depth-First Traversal.
                        System.out.println("The Depth-First Traversal of the graph is :");
                        g.DFT(0,1);
                        g.resetVisited();
                        break;
                case 8://Printing the Breadth-First Traversal.
                        System.out.println("The Breadth-First Traversal of the graph is :");
                        g.BFT(0,1);
                        g.resetVisited();
                        break;
                case 9:
                                        do
                                        {
                                                System.out.println("Minimum Spannig Tree Implementation");
                                                System.out.println("1)Kruskal Algorithm\n2)Prim's s Algorithm\nFlyod -Warshall Algorithm\n4)Exit to main menu");
                                                c = Integer.parseInt(br.readLine());
                                                switch(c)
                                                {
                                                        case 1:
                                                                        g.resetVisited();
                                                                        System.out.println("Implementing Kruskal Algorithm...");
                                                                        ImplementKruskal k = new ImplementKruskal(g);
                                                                        k.Algorithm();
                                                                        g.resetVisited();
                                                                        break;
                                                        case 2:
                                                                        ImplementPrims p = new ImplementPrims(g);
                                                                        p.Algorithm();
                                                                        break;
                                                        case 3:
                                                                        break;
                                                        case 4:
                                                                        break;
                                                        default:
                                                                        System.out.println("Invalid Option...");
                                                }
                                        }while(c != 4);
                                                break;
                case 10://Quitting the program.
                        System.exit(0);
                default:
                        System.out.println("Invalid Option!!..");
            }
        }while(true);
        }
     /*  catch(Exception e)
        {
            System.out.println(e);
        }*/
    }
}