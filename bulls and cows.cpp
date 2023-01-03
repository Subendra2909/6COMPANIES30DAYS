class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int a = 0;
        int b = 0;

        int v[] = {0,0,0,0,0,0,0,0,0,0};
        for(int i=0;i<n;i++){
            v[secret[i]-'0']++;
        }

        for(int i=0;i<n;i++){
            if(secret[i] == guess[i]){
                a++;
            }
        }

        for(int i=0;i<n;i++){
            if(v[guess[i]-'0'] > 0){
                b++;
                v[guess[i]-'0']--;
            }
        }

        string s1 = to_string(a);
        string s2 = to_string(b-a);

        string res = s1 + "A" + s2 + "B";
        return res;
    }
};