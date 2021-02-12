import java.io.*;
class Heap  {
    int arrayHeap[];
    int heapSize;
    Heap(int heapSize,int arrayHeap[])
    {
        this.arrayHeap = arrayHeap;
        this.heapSize = heapSize;
    }
    void heapify(int i,int heapEnd)
    {
        int largest;
        if(2*i <= heapEnd && arrayHeap[2*i]>=arrayHeap[i])
            largest = 2*i;
        else
            largest = i;
        if(2*i+1<= heapEnd && arrayHeap[2*i+1]>arrayHeap[largest])
            largest = 2*i+1;
        if(largest != i)
        {
            swap(i,largest);
            heapify(largest,heapEnd);
        }
    }
    void heapSort()
    {
        int heapEnd = heapSize -1;
        while(heapEnd>0)
        {
            swap(0,heapEnd);
            heapify(0,heapEnd);
            heapEnd--;
        }
    }
    void swap(int i,int j)
    {
    arrayHeap[i] = arrayHeap[i] + arrayHeap[j];
    arrayHeap[j] = arrayHeap[i] - arrayHeap[j];
    arrayHeap[i] = arrayHeap[i] - arrayHeap[j];
    }
    void print()
    {
        for(int i = 0;i<heapSize;i++)
            System.out.println(arrayHeap[i]);
    }

}

class ImplementHeapSort  {
  public static void main(String args[])
  {
      InputStreamReader isr = new InputStreamReader(System.in);
    BufferedReader br = new BufferedReader(isr);
      int arrayHeap[],heapSize;
      try
    {
        System.out.println("Enter the size of the Heap:");
        heapSize = Integer.parseInt(br.readLine());
        arrayHeap = new int[heapSize];
        for(int i = 0;i<heapSize;i++)
            arrayHeap[i] = Integer.parseInt(br.readLine());
        Heap h = new Heap(heapSize,arrayHeap);
        h.heapify(0,heapSize);
        System.out.println("The heap is ");
        h.print();
        h.heapSort();
        System.out.println("The sorted list is ");
        h.print();
    }
    catch(Exception e)
    {
        System.out.println(e);
    }
  }
} 