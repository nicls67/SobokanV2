/**
 * @file map.h
 * @brief Header file for class Map
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

#ifndef MAP_H
#define MAP_H

#include "common.h"
#include "mario.h"

class Mario;

/**
 * This class represents the map of a Sobokan game. It contains a grid with positions of  all items in the game and an object "Mario" which represents the character of the game.
 * @brief The Map class
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
class Map
{
public:
    Map();
    Map(int g[H][W], position *pos, int sens_mario);


    int getGrille(int x,int y);
    Mario *getMario();
    void setGrille(int x, int y, int type);

private:
    int grille[H][W];
    Mario *mario;
};

#endif // MAP_H
