#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

/**
 * @file main.cpp
 * @brief main function of program
 * @author Nicolas SIMON
 * @version 1.0
 * @date 09/07/2013
 *
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    if(QMessageBox::question(&w,"Début du jeu","Voulez-vous charger un niveau ?")==QMessageBox::Yes)
        w.chargerNiveau();
    
    return a.exec();
}
