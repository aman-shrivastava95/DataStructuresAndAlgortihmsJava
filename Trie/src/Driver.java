import leetcode.Trie;

public class Driver {
    public static void main(String[] args) {
        Trie t = new Trie() ;
        t.insert("apple");
        t.insert("apple");
        t.insert("app");
        t.insert("popo");
        System.out.println(t.search("apple"));
        System.out.println(t.hasPrefix("app").prefixCount);
        System.out.println(t.hasPrefix("kk")==null?0:t.hasPrefix("kk").prefixCount);
        System.out.println(t.search("popo"));

    }
}
