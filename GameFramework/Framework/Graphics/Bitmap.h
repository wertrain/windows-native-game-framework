#ifndef BITMAP_H_
#define BITMAP_H_

#include "Primitive.h"
#include <Windows.h>

namespace Framework {
namespace Graphics {

class Bitmap : public Primitive
{
public:
    Bitmap() ;
    virtual ~Bitmap();

protected:
    HBITMAP mHBitmap;
    BITMAP mBitmap;
    HDC mHMemDC;
    int mTransparentColor;
};

} // namespace Graphics 
} // namespace Framework

#endif // BITMAP_H_
