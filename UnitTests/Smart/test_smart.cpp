#include <QTest>

#include "test_smart.h"
#include "smart.h"

Test_Smart::Test_Smart(QObject* parent)
    : QObject(parent)
{

}

void Test_Smart::max()
{
    Smart s;
    QCOMPARE(s.max(1, 0), 1);
    QCOMPARE(s.max(-1, 1), 1);
    QCOMPARE(s.max(4, 8), 8);
    QCOMPARE(s.max(0, 0), 0);
    QCOMPARE(s.max(1, 1), 1);
    QCOMPARE(s.max(-10, -5), -5);
}

void Test_Smart::min_data()
{
    QTest::addColumn<int>("first");
    QTest::addColumn<int>("second");
    QTest::addColumn<int>("result");

    QTest::newRow("min_data_1") << 1 << 0 << 0;
    QTest::newRow("min_data_2") << -1 << 1 << -1;
    QTest::newRow("min_data_3") << 4 << 8 << 4;
    QTest::newRow("min_data_4") << 0 << 0 << 0;
    QTest::newRow("min_data_5") << 1 << 1 << 1;
    QTest::newRow("min_data_6") << -10 << -5 << -10;
}

void Test_Smart::min()
{
    Smart s;
    QFETCH(int, first);
    QFETCH(int, second);
    QFETCH(int, result);
    QCOMPARE(s.min(first, second), result);
}
