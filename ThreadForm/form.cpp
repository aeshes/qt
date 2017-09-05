#include "common.h"

#include <QWidget>
#include <QCloseEvent>
#include <QPushButton>
#include <QGridLayout>


ThreadForm::ThreadForm(QWidget *parent)
	: QDialog(parent)
{
	setWindowTitle(tr("Threads"));

	threadA.setMessage("A");
	threadB.setMessage("B");

	initGUI();
}

void ThreadForm::initGUI()
{
	threadAButton = new QPushButton(tr("Start A"), this);
	threadBButton = new QPushButton(tr("Start B"), this);
	quitButton = new QPushButton(tr("Quit"), this);

	connect(threadAButton, &QPushButton::clicked, this, &ThreadForm::startOrStopThreadA);
	connect(threadBButton, &QPushButton::clicked, this, &ThreadForm::startOrStopThreadB);
	connect(quitButton, &QPushButton::clicked, this, &ThreadForm::close);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(threadAButton, 0, 0);
	layout->addWidget(threadBButton, 0, 1);
	layout->addWidget(quitButton, 0, 2);
	setLayout(layout);
}

void ThreadForm::closeEvent(QCloseEvent *event)
{
	threadA.stop();
	threadB.stop();
	threadA.wait();
	threadB.wait();
	event->accept();
}

void ThreadForm::startOrStopThreadA()
{
	if (threadA.isRunning())
	{
		threadA.stop();
		threadAButton->setText(tr("Start A"));
	}
	else
	{
		threadA.start();
		threadAButton->setText(tr("Stop A"));
	}
}

void ThreadForm::startOrStopThreadB()
{
	if (threadB.isRunning())
	{
		threadB.stop();
		threadBButton->setText(tr("Start B"));
	}
	else
	{
		threadB.start();
		threadBButton->setText(tr("Stop B"));
	}
}