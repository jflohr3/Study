/* Problem Statement:
 *  Implement a class to handle representation of a polynomial
 */

 /*! Support Real number coefficients, but not complex polynomials.
  *    Because rigor..
  */
  
// TODO issue with param packed structs passed to push_back in Constructor
 
#include <iostream>
#include <cstdlib>
using namespace std;

#include <cmath>
#include <cstddef>
#include <vector>
#include <ranges>

 struct Cfloat
 {
   double mantissa;
   int exponent;
 };
 
class Cpolynomial
{
  public:
  
  void print(void)
  {
    cout << "Print Polynomial\n";
    
    int exp = 0;
    for( Cfloat& v:coef_list ) // Ranges are nice thanks c++20
    {
      if(exp != 0)
      {
        cout << v.mantissa * pow(10, v.exponent);
        cout << "x^";
        cout << exp++;
      }
      else
      {
        cout << v.mantissa * pow(10, v.exponent);
        ++exp;
      }
    }
  }
  
  template<class... T>
  Cpolynomial(T... these)
  {
    cout << "Constructor\n";
    cout << "Must be in order of LSP to MSP, starting with constant term\n";
    cout << "  include zero coefficients\n";
    coef_list.push_back(these...); 
  }
  
  private:
  std::vector<Cfloat> coef_list;
};

int main()
{
  // Least squares approx of unit circle
  Cfloat a = {( (12*(pow(M_PI,2)-10))/ pow(M_PI,3)),0};
  Cfloat b = {( (60*(pow(M_PI,2)-12))/ pow(M_PI,4)),0};
  Cfloat c = {( (60*(pow(M_PI,2)-12))/ pow(M_PI,5)),0};

  Cpolynomial MyPolynomial(a);
  
  MyPolynomial.print();

  return EXIT_SUCCESS;
}
