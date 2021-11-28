package leetcode;

import nodes.TrieNode;

//a complete string is a string whose all the prefix are present in the same array
public class CompleteStrings {
    public String solve(String[] arr){
        String res = "NONE"  ;
        //step 1: create a trie and insert all the word in the trie
        Trie t = new Trie() ;
        for(String word:arr){
            t.insert(word);
        }
        //check words one by one if it has all the prefix in the tree
        for(String word:arr){
            int currCount =  0 ;
            TrieNode temp = t.root ;

            //for a given word , if all the prefixes are present in the trie, then all the nodes along the
            //way will have ends here set to true
            for(int i=0;i<word.length();i++){
                if(temp.children[word.charAt(i)-'a']!=null){
                    if(temp.children[word.charAt(i)-'a'].endsHere){
                        currCount++ ;
                        temp = temp.children[word.charAt(i)-'a'] ;
                    }else{
                        break ;
                    }
                }
                if(currCount==word.length()){
                    //this means that all the prefix are present in the trie
                    if("NONE".equals(res) || word.length() > res.length() || (word.length() == res.length() && word.compareTo(res) < 0))
                        //if the lenght of res and current string is same, checking for which is lexicographically smaller
                        res = word ;
                }
            }
        }
        return res ;
    }
}
