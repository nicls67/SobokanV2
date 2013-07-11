/**
 * @file mario.h
 * @brief Header file for class Mario
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

#ifndef MARIO_H
#define MARIO_H

#include "common.h"
#include "map.h"

class Map;

/**
 * This class represents the character "Mario" driven by the player in a Sobokan game. It contains the position and the direction of the character.
 * @brief The Mario class
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
class Mario
{
public:
    Mario();
    Mario(position p, int dir, Map *m);

    position getPosition();
    int getDirection();

    void up();
    void down();
    void left();
    void right();

private:
    position pos;
    int direction;
    Map *map;
};

#endif // MARIO_H
