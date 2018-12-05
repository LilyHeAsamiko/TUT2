#include "graphicalhex.hh"
namespace Student{
GraphicalHex::GraphicalHex(std::shared_ptr<Common::Hex> hex) : QGraphicsPolygonItem()
{
    this->setPolygon(this->createQPolygonF());
    this->hex_ = hex;


}

void GraphicalHex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    if(hex_->getPieceType() == "Peak"){
        brush.setColor(Qt::GlobalColor::black);
    }
    else if(hex_->getPieceType() == "Mountain"){
        brush.setColor(Qt::gray);
    }
    else if(hex_->getPieceType() == "Beach"){
        brush.setColor(Qt::yellow);
    }
    else if(hex_->getPieceType() == "Water" || hex_->isWaterTile()){
        brush.setColor(Qt::blue);
    }
    else if(hex_->getPieceType() == "Coral"){
        brush.setColor(Qt::cyan);
    }
    else if(hex_->getPieceType() == "Forest"){
        brush.setColor(Qt::green);
    }
    painter->setBrush(brush);
    painter->drawPolygon(this->polygon());
    std::vector<std::shared_ptr<Common::Actor>> actors = hex_->getActors();
    for(auto actor : actors){
        std::string actortype =  actor->getActorType();
        QImage actorImage = QImage();
        if(actortype == "shark"){
            actorImage.load(QString(":Actors/shark.jpg"));

        }
        else if(actortype == "vortex"){
            actorImage.load(QString(":Actors/vortex.gif"));

        }
        else if(actortype == "seamunster"){
            actorImage.load(QString(":Actors/seamunster.png"));
        else if(actortype == "dophin"){
            actorImage.load(QString(":Actors/dophin.png"));

        }
        painter->drawImage(QRect(20,20,20,20), actorImage);
    }
}

void GraphicalHex::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    MainWindow* window = qobject_cast<MainWindow*>(this->scene()->parent());

    std::shared_ptr<Common::IGameRunner> gr = window->gamerunner();
    std::string actorType;
    try{
        actorType = gr->flipTile(this->hex_->getCoordinates());
        window->output()->appendPlainText(QString::fromStdString(actorType));
        this->update();
    }
    catch(Common::IllegalMoveException){
        window->output()->appendPlainText("Illegal move");
        return;
    }
}

std::shared_ptr<Common::Hex> GraphicalHex::hex() const
{
    return hex_;
}



QPolygonF GraphicalHex::createQPolygonF()
{
    QPolygonF polygon;
    polygon << QPointF(0,25) << QPointF(12.5, 3.3) << QPointF(37.5, 3.3)
            << QPointF(50, 25) << QPointF(37.5, 46.65) << QPointF(12.5, 46.65);
    return polygon;
}

}
