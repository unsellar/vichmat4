#include <iomanip>
#include <iostream>
#include <map>
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
    for(int i = 0; i <= n; i++){
        xs[i] = a + i*h;
    }
    for(int i = 0; i <= n-1; i++){
        x = a + i*h;
        res = func((xs[i]+xs[i+1])/2, dig);
        cout << setprecision (6) << res << " for x" << i << " = " << (xs[i]+xs[i+1])/2 << endl;
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

void par(float a, float b, float n, float dig[]){
    float h = (b-a)/n;
    float res;
    float xs[20];
    float x = a;
    float ds = 0, qs = 0;
    for(int i = 0; i<=n; i++){
        xs[i] = a + i*h;
        
    }
    for(int i = 1; i <= (n/2)-1; i++){
        res = func(xs[2*i], dig);
        x = a + i*h;
        cout << setprecision (6) << res << " for x" << i*2 << " = " << x << endl;
        ds += res;
    }
    for(int i = 0; i <= (n/2)-1; i++){
        res = func(xs[2*i + 1], dig);
        x = a + i*h;
        cout << setprecision (6) << res << " for x" << i*2 + 1 << " = " << x << endl;
        qs += res;
    }
    cout << setprecision (8) << "x0 = " << func(xs[0], dig) << endl << "x" << n << " = " << func(xs[int(n)], dig) << endl;
    float presumm = ( func(xs[0],dig) + func(xs[int(n)], dig) );
    cout << "presumm(fx0 + fx1) = " << presumm << endl;
    cout << setprecision (8) << "sum_chet = " << ds << endl << "sum_nechet = " << qs << endl
    << "h/3 * (fx0 + fxn + 2s1 + 4s2) = " << (h/3) * (presumm + 2*ds + 4*qs) << endl;
}

void gauss(float a, float b, float n, float dig[], float A[], float T[]){
    float summ = 0;
    int cf_g = 0;
    for(int i = 1; i <= n; i++){
        switch (int(n)) {
            case 4:
                if(i == 1) cf_g = 1 -1;
                if(i == 2) cf_g = 2 -1;
                if(i == 3) cf_g = 2 -1;
                if(i == 4) cf_g = 1 -1;
                break;
            case 6:
                if(i == 1) cf_g = 3 -1;
                if(i == 2) cf_g = 4 -1;
                if(i == 3) cf_g = 5 -1;
                if(i == 4) cf_g = 5 -1;
                if(i == 5) cf_g = 4 -1;
                if(i == 6) cf_g = 3 -1;
                break;
            case 8:
                if(i == 1) cf_g = 6 -1;
                if(i == 2) cf_g = 7 -1;
                if(i == 3) cf_g = 8 -1;
                if(i == 4) cf_g = 9 -1;
                if(i == 5) cf_g = 9 -1;
                if(i == 6) cf_g = 8 -1;
                if(i == 7) cf_g = 7 -1;
                if(i == 8) cf_g = 6 -1;
                break;
                
            default:
                break;
        }
        cout << "f = " << func((b+a)/2 + (b-a)/2 * T[cf_g], dig) << " for i = " << i << " and cf_g = " << cf_g << "   ";
        cout << "Ai = " << A[cf_g] << ", ti = " << A[cf_g] << endl;
        summ += A[cf_g] * func((b+a)/2 + (b-a)/2 * T[cf_g], dig);
    }
}

int main(int argc, const char * argv[]) {
    float n = 4, a = 1, b = 3;//н менять по заданию
    float dig[7] = {4,-18,-10,8,-3,-3,-1};//тут
    
    float gauss_A[9] = {0.347854,0.652145,0.171324,0.360761,0.467913,0.101228,0.222381,0.313706,0.362683};
    float gauss_T[9] = {0.861136,0.339981,0.932464,0.661209,0.238619,0.960298,0.796666,0.525532,0.183434};
    
    int mode;
    cin >> mode;
    switch (mode) {
        case 1:
            for(int i = 0; i < 3; i++){
                left_r(a, b, n, dig);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            break;
        case 2:
            for(int i = 0; i < 3; i++){
                rigth_r(a, b, n, dig);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            break;
        case 3:
            for(int i = 0; i < 3; i++){
                mid_r(a, b, n, dig);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            break;
        case 4:
            for(int i = 0; i < 3; i++){
                trap(a, b, n, dig);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            break;
        case 5:
            for(int i = 0; i < 3; i++){
                par(a, b, n, dig);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            break;
        case 6:
            for(int i = 0; i < 3; i++){
                gauss(a, b, n, dig, gauss_A, gauss_T);
                cout <<endl << "------------------" << endl;
                n+=2;
            }
            
            break;
        default:
            break;
    }
    
}

