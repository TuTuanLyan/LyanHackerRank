#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'downToZero' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER n as parameter.
 */

int downToZero(int n) {
    if(n <= 3) return n;
    vector<bool> save(n, false);
    queue<pair<int, int>> run;
    int step = 0;
    run.push({n, step});
    
    while(!run.empty()) {
        n = run.front().first;
        step = run.front().second;
        run.pop();
        
        if(n <= 1) {
            if(n == 1) step++;
            break;
        }
        
        if(!save[n - 1]) {
            save[n - 1] = true;
            run.push({n - 1, step + 1});
        }
        
        for(int i = sqrt(n); i >= 2; i--) {
            if(n % i == 0) {
                int fac = n/i > i ? n/i : i;
                if(!save[fac]) {
                    run.push({fac, step + 1});
                    save[fac] = true;
                }
            }
        }
    }
    
    return step;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        int result = downToZero(n);

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
