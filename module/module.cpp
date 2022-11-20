#include <cmath>
#include <iostream>

using namespace std;
#define  EPS  0.0000001


int main() {

    int numb = -100;

    while (numb != 0) {
        cout << "________________________\n";
        cout << "(print 0 to exit)\nenter the number of the task:";

        cin >> numb;

        switch (numb) {
        case 1: {

            int n;

            cout << "Enter n:\n";
            cin >> n;

            double sum = 0;

            for (int i = 1; i <= n; i++) {
                double f = pow(-1, i + 1) / (i * (i + 1));
                sum += f;
            }

            cout << "sum = " << sum << endl;

            break;

        }
        case 2: {
            double a1 = 1, an, i;
            an = a1;

            for (int n = 2;; n++)
            {
                double anx = (2 - pow(an, 3)) / 5;

                if (abs(anx - an) < EPS)
                {
                    i = n;
                    cout << "the index of n elements is = " << i << endl;
                    an = a1;

                    break;
                }
                else
                    an = anx;

            }
            for (int n = 1; n <= i; n++)
            {
                double anx = (2 - pow(an, 3)) / 5;
                an = anx;
                cout << anx << " \t";
            }
            cout << endl;

            break;

        }

        case 3: {
            int n, m;

            cout << "enter m, n:";
            cin >> m >> n;

            float** a = new float* [m];

            float* maax = new float[n];

            float* miin = new float[n];

            for (int i = 0; i < n; i++)
                a[i] = new float[n];

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << "enter a[" << i + 1 << "][" << j + 1 << "]:\n";
                    cin >> a[i][j];
                }
                cout << endl;
            }

            float max = a[0][0], min = a[0][0];
            int indmax = 0, indmin = 0;

            for (int j = 0; j < n; j++) {
                for (int i = 0; i < m; i++) {
                    if (a[i][j] > max) {
                        max = a[i][j];
                        indmax = j;
                    }

                    if (a[i][j] < min) {
                        min = a[i][j];
                        indmin = j;
                    }
                }
            }

            for (int i = 0; i < n; i++) {
                maax[i] = a[i][indmax];
            }

            for (int i = 0; i < n; i++) {
                miin[i] = a[i][indmin];
            }

            for (int i = 0; i < n; i++) {
                a[i][indmin] = maax[i];

                a[i][indmax] = miin[i];
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    cout << a[i][j] << " ";


                }
                cout << "\n";
            }

            for (int i = 0; i < n; i++)
            {
                delete[]a[i];
            }
            delete[]a;
            delete[]miin;
            delete[]maax;

            break;
        }

        default:
            break;

        }

    }

    return 0;
}