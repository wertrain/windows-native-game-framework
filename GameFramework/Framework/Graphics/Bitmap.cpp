#include "Bitmap.h"
#pragma comment (lib, "msimg32.lib")

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

bool Bitmap::CreateFromFile(LPCTSTR filename)
{
    // �摜�ǂݍ���
    mHBitmap = static_cast<HBITMAP>(LoadImage(NULL, filename, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));

    if(mHBitmap == NULL)
    {
        return false;
    }
    else
    {
        // �r�b�g�}�b�v�̏����擾
        GetObject(mHBitmap, sizeof(BITMAP), &mBitmap);
        // �������I�u�W�F�N�g�ɃR�s�[
        mHMemDC = CreateCompatibleDC(NULL);
        SelectObject(mHMemDC ,mHBitmap);
    }
    // �f�t�H���g�ł͗΂𓧉�
    mTransparentColor = RGB(0,255,0);

    return true;
}

void Bitmap::Draw(const HDC hdc, const int x, const int y)
{
    // �摜��color�𓧉߂��ăR�s�[����
    TransparentBlt(hdc, x, y, mBitmap.bmWidth, mBitmap.bmHeight,
        mHMemDC, 0, 0, mBitmap.bmWidth, mBitmap.bmHeight,
        mTransparentColor);
}

void Bitmap::Destroy()
{
    if(mHMemDC)
    {
        DeleteDC(mHMemDC);
        mHMemDC = NULL;
    }
    if(mHBitmap)
    {
        DeleteObject(mHBitmap);
        mHBitmap = NULL;
    }
}

void Bitmap::SetTransparentColor(const int color)
{
    mTransparentColor = color;
}

} // namespace Graphics
} // namespace Framework