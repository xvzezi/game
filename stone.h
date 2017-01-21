#pragma once

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QtGui>
#include <QObject>
#include <QImage>
#include <QPointF>
#include <QRectF>
#include <QTimer>
#include "Protocol.h"

const qreal birthScale = 0.03;
const qreal dropScale = 0.2;

class StoneManager;

class Stone :public QObject, public QGraphicsPixmapItem {
	Q_OBJECT
		unsigned int playerID;
	unsigned int stoneID;
	unsigned int stoneType;

	qreal speed;
	qreal currentScale;
	bool enableShoot;

	int stage;

	QPointF birthPos;
	QPointF dropPos;

	QPointF birthMov;
	QPointF popMov;
	QPointF popMovAccl;

	qreal scaleStep;

	QTimer* timer;

	StoneManager* parentManager;
protected:
	void removeThis();

public:
	Stone(QImage* stoneImg, QPointF birthPos, QPointF shootPos, int stoneID, int playerID, StoneManager* parentManager);
	unsigned int getStoneID() { return stoneID; }
	void setStoneID(int stoneID) { this->stoneID = stoneID; }
	unsigned int getStoneType() { return stoneType; }
	void setStoneType(int stoneType) { this->stoneType = stoneType; }
	void setSpeed(qreal newSpeed) { this->speed = newSpeed; }

	void speedUp();
	void speedDown();

	void start();
	void stop();

	void mousePressEvent(QGraphicsSceneMouseEvent * event);
	public slots:
	void drop();
};
