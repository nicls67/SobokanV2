/**
 * @file mario.cpp
 * @brief Contains methods for class Mario
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */



#include "mario.h"

/**
 * @brief Default contructor for class Mario
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
Mario::Mario(){
    pos.x=0;
    pos.y=0;
    direction=BAS;
}



/**
 * @brief Constructor of class Mario
 * @param p  position of Mario
 * @param dir  direction of Mario
 * @param m pointer to the Map containing Mario
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
Mario::Mario(position p, int dir, Map *m){
    pos=p;
    direction=dir;
    map=m;
}



/**
 * @brief Get position of Mario
 * @return position of Mario
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
position Mario::getPosition(){
    return pos;
}


/**
 * @brief Get direction of Mario
 * @return direction of Mario
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
int Mario::getDirection(){
    return direction;
}



/**
 *
 * @brief Move Mario upward
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void Mario::up(){
    direction=HAUT;

    if(pos.y!=0){
        //test si vide
        if(map->getGrille(pos.y-1,pos.x)==VIDE || map->getGrille(pos.y-1,pos.x)==OBJECTIF)
            pos.y--;
        //test si caisse
        else if(map->getGrille(pos.y-1,pos.x)==CAISSE && pos.y!=1){
            if(map->getGrille(pos.y-2,pos.x)==VIDE){
                map->setGrille(pos.y-2,pos.x,CAISSE);
                map->setGrille(pos.y-1,pos.x,VIDE);
                pos.y--;
            }
            else if(map->getGrille(pos.y-2,pos.x)==OBJECTIF){
                map->setGrille(pos.y-2,pos.x,CAISSE_OK);
                map->setGrille(pos.y-1,pos.x,VIDE);
                pos.y--;
            }
        }
        //test si caisse ok
        else if(map->getGrille(pos.y-1,pos.x)==CAISSE_OK && pos.y!=1){
            if(map->getGrille(pos.y-2,pos.x)==VIDE){
                map->setGrille(pos.y-2,pos.x,CAISSE);
                map->setGrille(pos.y-1,pos.x,OBJECTIF);
                pos.y--;
            }
            else if(map->getGrille(pos.y-2,pos.x)==OBJECTIF){
                map->setGrille(pos.y-2,pos.x,CAISSE_OK);
                map->setGrille(pos.y-1,pos.x,OBJECTIF);
                pos.y--;
            }
        }
    }
}



/**
 *
 * @brief Move Mario downward
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void Mario::down(){
    direction=BAS;
    if(pos.y!=H-1){
        //test si vide
        if(map->getGrille(pos.y+1,pos.x)==VIDE || map->getGrille(pos.y+1,pos.x)==OBJECTIF)
            pos.y++;
        //test si caisse
        else if(map->getGrille(pos.y+1,pos.x)==CAISSE && pos.y!=H-2){
            if(map->getGrille(pos.y+2,pos.x)==VIDE){
                map->setGrille(pos.y+2,pos.x,CAISSE);
                map->setGrille(pos.y+1,pos.x,VIDE);
                pos.y++;
            }
            else if(map->getGrille(pos.y+2,pos.x)==OBJECTIF){
                map->setGrille(pos.y+2,pos.x,CAISSE_OK);
                map->setGrille(pos.y+1,pos.x,VIDE);
                pos.y++;
            }
        }
        //test si caisse ok
        else if(map->getGrille(pos.y+1,pos.x)==CAISSE_OK && pos.y!=H-2){
            if(map->getGrille(pos.y+2,pos.x)==VIDE){
                map->setGrille(pos.y+2,pos.x,CAISSE);
                map->setGrille(pos.y+1,pos.x,OBJECTIF);
                pos.y++;
            }
            else if(map->getGrille(pos.y+2,pos.x)==OBJECTIF){
                map->setGrille(pos.y+2,pos.x,CAISSE_OK);
                map->setGrille(pos.y+1,pos.x,OBJECTIF);
                pos.y++;
            }
        }
    }
}


/**
 *
 * @brief Move Mario to left
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void Mario::left(){
    direction=GAUCHE;
    if(pos.x!=0){
        //test si vide
        if(map->getGrille(pos.y,pos.x-1)==VIDE || map->getGrille(pos.y,pos.x-1)==OBJECTIF)
            pos.x--;
        //test si caisse
        else if(map->getGrille(pos.y,pos.x-1)==CAISSE && pos.x!=1){
            if(map->getGrille(pos.y,pos.x-2)==VIDE){
                map->setGrille(pos.y,pos.x-2,CAISSE);
                map->setGrille(pos.y,pos.x-1,VIDE);
                pos.x--;
            }
            else if(map->getGrille(pos.y,pos.x-2)==OBJECTIF){
                map->setGrille(pos.y,pos.x-2,CAISSE_OK);
                map->setGrille(pos.y,pos.x-1,VIDE);
                pos.x--;
            }
        }
        //test si caisse ok
        else if(map->getGrille(pos.y,pos.x-1)==CAISSE_OK && pos.x!=1){
            if(map->getGrille(pos.y,pos.x-2)==VIDE){
                map->setGrille(pos.y,pos.x-2,CAISSE);
                map->setGrille(pos.y,pos.x-1,OBJECTIF);
                pos.x--;
            }
            else if(map->getGrille(pos.y,pos.x-2)==OBJECTIF){
                map->setGrille(pos.y,pos.x-2,CAISSE_OK);
                map->setGrille(pos.y,pos.x-1,OBJECTIF);
                pos.x--;
            }
        }
    }
}


/**
 *
 * @brief Move Mario to right
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void Mario::right(){
    direction = DROITE;
    if(pos.x!=W-1){
        //test si vide
        if(map->getGrille(pos.y,pos.x+1)==VIDE || map->getGrille(pos.y,pos.x+1)==OBJECTIF)
            pos.x++;
        //test si caisse
        else if(map->getGrille(pos.y,pos.x+1)==CAISSE && pos.x!=W-2){
            if(map->getGrille(pos.y,pos.x+2)==VIDE){
                map->setGrille(pos.y,pos.x+2,CAISSE);
                map->setGrille(pos.y,pos.x+1,VIDE);
                pos.x++;
            }
            else if(map->getGrille(pos.y,pos.x+2)==OBJECTIF){
                map->setGrille(pos.y,pos.x+2,CAISSE_OK);
                map->setGrille(pos.y,pos.x+1,VIDE);
                pos.x++;
            }
        }
        //test si caisse ok
        else if(map->getGrille(pos.y,pos.x+1)==CAISSE_OK && pos.x!=W-2){
            if(map->getGrille(pos.y,pos.x+2)==VIDE){
                map->setGrille(pos.y,pos.x+2,CAISSE);
                map->setGrille(pos.y,pos.x+1,OBJECTIF);
                pos.x++;
            }
            else if(map->getGrille(pos.y,pos.x+2)==OBJECTIF){
                map->setGrille(pos.y,pos.x+2,CAISSE_OK);
                map->setGrille(pos.y,pos.x+1,OBJECTIF);
                pos.x++;
            }
        }
    }
}
