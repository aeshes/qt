#include "life.h"

#include <QRect>
#include <QTimer>
#include <QDebug>

Universe::Universe(QObject *parent)
	: QGraphicsScene(parent)
{
	createUniverse();

	QTimer *timer = new QTimer;
	timer->setInterval(1000);
	connect(timer, &QTimer::timeout, this, &Universe::nextGeneration);

	showUniverse();

	timer->start();
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
		cells.push_back(row);
		startX = 0;
		startY += 20;
	}
}

void Universe::showUniverse()
{
	if (!cells.empty())
	{
		for (const auto& row : cells)
		{
			for (const auto& cell : row)
			{
				addItem(cell);
			}
		}
	}
}

void Universe::getNeighbours(int x, int y, QVector<Cell *> & neighbours)
{
	for (int i = x - 1; i <= x + 1; ++i)
	{
		for (int j = y - 1; j <= y + 1; ++j)
		{
			if (i < 0 || j < 0 || i >=10 || j >= 10) continue;
			if (i == x && j == y) continue;
			neighbours.push_back(cells[i][j]);
		}
	}
}

int Universe::countAliveNeighbours(int x, int y)
{
	QVector<Cell *> neighbours;
	getNeighbours(x, y, neighbours);

	int count = 0;
	for (const auto cell : neighbours)
	{
		if (cell->isAlive())
		{
			++count;
		}
	}
	return count;
}

void changeCellState(Cell *cell, int liveNeighbours)
{
	if (cell->isAlive())
	{
		if (liveNeighbours < 2 || liveNeighbours > 3)
			cell->setDead();
	}
	else
	{
		if (liveNeighbours == 3)
			cell->setAlive();
	}
}

void Universe::nextGeneration()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			changeCellState(cells[i][j], countAliveNeighbours(i, j));
		}
	}
}