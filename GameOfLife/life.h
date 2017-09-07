#pragma once

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QVector>


class Cell : public QGraphicsRectItem
{
public:
	explicit Cell(const QRectF& rect);
	bool isAlive();
	void inverseState();
	void setAlive();
	void setDead();

private:
	bool alive;
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void changeColor();
};

class Universe : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit Universe(QObject *parent = 0);

public slots:
	void nextGeneration();

private:
	QVector<QVector<Cell *>> cells;
	void createUniverse();
	void showUniverse();
	void getNeighbours(int x, int y, QVector<Cell *> & neighbours);
	int countAliveNeighbours(int x, int y);
};