#include "common.h"

#include <QPushButton>
#include <QLineEdit>
#include <QProgressBar>
#include <QGridLayout>
#include <QMessageBox>
#include <QUrl>
#include <QThread>
#include <QFile>


DownloaderGUI::DownloaderGUI(QWidget *parent)
	: QWidget(parent)
{
	downloader = new FileDownloader(this);
	initGUI();
}

void DownloaderGUI::initGUI()
{
	pushButton = new QPushButton(tr("&Download"));
	lineEdit = new QLineEdit;
	progressBar = new QProgressBar;

	connect(pushButton, &QPushButton::clicked, this, &DownloaderGUI::slotDownload);
	connect(downloader, &FileDownloader::progressChanged, this, &DownloaderGUI::slotDownloadProgress);
	connect(downloader, &FileDownloader::done, this, &DownloaderGUI::slotDone);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(lineEdit, 0, 0);
	layout->addWidget(pushButton, 0, 1);
	layout->addWidget(progressBar, 1, 0, 1, 1);
	setLayout(layout);
}

void DownloaderGUI::slotDownload()
{
	downloader->download(QUrl(lineEdit->text()));
}

void DownloaderGUI::slotDownloadProgress(qint64 nReceived, qint64 nTotal)
{
	if (nTotal <= 0)
	{
		slotError();
		return;
	}
	progressBar->setValue(100 * nReceived / nTotal);
}

void DownloaderGUI::slotDone(const QUrl& url, const QByteArray& data)
{
	QFile file(url.path().section('/', -1));
	if (file.open(QIODevice::WriteOnly))
	{
		file.write(data);
		file.close();
	}
}

void DownloaderGUI::slotError()
{
	QMessageBox::critical(Q_NULLPTR,
		tr("Error"),
		tr("Error while downloading file"));
}