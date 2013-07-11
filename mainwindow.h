/*
 *MainWindow.h
 *
 *This is part of Sobokan
 *
 *Main window header file of Sobokan
 *
 *Created by Nicolas Simon
 *09/07/2013
 *
 *
 */

/**
 * @file mainwindow.h
 * @brief Header file for class MainWindow
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QApplication>
#include <QMessageBox>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QProcess>
#include <QList>
#include <QFileDialog>

#include <fstream>

using namespace std;

#include "common.h"
#include "map.h"
#include "mario.h"

#define TAILLE_BLOC 34
#define H_FEN TAILLE_BLOC * H
#define W_FEN TAILLE_BLOC * W


/**
 * @brief The MainWindow class
 * @author Nicolas SIMON
 * @date 09/07/2013
 * @version 1.0
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void aboutSBK();
    void exe_new_lvl();
    void chargerNiveau();
    void recommencerNiveau();

private:
    void creationMenu();
    void creationScene();
    void updateScene();
    void niveau_termine();
    void keyPressEvent(QKeyEvent *event);

    QAction *recommencer;

    QWidget *zoneCentrale;
    QGraphicsScene *scene;
    QGraphicsPixmapItem* item[H][W];
    QGraphicsPixmapItem* marioItem;
    QGraphicsView *vue;

    QString nomFichier;

    Map *map;
    int obj_restant;
    bool ingame;
};

#endif // MAINWINDOW_H
