#ifndef GRAPHICALHEX_HH
#define GRAPHICALHEX_HH

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QImage>

#include "gameboard.hh"
#include "hex.hh"
#include "mainwindow.hh"
#include "igamerunner.hh"
#include "illegalmoveexception.hh"

namespace Student{
class GraphicalHex : public QGraphicsPolygonItem
{
public:
    GraphicalHex(std::shared_ptr<Common::Hex>);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    static QPolygonF createQPolygonF();

    std::shared_ptr<Common::Hex> hex() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);


private:
    std::shared_ptr<Common::Hex> hex_;
};
}
#endif // GRAPHICALHEX_HH
