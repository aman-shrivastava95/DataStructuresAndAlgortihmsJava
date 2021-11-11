import BasicGraph.DirectedGraph;
import BasicGraph.UndirectedGraph;

public class Driver {
    public static void main(String[] args) {
        testDirectedGraph() ;
        System.out.println();
        testUndirectedGraph() ;
    }

    private static void testUndirectedGraph() {
        UndirectedGraph g = new UndirectedGraph(4) ;
        //here is the flaw, the edges are being added twice, if the graphs is formed uni
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(0, 3);
        g.addEdge(1, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 3);
        g.printGraph();
        System.out.println("DFS :");
        g.dfs(2);
        System.out.println("BFS :");
        g.bfs(2);
    }

    private static void testDirectedGraph() {
        DirectedGraph g = new DirectedGraph(4) ;
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        g.printGraph();
        System.out.println();
        g.dfs(2);
        System.out.println("BFS");
        g.bfs(2);
    }
}
