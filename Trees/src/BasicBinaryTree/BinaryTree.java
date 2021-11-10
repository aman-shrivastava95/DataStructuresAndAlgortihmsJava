package BasicBinaryTree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class BinaryTree<T> {
    //making it public so that it is accessible outside the root
    public TreeNode<T> root ;
    public BinaryTree() {
        this.root = null ;
        System.out.println("Binary tree created with a null node");
    }

    //method to insert data level order in a binary tree
    public void levelOrderInsert(T data){
        Queue<TreeNode<T>> q = new LinkedList<>() ;
        if(root == null)
        {
            root = new TreeNode<T>(data) ;
            return ;
        }
        q.add(root) ;
        while(!q.isEmpty()){
            TreeNode<T> curr = q.poll() ;
            if(curr.left==null){
                curr.left  = new TreeNode<T>(data) ;
                break ;
            }else{
                q.add(curr.left) ;
            }
            if(curr.right==null){
                curr.right  = new TreeNode<T>(data) ;
                break ;
            }else{
                q.add(curr.right) ;
            }
        }
    }

    //inorder : recursive and iterative
    public void inorder(TreeNode<T> node){
        if(node!=null){
            inorder(node.left);
            System.out.print(node.val + " ");
            inorder(node.right);
        }
    }
    public void inorderIterative(){
        TreeNode<T> curr = this.root ;
        Stack<TreeNode<T>> s = new Stack<>();
        while(true){
            if(curr!=null){
                s.push(curr) ;
                curr = curr.left ;
            }else{
                if(s.empty())
                    break ;
                curr = s.pop() ;
                System.out.print(curr.val+ " ");
                curr = curr.right ;
            }
        }
    }

    //preOrder: recursive and iterative
    public void preorder(TreeNode<T> node){
        if(node!=null){
            System.out.print(node.val + " ");
            preorder(node.left);
            preorder(node.right);
        }
    }
    public void preorderIterative(){
        Stack<TreeNode<T>> s  = new Stack<>() ;
        TreeNode<T> curr = this.root ;
        while(true){
            if(curr!=null){
                System.out.print(curr.val + " ");
                s.push(curr) ;
                curr = curr.left ;
            }else{
                if(s.empty())break ;
                curr = s.pop() ;
                curr = curr.right ;
            }
        }
    }

    //postorder: recursive and iterative(two stack) and iterative (one stack)
    public void postOrder(TreeNode<T> node){
        if(node !=null){
            postOrder(node.left);
            postOrder(node.right);
            System.out.print(node.val + " ");
        }
    }
    public void iterativePostOrderTwoStack(){
        TreeNode<T> curr = root ;
        Stack<TreeNode<T>> s  = new Stack<>() ;
        Stack<TreeNode<T>> res  =  new Stack<>() ;
        s.push(root) ;
        while(!s.empty()){
           curr  = s.pop() ;
           res.push(curr) ;
           if(curr.left!=null)
               s.push(curr.left) ;
           if(curr.right!=null)
               s.push(curr.right) ;
        }
        //build the answer with res
        while(!res.empty()){
            System.out.print(res.pop().val+ " ");
        }
    }
    public void iterativePostOrderOneStack(){
        TreeNode<T> curr = root ;
        Stack<TreeNode<T>> s = new Stack<>() ;
        while(curr != null || !s.empty()){
            if(curr!=null){
                s.push(curr) ;
                curr  =curr.left ;
            }else{
                //it can have a right child to explore
                TreeNode<T> temp = s.peek().right ;
                if(temp!=null){
                    curr = temp ;
                }else{
                    temp = s.pop() ;
                    System.out.print(temp.val + " ");
                    while(!s.empty() && temp == s.peek().right){
                        temp = s.pop() ;
                        System.out.print(temp.val+ " ");
                    }
                }
            }
        }
    }

    //use of threaded binary trees
    public void morrisInorder(){
        TreeNode<T> curr  = this.root ;
        Stack<TreeNode<T>> s = new Stack<>() ;
        while(curr != null){
            if(curr.left==null){
                System.out.print(curr.val+ " ");
                curr = curr.right ;
            }else{
                TreeNode<T> prev = curr.left ;
                while(prev.right!=null && prev.right!=curr){
                    prev = prev.right ;
                }
                if(prev.right==null){
                    prev.right = curr ;
                    curr = curr.left ;
                }else{
                    prev.right = null ;
                    System.out.print(curr.val+ " ");
                    curr = curr.right ;
                }
            }
        }
    }
    public void morrisPreorder(){
        TreeNode<T> curr  = this.root ;
        Stack<TreeNode<T>> s = new Stack<>() ;
        while(curr != null){
            if(curr.left==null){
                System.out.print(curr.val+ " ");
                curr = curr.right ;
            }else{
                TreeNode<T> prev = curr.left ;
                while(prev.right!=null && prev.right!=curr){
                    prev = prev.right ;
                }
                if(prev.right==null){
                    prev.right = curr ;
                    System.out.print(curr.val+ " ");
                    curr = curr.left ;
                }else{
                    prev.right = null ;
                    curr = curr.right ;
                }
            }
        }
    }

    //height of the binary tree
    public int getheight(TreeNode<T> node){
        //using dfs(recursive) approach here, this can be done with bfs using queue here, but that can end up taking a lot of space, visualize the last level of a complete binary tree
        if(node==null) return 0 ;
        return 1 + Math.max(getheight(node.right) ,getheight(node.left)) ;
    }
}















