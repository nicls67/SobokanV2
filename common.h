/*
 * Common defines and structures definitions for Sobokan and LevelCreator
 */

/**
 * @file common.h
 * @brief Contains common definitions for all classes
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
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
 * @brief Structure with coordinates
 */
struct position{
    int x;
    int y;
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
