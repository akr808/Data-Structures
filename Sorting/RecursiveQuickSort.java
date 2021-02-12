import java.io.*; //Import statement.
class Qsort  {  //A class to implement recursive Quick Sort algorithm
        int[] arr;
        int size=0;
        Qsort(int x[],int n)  //The Constructor.
        {
                arr = x;
                size = n;
                print();
        }
        void print()  //A method to print the list at any instance.
        {
                System.out.println("The current list is:");
                for(int i=0;i<=size;i++)
                        System.out.println(arr[i]);
        }
        void swap(int x,int y) // A method to swap two elements of the list.
        {
                System.out.println("Swapped " + arr[x]+" at arr["+x+"]" + " and "+arr[y]+" at arr["+y+"]" );
                arr[x] = arr[x]+arr[y];
                arr[y] = arr[x]-arr[y];
                arr[x] = arr[x]-arr[y];
        }
int partition(int  p,int r) // A method to partition the list.
{
int left,right;
left = p;
right = r;
int pivotElement;
pivotElement = arr[p];
right = r;
while(left < right)
{

      while(left<size&&arr[left] <= pivotElement)
               left++;
       while(right>=p&&arr[right] > pivotElement)
               right--; if(left < right)
               swap(left,right);
}
arr[p] = arr[right];
arr[right] = pivotElement;
return right;
}

void QuickSort(int p,int r) //The recursive Quick Sort Algorithm.
{
        if(p<r)
        {
                int q=partition(p,r);  //finding the partion(Dividing the List)
                System.out.println("Pivot element is at location = "+p+" and the element is = "+arr[p]);
                System.out.println("The segment begins at location = "+q+" where the element is = "+arr[q]);
                System.out.println("The segment ends at location = "+r+" where the element is = "+arr[r]);
                print();
                QuickSort(p,q-1);//Conquring the left Partition(Sorting left partition)
                QuickSort(q+1,r);//Conquring the left Partition(Sorting right partition)
        }
}
}
class RecursiveQuickSort {  //Implementing the Qsort class.
        public static void main(String args[]) //The main method.
        {
                InputStreamReader isr = new InputStreamReader(System.in);
                BufferedReader br = new BufferedReader(isr);
                int n;
                int arr[];
                try // The begining of the try block.
                {
                        System.out.println("Enter the size of the list:");
                        n=Integer.parseInt(br.readLine());
                        arr = new int[n];
                        for(int i=0;i<n;i++)
                        {
                                System.out.println("Enter the element in location "+i);
                                arr[i]=Integer.parseInt(br.readLine());
                        }
                        Qsort q = new Qsort(arr,n-1);
                        q.QuickSort(0,n-1);
                        System.out.println("Sorting completed successfully!!...");
                }
                catch(Exception e) //Catching all exceptions.
                {
               {
                        System.out.println(e);
                }
        }

}

