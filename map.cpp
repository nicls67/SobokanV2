/**
 * @file map.cpp
 * @brief Contains methods for class Map
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

#include "map.h"


/**
 *
 * @brief Default constructor for class Map
 * @date 09/07/2013
 * @version 1.0
 */
Map::Map(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            grille[i][j]=0;
        }
    }
    //grille = {0};
    mario = new Mario();
}


/**
 * @brief Map::Map
 * @param g  grid
 * @param pos  position of Mario
 * @param sens_mario  direction of Mario
 * @version 1.0
 * @date 09/07/2013
 */
Map::Map(int g[H][W], position *pos, int sens_mario){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            grille[i][j]=g[i][j];
        }
    }
    mario = new Mario(pos,sens_mario,this);
}



/**
 * Give the type of item at the coordinates (x,y) of the map
 * @brief Get the grid
 * @return The type of item
 * @date 09/07/2013
 * @version 1.0
 * @param x
 * @param y
 */
int Map::getGrille(int x,int y){
    return grille[x][y];
}


/**
 * @brief Get the Mario object of the map
 * @return pointer to Mario object
 * @date 09/07/2013
 * @version 1.0
 */
Mario* Map::getMario(){
    return mario;
}


/**
 * @brief set the type of item at position (x,y)
 * @param x
 * @param y
 * @param type Type of item
 * @date 09/07/2013
 * @version 1.0
 */
void Map::setGrille(int x, int y, int type){
    grille[x][y]=type;
}
