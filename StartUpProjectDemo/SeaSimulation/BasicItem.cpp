/**
 * Project SeaSimulation
 * @author A. Francoeur
 * @version 0.1
 */


#include "BasicItem.h"

/**
 * BasicItem implementation
 * 
 * BasicItem is a class to group common sub-classes members and methods.
 */


BasicItem::BasicItem()
{
}

QRectF BasicItem::boundingRect() const
{
	return QRectF();
}

bool BasicItem::isColliding() {
    return false;
}

/**
 * @param QBrush
 * @return void
 */
void BasicItem::setBrush(QBrush* brush) {
    return;
}

/**
 * @param int
 * @return void
 */
void BasicItem::setAge(int age) {
    return;
}

/**
 * @return void
 */
void BasicItem::setBoundingRect() {

}

/**
 * @param int
 * @return void
 */
void BasicItem::setLongevity(int longevity) {
    return;
}

/**
 * @return int
 */
int BasicItem::longevity() {
    return 0;
}