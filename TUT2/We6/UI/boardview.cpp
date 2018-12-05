#include "boardview.hh"
namespace Student{
BoardView::BoardView()
{

}
}
/*
void BoardView::mousePressEvent(QMouseEvent* event)
{
    std::cout<<"MouseMoveEvent Triggered"<<std::endl;
    QList<QGraphicsItem *> items = this->items();
    QPointF itempos = items[0]->pos();

    const QPointF eventpos = event->localPos();
    QGraphicsView::mousePressEvent(event);

}
*/
/*
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // does this do something useful?
    connect(ui->startButton, &QPushButton::clicked,
            this, &Dialog::accept);

    // do something so the mainwindow won't open D:<
    connect(ui->quitButton, &QPushButton::clicked,
            this, &Dialog::reject);

}

void Dialog::accept()
{
    QDialog::accept();
    emit sendMode(ui->comboBox->currentIndex());
    emit sendPlayerAmount(ui->playerAmountSpin->value());
}


Dialog::~Dialog()
{
    delete ui;
}
*/
