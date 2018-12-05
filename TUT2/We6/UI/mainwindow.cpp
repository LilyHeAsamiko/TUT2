#include "mainwindow.hh"

namespace Student{
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    scene_(new QGraphicsScene()), view_(new Student::BoardView()), board_(std::make_shared<Student::GameBoard>())
{
    QDialog* startDialog = new QDialog();
    QHBoxLayout* layout = new QHBoxLayout();
    QPushButton* startButton = new QPushButton("Start the game");
    QSpinBox* playerSpinBox = new QSpinBox();
    QLabel* spinBoxLabel = new QLabel("Players:");
    this->playerBox_ = playerSpinBox;
    spinBoxLabel->setBuddy(playerSpinBox);
    layout->addWidget(spinBoxLabel);
    layout->addWidget(playerSpinBox);

    connect(startButton, SIGNAL(clicked()),
            this, SLOT(startPressed()));
    connect(this, SIGNAL(initBoard(int)), this, SLOT(initializeBoard(int)));
    connect(startButton, SIGNAL(clicked()), startDialog, SLOT(close()));

    layout->addWidget(startButton);
    startDialog->setLayout(layout);

    startDialog->show();

}

void MainWindow::initializeBoard(int playerAmount)
{
    std::shared_ptr<GameState> gameState = std::make_shared<GameState>();
    std::vector<std::shared_ptr<Common::IPlayer>> playerVector;
    for(int j = 0; j < playerAmount; ++j){
        playerVector.push_back(std::make_shared<Student::Player>(j));
    }

    gamerunner_ = Common::Initialization::getGameRunner(
                board_,
                gameState,
                playerVector);

    std::vector<std::shared_ptr<Common::Hex>> hexVector = board_->getHexVector();
    QPointF point;
    QRectF boundingrect;
    for(std::vector<std::shared_ptr<Common::Hex>>::const_iterator
        i = hexVector.begin();
        i != hexVector.end();
        ++i)
    {

        Common::CubeCoordinate coords = (*i)->getCoordinates();
        std::pair<float,float> pixels = Student::GameBoard::cubeToPixel(coords);

        GraphicalHex* graphicalHex = new GraphicalHex((*i));
        scene_->addItem(graphicalHex);
        graphicalHex->setPos(pixels.first,pixels.second);
    }
    for(auto player: playerVector){
        Common::CubeCoordinate coords = Common::CubeCoordinate(-10, 0, 10);
        int pawnId = 0;

        GraphicalPawn* graphicpawn = new GraphicalPawn();
        graphicpawn->setId(pawnId);
        std::pair<float,float> pixels = Student::GameBoard::cubeToPixel(coords);
        graphicpawn->setPos(pixels.first,pixels.second);
        scene_->addItem(graphicpawn);
        this->board_->addPawn(player->getPlayerId(),pawnId, coords);

        pawnId++;
    }



    QDesktopWidget dw;
    int width=dw.width()*0.6;
    int height=dw.height()*1;
    this->setFixedSize(width,height);
    this->show();
    this->setCentralWidget(view_);
    scene_->setParent(this);
    scene_->setSceneRect(-500,-430,1000,1000);
    view_->setScene(scene_);
    view_->centerOn(point);
    view_->setRenderHint(QPainter::Antialiasing,true);

    QPlainTextEdit* outputBox = new QPlainTextEdit();


    view_->show();
    outputBox->show();
    outputBox->setPlainText("Hello there");
    this->output_ = outputBox;
    output_->setReadOnly(true);


}

void MainWindow::startPressed()
{
    emit initBoard(this->playerBox_->value());
}



std::shared_ptr<Student::GameBoard> MainWindow::board() const
{
    return board_;
}

std::shared_ptr<Common::IGameRunner> MainWindow::gamerunner() const
{
    return gamerunner_;
}

QPlainTextEdit *MainWindow::output() const
{
    return output_;
}

}
