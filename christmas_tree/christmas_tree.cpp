#include <cmath>
#include <iostream>
using namespace std;
const double PI= 3.14159265359;
double sx, sy;
double sdCircle(double px, double py, double r) {
    double dx = px - sx, dy = py - sy;
    return sqrtf(dx * dx + dy * dy) - r;
}

double opUnion(double d1, double d2) {
    return d1 < d2 ? d1 : d2;
}

#define T px + scale * r * cosf(theta), py + scale * r * sin(theta)

double f(double px, double py, double theta, double scale, int n) {
    double d = 0.0f;
    for (double r = 0.0f; r < 0.8f; r += 0.02f)
        d = opUnion(d, sdCircle(T, 0.05f * scale * (0.95f - r)));

    if (n > 0)
        for (int t = -1; t <= 1; t += 2) {
            double tt = theta + t * 1.8f;
            double ss = scale * 0.9f;
            for (double r = 0.2f; r < 0.8f; r += 0.1f) {
                d = opUnion(d, f(T, tt, ss * 0.5f, n - 1));
                ss *= 0.8f;
            }
        }

    return d;
}

void main()
 {
	char ch;
    for (sy = 0.8f; sy > 0.0f; sy -= 0.02f,cout<<'\n')  
        for (sx = -0.35f; sx < 0.35f; sx += 0.01f)
		{//ch=f(0, 0, PI * 0.5f, 1.0f, n) < 0 ? '*' : ' ';
			ch=f(0, 0, PI * 0.5f, 1.0f, 3) < 0 ? '*' : ' ';
		cout<<ch;}
}



