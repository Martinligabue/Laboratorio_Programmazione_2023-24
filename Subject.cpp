#include "Subject.h"
#include <QDebug>
#include <QTimer>

void Subject::addObserver(barra* observer) {
    observers.push_back(observer);
}

void Subject::notifyAll(int percentuale) {
    for (barra* observer : observers) {
        observer->update(percentuale);
    }
}

void Subject::carica() {
        notifyAll(40);

    }



void Subject::prova() {
    qDebug() << "piango...";

}
