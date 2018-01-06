#ifndef MODEL_H
#define MODEL_H

#include <QList>
#include <QString>

class Model
{
public:
	Model();
	void showPorts();
	void connectToPort();

private:
	void searchSerialPorts();

private:
	QList<QString> portList;
};

#endif