#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


unordered_map<string, bool> memo;
string res = "";

bool recur(const vector<string>& passwords, const string& target, string& cur) {
    if (target.empty()) {
        res = cur;
        return true;
    }

    if (memo.find(target) != memo.end()) return memo[target];

    for (const string& password : passwords) {
        if (target.find(password) == 0) {
            string next = target.substr(password.size());
            string oldCur = cur;
            if (!cur.empty()) cur += " ";
            cur += password;

            if (recur(passwords, next, cur)) {
                return memo[target] = true;
            }

            cur = oldCur;
        }
    }

    return memo[target] = false;
}

string passwordCracker(vector<string> passwords, string loginAttempt) {
    memo.clear();
    res = "";
    string cur = "";
    
    string concat = "";
    for (const auto& p : passwords) concat += p;
    
    set<char> pwSet(concat.begin(), concat.end());
    set<char> lASet(loginAttempt.begin(), loginAttempt.end());
    
    for (char c : lASet) {
        if (pwSet.find(c) == pwSet.end()) return "WRONG PASSWORD";
    }

    if (recur(passwords, loginAttempt, cur)) {
        return res;
    }
    
    return "WRONG PASSWORD";
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string passwords_temp_temp;
        getline(cin, passwords_temp_temp);

        vector<string> passwords_temp = split(rtrim(passwords_temp_temp));

        vector<string> passwords(n);

        for (int i = 0; i < n; i++) {
            string passwords_item = passwords_temp[i];

            passwords[i] = passwords_item;
        }

        string loginAttempt;
        getline(cin, loginAttempt);

        string result = passwordCracker(passwords, loginAttempt);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
