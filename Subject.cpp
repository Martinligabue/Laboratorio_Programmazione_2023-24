#include "Subject.h"
#include <QDebug>
#include <unistd.h>

void Subject::addObserver(barra* observer) {
    observers.push_back(observer);
}

void Subject::notifyAll(int percentuale) {
    for (barra* observer : observers) {
        observer->update(percentuale);
    }
}

void Subject::carica() {
        sleep(1);
        notifyAll(40);
        sleep(2);
        notifyAll(20);

    }



void Subject::prova() {
    qDebug() << "piango...";

}
