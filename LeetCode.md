这道题目描述的有些模糊
首先
```
'*' Matches zero or more of the preceding element.
```
这句话表述的意思是'\*'可以重复之前的一个字母0次或者更多次，而且它可以令之前的字母不存在，比如input："aa" "aab\*" 结果应当是true
这里新想到了一个，重复零次，代表的应当是'\*'之前的字母不存在，而不是说这字母不重复，
```
The matching should cover the entire input string (not partial).
```
这句话表述的是完全匹配，即s=p，因此，input: "ab" ".\*c"的结果是错的

这道题没有想到解法，最初的想法是直接遍历比较，当遇到'\.'以及'\*'时，单独处理，前者还好说，但后者，不好判定，比如说是input: "aaa" "a\*a"以及input: "bbbba" ".\*a\*a"这种情况时，无法判定'\*'表述的含义（是重复还是去除，重复的话，要重复多少次），这里打算先看看解法，之后在自己实现一遍
临时想到了一个思路
按照我之前的思路，问题出在‘\*上面，那么是否可以先查找所有的'\*'，对每个'\*'单独处理，判断它是重复还是清除之前的元素，这样不知道结果会是怎么样
这个想法暂时留在这里，等看完官方给的解法之后在做详细思考
这个想法的根本其实是分段比较，即讲p按照'\*'分段，之后每一段都应当与s的一部分相匹配，如果全部都匹配了，那么匹配成功，如果有匹配失败的，那么就考虑'\*'的功能（重复与清除），如果全部考虑了还是失败，那么就false
尝试了一下，后面的比较复杂，就暂时搁置吧
思路如下
1. 利用"?\*"分割p，得到了x个部分，第一个部分以及最后一个部分一定要与s相应位置的子字符串相匹配，否则就是不匹配，匹配后的子字符串将不在考虑（比如将其删除）

2. 这一步进行完之后，在s中寻找p剩下部分可以出现的位置
比如s="asdaaaaaaab",p="asda\*aac\*ad\*b", "aa"可以出现的为1、2、3、4、5，"a"可以出现的位置为1、2、3、4、5、6、7

3. 之后遍历安排每个"?\*"中'\*'所代表的含义，并结合各部分可以出现的位置（注意：序号在前面的部分可以出现的位置一定在序号靠后的部分，"aa"部分序号为2，"a"部分序号为3，当"aa"出现在1的时候"a"就不能出现在1，2的位置，因为这两个位置已经被"aa"暂用了，），只要有一个能与s完全匹配，那么结果就为true，否则为false

代码没有写完，如下
```
class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 0 && p.size() != 0)
            return false;
        if(s.size() != 0 && p.size() == 0)
            return false;
        if(s.size() == 0 && p.size() == 0)
            return true;
        string::iterator pit = p.begin();
        string::iterator sit = s.begin();
        vector<int> vec;
        vector<int>::iterator vit;
        for(pit = p.begin(); pit != p.end(); pit += 1)
        {
            //寻找所有'*'的位置
            if(*pit == '*')
                vec.push_back(pit - p.begin());
        }
        if(vec.size() == 0)
        {
            //这种情况可能能合并到后面的情况中，但是现在先不考虑
            //p中没有'*'号，此时问题就简单了
            pit = p.begin();
            sit = s.begin();
            while(pit != p.end()|| sit != s.end())
            {
                if(*pit == *sit || *pit == '.')
                {    
                    pit += 1;
                    sit += 1;
                }
                else
                    return false;
            }
            return true;
        }
        else
        {
            int pbegin = 0, pend = p.size() - 1;
            int sbegin = 0, send = s.size() - 1;
            while(pbegin < pend && sbegin < send && pbegin < vec.at(0) - 1)
            {
                //分块后的第一部分
                if(p.at(pbegin) == s.at(sbegin) || p.at(pbegin) == '.')
                {
                    pbegin += 1;
                    sbegin += 1;
                }
                else
                    return false;
            }
            while(pbegin < pend && sbegin < send && pend > vec.back())
            {
                //分块后的最后一部分
                if(p.at(pend) == s.at(send) || p.at(pend) == '.')
                {
                    pend -= 1;
                    send -= 1;
                }
                else
                    return false;            
            }
            //后续操作没有写完，TBD
            
        }

    }
};
```


