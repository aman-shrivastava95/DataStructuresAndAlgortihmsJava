package nodes;

//node for a Trie, this can vary depending on the use case, no fixed schema for this
public class TrieNode {
    public char ch ;
    public boolean endsHere;
    public int endCount;
    public int prefixCount ;
    public TrieNode[] children;
    public TrieNode(char ch){
        this.ch = ch ;
        children = new TrieNode[26] ;
        this.endsHere = false ;
        this.endCount = 0 ;
        this.prefixCount = 0 ;
    }
}
