package Questions;

import Nodes.local.IntNode;
import java.util.ArrayList;
import java.util.List;

//question is important only for manipulation and to think about what needs to get printed with the arrow -> .
public class LeetCode257_RootToLeafPath {
    public List<String> solve(IntNode root){
        List<String> res =  new ArrayList<>() ;
        String curr = String.valueOf(root.val) ;
        util(root,curr,res) ;
        return res ;
    }

    private void util(IntNode node, String curr, List<String> res) {
        //if we are at the leaf,don't go further down
        if(node.left == null && node.right == null){
            res.add(curr) ;
            return;
        }
        //pass to the next nodes,if they exist, with the arrow notation, required in the question
        if(node.left!=null)
            util(node.left,curr+"->"+node.left.val,res);
        if(node.right!=null)
            util(node.right, curr+"->"+node.right.val,res) ;
    }
}
