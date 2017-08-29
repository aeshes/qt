#include "DownloadProgress.h"

#include <QString>
#include <QThread>
#include <QSignalMapper>
#include <QNetworkAccessManager>


DownloadProgress::DownloadProgress(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	downloadingThread = new QThread;
	downloader = new FileDownloader;
	downloader->moveToThread(downloadingThread);

	connect(ui.pushButton, &QPushButton::pressed,
		this, &DownloadProgress::onButtonClick);
	connect(this, &DownloadProgress::signalSendUrl,
		downloader, &FileDownloader::startDownload);
	connect(downloader, &FileDownloader::progressChanged,
		this, &DownloadProgress::updateProgress);

	downloadingThread->start();
}

void DownloadProgress::updateProgress(int value)
{
	ui.progressBar->setValue(value);
}

void DownloadProgress::onButtonClick()
{
	QString url = ui.lineEdit->text();
	emit signalSendUrl(url);
}

void FileDownloader::startDownload(const QString& url)
{
	for (auto i = 0; i <= 100; ++i)
	{
		emit progressChanged(i);
		QThread::msleep(50);
	}
	emit done();
}