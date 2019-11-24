#pragma once

#include <QtWidgets/QMainWindow>
#include <QChart>
#include <string>     // string, to_string
#include <QDebug>
#include <QtCharts/qchartview.h>
#include <qjsonvalue.h>



#include "ui_GlobalWarmingresponsible.h"
#include "mongoDB.h"


QT_CHARTS_USE_NAMESPACE

class GlobalWarmingresponsible : public QMainWindow
{
	Q_OBJECT

public:
	GlobalWarmingresponsible(QWidget *parent = Q_NULLPTR);



protected:
	//singleton mongo
	mongoDB* MongoDB = mongoDB::getInstance();

	//ChartLine 
	QChart* CreateChartLineCountry(QString Name_country);
	QChart* CreateChartLineCountry();
	QChart* CreateChartLineContinent(QString Name_continent);
	QChart* CreateChartLineWorld();

	//ChartBar
	QChart* CreateBarSeriesTOP();

	

private:
	Ui::GlobalWarmingresponsibleClass ui;
};
