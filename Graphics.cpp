/**
 * Graphics.cpp
 *
 * EECS 183, Fall 2016
 * Project 4: CoolPics
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#Description#>
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <algorithm>

#include "Graphics.h"
#include "bmp.h"

using namespace std;

// TODO: implement constructor, clear, setPixel, initArray.



// Your code goes above this line.
// Don't change the implementation below!

void Graphics::writeFile(string fileName) const
{
    ofstream outFile;
    outFile.open(fileName);
    
    // determine padding
    int padding = (4 - (DIMENSION * 3) % 4) % 4;
    
    // BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    bf.bfType = 0x4d42; // type of file = bitmap
    bf.bfSize = DIMENSION * (DIMENSION + padding) * 3 + 54; // TODO
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = 54; // location of pixels
    
    // BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    bi.biSize = 40; // header size
    bi.biWidth = DIMENSION;
    bi.biHeight = -DIMENSION;
    bi.biPlanes = 1;
    bi.biBitCount = 24;
    bi.biCompression = 0;
    bi.biSizeImage = bi.biWidth * bi.biHeight * 3;
    bi.biXPelsPerMeter = 2834;
    bi.biYPelsPerMeter = 2834;
    bi.biClrUsed = 0;
    bi.biClrImportant = 0;
    
    // write output BITMAPFILEHEADER
    outFile.write((char*)&bf, sizeof(BITMAPFILEHEADER));
    
    // write output BITMAPINFOHEADER
    outFile.write((char*)&bi, sizeof(BITMAPINFOHEADER));
    
    // iterate over lines
    for (int i = 0; i < DIMENSION; i++)
    {
        // iterate over pixels in line
        for (int j = 0; j < DIMENSION; j++)
        {
            // temporary storage
            Color pixel = pixelData[i][j];
            
            // write RGB triple to outfile
            outFile << (BYTE) pixel.getBlue() << (BYTE) pixel.getGreen()
            << (BYTE) pixel.getRed();
        }
        
        // write padding to outfile
        for (int k = 0; k < padding; k++)
        {
            outFile << 0;
        }
    }
    
    // close file
    outFile.close();
}

