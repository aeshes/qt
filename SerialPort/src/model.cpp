#include "model.h"

#include <QSerialPortInfo>
#include <QDebug>

Model::Model()
{
	searchSerialPorts();
}

void Model::searchSerialPorts()
{
	foreach(const QSerialPortInfo & info, QSerialPortInfo::availablePorts())
	{
		portList.append(info.portName());
	}
}

void Model::showPorts()
{
	foreach(const QString & portName, portList)
	{
		qDebug() << portName;
	}
}

void Model::connectToPort()
{

}