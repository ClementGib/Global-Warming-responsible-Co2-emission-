#include "GlobalWarmingresponsible.h"





using namespace std;


QT_CHARTS_USE_NAMESPACE



QChart* GlobalWarmingresponsible::CreateChartLineCountry(QString Name_country)
{
	std::string string_name = Name_country.toUtf8().constData();
	

	///Get country map
	map<std::string,double> My_country = MongoDB->GetValue_Country_ByName(string_name);


	QLineSeries* lineseries = new QLineSeries();



	map<std::string, double>::iterator itr;

	QCategoryAxis* axisX = new QCategoryAxis();
	axisX->setTitleText("Years");


	int index_line = 0;
	for (itr = My_country.begin(); itr != My_country.end(); ++itr) {

		lineseries->append(index_line,itr->second);
		axisX->append(QString::fromStdString(itr->first), index_line++);
	}
	




	QChart* chartline = new QChart();
	chartline->legend()->hide();
	chartline->addSeries(lineseries);

	//round to the greater 
	//int ValueMax = ceil(My_country.end()->second);
	//for (int index_Y = 0; index_Y < My_country.end()->second; index_Y++) {


	//	axisY->append(QString::number(index_Y), index_Y);
	//}

	
	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("CO2 emissions (metric tons per capita)");

	//chartline->setAxisX(axisX, lineseries);
	chartline->addAxis(axisX, Qt::AlignBottom);
	chartline->addAxis(axisY, Qt::AlignLeft);
	lineseries->attachAxis(axisX);
	lineseries->attachAxis(axisY);




	//Font label date
	QFont labelXfont;
	labelXfont.setPixelSize(8);
	axisX->setLabelsFont(labelXfont);



	QFont font;
	font.setPixelSize(22);
	chartline->setTitleFont(font);
	chartline->setTitleBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
	chartline->setTitle(Name_country);
	//chartline->setTitle(Name_country);

	QPen pen(QRgb(0x000000));
	pen.setWidth(5);
	lineseries->setPen(pen);
	chartline->setAnimationOptions(QChart::AllAnimations);





	return chartline;
}

QChart* GlobalWarmingresponsible::CreateChartLineCountry()
{

	///TEST
	QLineSeries* lineseries = new QLineSeries();
	lineseries->append(0,16);
	lineseries->append(1,25);
	lineseries->append(2,24);
	lineseries->append(3,19);
	lineseries->append(4,33);
	lineseries->append(5,25);
	lineseries->append(6,34);


	QChart* chartline = new QChart();
	chartline->legend()->hide();
	chartline->addSeries(lineseries);
	QFont font;
	font.setPixelSize(18);
	chartline->setTitleFont(font);
	chartline->setTitleBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
	chartline->setTitle("Barry Bonds HRs as Pirate");

	QPen pen(QRgb(0x000000));
	pen.setWidth(5);
	lineseries->setPen(pen);
	chartline->setAnimationOptions(QChart::AllAnimations);

	QCategoryAxis* axisX = new QCategoryAxis();
	axisX->append("1986", 0);
	axisX->append("1987", 1);
	axisX->append("1988", 2);
	axisX->append("1989", 3);
	axisX->append("1990", 4);
	axisX->append("1991", 5);
	axisX->append("1992", 6);

	chartline->setAxisX(axisX, lineseries);

	return chartline;
}

QChart* GlobalWarmingresponsible::CreateChartLineContinent(QString Name_continent)
{
	std::string string_name = Name_continent.toUtf8().constData();


	///Get country map
	map<std::string, double> My_country = MongoDB->GetValue_Countries_ByContinent(string_name);


	QLineSeries* lineseries = new QLineSeries();



	map<std::string, double>::iterator itr;

	QCategoryAxis* axisX = new QCategoryAxis();
	axisX->setTitleText("Years");


	double index_line = 0;
	for (itr = My_country.begin(); itr != My_country.end(); ++itr) {

		lineseries->append(index_line, itr->second);
		axisX->append(QString::fromStdString(itr->first), index_line++);
	}





	QChart* chartline = new QChart();
	chartline->legend()->hide();
	chartline->addSeries(lineseries);

	//round to the greater 
	//int ValueMax = ceil(My_country.end()->second);
	//for (int index_Y = 0; index_Y < My_country.end()->second; index_Y++) {



	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("CO2 emissions (metric tons per capita)");

	//chartline->setAxisX(axisX, lineseries);
	chartline->addAxis(axisX, Qt::AlignBottom);
	chartline->addAxis(axisY, Qt::AlignLeft);
	lineseries->attachAxis(axisX);
	lineseries->attachAxis(axisY);




	//Font label date
	QFont labelXfont;
	labelXfont.setPixelSize(8);
	axisX->setLabelsFont(labelXfont);



	QFont font;
	font.setPixelSize(22);
	chartline->setTitleFont(font);
	chartline->setTitleBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
	chartline->setTitle(Name_continent);
	//chartline->setTitle(Name_country);

	QPen pen(QRgb(0x000000));
	pen.setWidth(5);
	lineseries->setPen(pen);
	chartline->setAnimationOptions(QChart::AllAnimations);





	return chartline;
}

QChart* GlobalWarmingresponsible::CreateChartLineWorld()
{

	QString Name = "World";
	///Get country map
	map<std::string, double> My_country = MongoDB->GetValueWorld();


	QLineSeries* lineseries = new QLineSeries();



	map<std::string, double>::iterator itr;

	QCategoryAxis* axisX = new QCategoryAxis();
	axisX->setTitleText("Years");


	int index_line = 0;
	for (itr = My_country.begin(); itr != My_country.end(); ++itr) {

		lineseries->append(index_line, itr->second);
		axisX->append(QString::fromStdString(itr->first), index_line++);
	}





	QChart* chartline = new QChart();
	chartline->legend()->hide();
	chartline->addSeries(lineseries);

	//round to the greater 
	//int ValueMax = ceil(My_country.end()->second);
	//for (int index_Y = 0; index_Y < My_country.end()->second; index_Y++) {



	QValueAxis* axisY = new QValueAxis;
	axisY->setLabelFormat("%i");
	axisY->setTitleText("CO2 emissions (metric tons per capita)");

	//chartline->setAxisX(axisX, lineseries);
	chartline->addAxis(axisX, Qt::AlignBottom);
	chartline->addAxis(axisY, Qt::AlignLeft);
	lineseries->attachAxis(axisX);
	lineseries->attachAxis(axisY);




	//Font label date
	QFont labelXfont;
	labelXfont.setPixelSize(8);
	axisX->setLabelsFont(labelXfont);



	QFont font;
	font.setPixelSize(22);
	chartline->setTitleFont(font);
	chartline->setTitleBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
	chartline->setTitle(Name);
	//chartline->setTitle(Name_country);

	QPen pen(QRgb(0x000000));
	pen.setWidth(5);
	lineseries->setPen(pen);
	chartline->setAnimationOptions(QChart::AllAnimations);





	return chartline;
}

QChart* GlobalWarmingresponsible::CreateBarSeriesTOP()
{


	map<std::string, double> My_country = MongoDB->GetTOP();





	map<std::string, double>::iterator itr;

	//CHART BAR
	QBarSeries* series = new QBarSeries();

	int index_line = 0;
	for (itr = My_country.begin(); itr != My_country.end(); ++itr) {


		QBarSet* L_Set = new QBarSet(QString::fromStdString(itr->first));
		*L_Set << itr->second;
		series->append(L_Set);
	}



	QChart* chart = new QChart();
	chart->addSeries(series);

	//AnimationOption (avec ou sans)
	chart->setAnimationOptions(QChart::AllAnimations);
	QStringList categories;
	categories << "CO2 emissions (metric tons per capita)";

	QBarCategoryAxis *axis = new QBarCategoryAxis();
	axis->append(categories);
	chart->createDefaultAxes();
	chart->setAxisX(axis, series);
	chart->legend()->setVisible(true);
	chart->legend()->setAlignment(Qt::AlignBottom);

	QChartView* chartView = new QChartView(chart);
	chartView->setRenderHint(QPainter::Antialiasing);
	QPalette pal = qApp->palette();
	pal.setColor(QPalette::Window, QRgb(0xffffff));
	pal.setColor(QPalette::WindowText, QRgb(0x404040));
	qApp->setPalette(pal);






	return chart;
}



GlobalWarmingresponsible::GlobalWarmingresponsible(QWidget *parent)
	: QMainWindow(parent)
{





	ui.setupUi(this);

	//test, définir le widget central 
	//this->setCentralWidget(ui.graphicsViewW);

	///Monde
	ui.graphicsViewW->setChart(CreateChartLineWorld());
	ui.graphicsViewW->setRenderHint(QPainter::Antialiasing);

	
	//Europe
	ui.graphicsViewEU->setChart(CreateChartLineContinent("Europe"));
	ui.graphicsViewEU->setRenderHint(QPainter::Antialiasing);

	//Amerique du sud
	ui.graphicsViewNA->setChart(CreateChartLineContinent("North America"));
	ui.graphicsViewNA->setRenderHint(QPainter::Antialiasing);

	//Amerique du nord
	ui.graphicsViewSA->setChart(CreateChartLineContinent("South America"));
	ui.graphicsViewSA->setRenderHint(QPainter::Antialiasing);

	//Afrique
	ui.graphicsViewAF->setChart(CreateChartLineContinent("Africa"));
	ui.graphicsViewAF->setRenderHint(QPainter::Antialiasing);

	//Asie
	ui.graphicsViewAS->setChart(CreateChartLineContinent("Asia"));
	ui.graphicsViewAS->setRenderHint(QPainter::Antialiasing);

	ui.graphicsViewOC->setChart(CreateChartLineContinent("Oceania"));
	ui.graphicsViewOC->setRenderHint(QPainter::Antialiasing);

	ui.graphicsViewBar->setChart(CreateBarSeriesTOP());

}



