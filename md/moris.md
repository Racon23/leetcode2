## 中序
```
while (p1)
{
    p2 = p1->left;
    if (p2)
    {
        while (p2->right && p2->right != p1)
        {
            p2 = p2->right;
        }
        if (!p2->right)
        {
            // 找到左子树最右节点，连接到根
            p2->right = p1;
            p1 = p1->left;
            continue;
        }
        else
        {
            // p2已经遍历过一次
            p2->right = nullptr;
            // exe p1 中
        }
    }else{
        // exe p1 最左节点 左右
        return;
    }
    p1=p1->right;
}

exe(){
    
}
```

## 前序
```
while (p1)
{
    p2 = p1->left;
    if (p2)
    {
        while (p2->right && p2->right != p1)
        {
            p2 = p2->right;
        }
        if (!p2->right)
        {
            // exe 中
            res.emplace_back(p1->val);
            p2->right = p1;
            p1 = p1->left;
            continue;
        }
        else
        {
            p2->right = nullptr;
        }
    }
    else
    {
        // 最左节点 左右
        //exe
        res.emplace_back(p1->val);
    }
    // 当最左节点空 和 该节点已经连接过时，移到右

    p1 = p1->right;
}

```


## 后序
加入后要翻转来实现
```
while (p1 != nullptr)
{
    p2 = p1->left;
    if (p2 != nullptr)
    {
        while (p2->right != nullptr && p2->right != p1)
        {
            p2 = p2->right;
        }
        if (p2->right == nullptr)
        {
            p2->right = p1;
            p1 = p1->left;
            continue;
        }
        else
        {
            p2->right = nullptr;
            // exe 中，加入左子树的单侧右节点后翻转
            addPath(res, p1->left);
        }
    }
    p1 = p1->right;
}
// 根
addPath(res, root);

void addPath(vector<int> &vec, TreeNode *node)
    {
        int count = 0;
        while (node != nullptr)
        {
            ++count;
            vec.emplace_back(node->val);
            node = node->right;
        }
        reverse(vec.end() - count, vec.end());
    }
```