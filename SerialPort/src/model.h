#ifndef MODEL_H
#define MODEL_H

#include <QList>
#include <QString>
#include <QByteArray>
#include <QList>

#include <QSerialPort>


struct Settings
{
	QString name;
	qint32 baudRate;
	QSerialPort::DataBits dataBits;
	QSerialPort::Parity parity;
	QSerialPort::StopBits stopBits;
	QSerialPort::FlowControl flowControl;
};

class Model
{
public:
	Model();
	void showPorts();
	void connect();
	void disconnect();

	void setName(const QString& portName);
	void setBaudRate(qint32 baudrate);
	void setDataBits(int dataBits);
	void setParity(int parity);
	void setStopBits(int stopBits);
	void setFlowControl(int flowControl);

	QList<QString> getAvailablePorts();

	QByteArray read();
	void write(const QByteArray & data);

private:
	void searchSerialPorts();
	void defaultSettings();
	bool setPortSettings();

	QList<QString> portList;
	Settings portSettings;
	QSerialPort serial;
};

#endif