#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

class Solution {
public:
    int checkNumber(string num){
        int start = 0;
        if (num[0] == '-'){
            start = 1;
        }
        for (int i = start; i < num.size(); i++){
            if (!isdigit(num[i])){
                return false;
            }
        }
        return true;
    }
    
    int calPoints(vector<string>& operations) {
        vector<int> answers = {};
        int sum = 0;
        for (int i = 0; i < operations.size(); i++){
            if (checkNumber(operations[i])){
                answers.push_back(stoi(operations[i]));
            }else if(operations[i] == "C"){
                answers.pop_back();
            }else if(operations[i] == "D"){
                int doubleNum = answers.back() * 2;
                answers.push_back(doubleNum);
            }else if(operations[i] == "+"){
                int length = answers.size()-1;
                int numOne = answers[length];
                length -= 1;
                int numTwo = answers[length];
                int total = numOne + numTwo;
                answers.push_back(total);
            }
        }
        for (int a: answers){
            sum += a;
        }
        return sum;
    }
};

int main()
{
	vector<string> ops = {"5","-2","4","C","D","9","+","+"};
	Solution s;
	int ans = s.calPoints(ops);
	cout << ans;
	return 0;
}