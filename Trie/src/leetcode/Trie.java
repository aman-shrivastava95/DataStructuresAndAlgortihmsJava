package leetcode;

import nodes.TrieNode;

public class Trie {
    TrieNode root ;
    public Trie() {
        this.root = new TrieNode('#');//non-alphabetical character at the root
    }

    //method to insert in the trie
    public void insert(String word) {
        TrieNode curr = root ;
        for(int i=0; i<word.length(); i++){
            char currChar = word.charAt(i) ;
            if(curr.children[currChar-'a']==null )
                curr.children[currChar-'a'] = new TrieNode(currChar) ;
            curr = curr.children[currChar-'a'];
            curr.prefixCount++ ;
        }
        curr.endsHere = true ;
        curr.endCount++ ;
    }
    public int search(String word) {
        TrieNode res  = hasPrefix(word) ;
        if(res==null) return 0 ;
        return res.endCount ;
    }
    public TrieNode hasPrefix(String word){
        TrieNode curr = root ;
        for(char ch: word.toCharArray()){
            if(curr.children[ch - 'a']==null)
                return null ;
            curr = curr.children[ch - 'a'];
        }
        return curr ;
    }

    public boolean startsWith(String prefix) {
        return hasPrefix(prefix)!=null ;
    }
}
