/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#ifndef _BASICITEM_H
#define _BASICITEM_H

#include <QGraphicsItem>

class BasicItem: public QGraphicsItem
{
public:
	BasicItem();

	virtual QRectF boundingRect() const ;
		
	/**
	 * @param QBrush
	 */
	void setBrush(QBrush* color);
		
	/**
	 * @param int
	 */
	void setAge(int age);
		
	void setBoundingRect();
		
	/**
	 * @param int
	 */
	void setLongevity(int longevity);
		
	int longevity();

	bool isColliding();
	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

protected:
	virtual void advance() = 0;

private: 
	QPainterPath mShape;
	QBrush* mBrush;
	qreal mSize;
	int mAge;
	int mLongevity;
};

#endif //_BASICITEM_H