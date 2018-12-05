#include "gameboard.hh"

namespace Student{
GameBoard::GameBoard()
{
}

GameBoard::~GameBoard()
{

}

int GameBoard::checkTileOccupation(Common::CubeCoordinate tileCoord) const
{
    std::shared_ptr<Common::Hex> hex = this->getHex(tileCoord);
    if(hex != nullptr){
        return hex->getPawnAmount();
    }
    else{
        return -1;
    }

}

bool GameBoard::isWaterTile(Common::CubeCoordinate tileCoord) const
{
    std::shared_ptr<Common::Hex> hex = getHex(tileCoord);
    if(hex != nullptr){
        return hex->isWaterTile();
    }
    else{
        return false;
    }
}

std::shared_ptr<Common::Hex> GameBoard::getHex(Common::CubeCoordinate hexCoord) const
{
    for(int i = 0; i < this->hexVector_.size(); ++i)
    {
        Common::CubeCoordinate coords = hexVector_[i]->getCoordinates();
        if(coords == hexCoord){
            return hexVector_[i];
        }
    }
    return nullptr;
}

std::shared_ptr<Common::Pawn> GameBoard::getPawn(int pawnId)
{

    for(int i = 0; i < hexVector_.size(); ++i){
        std::vector<std::shared_ptr<Common::Pawn>> pawns = hexVector_[i]->getPawns();
        for(int j = 0; j < pawns.size(); ++j){
            if(pawns[j]->getId() == pawnId){
                return pawns[j];
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Common::Actor> GameBoard::getActor(int actorId)
{
    for(int i = 0; i < hexVector_.size(); ++i){
        std::vector<std::shared_ptr<Common::Actor>> actors = hexVector_[i]->getActors();
        for(int j= 0; j < actors.size(); ++j){
            if(actors[j]->getId() == actorId){
                return actors[j];
            }
        }
    }
    return nullptr;
}

std::shared_ptr<Common::Transport> GameBoard::getTransport(int transportId)
{
    for(int i = 0; i < hexVector_.size(); ++i){
        std::vector<std::shared_ptr<Common::Transport>> transports = hexVector_[i]->getTransports();
        for(int j= 0; j < transports.size(); ++j){
            if(transports[j]->getId() == transportId){
                return transports[j];
            }
        }
    }
    return nullptr;
}
void GameBoard::addPawn(int playerId, int pawnId)
{
    std::shared_ptr<Common::Pawn> newPawn = std::make_shared<Common::Pawn>();
    newPawn->setId(pawnId, playerId);
}

void GameBoard::addPawn(int playerId, int pawnId, Common::CubeCoordinate coord)
{
    std::shared_ptr<Common::Pawn> newPawn = std::make_shared<Common::Pawn>();
    newPawn->setId(pawnId, playerId);
    std::shared_ptr<Common::Hex> hex = this->getHex(coord);
    newPawn->setCoordinates(coord);
    hex->addPawn(newPawn);
}

void GameBoard::movePawn(int pawnId, Common::CubeCoordinate pawnCoord)
{
    std::shared_ptr<Common::Pawn> pawn = this->getPawn(pawnId);
    std::shared_ptr<Common::Hex> newHex = this->getHex(pawnCoord);
    if(pawn != nullptr && newHex != nullptr){
        std::shared_ptr<Common::Hex> oldHex = this->getHex(pawn->getCoordinates());
        oldHex->removePawn(pawn);
        newHex->addPawn(pawn);
    }



}

void GameBoard::removePawn(int pawnId)
{
    std::shared_ptr<Common::Pawn> pawn = this->getPawn(pawnId);
    std::shared_ptr<Common::Hex> hex = this->getHex(pawn->getCoordinates());
    if(hex != nullptr && pawn != nullptr){
        hex->removePawn(pawn);
    }

}

void GameBoard::addActor(std::shared_ptr<Common::Actor> actor, Common::CubeCoordinate actorCoord)
{
    std::shared_ptr<Common::Hex> hex = this->getHex(actorCoord);
    if(hex != nullptr && actor != nullptr){
        actor->addHex(hex);
        hex->addActor(actor);
    }
}

void GameBoard::moveActor(int actorId, Common::CubeCoordinate actorCoord)
{
    std::shared_ptr<Common::Hex> newHex = this->getHex(actorCoord);
    std::shared_ptr<Common::Actor> actor = this->getActor(actorId);
    if(newHex != nullptr && actor != nullptr){
        std::shared_ptr<Common::Hex> oldHex = actor->getHex();
        if(oldHex != nullptr){
            oldHex->removeActor(actor);
            newHex->addActor(actor);
        }


    }
}

void GameBoard::removeActor(int actorId)
{
    std::shared_ptr<Common::Actor> actor = this->getActor(actorId);
    std::shared_ptr<Common::Hex> hex = actor->getHex();
    if(hex != nullptr){
        hex->removeActor(actor);

    }
}

void GameBoard::addTransport(std::shared_ptr<Common::Transport> transport, Common::CubeCoordinate coord)
{
    std::shared_ptr<Common::Hex> hex = this->getHex(coord);
    transport->addHex(hex);
    hex->addTransport(transport);
}

void GameBoard::moveTransport(int id, Common::CubeCoordinate coord)
{

    std::shared_ptr<Common::Hex> newHex = this->getHex(coord);
    std::shared_ptr<Common::Transport> transport = this->getTransport(id);
    if(transport != nullptr && newHex != nullptr){
        std::shared_ptr<Common::Hex> oldHex = transport->getHex();
        if(oldHex != nullptr){
        oldHex->removeTransport(transport);
        newHex->addTransport(transport);

        }
    }
}

void GameBoard::removeTransport(int id)
{
    std::shared_ptr<Common::Transport> transport = this->getTransport(id);
    if(transport != nullptr){
        std::shared_ptr<Common::Hex> hex = transport->getHex();
        if(hex != nullptr){
            hex->removeTransport(transport);
        }
    }
}


std::vector<std::shared_ptr<Common::Hex>> GameBoard::getHexVector()
{
    return this->hexVector_;
}

std::pair<float, float> GameBoard::cubeToPixel(Common::CubeCoordinate coords)
{
    float x = 37.5*((3/2)*coords.x);
    float y = 25*((std::sqrt(3)/2)*coords.x + std::sqrt(3)*coords.y);
    auto result = std::make_pair(x,y);
    return result;
}

Common::CubeCoordinate GameBoard::pixelToCube(double x, double y)
{
    int q = (2./3 * x) / 25;
    int r = (-1./3 * x  +  sqrt(3)/3 * y )/ 37.5;
    return cubeRound(q,r,(-q + -r));
}

Common::CubeCoordinate GameBoard::cubeRound(float x, float y, float z)
{
    int rx = round(x);
    int ry = round(y);
    int rz = round(z);

    float x_diff = abs(rx - x);
    float y_diff = abs(ry - y);
    float z_diff = abs(rz - z);

    if (x_diff > y_diff and x_diff > z_diff){
       rx = -ry-rz;
    }
   else if(y_diff > z_diff){
       ry = -rx-rz;
   }
   else{
       rz = -rx-ry;
    }

   return Common::CubeCoordinate(rx,ry,rz);
}

std::vector<std::shared_ptr<Common::Pawn> > GameBoard::getPawnVector() const
{
    return pawnVector_;
}

void GameBoard::addHex(std::shared_ptr<Common::Hex> newHex){

    for(int i = 0; i < hexVector_.size(); ++i){
        if(hexVector_[i]->getCoordinates() == newHex->getCoordinates()){
            hexVector_[i] = newHex;
            return;
        }
    }
    this->hexVector_.push_back(newHex);
}

}
