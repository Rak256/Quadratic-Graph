#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

// This function prints the equation for a parabola when arguments a, b, and c from the quadratic expression y = a*x^2 + b*x + c are given. 
// x and y represent the x and y co-ordinate of each point in the cartesian plane, respectively.
// This program also prints the graph of an integer approximation (using std::round) of the inputted parabola. The line is visible
// if it is in the range (-10, 10) and domain (-10, 10)

int main();
void graph(int a, int b, int c);
void print_equation(double a, double b, double c);

void print_equation(double a, double b, double c){
    bool imaginary{};
    double r1{(-b + std::sqrt(b*b - 4*a*c))/(2*a)};
    double r2{(-b - std::sqrt(b*b - 4*a*c))/(2*a)};
    double re{-b/(2*a)};
    double im{};

    if ((b*b -4*a*c) < 0){
    imaginary = true;
    im = std::sqrt(-(b*b - 4*a*c))/(2*a);
    }
   

    if (a == 0 && b == 0){
        std::cout << "y = " << c;
        return;
        }

    else if (a == 0){
       if(b == 1){
        std::cout << "y = x ";
    }
    else if (b == -1){
        std::cout << "y = -x ";
    }
    else{
    std::cout << "y = " << b << "*x";
    }

    if (c < 0){
        std::cout << " - " << -c;
        return;
    }

    else if (c > 0){
        std::cout << " + " << c;
        return; 
    }
    }

    else {
        if (r1 == r2){
         std::cout << "y = ";

        if (a == -1){
            std::cout << "-";
        }

        else if (a != 1){
            std::cout << a;
        }

        std::cout << "(x";

        if (r1 < 0){
            std::cout << " + " << -r1;
        }

        else if (r1 > 0) {
            std::cout << " - " << r1;
        }
        if (imaginary){
            std::cout << "j";
        }
        std::cout << ")^2";
        }
//r1 != r2
        else{
            
        std::cout << "y = ";

        if (a == -1){
            std::cout << "-";
        }

        else if (a != 1){
            std::cout << a;
        }

        std::cout << "(x";

        if (imaginary){

             // re > 0 start
            if (re > 0){
            
            // re > 0, im < 0
            if ( im < 0){
                if (im == -1){
                    std::cout << " - " << re << " + j) (x " << " - " << re << " - j"; 
                }

                else{
                std::cout << " - " << re << " + " << -im << "j) (x " << " - " << re << " - " << -im << "j"; 
                }
               
            }

            // re > 0, im > 0
            else {
                if (im == 1){
                    std::cout << " - " << re << " + j) (x " << " - " << re << " - j"; 
                }
                else{
                 std::cout << " - " << re << " - " << im << "j) (x " << " - " << re << " + " << im << "j";
                }
            }

            }

            // re == 0
             else if (re == 0){

                if (im > 0){
                    if (im == 1){
                        std::cout << " + j) (x - j";
                    }
                    else{
                std::cout << " - " << im << "j) (x " << " + " << im << "j" ;
                    }
                }

                // im < 0
                else{
                    if (im == -1){
                     std::cout << " + j) (x - j";
                    }
                    else{
                    std::cout << " + " << -im << "j) (x " << " - " << -im << "j" ;
                    }
                }
             
            }
            //re == 0 end

            // re < 0
            else{
                if (im > 0){
                    if ( im == 1){
                          std::cout << " + " << -re << " + j) (x " << " + " << -re << " - j";
                    }
                    else{
                std::cout << " + "<< -re << " - " << im << "j) (x " << " + " << -re << " + " << im << "j" ;
                }
                }

                // im < 0
                else {
                    if (im == -1){
                          std::cout << " + " << -re << " + j) (x " << " + " << -re << " - j";
                    }
                    else{
                     std::cout << " + "<< -re << " + " << -im << "j) (x " << " + " << -re << " - " << -im << "j" ;
                }
                
                }

            }

            }

        else if (r1 < 0){
            std::cout << " + " << -r1;
        }

        else if (r1 > 0) {
            std::cout << " - " << r1;
        }
        if (!imaginary){
        std::cout << ") (x";
        }

        if (r2 < 0){
            std::cout << " + " << -r2;
        }

        else if (r2 > 0) {
            std::cout << " - " << r2;
        }
        
        std::cout << ")";
        }
    }
}
void graph(int a, int b, int c){
    
    for (int y{100}; y >= -100; --y){
      for (int x{-100}; x <= 100; ++x){
        if (x == 0 && y == 0){
          std::cout << "+";
        } 

        else if (x == 0){
          std::cout << "|";
        }

        else if (y == 0){
          std::cout << "-";
        }

        else if (a == 0 && b == 0){
            if (y == c){
           std::cout << "-";
            }

            else{
                std::cout << " ";
            }
    }

    else if (a == 0){
        if (b > 0 ){
            if (y == b*x+c){
            std::cout << "/";
            }

            else{
                std::cout << " ";
            }
        }

        else {
            if (y == b*x+c){
            std::cout << "\\";
            }

            else{
                std::cout << " ";
            }

        }
    }

    else if (y == a*x*x +b*x + c){
        std::cout << "*";
    }

    else{
          std::cout << " ";
        }
  }
      std::cout << std::endl;
    } 

}

int main(){

    while (true){
    bool loop{};
    double a{};
    double b{};
    double c{};

    std::cout <<"Enter the coefficient of the x^2 term: ";
    std::cin >> a;

    std::cout <<"Enter the coefficient of the x term: ";
    std::cin >> b;

    std::cout <<"Enter the constant term: ";
    std::cin >> c;
    
    std::cout << std::endl;

    print_equation(a, b, c);
    
    std::cout << std::endl;

    graph(std::round(a), std::round(b), std::round(c));

    std::cout << "Do you want to graph another parabola? Type 1 for yes or 0 for no: ";
    std::cin >> loop;

    if (!loop){
        break;
    }

    }
}

