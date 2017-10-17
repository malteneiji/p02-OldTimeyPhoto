#include<iostream>
#include"bitmap.h"
#include<vector>
#include<string>
using namespace std;
int main()
{
	int filecorrect = 0;
	bool validBmp;
	string filename;
	Bitmap image;
	vector <vector <Pixel> > bmp;
	Pixel rgb;
	int r , g , b;
	// loop until the user enters a correct filename
	while(filecorrect == 0)
	{
	cout << "Enter image filename : ";
	cin >> filename;
	image.open(filename);
	validBmp = image.isImage();
	if(validBmp == true)
	{
	filecorrect = 1;
	bmp = image.toPixelMatrix();
	cout <<"machupicchu.bmp has been loaded. it is "<<bmp[0].size()<<" pixels wide and "<< bmp.size()<< " pixels high"<< endl;
		for(int i = 0;i<bmp.size();i++)
		{
		 	for(int j = 0;j<bmp[0].size();j++)
			{
			//get the average of red green and blue and assign it to all rgb
			rgb = bmp[i][j];
			r = rgb.red;
			g = rgb.green;
			b = rgb.blue;	
			rgb.red = (r+g+b)/3;
			rgb.green = (r+g+b)/3;
			rgb.blue = (r+g+b)/3;
			bmp[i][j] = rgb;
		
			}
		}
		// save modified image 
		 image.fromPixelMatrix(bmp);
                 image.save("oldtimey.bmp");
		cout <<"File successfully converted to Grayscale" << endl;

	}

	else 
	{
	filecorrect = 0;
	cout << "The file must be a 24 bit depth Windows BMP file Please Retry"<< endl;
	}
	}
	return 0;
}
