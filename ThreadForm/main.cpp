#include "common.h"

#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	ThreadForm form;
	form.show();

	return a.exec();
}
