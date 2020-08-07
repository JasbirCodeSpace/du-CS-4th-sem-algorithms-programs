#include<iostream>
#include<list>

using namespace std;

class Graph{
private:
int V;
list<int>* adj;

public:
Graph(int V){
	this->V = V;
	adj = new list<int>[V];
	
}

void addEdge(int u,int v){
	
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void bfs(int s){
	
	bool *visited = new bool[V];
	
	for(int i=0;i<V;i++)
		visited[i] = false;
	
	visited[s] = true;
	
	list<int> queue;
	queue.push_back(s);
	
	list<int>::iterator i;
	
	while(!queue.empty()){
		
		 s = queue.front();
		cout<<s<<"  ";
		
		queue.pop_front();
		
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visited[*i]){
				visited[*i] = true;
               queue.push_back(*i);	
			}			   
		}
	}
}
};

int main(){
cout<<"\nenter the number of vertices in your graph\n";
int V;
cin>>V;

Graph graph(V);

cout<<"\nenter vertices between which you want edge\n";
int x,y;
int i=1;
while(1){
	cout<<"==========="<<i++<<"==========="<<endl;
	cin>>x;
	cin>>y;
	if(x!=-1 and y!=-1)
		graph.addEdge(x,y);
	else
		break;
	
	
}

cout<<"\nenter the source vertex\n";
int source;
cin>>source;

graph.bfs(source);

return 0;

}