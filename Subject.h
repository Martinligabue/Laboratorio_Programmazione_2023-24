#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
#include <unistd.h>
#include <QPushButton>

#include "barra.h"


class Subject{

    private:
    int percentuale;
    std::vector<barra*> observers;

public:
    void addObserver(barra* observer);
    void notifyAll(int percentuale);


    void carica();
    void prova();
};




#endif