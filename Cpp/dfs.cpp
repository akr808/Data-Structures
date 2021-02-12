#include<iostream>
class Graph {
private:
	int n;
	int arr[50][50];
	bool visit[50];
public:
	Graph(int nodes)
	{
		n = nodes;		
	}


	void getData();
	void printData();
	bool visited(int i);	
	void dfs(int);
	void bfs(int);
	void traverse();
	void set();
	bool completed();
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
void Graph::printData()
{
	for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n ;j++)
			{
				std::cout<<arr[i][j]<<"\t";
			}
			std::cout<<"\n";
		}
}
bool Graph::visited(int i)
{
	return visit[i];
}		

void Graph::traverse()
{
set();

if(!completed())
{
	for(int i = 0;i < n;i++)
		if(!visited(i))
			dfs(i);
}
}

void Graph::dfs(int v)
{
	if(visited(v))
		return;
	else
		std::cout<<v<<"\n";
		for(int i = 0;i < n;i++)
		{
			if(!visited(i) && arr[v][i] == 1)
			{
				dfs(i);
				
			}
			visit[v] = true;
		}

				
	

}

void Graph::bfs(int v)
{
	std::cout<<v<<"\n";
 	visit[v] = true;
 	for(int i = 0;i < n;i++)
 	{
 		if(arr[v][i] == 1 && !visited(i))
 			bfs(i);
 	}

}

bool Graph::completed()
{
	for(int  i = 0;i < n;i++)
		if(!visited(i))
			return false;
	return true;
}


int main()
{
int n;
std::cin>>n;
Graph g = Graph(n);
g.getData();
std::cout<<"\n";
g.printData();
g.traverse();
}
