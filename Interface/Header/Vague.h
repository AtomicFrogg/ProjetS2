#pragma once
#include "qthread.h"
#include "qdebug.h"

class Vague:public QThread
{
	Q_OBJECT
protected:
	void run() override {
		for (int i = 0;i < 400;i++) {
			qDebug() << "Travail en cours dans le thread " << i;
			QThread::sleep(1);
		}
	}
};

