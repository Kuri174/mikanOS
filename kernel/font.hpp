#pragma once

#include <cstdint>
#include "graphics.hpp"

#define KERNEL_GLYPH_WIDTH 8
#define KERNEL_GLYPH_HEIGHT 19

void WriteAscii(PixelWriter& writer, int x, int y, char c, const PixelColor& color);
void WriteString(PixelWriter& writer, int x, int y, const char* s, const PixelColor& color);
