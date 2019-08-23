class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) 
    {
        int len = sequence.size();
        if(0 == len)
            return false;
        
        int i = 0;
        while(--len)
        {
            //找到右子树的开始位置
            while(sequence[i] < sequence[len])
                i++;
            //右子树的结束位置应该是len
            while(sequence[i] > sequence[len])
                i++;
            if(i<len)
                return false;
            i=0;
        }
        return true;
    }
};

/*二叉树的后序遍历序列*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return help(sequence,0,sequence.size()-1);
    }
    /*判断[left,right]是不是bst*/
    bool help(vector<int>& seq, int left, int right)
    {
        if (left>right)    return false;
        if (left==right)    return true;
        int i=left;
        while(i<right && seq[i]<seq[right]){
            i++;
        }
        int j=right-1;
        while(j>=left && seq[j]>seq[right]){
            j--;
        }
        /*bst后序的边界应该是交错的*/
        if (j+1!=i)
            return false;
        bool res=true;;
        if (j>=left)
            res&=help(seq,left,j);
        if (right-1>=i)
            res&=help(seq,i,right-1);
        return res;
    }
};
