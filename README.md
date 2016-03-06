# tesseract_z_issue

![Z Character](https://raw.githubusercontent.com/matthill/tesseract_z_issue/master/z.png)

Input training data is here: [tif](https://github.com/openalpr/train-ocr/blob/master/eu/input/leu.netherlands.exp0.tif?raw=true) [box](https://raw.githubusercontent.com/openalpr/train-ocr/master/eu/input/leu.netherlands.exp0.box)

After running the program, the output is:
    
    [mhill@mhill-linux z]$ ./tesseract_z_test 
    Z : 95.4505
    symbol Z, conf: 95.450462 font: netherlands (index 1) size 53px	- Z conf: 95.450462
    		 	- N conf: 91.517166
    		 	- 2 conf: 86.062859
    		 	- M conf: 81.259239
    ---------------------------------------------

Z and 2 characters are not expected, it makes me wonder if the character is rotated when analyzed.
