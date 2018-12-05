#include "gamestate.hh"

namespace Student{
GameState::GameState()
{
    currentPlayer_ = 0;
}

GameState::~GameState()
{

}

Common::GamePhase GameState::currentGamePhase() const
{
    return currentGamePhase_;
}

int GameState::currentPlayer() const
{
    return currentPlayer_;
}

void GameState::changeGamePhase(Common::GamePhase nextPhase)
{
    currentGamePhase_ = nextPhase;
}

void GameState::changePlayerTurn(int nextPlayer)
{
    currentPlayer_ = nextPlayer;
}
}
