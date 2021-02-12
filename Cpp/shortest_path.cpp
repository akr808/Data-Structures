#include<iostream>
#include<stdio.h>
#define INFINITE -1
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
	int EdgeWeight();
	void getVertexName();
	int min(int ,int);
	void Dijkstra();
	void set_infinite(int mind[]);
	void print_min(int[]);
};

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

				
void Graph::getVertexName()
{
	for(int i = 0;i< n;i++)
		std::cin>>v[i];
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

int Graph::min(int a, int b)
{
return a<b?a:b;
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

	

void Graph::Dijkstra()
{
	int mind[n];
	int source = 0;
	set_infinite(mind);
	for(int i =0;i < n;i++)	
	{
		for(int j = 0;j < n;j++)
		{
			for(int k = 0;k < n;k++)
			{				
				if(arr[i][k] > 0 && arr[k][j] > 0)
				{
					if(j == source)
						mind[j] = 0;
					if(mind[j] == INFINITE)
						mind[j] = arr[i][k]+arr[k][j];
					else
						mind[j] = min(mind[j],arr[source][k]+arr[k][j]);
				}
			}
		}
	
	}
	std::cout<<"Minimum cost matrix with source vertex "<<v[source] <<" is:\n";
	print_min(mind);
	
}


void Graph::print_min(int mind[])
{
	for(int i = 0;i < n;i++)
	{
		std::cout<<"Minimum distance to vertex "<<v[i]<<" is ";
		if(mind[i] != INFINITE)
			std::cout<<mind[i]<<"\n";
		else
			std::cout<<"INFINITE";
	}
}
void Graph::set_infinite(int mind[])
{
	for(int i =0;i < n;i++)
	{
		mind[i] = INFINITE;	
	}
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
g.Dijkstra();
return 0;
}
