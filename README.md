### Image-Transform-with-C++
-----------------
Takes a PNG image encodes it with lodepng, Converts RGB to HSL and uses it to perform different transformations
like grayscale , illinify , spotlight and watermark. ( Final assignment for the course Object Oriented DS with C++)
>Refer here for documentation of lodepng - https://github.com/lvandeve/lodepng

### Sample Image
------------------
![sample image](https://github.com/victorX101/Image-Transform/blob/master/alma.png)

### Illinified Image
------------------
![gray-scaled-image](https://github.com/victorX101/Image-Transform/blob/master/out-illinify.png)

### Spotlight Image
-----------------
![spotlight-image](https://github.com/victorX101/Image-Transform/blob/master/out-spotlight.png)

### Watermarked Image
-----------------
![watermarked-image](https://github.com/victorX101/Image-Transform/blob/master/out-watermark.png)

### Compiling in C++
---------------------
* It has a Makefile which develops Imagetransform and test executables. 
* Go to the folder where Makefile is present and Run make command to develop two executables. 
* Run ./ImageTransform to create 4 tranformed PNG images from alma.PNG.  
The logic for Image tranformation is documented in Comments of ImageTransform.cpp 
> Run make test to run tests on your program as defined in the test folder. 
**You can change the image name (By default it is alma.png) and center coordinates for spotlight in main.cpp file**
