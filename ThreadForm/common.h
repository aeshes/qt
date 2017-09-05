#pragma once

#include <QDialog>
#include <QThread>

class QThread;
class QString;

class Thread : public QThread
{
public:
	Thread();

	void setMessage(const QString& str);
	void run();
	void stop();

private:
	QString msg;
	volatile bool stopped;
};

class QWidget;
class QCloseEvent;
class QPushButton;

class ThreadForm : public QDialog
{
	Q_OBJECT

public:
	explicit ThreadForm(QWidget *parent = Q_NULLPTR);

protected:
	void closeEvent(QCloseEvent *event);

private slots:
	void startOrStopThreadA();
	void startOrStopThreadB();

private:
	Thread threadA;
	Thread threadB;
	QPushButton *threadAButton;
	QPushButton *threadBButton;
	QPushButton *quitButton;
};