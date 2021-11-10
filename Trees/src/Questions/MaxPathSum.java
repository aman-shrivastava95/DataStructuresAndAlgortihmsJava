package Questions;

import Nodes.local.IntNode;

public class MaxPathSum{
    int result = Integer.MIN_VALUE ;
    public int solve(IntNode root){
        maxPathHelper(root) ;
        return result ;
    }
    /*Basically we try to find the maximum of all the three cases, it could be straight, or it coult start from a node, or contains both side of the subtree*/
    /*try to visualize it, it is pretty easy*/
    private int maxPathHelper(IntNode node) {
        if(node == null) return 0 ;
        int L = maxPathHelper(node.left) ;
        int R = maxPathHelper(node.right) ;
        int straight  = Math.max(node.val, node.val + Math.max(L,R)) ;
        int containsBothLandR = Math.max(straight,L + R + node.val) ;
        result = Math.max(result,containsBothLandR) ;
        return straight ;
    }
}
