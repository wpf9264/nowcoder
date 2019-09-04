/*字符流中第一个不重复的字符*/
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         record[ch]++;
        if (record[ch]==1)
            q.push(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        while(!q.empty() && record[q.front()]!=1){
            q.pop();
        }
        return q.empty()?'#':q.front();
    }
private:
    queue<char> q;    //保存第一次好=出现的字符
    unordered_map<char,int> record;    //保存所有字符出现次数

};
