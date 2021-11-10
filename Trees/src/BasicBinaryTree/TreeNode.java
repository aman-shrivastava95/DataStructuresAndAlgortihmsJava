package BasicBinaryTree;

/*structure for the BasicBinaryTree.TreeNode,use this structure whereEver possible as this is generic*/
public class TreeNode<T> {
    public T val ;
    public TreeNode<T> left, right ;
    public TreeNode(T data){
        this.val = data;
        this.left = this.right = null ;
    }
}
