#ifndef GRAPHICALPAWN_HH
#define GRAPHICALPAWN_HH

#include <QGraphicsEllipseItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

#include "mainwindow.hh"
#include "hex.hh"
#include "igamerunner.hh"
#include "gameboard.hh"
#include "graphicalhex.hh"
namespace Student {


class GraphicalPawn : public QGraphicsEllipseItem
{
public:
    GraphicalPawn();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = Q_NULLPTR);
    void setId(int id);

    int pawnId() const;

protected:

    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    int pawnId_;
};
}
#endif // GRAPHICALPAWN_HH
