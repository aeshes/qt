#include <QtWidgets/QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "life.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Universe universe;

	QGraphicsView view(&universe);
	view.show();

	return a.exec();
}
