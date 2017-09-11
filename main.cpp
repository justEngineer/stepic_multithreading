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
    std::cin >> temp;
    std::cout << "Hello World!" + temp << std::endl;
    system("PAUSE"); // <---
    return 0;
}
