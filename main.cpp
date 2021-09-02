#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <ctime>

using namespace std;

#define MAX_OPERATOR_NUM 5
#define MAX_QUESTION_NUM 10
#define MAX_NUM_VALUE 20
#define MAX_PAIR_PARENTHESES 5
/*
 * 支持真分数
 * 倒计时
 * 括号
 * 移植到网页程序
 */

struct Config {
    string language{"CN"};
    int numOfQuestions = 0;
};

void initSystem(const struct Config &configs);

string compute(const string &question);

void ansInput(vector<string> &userAns);

bool response(const string &rightAns, const string &userAns);

// Main
int main(int argc, char *argv[]) {

    struct Config myConfig{};
    myConfig.numOfQuestions = MAX_QUESTION_NUM;
    //  Init
    initSystem(myConfig);

    //  Operators
    vector<string> operators{"×", "÷", "+", "-"};

    int numOfQuestions = myConfig.numOfQuestions;
    vector<string> questions(numOfQuestions), ans;
    ans.reserve(numOfQuestions);

    //  Generating questions
    srand((unsigned) time(nullptr));
    printf("Num of questions:%d\n", numOfQuestions);
//    printf("numOfOperator\tnumOfNumber\tPairOfParentheses\n");

    for (auto &question: questions) {
        string tempQes, tempAns;

        //  Generating question and answer
        unsigned int numOfOperators = (unsigned int) (rand() % (MAX_OPERATOR_NUM - 1)) + 1,
                numOfNumber = numOfOperators + 1,
                pairOfParentheses = (rand() % MAX_PAIR_PARENTHESES);
//        printf("%u\t%u\t%u\n", numOfOperators, numOfNumber, pairOfParentheses);

        tempQes += to_string((rand() % MAX_NUM_VALUE));
        for (int i = 0; i < numOfOperators; i++) {
            bool WhetherToGenerateParentheses = (bool) (rand() & 1);

            string ope = operators.at((rand() % operators.size()));
            tempQes += ope;
            int num = (rand() % MAX_NUM_VALUE);
            tempQes += to_string(num);
        }
//        tempAns = compute(tempQes);
        cout << tempQes << '\t' << tempAns << endl;
        //  restore
        question = move(tempQes);
        ans.emplace_back(move(tempAns));
    }

#if 0
    unsigned long score = 0;
    vector<string> userAns;
    ansInput(userAns);
    for (int i = 0; i < numOfQuestions; i++) {
        if (response(ans.at(i), userAns.at(i))) {
            cout << i << " Right!!!" << endl;
            score++;
        } else {
            cout << i << " Wrong!!!\t";
            cout << "The Right Answer is " << ans.at(i);
        }
    }

    cout << "最终成绩为: " << score << endl;
#endif
    return 0;
}

void initSystem(const struct Config &configs) {
    //  Init languages
    map<string, vector<string>> languages{{"CN", vector<string>{}},
                                          {"EN", vector<string>{}}};
    vector<string> usingLanguage = languages[configs.language];
}

string compute(const string &question) {
    string ans{"hello"};

    return ans;
}

void ansInput(vector<string> &userAns) {
    userAns = vector<string>{
            "10",
            "23",
            "3",
            "100",
    };
}

bool response(const string &rightAns, const string &userAns) {
    return rightAns == userAns;
}

