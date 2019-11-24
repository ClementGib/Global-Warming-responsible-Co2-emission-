#include "GlobalWarmingresponsible.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCore/QDateTime>
#include <QtCharts/QDateTimeAxis>
#include <QtCore/QDebug>
#include <QtCharts/QValueAxis>
#include <QPainter>

#include <iostream>
#include <string>


#include "mongoDB.h"

using namespace std;




int main(int argc, char *argv[])
{


	QApplication a(argc, argv);

	

	GlobalWarmingresponsible w;
	w.show();


	return a.exec();
}
