#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;

class Edge;

class Vertex
{
    public:
       char name;
       list<Edge*> elist;       
       Vertex(char n)
       {
        name = n;
       }
};
class Edge
{
    public:
       Vertex* u;
       Vertex* v;
       int w;
       Edge(Vertex* f, Vertex* t, int d)
       {
        u=f;
        v=t;
        w=d;
       }
};
class Graph
{	
	
    private:
        list <Vertex*> graph;

    public:
    	int no_of_vertices;
    	int no_of_edges;
        Graph(){
            no_of_vertices=0;
		    no_of_edges=0;
        }
    
//    void addVertex(char n)
//    {
//        Vertex *v = new Vertex(n);
//        graph.push_back(v);
//    }
    void addVertex(Vertex* x)
    {	
    	no_of_vertices++;
        graph.push_back(x);
    }
    void addEdge(Vertex* f, Vertex* t, int d)
    {	
    	no_of_edges++;
        Edge *e1=new Edge(f,t,d);
        Edge *e2=new Edge(t,f,d);
        f->elist.push_back(e1);
        t->elist.push_back(e2);
    }

    void display()
    {
        for (Vertex *vert: graph)
        {
            cout << vert->name << "=>{";
            for (Edge *e: vert->elist)
                cout << "(" << e->v->name <<"," << e->w <<"),";
            cout<< "}" << endl;
        }
    }
    Vertex* find(char c)
    {
        for (Vertex* x: graph)
            if (x->name == c)
                return x;
        return NULL;
    }
    void dfs(char start)
    {
        stack<Vertex*> stk;
        int N = graph.size();       //method for getting size of list
        int visited[N];

        for (int i=0;i<N;i++) 
            visited[i]=0;        

        Vertex* vx=find(start);

        if (vx==NULL)
            return;

        stk.push(vx);

        while(!stk.empty())
        {
            Vertex* n= stk.top();
            stk.pop();

            int index = n->name - 'A';
            if (!visited[index])
            {
                cout << n->name << "=>";
                visited[index] = 1;
            }
            for (Edge *e : n->elist)
            {
                int i = e->v->name - 'A';
                if (!visited[i])
                    stk.push(e->v);
            }

          }
          cout<<endl;
    }
    void matrix()
    {
        int matrix[no_of_vertices][no_of_vertices];

        // Initialize the matrix with 0
        for (int i = 0; i < no_of_vertices; i++)
        {
            for (int j = 0; j < no_of_vertices; j++)
            {
                matrix[i][j] = 0;
            }
        }

        // Fill the matrix based on the edges
        for (Vertex *v : graph)
        {
            for (Edge *e : v->elist)
            {
                int i = v->name - 'A';
                int j = e->v->name - 'A';
                matrix[i][j] = e->w; 
            }
        }

        // Print the matrix
        for (int i = 0; i < no_of_vertices; i++)
        {
            for (int j = 0; j < no_of_vertices; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    void bfs(char start)
	{
	    queue<Vertex*> que;
	    int N = graph.size();
	    int visited[N];
	
	    for (int i = 0; i < N; i++)
	        visited[i] = 0;
	
	    Vertex* vx = find(start);
	
	    if (vx == NULL)
	        return;
	
	    que.push(vx);
	    visited[vx->name - 'A'] = 1;
	
	    while (!que.empty())
	    {
	        Vertex* n = que.front();
	        que.pop();
	
	        cout << n->name << "=>";
	
	        for (Edge* e : n->elist)
	        {
	            int i = e->v->name - 'A';
	            if (!visited[i])
	            {
	                que.push(e->v);
	                visited[i] = 1;
	            }
	        }
	    }
	
	    cout << endl;
	}

    
};



int main()
{
    Graph g;
    Vertex a('A');
    Vertex b('B');
    Vertex c('C');
    Vertex d('D');
    Vertex e('E');

    g.addVertex(&a);
    g.addVertex(&b);
    g.addVertex(&c);
    g.addVertex(&d);
    g.addVertex(&e);
	
    g.addEdge(&a,&b,4);
    g.addEdge(&a,&c,2);
    g.addEdge(&b,&d,1);
    g.addEdge(&d,&e,3);
    g.addEdge(&d,&c,2);
    g.display();
    g.dfs('A');
    g.matrix();
    g.bfs('A');

    return 0;
}