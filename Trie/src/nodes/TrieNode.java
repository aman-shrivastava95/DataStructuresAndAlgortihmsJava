package nodes;

public class TrieNode {
    public char ch ;
    public boolean endshere = false ;
    public TrieNode[] children;
    public TrieNode(char ch){
        this.ch = ch ;
        children = new TrieNode[26] ;
    }
}
