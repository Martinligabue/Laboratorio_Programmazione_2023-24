#include <QApplication>
#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>

#include "unistd.h"

#include <iostream>

#include "Subject.h"





int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    
    barra b;
    Subject s;
    
    s.addObserver(&b);

    
    
    s.carica();

    b.show();

    



    return a.exec();;
    
}
