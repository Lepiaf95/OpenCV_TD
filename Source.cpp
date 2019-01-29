#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/core/Mat.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void exo1() // Chargement et affichage d'une ilage
{
	namedWindow("image", WINDOW_AUTOSIZE );
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
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/plane.jpg");
	if (img_source.empty())
			cout << "Cette image est vide !" << endl;

	namedWindow("image_destination", WINDOW_AUTOSIZE);
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
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/monalisa.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	namedWindow("image_gaussien", WINDOW_AUTOSIZE);
	Mat img_gaussien;

	namedWindow("image_median", WINDOW_AUTOSIZE);
	Mat img_median;

	namedWindow("image_bilateral", WINDOW_AUTOSIZE);
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
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/apple.png");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	namedWindow("image_dilatee", WINDOW_AUTOSIZE);
	Mat img_dilatee;

	namedWindow("image_erodee", WINDOW_AUTOSIZE);
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

	namedWindow("image_resultat", WINDOW_AUTOSIZE);
	Mat img_resultat;

	// Faire une autre fonction !!!!
	medianBlur(img_source, img_resultat, 5);

	imshow("image_source", img_source);
	imshow("image_resultat", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

void exo6() // Détection et contours
{
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/building.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	namedWindow("image_resultat", WINDOW_AUTOSIZE);
	Mat img_resultat;

	// Faire une autre fonction !!!!
	medianBlur(img_source, img_resultat, 5);

	imshow("image_source", img_source);
	imshow("image_resultat", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

void exo7() // Egalisaton d'histogrammes
{
	namedWindow("image_source", WINDOW_AUTOSIZE);
	Mat img_source = imread("images/bird.jpg");
	if (img_source.empty())
		cout << "Cette image est vide !" << endl;

	namedWindow("image_resultat", WINDOW_AUTOSIZE);
	Mat img_resultat;

	// Faire une autre fonction !!!!
	medianBlur(img_source, img_resultat, 5);

	imshow("image_source", img_source);
	imshow("image_resultat", img_resultat);
	waitKey(0);
	destroyAllWindows();
}

int main() 
{	
	exo1();
	exo2();
	exo3();
	exo4();
	exo5();
	exo6();
	exo7();
	return 0;
}