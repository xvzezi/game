#pragma once

#include <QGraphicsRectItem>
#include <QObject>
#include <vector>
#include <string>
#include "stone.h"
#include "Protocol.h"
#include <QImage>
#include <QRectF>
#include <QtGlobal>

class GameManager;

class StoneManager :public QObject, public QGraphicsRectItem
{
	Q_OBJECT

		GameProtocol playerID;

	QPointF originPos;
	QPointF birthPos;
	int linePos;
	int shootLineY;

	int level;

	std::vector<QImage*>stoneImages;

	std::vector<Stone*>stonePointers;
	std::vector<int>stoneLayer;

	QTimer* timer;

	GameManager* parentManager;

	int scoreGap = 0;
	double currentSpeed = 1.2;

protected:
	unsigned int genStoneID();
	int genLayer();

public:
	StoneManager(QPointF position, GameProtocol playerID, GameManager* parentManager);
	~StoneManager();
	void keyPressEvent(QKeyEvent* event);
	void removeStone(unsigned int stoneID);
	void popFront(unsigned int stoneID);
	void levelUp();
	void stop();
	void start();
	void addScore(int score);
	void missOne();
	int getWaterHeight();
	int getCurrentScore();
	double getCurrentSpeed();
	public slots:
	void spawn();
};
