#include <iomanip>
#include <iostream>
using namespace std;

float func(float x, float dig[]){
    return (dig[0]*x*x + dig[1]*x + dig[2])/(dig[3]*x*x*x + dig[4]*x*x + dig[5]*x + dig[6]);
}

void left_r(float a, float b, float n, float dig[]){
    float sum = 0, h = (b-a)/n;
    float x = a;
    float res;
    for(float i = 0; i <= n-1; i++){
        x = a + i*h;
        res = func(x, dig);
        cout << setprecision (6) << res << " for x" << i << " = " << x << endl;
        sum += res;
        
    }
    cout << setprecision (8) << "sum = " << sum << endl << "sum * h = " << sum * h << endl;
}
void rigth_r(float a, float b, float n, float dig[]){
    float sum = 0, h = (b-a)/n;
    float x = a;
    float res;
    for(float i = 1; i <= n; i++){
        x = a + i*h;
        res = func(x, dig);
        cout << setprecision (6) << res << " for x" << i << " = " << x << endl;
        sum += res;
        
    }
    cout << setprecision (8) << "sum = " << sum << endl << "sum * h = " << sum * h << endl;
}
    
void mid_r(float a, float b, float n, float dig[]){
    float sum = 0, h = (b-a)/n;
    float x = a;
    float res;
    float xs[20];
    for(int i = 0; i<=n; i++){
        xs[i] = a + i*h;
    }
    for(int i = 1; i <= n-1; i++){
        x = a + i*h;
        res = func((xs[i]+xs[i+1])/2, dig);
        cout << setprecision (6) << res << " for x" << i << " = " << x << endl;
        sum += res;

    }
    cout << setprecision (8) << "sum = " << sum << endl << "sum * h = " << sum * h << endl;
}

void trap(float a, float b, float n, float dig[]){
    float sum = 0, h = (b-a)/n;
    float res;
    float xs[20];
    float x = a;
    for(int i = 0; i<=n; i++){
        xs[i] = a + i*h;
    }
    for(int i = 1; i <= n-1; i++){
        res = func(xs[i], dig);
        x = a + i*h;
        cout << setprecision (6) << res << " for x" << i << " = " << x << endl;
        sum += res;
    }
    cout << "x0 = " << func(xs[0], dig) << endl << "xn = " << func(xs[int(n)], dig) << endl;
    float presumm = ( func(xs[0],dig) + func(xs[int(n)], dig) ) / 2;
    cout << "presumm = " << presumm << endl;
    cout << setprecision (8) << "sum = " << sum << endl << "(sum+presumm) * h = " << (sum+presumm) * h << endl;
    
}

int main(int argc, const char * argv[]) {
    float n = 8, a = 1, b = 3;//н менять по заданию
    float dig[7] = {4,-18,-10,8,-3,-3,-1};//тут
    int mode;
    cin >> mode;
    switch (mode) {
        case 1:
            left_r(a, b, n, dig);
            break;
        case 2:
            rigth_r(a, b, n, dig);
            break;
        case 3:
            mid_r(a, b, n, dig);
            break;
        case 4:
            trap(a, b, n, dig);
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            break;
    }
    
}
//alksjdalkw
