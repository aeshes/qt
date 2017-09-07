#include "life.h"

#include <QRect>
#include <QBrush>


Cell::Cell(const QRectF& rect)
	: QGraphicsRectItem(rect), alive(false)
{

}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
	inverseState();
	changeColor();
}

bool Cell::isAlive()
{
	return alive;
}

void Cell::setAlive()
{
	alive = true;
	changeColor();
}

void Cell::setDead()
{
	alive = false;
	changeColor();
}

void Cell::inverseState()
{
	alive = !alive;
}

void Cell::changeColor()
{
	alive ? this->setBrush(QBrush(Qt::black)) : this->setBrush(QBrush(Qt::white));
}