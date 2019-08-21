class Solution {
public:
	void replaceSpace(char *str,int length) {
        if (str==nullptr || length<=0)    
            return;
        int numOfSpace=0,oldLen=0;
        char* p=str;        //指向源字符串
        while(*p!='\0'){
            oldLen++;
            if (*p==' '){
                numOfSpace++;
            }
            p++;
        }
        int newLen=oldLen+2*numOfSpace;
        char* q=str+newLen;    //指向新串的末尾
        while(q!=p){
            if (*p!=' '){
                *q--=*p;
            }else{
                *(q--)='0';
                *(q--)='2';
                *(q--)='%';
            }
            p--;
        }
        return ;
	}
};
