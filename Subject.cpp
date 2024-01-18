#include "Subject.h"
#include <QDebug>
#include <unistd.h>
#include <QWidget>




Subject::Subject() : QPushButton(){};


void Subject::addObserver(barra* observer) {
    observers.push_back(observer);
}

void Subject::notifyAll(int percentuale) {
    for (barra* observer : observers) {
        observer->update(percentuale);
    }
}

void Subject::carica(int i) {
        notifyAll(i);
    }



void Subject::prova() {
    qDebug() << "piango...";

}
