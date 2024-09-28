#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'stoneDivision' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. LONG_INTEGER n
 *  2. LONG_INTEGER_ARRAY s
 */


long Count(long n, long p, const vector<long> &s, unordered_map<long, long> &save){
    if(save.find(n) != save.end()) return save[n];
    
    long cnt = 0;
    
    for(auto &x : s){
        if(x >= n) return save[n] = cnt;
        if(n % x == 0){
            cnt = max(cnt, Count(x, n*p/x, s, save) + p);
        }
    }
    
    return save[n] = cnt;
}

long stoneDivision(long n, vector<long> s) {
    unordered_map<long, long> save;
    save.clear();
    sort(s.begin(), s.end());
    return Count(n, 1, s, save);                     
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        long n = stol(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        string s_temp_temp;
        getline(cin, s_temp_temp);

        vector<string> s_temp = split(rtrim(s_temp_temp));

        vector<long> s(m);

        for (int i = 0; i < m; i++) {
            long s_item = stol(s_temp[i]);

            s[i] = s_item;
        }

        long result = stoneDivision(n, s);

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
