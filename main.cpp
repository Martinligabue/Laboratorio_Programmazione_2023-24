#include <QApplication>
#include <QProgressBar>
#include <QTimer>
#include <QMainWindow>
#include <QObject>
#include "unistd.h"

#include <iostream>

#include "Subject.h"





int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QMainWindow finestra;
    finestra.setWindowTitle("Barra di Progresso");
    finestra.setFixedSize(600, 300);
    
    barra b;
    b.setParent(&finestra);
    b.setGeometry(100, 120, 400, 60);

    Subject s;
    s.addObserver(&b);
    s.carica();

    finestra.show();







    return a.exec();
    
}
