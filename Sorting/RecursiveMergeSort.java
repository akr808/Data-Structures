//A program to implement the Merge Sort Algorithm Recursively.
import java.io.*; //Import statement.
class MergeSort  {  //A class to implement recursive Merge Sort algorithm
        int[] arr;
        int size=0;
        MergeSort(int x[],int n)  //The Constructor.
        {
                arr = x;
                size = n;
        }
        void mergeSort(int left,int right) //A method to sort using Merge
Sort Algorithm.
        {
                int mid=(right+left)/2;
                if(right==left)
                        return;
                mergeSort(left,mid);
                print();
                mergeSort(mid+1,right);
                print();
                merge(left,mid,right);
                print();
        }
        void merge(int left,int mid,int right) //A method to merge two partitions.
        {
                int[] aux = new int[right-left+1];
                int i=0,j=0,k=0;
                for(i=left,j=mid+1;i<=mid&&j<=right;)
                 {
                         if(arr[i]<=arr[j])
                                 aux[k]=arr[i++];
                         else
                                 aux[k]=arr[j++];               
                         k++;   
                 }
                 if(i<=mid)
                 {
                         while(i<=mid)
                                 aux[k++]=arr[i++];
                 }
                 if(j<=left)
                 {
                         while(j<=mid)
                                aux[k++]=arr[j++];
                 }
                 for(i=0;i<=right-left;i++)
                        arr[left+i]=aux[i];
        }
        void print()  //A method to print the list at any instance.
        {
                System.out.println("The current list is:");
                for(int i=0;i<size;i++)
                        System.out.println(arr[i]);                     
        }
}
class RecursiveMergeSort  { //A method to implement the MergeSort class
        public static void main(String args[])
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
                        MergeSort q = new MergeSort(arr,n);     
                        q.mergeSort(0,n-1);
                        System.out.println("Sorting completed successfully!!...");             
                }
                catch(Exception e) //Catching all exceptions.
                {
                        System.out.println(e);
                }               
        }
}