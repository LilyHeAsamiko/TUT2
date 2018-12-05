#ifndef BOARDVIEW_HH
#define BOARDVIEW_HH

#include <iostream>
#include <QGraphicsView>
#include <QMouseEvent>


namespace Student {
class BoardView : public QGraphicsView
{
public:
    BoardView();


protected:
    //void mousePressEvent(QMouseEvent* event);
};
}

#endif // BOARDVIEW_HH
