#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

    /*
     N - number of hours
     M - number of topics
     t[i] - number of hours required by i topic
     k[i] - number of questions in i topic
     calculates maximum number of questions can be learned and
     returns indexes of learned topics
     */
    unordered_set<int> learnedTopics(int N, int M, const vector<int> &t, const vector<int> &k) {
        /*
        dp[i][j] = max number of questions can be learned for time j among first i topics
        */
        vector<vector<int>> dp(M + 1, vector<int> (N + 1));
        vector<vector<pair<int,int>>> relaxedByPosition(M + 1, vector<pair<int,int>> (N + 1, {-1,-1}));
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                dp[i][j] = dp[i - 1][j];
                relaxedByPosition[i][j] = {i-1, j}; // we are not taking topic i-1
                if (t[i-1] <= j) {
                    int value = dp[i - 1][j - t[i-1]] + k[i-1];
                    if(value > dp[i][j]) {
                        dp[i][j] = value;   // we are taking topic i-1
                        relaxedByPosition[i][j] = {i - 1, j - t[i-1]};
                    }
                }
            }
        }
        unordered_set<int> topics;
        auto [i,j] = make_pair(M, N);
        while(make_pair(i,j) != make_pair(-1,-1)) {
            if(relaxedByPosition[i][j] != make_pair(-1, -1)
               && relaxedByPosition[i][j] != make_pair(i-1, j)) {
                topics.insert(i-1);
            }
            auto [i1, j1] = relaxedByPosition[i][j];
            swap(i, i1);
            swap(j, j1);
        }
        return topics;
    }

    /*
     askedQuestions[i] = index of topic of question i
     returns a mark student gets (mark is in [0,1]) and learned topics indexes
    */
    pair<double, unordered_set<int>> test(int N, int M, const vector<int> &t, const vector<int> &k, const vector<int> & askedQuestions) {
        if(askedQuestions.empty()) {
            return {1,{}};
        }
        auto learned = learnedTopics(N, M, t, k);
        int answered = 0;
        for(auto q : askedQuestions) {
            if(learned.count(q)) {
                answered++;
            }
        }
        double result = static_cast<double>(answered) / askedQuestions.size();
        return {result, learned};
    }

    void readVector(vector<int> &vec) {
        for(int & i : vec) {
            cin >> i;
        }
    }

    void printAnswer(double mark, const unordered_set<int> & learned) {
        string answer = "Mark out of 1 is " + to_string(mark) +
                ".\n(Learned topics : [";
        for(auto topic : learned) {
            answer += to_string(topic) + ",";
        }
        if(answer.back() == ',') {
            answer[answer.size()-1] = ']';
        } else {
            answer += ']';
        }
        answer += ')';
        cout << answer;
    }

    void solve() {
        int N, M, L;
        cin >> N;
        cin >> M;
        vector<int> t(M);
        vector<int> k(M);
        readVector(t);
        readVector(k);
        cin >> L;
        vector<int> asked(L);
        readVector(asked);
        auto[mark, learned] = test(N, M, t, k, asked);
        printAnswer(mark, learned);
    }

int main() {
    solve();
}
