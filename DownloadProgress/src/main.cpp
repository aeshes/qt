#include "common.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	DownloaderGUI gui;
	gui.show();

	return a.exec();
}
