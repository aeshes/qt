#include "common.h"

#include <QThread>
#include <QString>
#include <QDebug>


Thread::Thread()
	: stopped(false)
{

}

void Thread::run()
{
	while (!stopped)
	{
		qDebug() << msg;
		QThread::msleep(1000);
	}
	stopped = false;
}

void Thread::stop()
{
	stopped = true;
}

void Thread::setMessage(const QString& str)
{
	msg = str;
}