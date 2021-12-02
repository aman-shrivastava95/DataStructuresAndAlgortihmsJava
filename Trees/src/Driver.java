import BasicBinaryTree.BinaryTree;
import PreBuiltTrees.IntegerTree;
import Questions.* ;


/**
 * this is the main class for running all the test cases for leetcode questions and also for the basic implementation testing for the data structure and algorithms
 */
public class Driver {
    public static void main(String[] args) {
        //we can have all the tests here categorized  as different methods
        //basicBinaryTreeTests() ;
        questionsTest() ;
        //basicBinaryTreeTests();
    }


    /**
     * method to run solutions for leetcode problems
     */
    private static void questionsTest() {
        //create a tree, from prebuilt tree and then pass them accordingly
        IntegerTree tree = new IntegerTree(new Integer[]{1,2,3,4,5,6,7}) ;
        LeetCode257_RootToLeafPath q = new LeetCode257_RootToLeafPath() ;
        for(String str:q.solve(tree.root)){
            System.out.println(str);
        }
    }

    /**
     * method to run basic implementations of data structure and alogrithms
     */
    private static void basicBinaryTreeTests() {
        //good way of creating a tree for testing, if we want a complete tree, for custom tree,with custom tree structure, we need to create manually
        //this is the basic binary tree
        BinaryTree<Integer> tree = new BinaryTree<>() ;
        for(int i=1; i<8; i++){
            tree.levelOrderInsert(i);
        }
        System.out.println(tree.getheight(tree.root));
    }
}
