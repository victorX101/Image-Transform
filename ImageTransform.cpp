#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

using uiuc::PNG;
using uiuc::HSLAPixel;

PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a reference to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly. No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @return The image with a spotlight with centerX = 450 and centerY = 150
 */
PNG createSpotlight(PNG image, int centerX, int centerY) {
		
		double ratio = 0.8;
		double distance;
		for(unsigned x = 0; x<image.width();x++)
		{
			for(unsigned y = 0;y<image.height();y++)
			{
				distance = sqrt((x - centerX)*(x - centerX) + (y-centerY)*(y-centerY));
				if(distance<=160.0)
				ratio = distance*0.005;
				HSLAPixel & pixel = image.getPixel(x, y);
				pixel.l = (1.0-ratio)*pixel.l;
			}
		}
  return image;
  
}
 

/**
 * Returns a image transformed to Illini colors.
 *
 * The hue of every pixel is set to the a hue value of either orange or
 * blue, based on if the pixel's hue value is closer to orange than blue.
 *
 * @param image A PNG object which holds the image data to be modified.
 *
 * @return The illinify'd image.
**/
bool whichclose(double &hValue)
{
	double orange = 11;
	double blue = 216;
	double dist1 = abs(hValue - orange);
	double dist2 = abs(hValue - blue);
	dist1 = (dist1>360-dist1)?360-dist1:dist1;
	dist2 = (dist2>360-dist2)?360-dist2:dist2;
	return dist1<dist2;
}
	

PNG illinify(PNG image) {
	
	bool orange;
	for(unsigned x = 0; x<image.width();x++)
		{
			for(unsigned y = 0;y<image.height();y++)
			{
				HSLAPixel &pixel = image.getPixel(x,y);
				orange = whichclose(pixel.h);
				if(orange)
				pixel.h = 11.0;
				else
				pixel.h = 216.0;
			}
		}
  return image;
}
 

/**
* Returns an immge that has been watermarked by another image.
*
* The luminance of every pixel of the second image is checked, if that
* pixel's luminance is 1 (100%), then the pixel at the same location on
* the first image has its luminance increased by 0.2.
*
* @param firstImage  The first of the two PNGs, which is the base image.
* @param secondImage The second of the two PNGs, which acts as the stencil.
*
* @return The watermarked image.
*/
unsigned int min( unsigned int &a , unsigned int &b)
{
		return (a>b)?b:a;
}
PNG watermark(PNG firstImage, PNG secondImage) {
	for(unsigned x = 0; x<min(firstImage.width(),secondImage.width());x++)
		{
			for(unsigned y = 0;y<min(firstImage.height(),secondImage.height());y++)
			{
				HSLAPixel &pixelsten = secondImage.getPixel(x,y);
				HSLAPixel &pixelbase = firstImage.getPixel(x,y);
				if(pixelsten.l == 1)
				{
					if(pixelbase.l <= 0.8)
					pixelbase.l+=0.2;
				}
			}
		}			
				
  return firstImage;
}
