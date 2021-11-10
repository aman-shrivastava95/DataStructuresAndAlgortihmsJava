package Questions;

import Nodes.local.IntNode;

/**
 * class to find the diameter of a binary tree,
 *  node is the binary tree node containing integer values
 */
public class Diameter {
    public void solve(IntNode node){
        System.out.println("The diameter o(n^2) of the tree is: " + diameter(node) );
        System.out.println("The diameter o(n) of the tree is: " + getDiameter(node,new Height()));
    }

    /**
     * @param node the node of type integer
     * @return the diameter of a binary tree, in this case, it is defined as the number of edges between any two nodes, highest in this case
     * complexity of this approach is o(n^2)
     */
    private int diameter(IntNode node) {
        if(node==null) return 0 ;
        int LD = diameter(node.left) ;
        int RD = diameter(node.right) ;
        int currMidNode = height(node.left) + height(node.right) ;//we can add +1 if is the number of vertex between any two nodes
        return Math.max(currMidNode,Math.max(LD,RD)) ;
    }

    private int  height(IntNode node){
        if(node == null) return 0 ;
        return 1 + Math.max(height(node.left),height(node.right)) ;
    }

    /**
     * @param node root of the tree
     * @param height wrapper class passed as reference so that the value is reflected in the parent call of recursion as well
     * @return
     */
    private int getDiameter(IntNode node,Height height) {
        if (node == null) {
            height.h = 0;//height set to 0
            return 0;//diameter returned to 1
        }
        //creating two variables which will be set as the height of left subtree and right subtree
        Height lh = new Height(), rh = new Height();
        int leftDiameter = getDiameter(node.left, lh);
        int rightDiameter = getDiameter(node.right, rh);
        //set height for the current node, which will be used by the parent call
        height.h = Math.max(lh.h, rh.h) + 1;
        return Math.max(Math.max(leftDiameter, rightDiameter), lh.h + rh.h);//we can add 2 here if it is the number of vertex between any two nodes
    }

    /**
     * wrapper around the primitive int, so that it can be passed as referenced not as values, and changes can be reflected in the calling method.
     */
    class Height{
        int  h ;
    }
}
