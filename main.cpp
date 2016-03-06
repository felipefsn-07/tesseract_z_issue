
#include "tesseract/baseapi.h"
#include <iostream>
#include <leptonica/allheaders.h>


using namespace std;
using namespace tesseract;

int main( int argc, const char** argv )
{
    tesseract::TessBaseAPI tesseract;
    tesseract.Init("./", "leu" 	);
    tesseract.SetVariable("save_blob_choices", "T");
    tesseract.SetVariable("debug_file", "/dev/null");
    tesseract.SetPageSegMode(PSM_SINGLE_CHAR);

    PIX *pixs = pixRead("z.png");

    int z_width = 32;
    int z_height = 41;
    int num_channels = 1;
    tesseract.SetImage(pixs);

    tesseract.SetRectangle(0, 0, z_width, z_height);
    tesseract.Recognize(NULL);

    tesseract::ResultIterator* ri = tesseract.GetIterator();
    tesseract::PageIteratorLevel level = tesseract::RIL_SYMBOL;

    do
    {
        const char* symbol = ri->GetUTF8Text(level);
        float conf = ri->Confidence(level);

        bool dontcare;
        int fontindex = 0;
        int pointsize = 0;
        const char* fontName = ri->WordFontAttributes(&dontcare, &dontcare, &dontcare, &dontcare, &dontcare, &dontcare, &pointsize, &fontindex);

        // Ignore NULL pointers, spaces, and characters that are way too small to be valid
        int MIN_PIXEL_SIZE = 6;
        if(symbol != 0 && pointsize >= MIN_PIXEL_SIZE)
        {
            cout << symbol << " : " << conf << endl;

            printf("symbol %s, conf: %f font: %s (index %d) size %dpx",  symbol, conf, fontName, fontindex, pointsize);

            bool indent = false;
            tesseract::ChoiceIterator ci(*ri);
            do
            {
                const char* choice = ci.GetUTF8Text();

                if (indent) printf("\t\t ");
                printf("\t- ");
                printf("%s conf: %f\n", choice, ci.Confidence());


                indent = true;
            }
            while(ci.Next());

        }

        printf("---------------------------------------------\n");

        delete[] symbol;
    }
    while((ri->Next(level)));

    return 0;
}