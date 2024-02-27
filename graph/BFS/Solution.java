import java.util.*;

class Solution {
    static class Node {
        String name;
        List<Node> children = new ArrayList<Node>();

        public Node(String name) {
            this.name = name;
        }

        public List<String> breadthFirstSearch(List<String> array) {
            Queue<Node> queue = new LinkedList<Node>();
            queue.add(this);
            while (!queue.isEmpty()) {
                Node curr = queue.poll();
                array.add(curr.name);
                queue.addAll(curr.children);
            }
            // Write your code here.
            return array;
        }

        public Node addChild(String name) {
            Node child = new Node(name);
            children.add(child);
            return this;
        }
    }

    public static void main(String[] args) {
        Node graph = new Node("A");
        graph.addChild("B");
        graph.addChild("C").addChild("D");
        graph.children.get(0).addChild("E").addChild("F");
        graph.children.get(2).addChild("G").addChild("H");
        graph.children.get(0).children.get(1).addChild("I").addChild("J");
        graph.children.get(2).children.get(0).addChild("K");
        List<String> result = graph.breadthFirstSearch(new ArrayList<String>());
        for (String s : result) {
            System.out.println(s);
        }
    }
}
