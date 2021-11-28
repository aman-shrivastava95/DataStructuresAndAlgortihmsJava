package leetcode;

import nodes.TrieNode;

public class DistinctSubstrings {
    public int  countDistinctSubstring(String s){
        //basic idea is inserting all the substrings in the trie and counting the nodes in the trie
        //which is the answer.
        int count = 0;
        TrieNode root = new TrieNode('#');
        for (int i = 0; i < s.length(); i++) {
            TrieNode node = root ;
            for (int j = i; j <s.length(); j++) {
                if(node.children[s.charAt(j)-'a']==null){
                    node.children[s.charAt(j)-'a']=new TrieNode(s.charAt(j));
                    count++ ;
                }
                node = node.children[s.charAt(j)-'a'];
            }
        }
        return count + 1 ;//one extra for empty spaces
    }
}
