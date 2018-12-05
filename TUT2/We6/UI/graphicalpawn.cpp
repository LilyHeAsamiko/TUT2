#include "graphicalpawn.hh"
namespace Student{
GraphicalPawn::GraphicalPawn()
{
    this->setFlag(ItemIsSelectable);
    this->setRect(20,20,20,20);
}

void GraphicalPawn::paint(QPainter *painter,
                                                const QStyleOptionGraphicsItem *option,
                                                QWidget *widget)
{

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::red);
    painter->setBrush(brush);
    painter->drawEllipse(20,20,20,20);
}

void GraphicalPawn::setId(int id)
{
    this->pawnId_ = id;
}

void GraphicalPawn::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF origin = this->scenePos();
    QPointF target = this->scene()->itemAt(event->scenePos(), QTransform())->scenePos();


    Common::CubeCoordinate coordsOrigin = Student::GameBoard::pixelToCube(origin.x(), origin.y());
    Common::CubeCoordinate coordsTarget = Student::GameBoard::pixelToCube(target.x(), target.y());



    MainWindow* window = qobject_cast<MainWindow*>(this->scene()->parent());

    std::shared_ptr<Common::IGameRunner> gr = window->gamerunner();
    try{
        gr->movePawn(coordsOrigin, coordsTarget, this->pawnId());
        this->setPos(target);
    }
    catch(Common::IllegalMoveException){
        std::cout << "illegal move" << std::endl;

    }

}

int GraphicalPawn::pawnId() const
{
    return pawnId_;
}
}
