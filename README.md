
# Projet MongoDB
## Objectifs principaux :
* À rendre au plus tard le dimanche 3 novembre au soir (minuit au plus tard : essayez de vraiment respecter cette limite)
* Projet personnel ou fait en groupe jusqu'à 3 personnes
* La thématique du projet est libre : page web, autre type d'application...
* L'utilisation d'une base mongoDB est IMPÉRATIVE
* Envoi IMPÉRATIF d'un document explicatif (technique et fonctionnel) :
1. Fonctionnel : expliquez ce que fait votre projet, comment (sur quel bouton appuyer, quels résultats sont attendus etc...) comment le lancer? Le document doit clarifier L'UTILISATION du projet.
2. Technique : Quels choix techniques ont été faits? Pourquoi (traduction : JUSTIFIEZ VOS CHOIX TECHNIQUES) Quels autres outils avez-vous intégré à votre projet? (API, bibliothèque, autres...) Donnez les étapes précises qui permettent d'utiliser votre projet de façon efficace (installation etc...) Si vous utilisez des sources extérieures d'informations, merci de préciser lesquelles. Le document doit donc également clarifier LE FONCTIONNEMENT du projet.
* À envoyer par Docker/Github/lien etc... (m)

## Objectifs personnels :
* Faire un projet cross-platform via CMake 3.16 (Windows, Unix, MacOS)
* Faire un projet mongo permettant d’afficher les données de production de gaz à effet de serre des différents pays (d’après la base who-is-responsible-for-global-warming ).
* Afficher la production de gaz à effet de serre des continents du monde via Qt 5
* Faire un top 5 des pays ayant la plus grosse émissions de CO2 (metric tons per capita).

## __MongoDB driver :__
__Linux:__
```bash
"./bootstrap
make
make install" (sudo si besoin)
Windows:
cd cmake-build
cmake -G "Visual Studio 16 2019 Win64" \
"-DCMAKE_INSTALL_PREFIX=C:\mongo-c-driver" \
"-DCMAKE_PREFIX_PATH=C:\mongo-c-driver" \
..
```
__Windows :__
<p> Visual Studio :</p>

<p> Download vcpkg pour windows: </p>

```bash
cd .\Users\Cleme\Documents\vcpkg\vcpkg\
Installdrivers MongoDB
.\vcpkg search mongodb
.\vcpkg.exe install mongo-cxx-driver
.\vcpkg.exe install mongo-cxx-driver:x64-windows
```

## __Install Qt5 :__

__Visual Studio :__

 <p> Download vcpkg pour windows: </p>

```bash 
cd .\Users\Cleme\Documents\vcpkg\
./vcpkg.exe install qt5-base:x64-windows
```

## BASE MONGO :
__Importation de la collection contenant des infos générales sur les régions :__

```bash 
mongoimport --db=GlobWarm --collection=info --type=csv --headerline --
file=/mnt/c/Users/Cleme/Dropbox/X/XDev/DB/MongoDB/Projet/db/Metadata_Country_API_EN.A
TM.CO2E.PC_DS2_en_csv_v2_10576797.csv
```

__Importation de la collection contenant la production de gaz à effet de serre pour chaque pays
depuis 1960 :__

```bash 
mongoimport --db=GlobWarm --collection=countries --type=csv --headerline --
file=/mnt/c/Users/Cleme/Dropbox/X/XDev/DB/MongoDB/Projet/db/API_EN.ATM.CO2E.PC_DS2_e
n_csv_v2_10576797.csv
```
```bash 
sudo mongod --port=27017
```
__Collection: countries:__

| "_id"            | ObjectId("5dc968abcd1989356756960a")     |
|------------------|------------------------------------------|
| "Country Name"   | "Australia"                              |
| "Country Code"   | "AUS"                                    |
| "Indicator Name" | "CO2 emissions (metric tons per capita)" |
| "Indicator Code" | "EN.ATM.CO2E.PC"                         |
| "1960"           | 8.58293664258675                         |
|  ...             | “…”                                      |
| "2014"           | 15.3887660194467                         |
|                  |                                          |
|                  |                                          |

__Collection : info__
| "_id"            | ObjectId("5dc968abcd1989356756960a")     |
|------------------|------------------------------------------|
| "Country Name"   | "Australia"                              |
| "Country Code"   | "AUS"                                    |
| "Indicator Name" | "CO2 emissions (metric tons per capita)" |
| "Indicator Code" | "EN.ATM.CO2E.PC"                         |
| "1960"           | 8.58293664258675                         |
|  ...             | “…”                                      |
| "2014"           | 15.3887660194467                         |


## PROJET :
<p> Le projet a été développé via Visual Studio 2019 avec les drivers incluant les librairies mongos pour
pouvoir échanger avec le serveur : </p>

* bsoncxx
* mongocxx

<p>L’usage de mongoDB à été faite via un singleton (class static), afin de s’assurer qu’il soit instancié
qu’une seule fois.
L’utilisation de Qt5 ainsi que des QCharts (Graphiques intégré à Qt) à permit de rendre les données
plus significative</p>

<img src="https://github.com/ClementGib/Global-Warming-responsible-Co2-emission-/blob/master/image/TP_Mongo-Gibert_Cl%C3%A9ment_all.jpg">

<p> L’application permet d’afficher l’émission des gaz à effet de serre de chaque continents (onglets)
mais aussi un top 5 des pays émetteurs.
Pour exécuter l’application il faut être sur Windows 10 et posséder les DLL suivant (répertoire de
l’exécutable) : </p>

* bsoncxx.dll
* libbson-1.0.dll
* libmongoc-1.0.dll
* mongocxx.dll
* Qt5Charts.dll
* Qt5Core.dll
* Qt5Gui.dll
* Qt5Widgets.dll
* zlib1.dll

<img src="https://github.com/ClementGib/Global-Warming-responsible-Co2-emission-/blob/master/image/TP_Mongo-Gibert_Cl%C3%A9ment.jpg">

__TOP 5 Countries:__

<img src="https://github.com/ClementGib/Global-Warming-responsible-Co2-emission-/blob/master/image/TP_Mongo-Gibert_Cl%C3%A9ment_graph.jpg">
