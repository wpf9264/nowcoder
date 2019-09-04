/*数组中重复的数字*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    /*
    bool duplicate(int numbers[], int length, int* duplication) {
        set<int> record;
        for(int i=0; i<length; ++i){
            auto iter=record.find(numbers[i]);
            if (iter==record.end()){
                record.insert(numbers[i]);
            }else{
                *duplication=numbers[i];
                return true;
            }
        }
        return false;
    }
    */
    /*这种方法不好,会溢出,会改变原值*/
    bool duplicate(int numbers[], int length, int* duplication)
    {
        /*对于numbers[index],如果numbers[index]>length 说明角标index已经出现过*/
        for(int i=0;i<length;++i)
        {
            int index = numbers[i] % length;
            if(numbers[index] >= length)
            {
                *duplication = index;
                return true;
            }
            numbers[index] += length;
        }
        return false;
    }
};
