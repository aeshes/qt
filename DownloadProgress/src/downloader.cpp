#include "common.h"

#include <QString>
#include <QThread>
#include <QSignalMapper>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


FileDownloader::FileDownloader(QObject *parent)
	: QObject(parent)
{
	networkManager = new QNetworkAccessManager(this);
	connect(networkManager, &QNetworkAccessManager::finished, this, &FileDownloader::slotFinished);
}

void FileDownloader::download(const QUrl& url)
{
	for (auto i = 0; i <= 100; ++i)
	{
		emit progressChanged(i, 100);
		QThread::msleep(50);
	}
}

void FileDownloader::slotFinished(QNetworkReply *reply)
{
	if (reply->error() != QNetworkReply::NoError)
	{
		emit error();
	}
	else
	{
		emit done(reply->url(), reply->readAll());
	}
	reply->deleteLater();
}