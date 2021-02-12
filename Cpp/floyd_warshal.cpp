#include<iostream>
#include<stdio.h>
#define INFINITE NULL
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
	void floyd();
	void set_infinite(int,int mind[50][50]);
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
void Graph::set_infinite(int x,int mind[50][50])
{
	for(int i =0;i < n;i++)
	{
		for(int j = 0; j < n;j++)
		{
			if(i ==j)
				mind[i][j] = 0;
			if(i != j && arr[i][j] == 0)
				mind[i][j] = INFINITE;
			else
				mind[i][j] = arr[i][j];

		}
	}
}


void Graph::floyd()
{
	int mind[50][50];
	set_infinite(n,mind);
	for(int k = 0 ; k < n;k++)
	{
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n;j ++)
			{
				if (i == j)
					continue;
				if(mind[i][k] != NULL && mind[k][j] != NULL)
				{
					if(mind[i][j] == INFINITE)
						mind[i][j] = mind[i][k]+mind[k][j];
					else
						mind[i][j] = min(mind[i][j],mind[i][k]+mind[k][j]);
				}
			}
		}
		
		}
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
	for(int x = 0;x <n;x++)
	{
		std::cout<<v[x]<<"|";
		for(int y = 0;y < n;y++)
		{
			//if(mind[x][y] == NULL)
			//	std::cout<<"\t*";
			//else
				std::cout<<"\t"<<mind[x][y];
		}
		std::cout<<"\n";		
	}

	
	std::cout<<"\n";
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
std::cout<<"\n";
g.floyd();
return 0;
}
