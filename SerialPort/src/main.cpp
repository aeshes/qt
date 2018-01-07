#include <QtCore/QCoreApplication>
#include <QDebug>

#include <QSerialPort>
#include <QSerialPortInfo>

#include "model.h"


void listSerialPorts()
{
	foreach(const QSerialPortInfo& info, QSerialPortInfo::availablePorts())
	{
		qDebug() << "Name: " << info.portName();
		qDebug() << "Description: " << info.description();
		qDebug() << "Manufacturer: " << info.manufacturer();
		qDebug() << "\n";
	}
}


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Model model;
	model.showPorts();
	model.setName("COM3");
	model.connectToPort();

	return a.exec();
}
