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

private:
	QVector<QVector<Cell *>> universe;
	void createUniverse();
	void showUniverse();
};