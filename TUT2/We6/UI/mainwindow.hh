#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDesktopWidget>
#include <QGraphicsView>
#include <QPushButton>
#include <QSpinBox>
#include <QDialog>
#include <QLabel>
#include <QHBoxLayout>
#include <QWidget>
#include <QDebug>
#include <vector>
#include <memory>
#include <iostream>
#include <QPlainTextEdit>

#include "math.h"
#include "gameboard.hh"
#include "gamestate.hh"
#include "player.hh"
#include "gameengine.hh"
#include "initialize.hh"
#include "graphicalhex.hh"
#include "boardview.hh"
#include "graphicalpawn.hh"

namespace Student{
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);


    std::shared_ptr<Student::GameBoard> board() const;

    std::shared_ptr<Common::IGameRunner> gamerunner() const;

    QPlainTextEdit *output() const;

signals:
    void initBoard(int);

private:
    QGraphicsScene* scene_;
    Student::BoardView* view_;
    std::shared_ptr<Student::GameBoard> board_;
    QSpinBox* playerBox_;
    std::shared_ptr<Common::IGameRunner> gamerunner_;
    QPlainTextEdit* output_;


public slots:
    void initializeBoard(int);
    void startPressed();
};
}
#endif // MAINWINDOW_HH
