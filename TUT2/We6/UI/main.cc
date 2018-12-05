#include "gameboard.hh"
#include "gamestate.hh"
#include "player.hh"
#include "mainwindow.hh"
#include "initialize.hh"
#include "igamerunner.hh"
#include "gameengine.hh"


#include <memory>

#include <QDockWidget>

#include <QApplication>
#include <QGraphicsScene>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Student::MainWindow* mainWindow = new Student::MainWindow();
    return a.exec();
}
