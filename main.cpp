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

//using namespace std;

int main(int argc, char *argv[])
{
    std::string temp;
    map<int,int> m;   //здесь храним пары степень-коэффициент
        regex r("([\+-]?)([\d]]*)\\*?(x?)\\^?([\d]*)");
        sregex_iterator pos(polynomial.cbegin(),polynomial.cend(),r);  //polynomial - строка, содержащая полином
        sregex_iterator end;
        for(;pos!=end;pos++)
        {
            int power=1;
            int koef=0;
            bool sign=1;
            if(pos->str(4)!="") power = stoi(pos->str(4));
            if(pos->str(3)!="x") power=0;
            if(pos->str(1)=="-") sign=0;
            if(pos->str(2)!="") koef=sign?(stoi(pos->str(2))):(-stoi(pos->str(2)));
            else if(pos->str(3)=="x") koef=sign?1:-1;
            else koef=0;
            m[power]+=koef;
        }
    std::cin >> temp;
    std::cout << "Hello World!" + temp << std::endl;
    system("PAUSE"); // <---
    return 0;
}
