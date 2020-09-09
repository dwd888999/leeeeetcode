
#include <iostream>
#include <vector>
using namespace std;

//����һ����������, ����������ҵ����и�����ĵ��������У����������еĳ���������2��

//ʾ��:

// ����: [4, 6, 7, 7]
// ���: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
// ˵��:

// 1����������ĳ��Ȳ��ᳬ��15��
// 2�������е�������Χ��?[-100,100]��
// 3�����������п��ܰ����ظ����֣���ȵ�����Ӧ�ñ���Ϊ������һ�������
//
// [4,2,7,7]
//                  []
//         4   2     7   7
//     2 7 7   7 7   7      �޿�ѡ


class Solution {
public:
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtracking(nums, 0);
        return ret;
    }
    // �����㷨
    // ������Ҫ�������ȥ��
    // �ڵݹ��ͬһ�������ֱ���ͬһ������set��¼����ݹ��Ƿ�ʹ�õ�ǰֵ

    void backtracking(vector<int> nums, int begin){
        // if(begin >= nums.size()) return;
        if(tmp.size() >= 2){
            ret.push_back(tmp);
        }
        // std::set<int> s; 
        vector<int> s(201, 0);  //��vector����set
        for(int i = begin; i < nums.size(); i++){
            if(tmp.size() > 0 && nums[i] < tmp[tmp.size() - 1] || s[nums[i] + 100] == 1) continue; 
            tmp.push_back(nums[i]);
            s[nums[i] + 100] = 1;
            // s.insert(nums[i]);
            backtracking(nums, i + 1);
            tmp.pop_back();
        }
    }

};

