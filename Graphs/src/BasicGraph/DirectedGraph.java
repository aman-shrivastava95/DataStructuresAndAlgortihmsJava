package BasicGraph;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/**
 * adjacency list implementation of the directed graph.
 */
public class DirectedGraph {
    int V ;//vertex of the graph
    List<List<Integer>> adj; //adjacency list for the graph

    public DirectedGraph(int V){
        this.V = V ;
        this.adj = new ArrayList<>() ;
        for(int i=0; i<V; i++){
            this.adj.add(new ArrayList<>()) ;
        }
    }
    public void addEdge(int src, int dest){
        this.adj.get(src).add(dest) ;
    }
    public void printGraph(){
        for (List<Integer> list : adj) {
            for (int v : list) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }
    public void dfs(int src){
        boolean[] visited = new boolean[V] ;
        dfsUtil(src,visited) ;
    }

    private void dfsUtil(int node, boolean[] visited) {
        if(visited[node])
            return;
        //visit the current node
        visited[node] = true ;
        System.out.println(node+ " ");
        //call dfs in all the neighbors
        for(int v:adj.get(node)){
            dfsUtil(v,visited);
        }
    }
    public void bfs(int src){
        boolean[] visited = new boolean[V] ;
        Queue<Integer> q =  new LinkedList<>() ;
        q.add(src) ;
        visited[src] = true ;
        while(!q.isEmpty()){
            int currNode = q.poll() ;
            System.out.println(currNode);

            for(int neighbor : adj.get(currNode)){
                if(!visited[neighbor]){
                    q.add(neighbor) ;
                    visited[neighbor] = true ;
                }

            }
        }
    }
}
