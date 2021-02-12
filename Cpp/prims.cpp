#include<iostream>
#include<stdio.h>
class Graph {
private:
	int n;
	int arr[50][50];
	bool visit[50];
	
public:
	char v[50];
	Graph(int nodes)
	{
		n = nodes;		
	}


	void getData();
	void printData();
	bool visited(int i);	
	void set();
	void addEdge(int,int,int);
	bool checkCycle(int,int);
	bool bfs(int,int);
	int EdgeCount();
	void compute(int[][3]);
	void sort(int[][3]);
	void print(int[][3]);
	Graph prims(int);
	int EdgeWeight();
	int minEdge(int[],int);
	void getVertexName();
};

void Graph::getVertexName()
{
	for(int i = 0;i< n;i++)
		std::cin>>v[i];
}

void Graph::set()
{
for(int i = 0;i < n;i++)
	visit[i] = false;
}
void Graph::getData()
	{
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n ;j++)
			{
				std::cin>>arr[i][j];
			}
		}
	}
	
bool Graph::bfs(int v,int u)
{
//	std::cout<<"\nExploring"<<v<<"\n";
	for(int i = 0;i < n;i++)
	{
		if (i == u && arr[v][i] != 0)
		{
			//std::cout<<"Found Vertex";
			return true;
		}
	
		if(arr[v][i] != 0 && !visited(i))
		{	
			visit[i] = true;
			if(bfs(i,u) == true)
				return true;		 	
		
		}
	}
	return false;

}

				
	
void Graph::printData()
{
	for (int i = 0;i < n;i++)
		std::cout<<"\t"<<v[i];
	std::cout<<"\n";
	for(int i =0;i<n*7;i++)
	{
		if(i ==0)
			std::cout<<"\t";
		std::cout<<"-";
	}
	std::cout<<"\n";
	for(int i = 0;i < n;i++)
		{
			std::cout<<v[i]<<"|";
			for(int j = 0;j < n ;j++)
			{
				std::cout<<"\t"<<arr[i][j];
			}
			std::cout<<"\n";
		}
}

bool Graph::visited(int i)
{
	return visit[i];
}		
void Graph::addEdge(int x,int y,int weight)
{
	arr[x][y] = weight;
}

bool Graph:: checkCycle(int v1,int v2) 
{
	//A function to check if adding of Edge v1<->v2 creates a cycle in the graph;
	set();
	return bfs(v1,v2);
}

Graph Graph::prims(int ver)
{
	Graph min = Graph(n);
	int vlist[n],vno =0;
	vlist[vno++] = ver;

	for(int i = 0 ;i < n - 1;i++)
	{
		int start = minEdge(vlist,vno++);
		if(!min.checkCycle(start,vlist[vno]))
		{
			std::cout<<"Adding Undirected Edge from Vertex "<<v[start]<<" to Vertex "<<v[vlist[vno]]<<" with weight "<<arr[start][vlist[vno]]<<"\nPress Any Key to continue...\n";
			fflush(stdin);
			getchar();
			min.addEdge(start,vlist[vno],arr[vlist[vno]][start]);
			min.addEdge(vlist[vno],start,arr[vlist[vno]][start]);
		}

	}
		
return min;
}


void Graph::print(int list[][3])
{
	for(int i = 0;i < EdgeCount();i++)
	{
		for(int j = 0;j < 3;j ++)
			std::cout<<list[i][j]<<" ";
		std::cout<<"\n";
	}
}

int Graph::minEdge(int vlist[],int vno)
{
	int minx = -1,miny = -1;
	for(int i = 0;i <= vno;i++)
	{
			
		for(int j = 0;j < n;j++)
		{
			int flg = 0;
			for(int k = 0;k <= vno;k++)
				if(vlist[k] == j)
				{
					flg = 1;
					break;
				}
				
			if(flg ==1)
				continue;
			
			if (arr[vlist[i]][j] == 0)
				continue;
			if(minx == -1 && miny == -1) 
			{
				minx = vlist[i];
				miny = j;
			}
			if(arr[vlist[i]][j] < arr[minx][miny])
			{
				minx = vlist[i];
				miny = j;
			}
				
		}
	}
	vlist[vno+1] = miny;
	return minx;
}

int Graph::EdgeCount()
{
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(arr[i][j] > 0 && i < j)
				count++;
	return count;
	
}
int Graph::EdgeWeight()
{
	int count = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			if(arr[i][j] > 0 && i < j)
				count += arr[i][j];
	return count;
	
}
int main() 
{
int n;
std::cout<<"Enter the number of Vertices in the Graph: ";
std::cin>>n;
Graph g = Graph(n);
std::cout<<"Enter the Adjacency Matrix representation of the Graph: \n";
g.getData();
std::cout<<"Enter the vertex names in order:\n";
g.getVertexName();
std::cout<<"\n";
g.printData();
Graph min = g.prims(0);
for(int i =0;i<n;i++)
	min.v[i] = g.v[i];
std::cout<<"\n";
min.printData();
std::cout<<"The weight of the Minuimum Spanning Tree is :"<<min.EdgeWeight()<<"\n";
 


return 0;
}
