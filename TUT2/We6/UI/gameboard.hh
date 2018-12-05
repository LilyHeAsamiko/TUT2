#ifndef GAMEBOARD_HH
#define GAMEBOARD_HH

#include <vector>
#include <unordered_map>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <math.h>

#include "igameboard.hh"
#include "pawn.hh"
#include "actor.hh"
#include "transport.hh"


namespace Student {
class GameBoard : public Common::IGameBoard
{
public:
    GameBoard();
    ~GameBoard();

    int checkTileOccupation(Common::CubeCoordinate tileCoord) const;
    bool isWaterTile(Common::CubeCoordinate tileCoord) const;
    std::shared_ptr<Common::Hex> getHex(Common::CubeCoordinate hexCoord) const;
    std::shared_ptr<Common::Pawn> getPawn(int pawnId);
    std::shared_ptr<Common::Actor> getActor(int actorId);
    std::shared_ptr<Common::Transport> getTransport(int transportId);


    void addPawn(int playerId, int pawnId);
    void addPawn(int playerId, int pawnId, Common::CubeCoordinate coord);
    void movePawn(int pawnId, Common::CubeCoordinate pawnCoord);
    void removePawn(int pawnId);

    void addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord);
    void moveActor(int actorId, Common::CubeCoordinate actorCoord);
    void removeActor(int actorId);

    void addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord);
    void moveTransport(int id, Common::CubeCoordinate coord);
    void removeTransport(int id);

    void addHex(std::shared_ptr<Common::Hex> newHex);
    std::vector<std::shared_ptr<Common::Hex>> getHexVector();

    static std::pair<float, float> cubeToPixel(Common::CubeCoordinate coords);
    static Common::CubeCoordinate pixelToCube(double x, double y);
    static Common::CubeCoordinate cubeRound(float x, float y, float z);

    std::vector<std::shared_ptr<Common::Pawn> > getPawnVector() const;


private:


    std::vector<std::shared_ptr<Common::Hex>> hexVector_;
    std::vector<std::shared_ptr<Common::Pawn>> pawnVector_;

};
}
#endif // GAMEBOARD_HH
