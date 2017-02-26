/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {boolean}
 */
var isSymmetric = function(root) {
    if (root === null) {
        return true;
    } else {
        return isSymmetriced(root.left, root.right);
    }
};

function isSymmetriced (left, right) {
    if (left === null || right === null) {
        return left === right;
    } 
    if (left.val !== right.val) {
        return false;
    }
    
    return isSymmetriced(left.left, right.right) && isSymmetriced(left.right, right.left);
}