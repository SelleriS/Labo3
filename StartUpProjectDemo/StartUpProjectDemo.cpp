#include "StartUpProjectDemo.h"


#include <QRandomGenerator>
#include <QGraphicsView>
#include <QHBoxLayout>
#include "QControlBar.h"
#include "QParameters.h"
#include "QArrowItem.h"


const size_t StartUpProjectDemo::sMaxNbrOfItems{ 1000 };
const QSize StartUpProjectDemo::sSceneSize(1000, 600);
const QColor StartUpProjectDemo::sSceneBackgroundColor(16, 32, 64);


StartUpProjectDemo::StartUpProjectDemo(QWidget *parent)
	:	QMainWindow(parent),
		mSimulationView{ new QGraphicsView(&mGraphicsScene) },
		mParameters{ new QParameters(sMaxNbrOfItems) },
		mControlBar{ new QControlBar(Qt::Vertical) }
{
	ui.setupUi(this);

	mControlBar->setReady();
	mControlBar->setText("Start new simulation", "End simulation", "Pause simulation", "Resume simulation", "One step simulation");
	mControlBar->setColor(QColor(0, 255, 0), QColor(255, 255, 0), QColor(255, 0, 0), QColor(230, 230, 230), QColor(128, 128, 128));
	mGraphicsScene.setSceneRect(-sSceneSize.width() / 2, -sSceneSize.height() / 2, sSceneSize.width(), sSceneSize.height());
	
	QWidget * controlWidget{ new QWidget };
	QVBoxLayout * controlLayout{ new QVBoxLayout };
	controlWidget->setLayout(controlLayout);
	controlLayout->addWidget(mParameters);
	controlLayout->addStretch();
	controlLayout->addWidget(mControlBar);

	QWidget * centralWidget{ new QWidget };
	QHBoxLayout * centralLayout{ new QHBoxLayout };
	centralWidget->setLayout(centralLayout);

	centralLayout->addWidget(mSimulationView);
	centralLayout->addWidget(controlWidget);

	setCentralWidget(centralWidget);

	connect(mControlBar, &QControlBar::started, this, &StartUpProjectDemo::startSimulation);
	connect(mControlBar, &QControlBar::stopped, this, &StartUpProjectDemo::stopSimulation);
	connect(mControlBar, &QControlBar::paused, this, &StartUpProjectDemo::pauseSimulation);
	connect(mControlBar, &QControlBar::resumed, this, &StartUpProjectDemo::resumeSimulation);
	connect(mControlBar, &QControlBar::stepped, this, &StartUpProjectDemo::stepSimulation);

	connect(&mTimer, &QTimer::timeout, &mGraphicsScene, &QGraphicsScene::advance);
}

void StartUpProjectDemo::startSimulation()
{
	// Vide la scène pour démarrer une nouvelle démo
	mGraphicsScene.clear();

	// Met un item rectangulaire pour bien voir les limites de la scène
	QGraphicsRectItem * background{ new QGraphicsRectItem(mGraphicsScene.sceneRect()) };
	background->setPen(Qt::NoPen);
	background->setBrush(sSceneBackgroundColor);

	mGraphicsScene.addItem(background);
	for (int i{ 0 }; i < mParameters->nbrOfItems(); ++i) {
		mGraphicsScene.addItem(
			// Tous les litéraux ici devraient être créés dans des constantes symboliques!
			new QArrowItem(
					QPointF(),					// ils sont tous à l'origine au départ!
					random(360.0),				// orientation aléatoire
					random(1.0, 10.0),			// vitesse aléatoire entre 1 et 10
					random(5.0, 15.0),			// taille aléatoire entre 5 et 15
					randomColor()));			// couleur aléatoire
	}
	mTimer.start(30);
}

double StartUpProjectDemo::random(qreal maxValue)
{
	return QRandomGenerator::global()->bounded(maxValue);
}

double StartUpProjectDemo::random(qreal minValue, qreal maxValue)
{
	return random(maxValue - minValue) + minValue;
}

QColor StartUpProjectDemo::randomColor()
{
	return QColor::fromRgb(QRandomGenerator::global()->generate());
}

void StartUpProjectDemo::stepSimulation()
{
	mGraphicsScene.advance();
}

void StartUpProjectDemo::pauseSimulation()
{
	mTimer.stop();
}

void StartUpProjectDemo::resumeSimulation()
{
	mTimer.start(30);
}

void StartUpProjectDemo::stopSimulation()
{
	mTimer.stop();
}

