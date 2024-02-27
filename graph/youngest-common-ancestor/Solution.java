import java.util.*;

class Solution {
    private static int getDepth(AncestralTree descendantOne,
            AncestralTree topAncestor) {
        int depth = 0;
        while (descendantOne != topAncestor) {
            depth++;
            descendantOne = descendantOne.ancestor;
        }
        return depth;
    }

    public static AncestralTree getYoungestCommonAncestor(
            AncestralTree topAncestor,
            AncestralTree descendantOne,
            AncestralTree descendantTwo) {
        int depthOne = getDepth(descendantOne, topAncestor);
        int depthTwo = getDepth(descendantTwo, topAncestor);
        if (depthOne > depthTwo) {
            while (depthOne != depthTwo) {
                depthOne--;
                descendantOne = descendantOne.ancestor;
            }
        } else if (depthOne < depthTwo) {
            while (depthOne != depthTwo) {
                depthTwo--;
                descendantTwo = descendantTwo.ancestor;
            }
        }
        while (descendantOne != descendantTwo) {
            descendantOne = descendantOne.ancestor;
            descendantTwo = descendantTwo.ancestor;
        }
        return descendantOne;
    }

    static class AncestralTree {
        public char name;
        public AncestralTree ancestor;

        AncestralTree(char name) {
            this.name = name;
            this.ancestor = null;
        }

        void addAsAncestor(AncestralTree[] descendants) {
            for (AncestralTree descendant : descendants) {
                descendant.ancestor = this;
            }
        }
    }

    public static void main(String[] args) {
        AncestralTree A = new AncestralTree('A');
        AncestralTree B = new AncestralTree('B');
        AncestralTree C = new AncestralTree('C');
        AncestralTree D = new AncestralTree('D');
        AncestralTree E = new AncestralTree('E');
        AncestralTree F = new AncestralTree('F');
        AncestralTree G = new AncestralTree('G');
        AncestralTree H = new AncestralTree('H');
        AncestralTree I = new AncestralTree('I');
        AncestralTree J = new AncestralTree('J');
        AncestralTree K = new AncestralTree('K');
        A.addAsAncestor(new AncestralTree[] { B, C, D });
        B.addAsAncestor(new AncestralTree[] { E, F });
        C.addAsAncestor(new AncestralTree[] { G, H });
        E.addAsAncestor(new AncestralTree[] { I, J });
        G.addAsAncestor(new AncestralTree[] { K });
        System.out.println(getYoungestCommonAncestor(A, E, I).name);
    }
}
