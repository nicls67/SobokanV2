/*
 *MainWindow.cpp
 *
 *This is part of Sobokan
 *
 *
 *Main window of Sobokan
 *
 *Created by Nicolas Simon
 *
 *
 *
 */

/**
 * @file mainwindow.cpp
 * @brief Contains methods for class MainWindow
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

#include "mainwindow.h"

#ifdef Q_OS_WIN32
    #include <windows.h>
#endif

/**
 *
 * @author Nicolas SIMON
 * @date 11/07/2013
 * @brief MainWindow class constructor
 * @param parent
 * @version 1.0.1
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /*
     * Window size = W+1, H+22
     */
    setFixedSize(W_FEN+1,H_FEN+22);

    zoneCentrale = new QWidget;
    setCentralWidget(zoneCentrale);
    setFocusPolicy(Qt::StrongFocus);

    map=NULL;
    scene=NULL;
    vue=NULL;

    ingame=false;

    creationMenu();
    creationScene();
}

/**
 *
 * @brief MainWindow destructor
 */
MainWindow::~MainWindow(){}




/**
 *
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @brief Creating the menu bar
 * @version 1.0
 */
void MainWindow::creationMenu(){

    //définition des menus
    QMenu *menuFichier = menuBar()->addMenu("Fichier");
    QMenu *menuNiveau = menuBar()->addMenu("Niveau");
    QMenu *menuAide = menuBar()->addMenu("Aide");


    //menu fichier
    QAction *charger = menuFichier->addAction("Charger un niveau");
    connect(charger,SIGNAL(triggered()),this,SLOT(chargerNiveau()));
    recommencer = menuFichier->addAction("Recommencer le niveau");
    recommencer->setEnabled(false);
    connect(recommencer,SIGNAL(triggered()),this,SLOT(recommencerNiveau()));
    menuFichier->addSeparator();
    QAction *quitter = menuFichier->addAction("Quitter");
    connect(quitter,SIGNAL(triggered()),qApp,SLOT(quit()));



    //menu niveau
    QAction *new_level = menuNiveau->addAction("Créer un niveau");
    connect(new_level,SIGNAL(triggered()),this,SLOT(exe_new_lvl()));


    //menu aide
    QAction *aboutSBK = menuAide->addAction("A propos de Sobokan");
    QAction *aboutQt = menuAide->addAction("A propos de Qt");
    connect(aboutSBK,SIGNAL(triggered()),this,SLOT(aboutSBK()));
    connect(aboutQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));

}


/**
 *
 * @brief Create the scene of the game
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void MainWindow::creationScene(){

    scene =  new QGraphicsScene;

    vue= new QGraphicsView(scene, zoneCentrale);
    //vue->setSceneRect(0,0,W_FEN,H_FEN);
    vue->setSceneRect(0,0,1500,1500);
}


/**
 * @brief About the program
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void MainWindow::aboutSBK(){
    QMessageBox::about(this,"A propos de Sobokan","Sobokan v2.0\n\nBased on Qt 5.0.1\n\nAuthor : Nicolas Simon\nPour ma Lucile <3\n");
}



/**
 * @brief Launch program LevelCreator
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
void MainWindow::exe_new_lvl(){
#ifdef Q_OS_WIN32
    // For Windows UAC:
    ShellExecute(NULL, NULL,
                 reinterpret_cast<const WCHAR*>("LevelCreator2.exe"),
                 NULL, NULL, SW_SHOWNORMAL);
#else
    QProcess::startDetached("LevelCreator2.exe");
#endif
}



/**
 *
 * @brief Load a level from a file
 * @author Nicolas SIMON
 * @date 11/07/2013
 * @version 1.0.2
 */
void MainWindow::chargerNiveau(){

    nomFichier = QFileDialog::getOpenFileName(this, "Ouvrir", "levels", "Sobokan level files (*.lvl)");

    ifstream f(nomFichier.toStdString().c_str(), ios::in | ios::binary);

    int grille[H][W];
    position *pos = new position();

    int test; //for testing reading file only

    if(f.is_open()){
        f.read((char*)&test,sizeof(int));
        f.read((char*)&test,sizeof(int));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                f.read((char*)&grille[i][j],sizeof(int));
            }
        }
        f.read((char*)pos,sizeof(position));
        f.close();
    }
    else{
        QMessageBox::critical(this, "Erreur", "Impossible de charger le niveau");
        return;
    }

    if(map!=NULL)
        delete map;
    map = new Map(grille,pos,BAS);

    scene->clear();
    updateScene();
    ingame=true;

    recommencer->setEnabled(true);

    return;
}





/**
 *
 * @brief Reload the current level
 * @author Nicolas SIMON
 * @date 11/07/2013
 * @version 1.0.2
 */
void MainWindow::recommencerNiveau(){
    ifstream f(nomFichier.toStdString().c_str(), ios::in | ios::binary);

    int grille[H][W];
    position *pos = new position();

    int test; //test reading file only

    if(f.is_open()){
        f.read((char*)&test,sizeof(int));
        f.read((char*)&test,sizeof(int));
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                f.read((char*)&grille[i][j],sizeof(int));
            }
        }
        f.read((char*)pos,sizeof(position));
        f.close();
        delete map;
        map = new Map(grille,pos,BAS);


        scene->clear();
        updateScene();
        ingame=true;

    }
    else
        QMessageBox::critical(this, "Erreur", "Impossible de charger le niveau");

    return;
}




/**
 *
 * @brief Update the scene with new positions
 * @author Nicolas SIMON
 * @date 16/09/2013
 * @version 1.1
 */
void MainWindow::updateScene(){

    //update niveau
    obj_restant=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            switch(map->getGrille(j,i)){
            case MUR:
                item[i][j] = scene->addPixmap(QPixmap("sprites//mur.jpg"));
                item[i][j]->setPos(i*TAILLE_BLOC,j*TAILLE_BLOC);
                break;
            case CAISSE:
                item[i][j] = scene->addPixmap(QPixmap("sprites//caisse.jpg"));
                item[i][j]->setPos(i*TAILLE_BLOC,j*TAILLE_BLOC);
                break;
            case OBJECTIF:
                item[i][j] = scene->addPixmap(QPixmap("sprites//objectif.png"));
                item[i][j]->setPos(i*TAILLE_BLOC,j*TAILLE_BLOC);
                obj_restant++;
                break;
            case CAISSE_OK:
                item[i][j] = scene->addPixmap(QPixmap("sprites//caisse_ok.jpg"));
                item[i][j]->setPos(i*TAILLE_BLOC,j*TAILLE_BLOC);
                break;
            }

        }
    }

    //update mario
    switch(map->getMario()->getDirection()){
    case HAUT:
        marioItem = scene->addPixmap(QPixmap("sprites//mario_haut.gif"));
        marioItem->setPos(map->getMario()->getPosition()->x()*TAILLE_BLOC,map->getMario()->getPosition()->y()*TAILLE_BLOC);
        marioItem->setZValue(1);
        break;
    case BAS:
        marioItem = scene->addPixmap(QPixmap("sprites//mario_bas.gif"));
        marioItem->setPos(map->getMario()->getPosition()->x()*TAILLE_BLOC,map->getMario()->getPosition()->y()*TAILLE_BLOC);
        marioItem->setZValue(1);
        break;
    case DROITE:
        marioItem = scene->addPixmap(QPixmap("sprites//mario_droite.gif"));
        marioItem->setPos(map->getMario()->getPosition()->x()*TAILLE_BLOC,map->getMario()->getPosition()->y()*TAILLE_BLOC);
        marioItem->setZValue(1);
        break;
    case GAUCHE:
        marioItem = scene->addPixmap(QPixmap("sprites//mario_gauche.gif"));
        marioItem->setPos(map->getMario()->getPosition()->x()*TAILLE_BLOC,map->getMario()->getPosition()->y()*TAILLE_BLOC);
        marioItem->setZValue(1);
        break;
    }

    //verif niveau terminé
    if(obj_restant==0)
        niveau_termine();
}



/**
 * Display a message box to ask whether the player wants to start a new game or restart the last one
 * @brief Member called when a level is finished
 * @author Nicolas SIMON
 * @date 11/07/2013
 * @version 1.0.5
 */
void MainWindow::niveau_termine(){
    ingame=false;
    recommencer->setEnabled(false);
    QMessageBox::information(this, "Félicitations", "Vous avez terminé le niveau!");
    int a=QMessageBox::question(this,"Nouvelle partie","Voulez vous charger un nouveau niveau ?",QMessageBox::Retry | QMessageBox::Yes | QMessageBox::No);

    if (a==QMessageBox::Yes)
        chargerNiveau();
    else if(a==QMessageBox::Retry)
        recommencerNiveau();
    else
        scene->clear();
}


/**
 * This method catch a key event, update the map and update the scene. This method overlaods the "keyPressEvent" method of class QMainWindow.
 * @brief Catch a key event
 * @param event
 * @author Nicolas SIMON
 * @date 11/07/2013
 * @version 1.1
 */
void MainWindow::keyPressEvent(QKeyEvent *event){
    if(ingame){
        switch(event->key()){
        case Qt::Key_Z:
            map->getMario()->up();
            break;
        case Qt::Key_S:
            map->getMario()->down();
            break;
        case Qt::Key_Q:
            map->getMario()->left();
            break;
        case Qt::Key_D:
            map->getMario()->right();
            break;
        }

        scene->clear();
        updateScene();
    }

}
