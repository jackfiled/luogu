#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

void preorder(string& inorder, string& postorder)
{
    if (inorder.empty())
    {
        return;
    }

    char root = postorder[postorder.length() - 1];
    int rootPos = inorder.find(root);
    // 从后序遍历中删除根节点
    postorder.erase(postorder.length() - 1);

    printf("%c", root);

    string leftInorder = inorder.substr(0, rootPos);
    string leftPostorder = postorder.substr(0, rootPos);
    preorder(leftInorder, leftPostorder);

    string rightInorder = inorder.substr(rootPos + 1);
    string rightPostorder = postorder.substr(rootPos);
    preorder(rightInorder, rightPostorder);
}

int main()
{
    string inorder, postorder;
    cin >> inorder >> postorder;

    preorder(inorder, postorder);
    printf("\n");
    return 0;
}