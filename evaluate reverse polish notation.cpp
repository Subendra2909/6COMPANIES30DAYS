class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                int z;
                if(tokens[i] == "+"){
                    z = x+y;
                }
                else if(tokens[i] == "-"){
                    z = y-x;
                }
                else if(tokens[i] == "*"){
                    z = x*y;
                }
                else{
                    z = y/x;
                }
                s.push(z);
            }
            else{
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};