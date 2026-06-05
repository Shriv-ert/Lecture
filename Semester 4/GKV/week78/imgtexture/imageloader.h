/*
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above notice and this permission notice shall be included in all copies
 or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

 File for "Putting It All Together" lesson of the OpenGL tutorial on
 www.videotutorialsrock.com
*/

#ifndef IMAGE_LOADER_H_INCLUDED
#define IMAGE_LOADER_H_INCLUDED

// Represents an image
class Image {
 public:
	Image(char* ps, int w, int h);
	~Image();

	// An array of the form (R1, G1, B1, R2, G2, B2, ...)
	// Color components range from 0 to 255.
	// The array starts at the bottom-left pixel, moves right across the row,
	// then moves up to the next row. This matches the format OpenGL expects.
	char* pixels;
	int width;
	int height;
};

// Reads a 24-bit uncompressed BMP image from file.
Image* loadBMP(const char* filename);

#endif  // IMAGE_LOADER_H_INCLUDED
