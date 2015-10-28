#include "Bitmap.h"

namespace Framework {
namespace Graphics {

Bitmap::Bitmap()
    : mHBitmap(NULL)
    , mHMemDC(NULL)
    , mTransparentColor(0)
{

}

Bitmap::~Bitmap()
{

}

} // namespace Graphics
} // namespace Framework