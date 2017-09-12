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

//using namespace std;

int main(int argc, char *argv[])
{
/*
    std::map<std::string, std::vector<int>> map;
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    map["one"] = v;


    std::vector<int> v2;
    v2.push_back(11);
    v2.push_back(12);
    v2.push_back(13);
    map["two"] = v2;

    for(const auto &kvp: map)
    {
       std::cout << kvp.first << std::endl;
       for(auto &v: kvp.second)
          std::cout << v << std::endl;
    }

    int arr[] = {1,2,3,4,5};

    for(int &e: arr) {
       e *= e;
       std::cout << e << std::endl;
    }
//    system("PAUSE"); // <---
    return 0;
*/
    std::string polynomial = "-2*x^5+5";
    std::map<int,int> m;   //здесь храним пары степень-коэффициент
/*    while (std::cin >> polynomial) {
        if (polynomial == "") {
            break;
        }
*/
//        std::regex r("([\+-]?)([\d]*)\\*?(x?)\\^?([\d]*)");

//      std::regex words_regex("([\+-]?)([[:d:]]*)[\\*?]x?\^?([[:d:]]*)"/*, std::regex_constants::basic*/);
//        std::regex words_regex("([\+-]?)([\d]*)\\*?(x?)\\^?([\d]*)");
        std::regex words_regex("([\+-]?)([\\d]*)[\\*]?(x?)[\^]?([\\d]*)");
        std::cmatch result;
//        std::sregex_iterator pos(polynomial.begin(), polynomial.end(), words_regex);  //polynomial - строка, содержащая полином
//        std::sregex_iterator end;


//        for(auto pos = pos.begin(), pos != pos.end(); pos++)
        if (std::regex_search(polynomial.c_str(), result, words_regex))
        {
            std::cout << "Gotcha!!!" << std::endl;
            for(auto &e: result) {
               std::cout << e << std::endl;
            }
            /*
            int power=1;
            int koef=0;
            bool sign=0;
            int s=0;

            if (result[3]=="x") {
                if(result[1]=="-") {
                    s=1;
                }
                koef = ((-1)^s)*stoi(result[2]);
                power = stoi(result[4]) - 1;
            }
/*
            if(pos->str(4)!="") power = stoi(pos->str(4));
            if(pos->str(3)!="x") power=0;
            if(pos->str(1)=="-") sign=0;
            if(pos->str(2)!="") koef=sign?(stoi(pos->str(2))):(-stoi(pos->str(2)));
            else if(pos->str(3)=="x") koef=sign?1:-1;
            else koef=0;
*//*
            m[power]+=koef;
            */
        }
        else {
            std::cout << "Nope :(" << std::endl;
        }
        for(auto& item : m)
        {
            std::cout << item.first << " : " << item.second << std::endl; //Вывод ключей и значений
        }
        /*
        for(auto &kvp: m)
        {
           std::cout << kvp.first << std::endl;
           for(auto &v: kvp.second) {
              std::cout << v << std::endl;
           }
        }
        */
//    std::cout << "Hello World!" << std::endl;
//    }
    system("PAUSE"); // <---
    return 0;

}
