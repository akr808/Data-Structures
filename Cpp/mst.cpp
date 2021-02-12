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
	Graph kruskel();
	int EdgeWeight();
	void getVertexName();
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
	//A function to check if ading of Edge v1<->v2 creates a cycle in the graph;
	set();
	return bfs(v1,v2);
}

Graph Graph::kruskel()
{
	Graph min = Graph(n);
	int list[EdgeCount()][3];
	compute(list);
	//std::cout<<"The list of Edges in the Graph is:\n";
	//print(list);
	sort(list);
	//std::cout<<"The list after sorting is:\n";
	//print(list);
	
	for(int i = 0;i < EdgeCount();i++)
	{
		if(!min.checkCycle(list[i][0],list[i][1]))
		{
			std::cout<<"Adding Undirected Edge from Vertex "<<v[list[i][0]]<<" to Vertex "<<v[list[i][1]]<<" with weight "<<arr[list[i][0]][list[i][1]]<<"\nPress Any Key to continue...\n";
			fflush(stdin);
			getchar();
			min.addEdge(list[i][0],list[i][1],list[i][2]);
			min.addEdge(list[i][1],list[i][0],list[i][2]);
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
void Graph::compute(int list[][3])
{
	int count = 0;
	for(int i = 0;i < n;i++)
		for( int j = 0;j < n;j++)
			if(arr[i][j] != 0 && i < j)
			{
				list[count][0] = i;
				list[count][1] = j;
				list[count++][2] = arr[i][j];
				
			}
}

void Graph::sort(int list[][3])
{
	for(int i = 0;i < EdgeCount();i++)
	{
		for(int j = i+1;j < EdgeCount();j ++)
		{
			if(list[i][2] > list[j][2])
			{	
				//std::cout<<"Swapping Vertex weight"<<list[i][2]<<" and vertex weight "<<list[j][2]<<"\n";
				/*
				//Swapping the first Vertex.
				list[i][0] =+ list[j][0];
				list[j][0] = list[i][0] - list[j][0];
				list[i][0] = list[i][0] - list[j][0];
				//Swapping the Second Vertex.
				list[i][1] =+ list[j][1];
				list[j][1] = list[i][1] - list[j][1];
				list[i][1] = list[i][1] - list[j][1];
				//Swapping the weights.
				list[i][2] =+ list[j][2];
				list[j][2] = list[i][2] - list[j][2];
				list[i][2] = list[i][2] - list[j][2];*/
				int temp;
				temp = list[i][0];
				list[i][0] = list[j][0];
				list[j][0] = temp;
				
				temp = list[i][1];
				list[i][1] = list[j][1];
				list[j][1] = temp;
				
				temp = list[i][2];
				list[i][2] = list[j][2];
				list[j][2] = temp;
			}
		}
	}
	
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
Graph min = g.kruskel();
for(int i =0;i<n;i++)
	min.v[i] = g.v[i];
std::cout<<"\n";
min.printData();
std::cout<<"The weight of the Minuimum Spanning Tree is :"<<min.EdgeWeight()<<"\n";
return 0;
}
