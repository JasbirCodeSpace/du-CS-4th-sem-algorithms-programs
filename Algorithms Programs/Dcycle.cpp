#include<iostream>
#include<list>
#include<stack>
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
}


void dfs(int s){
	
	bool *visited = new bool[V];
	string *color = new string[V];
	
	for(int i=0;i<V;i++){
		visited[i] = false;
		color[i] = "white";
		}
	
	visited[s] = true;
	color[s] = "grey";
	
	stack<int> stk;
	stk.push(s);
	
	list<int>::iterator i;
	
	while(!stk.empty()){
		
		 s = stk.top();
		cout<<s<<"  ";
		
		stk.pop();
		
		for(i=adj[s].begin();i!=adj[s].end();++i){
			if(!visited[*i] and color[*i] == "white"){
				visited[*i] = true;
				color[*i] = "grey";
               stk.push(*i);	
			}	

            else if(color[*i] == "grey"){
			 cout<<"\nTHE GIVEN GRAPH CONTAINS CYCLE\n";
			 return;
			}		
		}
		color[s] = "black";
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

graph.dfs(source);

return 0;

}