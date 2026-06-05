// imageloader.cpp — implementasi loader BMP

#include <cassert>
#include <fstream>
#include <memory>
#include "imageloader.h"

using namespace std;

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {}
Image::~Image() { delete[] pixels; }

namespace {
int toInt(const char* bytes) {
	return (int)(((unsigned char)bytes[3] << 24) |
							 ((unsigned char)bytes[2] << 16) |
							 ((unsigned char)bytes[1] << 8) |
							 (unsigned char)bytes[0]);
}

short toShort(const char* bytes) {
	return (short)(((unsigned char)bytes[1] << 8) |
								 (unsigned char)bytes[0]);
}

int readInt(ifstream &input) {
	char buffer[4];
	input.read(buffer, 4);
	return toInt(buffer);
}

short readShort(ifstream &input) {
	char buffer[2];
	input.read(buffer, 2);
	return toShort(buffer);
}

} // namespace

Image* loadBMP(const char* filename) {
	ifstream input(filename, ios::binary);
	assert(!input.fail() && "File tidak ditemukan!!!");

	char header[2];
	input.read(header, 2);
	assert(header[0] == 'B' && header[1] == 'M' && "Bukan file bitmap!!!");

	input.ignore(8);
	int dataOffset = readInt(input);

	int headerSize = readInt(input);
	int width = 0, height = 0;

	switch (headerSize) {
		case 40: // Windows BITMAPINFOHEADER
			width = readInt(input);
			height = readInt(input);
			input.ignore(2); // planes
			assert(readShort(input) == 24 && "Gambar tidak 24 bits per pixel!");
			assert(readInt(input) == 0 && "Gambar dikompres!");
			break;

		case 12: // OS/2 BITMAPCOREHEADER
			width = readShort(input);
			height = readShort(input);
			input.ignore(2);
			assert(readShort(input) == 24 && "Gambar tidak 24 bits per pixel!");
			break;

		case 64:
			assert(false && "Tidak dapat mengambil OS/2 V2 bitmaps");
			break;
		case 108:
			assert(false && "Tidak dapat mengambil Windows V4 bitmaps");
			break;
		case 124: // Windows V5 BITMAPV5HEADER
			// similar layout for initial fields
			width = readInt(input);
			height = readInt(input);
			input.ignore(2); // planes
			assert(readShort(input) == 24 && "Gambar tidak 24 bits per pixel!");
			assert(readInt(input) == 0 && "Gambar dikompres!");
			break;
		default:
			assert(false && "Format bitmap ini tidak diketahui!");
	}

	int rowSize = ((width * 3 + 3) / 4) * 4;
	int size = rowSize * height;

	unique_ptr<char[]> pixels(new char[size]);
	input.seekg(dataOffset, ios::beg);
	input.read(pixels.get(), size);

	unique_ptr<char[]> pixels2(new char[width * height * 3]);

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			for (int c = 0; c < 3; ++c) {
				pixels2[3 * (width * y + x) + c] =
						pixels[rowSize * y + 3 * x + (2 - c)];
			}
		}
	}

	input.close();
	return new Image(pixels2.release(), width, height);
}
