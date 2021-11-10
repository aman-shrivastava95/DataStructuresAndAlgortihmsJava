package PreBuiltTrees;

//mostly all the questions use an integer values in the tree, so this should be good to get a nice structure., the same code can be used to deserialize an struccture
import Nodes.local.IntNode;

import java.util.LinkedList;
import java.util.Queue;

/**
 * class for a inary tree where data stored in tree nodes are integer
 */
public class IntegerTree {
    public IntNode root  ;

    /**
     *  default constructor
     */
    public IntegerTree(){
    }
    /**
     * @param values array of integer values,to form the tree, nulls are allowed
     */
    public IntegerTree (Integer[] values){
        System.out.println("creating a binary tree with the given serialized values");
        this.root = null ;
        for(Integer data:values){
            //some values can be null, no worries, they comprise the tree structure.
            levelOrderInsert(data);
        }
    }

    /**
     * @param data takes the integer data to be added to the binary tree
     * takes an integer data and adds it to the binary tree. follows the level order pattern to add the binary tree.
     */
    private void levelOrderInsert(Integer data){
        //prepare and keep the key first
        IntNode key ;
        if(data==null)
            key = null ;
        else
            key = new IntNode(data) ;

        //using bfs, easy to maintain the tree structure
        Queue<IntNode> q = new LinkedList<>() ;
        if(root == null)
        {
            this.root = key ;
            return ;
        }
        q.add(this.root) ;
        while(!q.isEmpty()){
            IntNode curr = q.poll() ;
            if(curr.left==null){
                curr.left  = key;
                break ;
            }else{
                q.add(curr.left) ;
            }
            if(curr.right==null){
                curr.right  = key;
                break ;
            }else{
                q.add(curr.right) ;
            }
        }
    }
}
