#pragma once
#include "qthread.h"
#include "qdebug.h"
#include <iostream>
#include <istream>

using namespace std;
class Vague:public QThread
{
	Q_OBJECT
public :
	bool lancerVague();
protected:
	void run() override {
		for (int i = 0;i < 400;i++) {
			qDebug() << "Travail en cours dans le thread " << i;
			QThread::sleep(1);
		}
	}
};

