/*#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    return a.exec();
}
*/
#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <regex>
#include <string>

void getAnswer(const int &first, const int &second, std::string &answer) {
    if (first != 0) {
        if (first == 1) {
            answer += std::to_string(second) + "*x"; //Вывод ключей и значений
        }
        else {
            answer += std::to_string(second) + "*x^" + std::to_string(first); //Вывод ключей и значений
        }
    }
    else {
        answer += std::to_string(second);
    }
}

int main(int argc, char *argv[])
{
    std::string answer = "";

    for (std::string polynomial; std::getline(std::cin, polynomial); answer = "") {
        if (polynomial.empty()) {
            break;
        }
        std::map<int,int> m;   //здесь храним пары степень-коэффициент

        std::regex words_regex("([\+-]?)"       // Знак
                               "([\\d]*)[\\*]?" // Коэффициент
                               "(x)[[\^]?"       // Наличие неизвестного
                               "([\\d]*)]?");     // Степень
        std::cmatch result;
        if (std::regex_search(polynomial.c_str(), result, words_regex)) {

            std::sregex_iterator pos(polynomial.cbegin(), polynomial.cend(), words_regex);  //polynomial - строка, содержащая полином
            std::sregex_iterator end;

            for(; pos != end; pos++)
            {
                int power = 0;
                int koef = 0;
                int sign = 0;

                if(pos->str(1) == "-") { sign = 1; }
                if((pos->str(4) != "0") && (pos->str(4) != "")) { power = stoi(pos->str(4)) - 1; }
                if(pos->str(2)!="") { koef = pow((-1),sign) * stoi(pos->str(2)) * (power + 1); }
                else  { koef = pow((-1),sign) * (power + 1); }
                m[power] += koef;
            }
            // вывод первого выражения, без знака "+" впереди
            auto item = m.rbegin();
            getAnswer(item->first, item->second, answer);
            // вывод последующих слагаемых, со знаком
            for(auto item = ++m.rbegin(); item != m.rend(); ++item) {
                if (item->second > 0) { answer += "+"; }
                getAnswer(item->first, item->second, answer);
            }
            std::cout << answer << std::endl;
        }
    }
    return 0;
}
