import java.util.*;

//  Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private HashMap<Integer, Integer> hash = new HashMap<Integer, Integer>();
    private int[] postorder;
    private int lastPos;

    public TreeNode buildTree(int left, int right) {
        if (left > right) {
            return null;
        }
        TreeNode root = new TreeNode(this.postorder[this.lastPos]);
        int mid = hash.get(this.postorder[this.lastPos]);
        this.lastPos -= 1;

        // 后序遍历先左子树，后右子树，最后根节点
        root.right = buildTree(mid + 1, right);
        root.left = buildTree(left, mid - 1);
        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        this.postorder = postorder;
        this.lastPos = postorder.length - 1;
        for (int i = 0; i < inorder.length; i++) {
            hash.put(inorder[i], i);
        }
        return buildTree(0, inorder.length - 1);
    }
}