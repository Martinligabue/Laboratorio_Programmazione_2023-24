#ifndef BARRA_H
#define BARRA_H

#include <unistd.h>
#include <iostream>
#include <QProgressBar>


class barra : public QProgressBar {
public:
    barra() {
        setAlignment(Qt::AlignCenter);
        setRange(0, 100);
        setFixedSize(500, 300);
        //setValue(0);
    }

    void update(int percentuale) {
        setValue(percentuale);
        
    }
};


#endif
