#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

class Graph{

private:
int V;
list<int> *adj;

public:
Graph(int V){

this->V = V;
adj =new list<int>[V];
}

void addEdge(int x,int y){
adj[x].push_back(y);
}

Graph transpose(Graph g){
	
	Graph _g(g.V);
	list<int> :: iterator i;
	
	for(int j=0;j<g.V;j++){
	for(i=g.adj[j].begin();i!=g.adj[j].end();i++){
		
		_g.adj[*i].push_back(j);
	}
	
	
}

return _g;
}


stack<int> dfs(int s){
	
	bool *visited = new bool[V];
	
	for(int j=0;j<V;j++){
		visited[j] = false;
	}
	
	stack<int> stk,stk2;
	list<int> :: iterator i;
	
	visited[s] = true;
	stk.push(s);
	stk2.push(s);
	
	while(!stk.empty()){
		
		int u = stk.top();
		cout<<"   "<<u<<"  ";
		stk.pop();
		
		for(i=adj[u].begin();i!=adj[u].end();i++){
			
			if(!visited[*i]){
				
				visited[*i] = true;
				stk.push(*i);
				stk2.push(*i);
			}
		}
		
	}
	
	return stk2;
	
}

void Scomponent(Graph g){
	
	Graph _g = transpose(g);
	stack<int> stk = g.dfs(0);
	
	while(!stk.empty()){
		
		int u = stk.top();
		stk.pop();
		cout<<endl;
		_g.dfs(u);
		cout<<endl;
		
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

graph.Scomponent(graph);



return 0;

}