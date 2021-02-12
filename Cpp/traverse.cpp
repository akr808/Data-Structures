#include<iostream>
class Graph {
private:
	int n;
	int arr[50][50];
	bool visit[50];
	char v[50];
public:
	Graph(int nodes)
	{
		n = nodes;		
	}


	void getData();
	void printData();
	bool visited(int i);	
	void dfs(int);
	void bfs(int,bool[]);
	void traverse();
	void set();
	bool completed();
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

void Graph::traverse()
{
set();
std::cout<<"\nGraph Traversal Menu\n1)DFS\n2)BFS\n3)Exit\nEnter your Choice:";
int ch;
std::cin>>ch;
switch(ch)
{
	case 1:
		std::cout<<"The DFS Traversal of the given Graph is:\n";
		dfs(4);
		if(!completed())
		{
			for(int i = 0;i < n;i++)
				if(!visited(i))
					dfs(i);
		}
		break;
	case 2:
		bool explored[n];
		for(int i = 0;i < n;i++)
			explored[n] = false;
		std::cout<<"The BFS Traversal of the given Graph is:\n";
		std::cout<<v[0]<<"\n";
		bfs(0,explored);
		if(!completed())
		{
			for(int i = 0;i < n;i++)
				if(!visited(i))
				{
					std::cout<<v[i]<<"\n";
					bfs(i,explored);
				}
		}
		break;
	case 3:
			break;
	
}


}

void Graph::dfs(int ver)
{
	if(visited(ver))
		return;
	else
		std::cout<<v[ver]<<"\n";		
		for(int i = 0;i < n;i++)
		{
			if(!visited(i) && arr[ver][i] == 1)
			{
				dfs(i);
				
			}
			visit[ver] = true;
		}

			
			
	

}


void Graph::bfs(int ver,bool explored[])
{
	std::cout<<"Visiting vertex "<<ver<<"\n";
	if(visited(ver))
		return;
 	visit[ver] = true;
 	for(int i = 0;i < n;i++)
 	{
 	/*	std::cout<<"\nChecking vertex "<<v[i]<<"\n";
 		std::cout<<"arr["<<ver<<"]["<<i<<"] = "<<arr[ver][i]<<"\n";
 		std::cout<<"visited["<<i<<"]="<<visited(i)<<"\n";
 		std::cout<<"explored["<<i<<"]="<<explored[i]<<"\n";*/
 		if(arr[ver][i] != 0 && !visited(i) && !explored[i])
 		{

 			std::cout<<v[i]<<"\n";
 			explored[i] = true;
 		}
 	}
 	for(int i = 0;i < n;i++)
 	{
 		if(arr[ver][i] != 0 && !visited(i))
 		{
 		//	std::cout<<"Calling bfs("<<i<<")\n";
 			bfs(i,explored);
 		}
 	}

}
void Graph::getVertexName()
{
	for(int i = 0;i< n;i++)
		std::cin>>v[i];
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
std::cout<<"Enter the number of Vertices in the Graph: ";
std::cin>>n;
Graph g = Graph(n);
std::cout<<"Enter the Adjacency Matrix representation of the Graph: \n";
g.getData();
std::cout<<"Enter the vertex names in order:\n";
g.getVertexName();
std::cout<<"\n";
g.printData();
g.traverse();
}
