#pragma once


#include <QtWidgets/QMainWindow>
#include "ui_StartUpProjectDemo.h"

#include <QGraphicsScene>
#include <QTimer>

class QGraphicsView;
class QControlBar;
class QParameters;


class StartUpProjectDemo : public QMainWindow
{
	Q_OBJECT

public:
	StartUpProjectDemo(QWidget *parent = Q_NULLPTR);

private:
	Ui::StartUpProjectDemoClass ui;

	QGraphicsScene mGraphicsScene;
	QGraphicsView * mSimulationView;
	QParameters * mParameters;
	QControlBar * mControlBar;

	QTimer mTimer;

	static const size_t sMaxNbrOfItems;
	static const QSize sSceneSize;
	static const QColor sSceneBackgroundColor;

	// Fonctions utilitaires de génération de valeurs aléatoires : devraient être ailleurs.
	double random(qreal maxValue);
	double random(qreal minValue, qreal maxValue);
	QColor randomColor();

private slots:
	void startSimulation();
	void stepSimulation();
	void pauseSimulation();
	void resumeSimulation();
	void stopSimulation();
};
