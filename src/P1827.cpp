#include <iostream>
#include <string>

using namespace std;

void postorder(string preorder, string inorder)
{
    if (preorder.empty())
    {
        return;
    }

    char root = preorder[0];
    int rootPos = inorder.find(root);
    preorder.erase(preorder.begin());

    string leftPreorder = preorder.substr(0, rootPos);
    string rightPreorder = preorder.substr(rootPos);
    string leftInorder = inorder.substr(0, rootPos);
    string rightInorder = inorder.substr(rootPos + 1);

    postorder(leftPreorder, leftInorder);
    postorder(rightPreorder, rightInorder);
    printf("%c", root);
}

int main()
{
    string preorder, inorder;
    cin >> inorder >> preorder;
    postorder(preorder, inorder);

    return 0;
}