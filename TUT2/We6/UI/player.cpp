#include "player.hh"
namespace Student{
Player::Player(int playerId)
{
    this->playerId_ = playerId;
    actionsLeft_ = 3;
}

int Player::getPlayerId() const
{
    return playerId_;
}

void Player::setActionsLeft(unsigned int actionsLeft)
{
    actionsLeft_ = actionsLeft;
}

unsigned int Player::getActionsLeft() const
{
    return actionsLeft_;
}
}
