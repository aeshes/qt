#pragma once

#include <QWidget>

class QString;
class QThread;
class QNetworkAccessManager;
class QNetworkReply;
class QUrl;
class QPushButton;
class QLineEdit;
class QProgressBar;

class FileDownloader : public QObject
{
	Q_OBJECT
public:
	explicit FileDownloader(QObject *parent = Q_NULLPTR);
	void download(const QUrl& url);

signals:
	void progressChanged(qint64 nReceived, qint64 nTotal);
	void done(const QUrl& url, const QByteArray& data);
	void error();

private slots:
	void slotFinished(QNetworkReply *reply);

private:
	QNetworkAccessManager *networkManager;
};

class DownloaderGUI : public QWidget
{
	Q_OBJECT
public:
	DownloaderGUI(QWidget *parent = Q_NULLPTR);

private slots:
	void slotDownload();
	void slotError();
	void slotDownloadProgress(qint64 nReceived, qint64 nTotal);
	void slotDone(const QUrl& url, const QByteArray& data);

private:
	void initGUI();

private:
	QPushButton    *pushButton;
	QLineEdit      *lineEdit;
	QProgressBar   *progressBar;
	FileDownloader *downloader;
};