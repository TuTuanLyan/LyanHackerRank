#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'largestRectangle' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY h as parameter.
 */

int largestRectangle(vector<int> h) {
    int maxA = 0;
    int n = h.size();
    stack<int> save;
    int curA;
    
    for(int i = 0; i < n; i++) {
        while(!save.empty() && h[save.top()] > h[i]) {
            int cur = save.top();
            save.pop();
            curA = h[cur] * (save.empty() ? i : (i - save.top() - 1));
            maxA = curA > maxA ? curA : maxA;
        }
        save.push(i);
    }
    
    while(!save.empty()) {
        int cur = save.top();
        save.pop();
        curA = h[cur] * (save.empty() ? n : (n - save.top() - 1));
        maxA = curA > maxA ? curA : maxA;
    }
    
    return maxA;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string h_temp_temp;
    getline(cin, h_temp_temp);

    vector<string> h_temp = split(rtrim(h_temp_temp));

    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        int h_item = stoi(h_temp[i]);

        h[i] = h_item;
    }

    long result = largestRectangle(h);

    fout << result << "\n";

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
