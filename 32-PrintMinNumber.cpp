/*标书组排成最小的数*/
class Solution {
public:
    struct Comp{
        bool operator()(const int a,const int b)const{
            string s1=to_string(a)+to_string(b);
            string s2=to_string(b)+to_string(a);
            return s1<s2;
        }
    };
    
    string PrintMinNumber(vector<int> numbers) {
        string res="";
        sort(numbers.begin(),numbers.end(),Comp{});
        for(auto&x:numbers){
            res+=to_string(x);
        }
        return res;
    }
};
/*
            两个整型数字组合后可能出现大数，因此转换到字符形式
            因为是组合出最小数，那我们可以将所有的数字按“从小到大”排列
            这里我们需要重新定义我们需要的“大小”关系
            组合a=3和b=32两个数字有 s1=“332”，s2=“323” 
            对于我们来说 s1>s2 因此我们 定为 a>b
            排序之后只需要将所有的数字按顺序转换为字符进行拼接即可
        */
/*
        sort中的比较函数compare要声明为静态成员函数或全局函数，
        不能作为普通成员函数，否则会报错。因为：非静态成员函数是
        依赖于具体对象的，而std :: sort这类函数是全局的，因此无
        法在排序中调用非静态成员函数。静态成员函数或者全局函数是不
        依赖于具体对象的，可以独立访问，无须创建任何对象实例就可访
        问。同时静态成员函数不可以调用类的非静态成员。
    */
