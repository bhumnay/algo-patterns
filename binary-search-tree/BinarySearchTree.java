import java.util.ConcurrentModificationException;
import java.util.Iterator;
import java.util.Stack;

public class BinarySearchTree<T extends Comparable<T>> {
    private int countNode = 0;
    private Node root = null;

    private class Node {
        T data;
        Node left = null, right = null;

        public Node(T data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
    }

    public boolean add(T value) {
        if (contains(value)) {
            return false;
        }
        root = add(root, value);
        countNode++;
        return true;
    }

    private Node add(Node root, T value) {
        if (root == null)
            return new Node(value, null, null);
        if (value.compareTo(root.data) < 0) {
            root.left = add(root.left, value);
        } else if (value.compareTo(root.data) > 0) {
            root.right = add(root.right, value);
        }
        return root;
    }

    public boolean contains(T value) {
        if (root == null)
            return false;
        return contains(root, value);
    }

    private boolean contains(Node root, T value) {
        if (root == null)
            return false;
        if (root.data.compareTo(value) == 0)
            return true;
        if (value.compareTo(root.data) < 0)
            return contains(root.left, value);
        return contains(root.right, value);
    }

    public boolean remove(T value) {
        if (!contains(value) || root == null)
            return false;
        root = remove(root, value);
        countNode--;
        return true;
    }

    private Node remove(Node root, T value) {
        if (root == null)
            return root;
        if (value.compareTo(root.data) < 0) {
            root.left = remove(root.left, value);
        } else if (value.compareTo(root.data) > 0) {
            root.right = remove(root.right, value);
        } else {
            if (root.left == null) {
                return root.right;
            }
            if (root.right == null) {
                return root.left;
            }
            T rightMin = getMinValue(root.right);
            root.data = rightMin;
            root.right = remove(root.right, rightMin);
        }
        return root;
    }

    private T getMinValue(Node root) {
        if (root.left == null)
            return root.data;
        return getMinValue(root.left);
    }

    public Iterator<T> traverse(TreeTraversalOrder order) {
        switch (order) {
            case TreeTraversalOrder.IN_ORDER:
                return iterativeInOrder();
            default:
                break;
        }
        return null;
    }

    private Iterator<T> iterativeInOrder() {
        final int expectedNodeCount = countNode;
        Stack<Node> stackOfNodes = new Stack<>();
        return new Iterator<T>() {
            Node curr = root;

            @Override
            public boolean hasNext() {
                if (expectedNodeCount != countNode)
                    throw new ConcurrentModificationException();
                return !stackOfNodes.isEmpty() || curr != null;
            }

            @Override
            public T next() {
                if (expectedNodeCount != countNode)
                    throw new ConcurrentModificationException();
                while (curr != null) {
                    stackOfNodes.push(curr);
                    curr = curr.left;
                }
                curr = stackOfNodes.pop();
                Node temp = curr;
                curr = curr.right;
                return temp.data;
            }
        };
    }

    public static void main(String[] args) {
        BinarySearchTree<Integer> bstExample = new BinarySearchTree<Integer>();
        bstExample.add(5);
        bstExample.add(1);
        bstExample.add(6);
        bstExample.add(2);
        bstExample.add(0);
        Iterator it = bstExample.traverse(TreeTraversalOrder.IN_ORDER);
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }

}

enum TreeTraversalOrder {
    PRE_ORDER,
    IN_ORDER,
    POST_ORDER,
    LEVEL_ORDER
}
