#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <unistd.h>
#include "barra.h"

class Subject {
private:
    int percentuale;
    std::vector<barra*> observers;

public:
    void addObserver(barra* observer) {
        observers.push_back(observer);
    }

    void notifyAll(int percentuale) {
        for (barra* observer : observers) {
            observer->update(percentuale);
        }
    }


    void carica() {
        for (int i= 0; i<3; i++){
            notifyAll(i*10);
            sleep(1);
      

    }
            
    }
};


#endif