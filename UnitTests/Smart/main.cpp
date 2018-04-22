#include <QCoreApplication>
#include <QTest>

#include "test_smart.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTest::qExec(new Test_Smart, argc, argv);

    return a.exec();
}
