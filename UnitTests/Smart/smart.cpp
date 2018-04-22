#include "smart.h"

Smart::Smart(QObject* parent)
    : QObject(parent)
{

}

int Smart::min(int a, int b)
{
    return a < b ? a : b;
}

int Smart::max(int a, int b)
{
    return a < b ? b : a;
}
