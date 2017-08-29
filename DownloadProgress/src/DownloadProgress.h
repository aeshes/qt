#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_DownloadProgress.h"

class QString;
class QThread;
class QNetworkAccessManager;
class FileDownloader;

class DownloadProgress : public QMainWindow
{
	Q_OBJECT
	QThread *downloadingThread;
	FileDownloader *downloader;
public:
	explicit DownloadProgress(QWidget *parent = Q_NULLPTR);

signals:
	void signalSendUrl(const QString& url);

public slots:
	void updateProgress(int value);
	void onButtonClick();

private:
	Ui::QtDownloadProgressClass ui;
};

class FileDownloader : public QObject
{
	Q_OBJECT
public:
	explicit FileDownloader(QObject *parent = Q_NULLPTR)
		: QObject(parent) {}

signals:
	void progressChanged(int);
	void done();

public slots:
	void startDownload(const QString& url);
};
