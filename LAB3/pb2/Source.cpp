#include "Canvas.h"
int main()
{
    Canvas canvas(50, 20);
    canvas.DrawCircle(25, 10, 8, '*');
    canvas.FillCircle(25, 10, 5, '+');
    canvas.DrawRect(5, 5, 15, 15, '#');
    canvas.FillRect(6, 6, 14, 14, '@');
    canvas.SetPoint(0, 0, 'X');
    canvas.DrawLine(0, 0, 49, 19, '-');
    canvas.Print();
    canvas.Clear();
    canvas.Print();
    return 0;
}
