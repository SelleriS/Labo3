#include "QArrowItem.h"


#include <QPainter>
#include <QRandomGenerator>
#include <QtMath>
#include <QGraphicsScene>
#include <QtMath>


QArrowItem::QArrowItem(QPointF const & initialPosition, qreal initialOrientationDegrees, qreal initialSpeed, qreal scale, QBrush const & brush, QGraphicsItem * parent)
	:	QGraphicsItem(parent), 
		mBrush(brush),
		mSpeed{ initialSpeed }
{
	mShape	<< QPointF(0, 0)
			<< QPointF(-0.25, 0.5)
			<< QPointF(1, 0)
			<< QPointF(-0.25, -0.5);

	setPos(initialPosition);
	setRotation(initialOrientationDegrees);
	setScale(scale);
}

void QArrowItem::setColor(QBrush const & brush)
{
	mBrush = brush;
}

void QArrowItem::setSpeed(qreal speed)
{
	mSpeed = speed;
}

QRectF QArrowItem::boundingRect() const
{
	return QRectF(-0.25 * scale(), -0.5 * scale(), 1.0 * scale(), 1.25 * scale());
}

void QArrowItem::paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget)
{
	painter->setPen(Qt::NoPen);
	painter->setBrush(mBrush);
	painter->drawPolygon(mShape);
}

void QArrowItem::advance(int phase)
{
	if (phase == 0) {
		// do nothing
	} else if (phase == 1) {
		static constexpr const qreal maxDeltaOrientation{ 12.5 }; // in °
		// Détermine la nouvelle orientation selon une variation aléatoire dans l'intervalle [-maxDeltaOrientation, maxDeltaOrientation]
		qreal newOrientationDegrees{ rotation() + QRandomGenerator::global()->bounded(2.0 * maxDeltaOrientation) - maxDeltaOrientation };
		qreal newOrientationRadians{ qDegreesToRadians(newOrientationDegrees) };
		// Détermine la nouvelle position selon la nouvelle orientation et la vitesse
		QPointF newPosition(pos() + QPointF(qCos(newOrientationRadians), qSin(newOrientationRadians)) * mSpeed);
		// Si la nouvelle position est à l'extérieur de la scène, la nouvelle position est téléportée à la région opposée de la scène
		warp(newPosition);

		// Applique la nouvelle orientation et la nouvelle position
		setRotation(newOrientationDegrees);
		setPos(newPosition);
	}
}

qreal QArrowItem::warp(qreal value, qreal begin, qreal end) {
	const qreal width = end - begin;
	return value - qFloor((value - begin) / width) * width;
}

void QArrowItem::warp(QPointF & point) {
	point.setX(warp(point.x(), scene()->sceneRect().left(), scene()->sceneRect().right()));
	point.setY(warp(point.y(), scene()->sceneRect().top(), scene()->sceneRect().bottom()));
}
