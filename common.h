/*
 * Common defines and structures definitions for Sobokan and LevelCreator
 */

/**
 * @file common.h
 * @brief Contains common definitions for all classes
 * @author Nicolas SIMON
 * @version 2.0
 * @date 16/09/2013
 *
 */

#ifndef COMMON_H
#define COMMON_H

/**
 * Defines height of map
 */
#define H 5

/**
 * Defines width of map
 */
#define W 5

/**
 * @brief Represents a position on the map
 * @version 2.0
 * @date 16/09/2013
 */
class position{
public:
    position(){_x=0; _y=0;}
    position(int a, int b){_x=a; _y=b;}
    inline int x(){return _x;}
    inline int y(){return _y;}
    inline void setX(int a){_x=a;}
    inline void setY(int a){_y=a;}
    /**
     * @brief Increments x
     */
    inline void incX(){_x++;}
    /**
     * @brief Increments y
     */
    inline void incY(){_y++;}
    /**
     * @brief Decrements x
     */
    inline void decX(){_x--;}
    /**
     * @brief Decrements y
     */
    inline void decY(){_y--;}

private:
    int _x;
    int _y;
};




/**
 * Enumeration for possible directions
 */
enum {HAUT, BAS, GAUCHE, DROITE};

/**
 * Enumeration for items in the map
 */
enum {VIDE, MUR, CAISSE, OBJECTIF, CAISSE_OK};

#endif // COMMON_H
