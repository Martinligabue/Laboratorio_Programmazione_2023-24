#include <QApplication>
#include <QMainWindow>
#include "unistd.h"
#include <QPushButton>
#include <QLabel>
#include <iostream>
#include <QTimer>
#include "Subject.h"





int main(int argc, char *argv[]) {

    QApplication a(argc, argv);

    QMainWindow finestra;
    finestra.setWindowTitle("Barra di Progresso");
    finestra.setFixedSize(600, 300);
    
    QLabel messaggio("cliccla il bottone per aggiornare lo stato del Subject <br>    e  vedere la barra di progresso caricarsi");
    messaggio.setParent(&finestra);
    messaggio.setGeometry(100, 10, 400, 60);


    barra *b = new barra();
    b->setParent(&finestra);
    b->setGeometry(100, 120, 400, 60);

    Subject *s = new Subject();
    
    s->addObserver(b);

    s->setParent(&finestra);
    
    int contatore = 0;
    

 QObject::connect(s, &QPushButton::clicked, [s, &contatore, &messaggio]() {
        s->carica(++contatore);
        if(contatore == 100){
            messaggio.setText("Hai completato il caricamento!");
            s->setEnabled(false);
        }
    });



    finestra.show();







    return a.exec();
    
}
