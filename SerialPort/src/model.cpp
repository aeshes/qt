#include "model.h"

#include <QSerialPortInfo>
#include <QDebug>

Model::Model()
{
	defaultSettings();
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
	serial.setPortName(portSettings.name);
	if (serial.open(QIODevice::ReadWrite))
	{
		if (setPortSettings())
		{
			if (serial.isOpen()) qDebug() << "Port " << portSettings.name << " is opened";
		}
		else serial.close();
	}
}

bool Model::setPortSettings()
{
	return serial.setBaudRate(portSettings.baudRate)
		&& serial.setDataBits(portSettings.dataBits)
		&& serial.setParity(portSettings.parity)
		&& serial.setStopBits(portSettings.stopBits)
		&& serial.setFlowControl(portSettings.flowControl);
}

void Model::defaultSettings()
{
	setName("");
	setBaudRate(QSerialPort::Baud9600);
	setDataBits(QSerialPort::Data8);
	setParity(QSerialPort::NoParity);
	setStopBits(QSerialPort::OneStop);
	setFlowControl(QSerialPort::NoFlowControl);
}

void Model::setName(const QString & portName)
{
	portSettings.name = portName;
}

void Model::setBaudRate(qint32 baudrate)
{
	portSettings.baudRate = baudrate;
}

void Model::setDataBits(int dataBits)
{
	portSettings.dataBits = static_cast<QSerialPort::DataBits>(dataBits);
}

void Model::setParity(int parity)
{
	portSettings.parity = static_cast<QSerialPort::Parity>(parity);
}

void Model::setStopBits(int stopBits)
{
	portSettings.stopBits = static_cast<QSerialPort::StopBits>(stopBits);
}

void Model::setFlowControl(int flowControl)
{
	portSettings.flowControl = static_cast<QSerialPort::FlowControl>(flowControl);
}
