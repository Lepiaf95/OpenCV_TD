#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/Mat.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void exo1() // Chargement et affichage d'une ilage
{
	Mat img = imread("images/landscape.jpg");
	
	if (img.empty())
		cout << "Cette image est vide !" << endl;
	else
	imshow("image", img);
	waitKey(0);
	destroyWindow("image");
}

void exo2() // Filtrage linéaire
{
	Mat img_source = imread("images/plane.jpg");
	if (img_source.empty())
			cout << "Cette image est vide !" << endl;

	Mat img_destination;

	Mat noyau = Mat::ones(Size(3,3), CV_32F);
	noyau /= 9;
	

	filter2D(img_source, img_destination, -1, noyau);

	imshow("image_source", img_source);
	imshow("image_destination", img_destination);
	waitKey(0);
	destroyAllWindows();
}

void exo3() // Lissage de l'image
{
	Mat img_source = imread("images/monalisa.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	Mat img_gaussien;

	Mat img_median;

	Mat img_bilateral;

	GaussianBlur(img_source, img_gaussien,Size(5,5),0);
	medianBlur(img_source, img_median, 5);
	bilateralFilter(img_source, img_bilateral, 15, 15*2, 15/2.0);


	imshow("image_source", img_source);
	imshow("image_gaussien", img_gaussien);
	imshow("image_median", img_median);
	imshow("image_bilateral", img_bilateral);
	waitKey(0);
	destroyAllWindows();

}

void exo4() // Morphologie mathématiques
{
	Mat img_source = imread("images/apple.png");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	Mat img_dilatee;

	Mat img_erodee;

	Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));

	dilate(img_source, img_dilatee, kernel);
	erode(img_source, img_erodee, kernel);

	imshow("image_source", img_source);
	imshow("image_dilatee", img_dilatee);
	imshow("image_erodee", img_erodee);
	waitKey(0);
	destroyAllWindows();
}

void exo5() // Seuillage de l'image
{
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/tiger.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	namedWindow("threshold", WINDOW_AUTOSIZE);
	Mat img_resultat;

	// Convertir l'image en gris
	namedWindow("image_source_grise", WINDOW_AUTOSIZE);
	Mat img_source_gray = imread("images/tiger.jpg", IMREAD_GRAYSCALE);


	threshold(img_source_gray, img_resultat, 100, 255, THRESH_BINARY);

	imshow("image_source", img_source);
	imshow("image_source_grise", img_source_gray);
	imshow("threshold", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

void exo6() // Détection et contours
{
	Mat img_source = imread("images/building.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	Mat img_resultat1;
	Mat img_resultat2 = imread("images/building.jpg", IMREAD_GRAYSCALE);
	Mat img_resultat3;

	// Convertir l'image en gris
	Mat img_source_gray;
	cvtColor(img_source, img_source_gray, COLOR_BGR2GRAY);

	Laplacian(img_source_gray, img_resultat1, 16, 3);
	convertScaleAbs(img_resultat1, img_resultat1);
	// Sobel()
	Canny(img_source, img_resultat3, 20, 110);


	imshow("image_source", img_source);
	imshow("image_source_grise", img_source_gray);
	imshow("laplacian", img_resultat1);
	imshow("image_source_grise2", img_resultat2);
	imshow("canny", img_resultat3);
	waitKey(0);
	destroyAllWindows();
}

void exo7() // Egalisaton d'histogrammes
{
	Mat img_source = imread("images/bird.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;
	Mat img_source_gray;
	// Convertir l'image en gris
	cvtColor(img_source, img_source_gray, COLOR_BGR2GRAY);

	Mat img_resultat;

	equalizeHist(img_source_gray, img_resultat);

	imshow("image_source", img_source);
	imshow("image_source_grise", img_source_gray);
	imshow("image_resultat", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

void exo8() // Appariement d'images
{
	Mat img_source = imread("images/bus.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;
	Mat img_source_modele = imread("images/bus_template.png");
	if (img_source_modele.empty())
		cout << "Cette image est vide !" << endl;

	Mat img_resultat;

	double minVal;
	double maxVal;
	Point minLoc;
	Point maxLoc;

	matchTemplate(img_source, img_source_modele, img_resultat, TM_SQDIFF_NORMED);
	minMaxLoc(img_resultat, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
	rectangle(img_source, minLoc, Point(minLoc.x + img_source_modele.cols, minLoc.y + img_source_modele.rows), Scalar::all(0), 2, 8, 0);

	imshow("image_source", img_source);
	imshow("image_source_modele", img_source_modele);
	imshow("matchTemplate", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

void exo9() // Détection de contours
{
	Mat img_source = imread("images/porsche.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	Mat img_source_gray;
	cvtColor(img_source, img_source_gray, COLOR_BGR2GRAY);

	Mat img_resultat;
	Canny(img_source, img_resultat, 100, 200);

	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;
	findContours(img_resultat, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	// Tracer les contours trouvés
	RNG rng(12345);
	Mat drawing = Mat::zeros(img_resultat.size(), CV_8UC3);
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours, i, color, 2, 8, hierarchy, 0, Point());
	}

	imshow("image_source", img_source);
	imshow("image_source_grise", img_source_gray);
	imshow("matchTemplate", img_resultat);
	imshow("contours", drawing);
	waitKey(0);
	destroyAllWindows();
}

void exo10() // Enveloppe convexe
{
	Mat image(Size(500, 500), CV_32F);
	while (1)
	{
		vector<vector<Point> > points;
	}

	imshow("enveloppe convexe", image);
	waitKey(0);
	destroyAllWindows();
}

void Partie1()
{
	exo1();
	exo2();
	exo3();		
	exo4();
	exo5();
	exo6();
	exo7();
}

void Partie2()
{
	exo8();
	exo9();
	exo10();
}
int main() 
{	
	// Partie 1
	//Partie1();

	// Partie 2
	Partie2();

	return 0;
}