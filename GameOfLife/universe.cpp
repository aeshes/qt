#include "life.h"

#include <QRect>

Universe::Universe(QObject *parent)
	: QGraphicsScene(parent)
{
	createUniverse();
	showUniverse();
}

void Universe::createUniverse()
{
	int startX = 0, startY = 0;
	for (int i = 0; i < 10; ++i)
	{
		QVector<Cell *> row;
		for (int j = 0; j < 10; ++j)
		{
			row.push_back(new Cell(QRectF(startX, startY, 20, 20)));
			startX += 20;
		}
		universe.push_back(row);
		startX = 0;
		startY += 20;
	}
}

void Universe::showUniverse()
{
	if (!universe.empty())
	{
		for (const auto& row : universe)
		{
			for (const auto& cell : row)
			{
				addItem(cell);
			}
		}
	}
}