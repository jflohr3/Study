/* Problem Statement:
 *  Implement a class to handle representation of a polynomial
 */
#include <iostream>
#include <cstdlib>
using namespace std;

#include <cstddef>
#include <vector>

/* floats, doubles cannot be used in templates
   hIStOriC ReASonS... *the types aren't implemented in a std way 
                       *compiler would have issues determining which to use when 
                       given a literal.. then why have literal qualifiers then?
   probably the first issue is the only real reason they are not allowed...
 */
 
/* accept whole number coefficients - easy
 * accept rational numbers - can't use floats,doubles.
 *    Use std::pair for numerator denominator - SOLVED
 * accept irrational numbers - Middle school math teachers mad that polynomials
 *                              are allowed irrational coefficients.
 *    Use std::pair with Mantissa & exponent
 */
 
/* Polynomial irrational coefficient history
 * https://www.cambridge.org/core/journals/science-in-context/article/\
 * irrational-coefficients-in-renaissance-algebra/38391278E789631131A9F9BFC4DC8B0B
 * Irrational “Coefficients” in Renaissance Algebra
 * Published online by Cambridge University Press:  12 July 2017
 */
 
 // TODO lets finish the Generic Programming hundred page chapter before
 //   readdressing this. Want to do a exhaustive solution...
 // TODO apparently std::pair and std::tuple is a code smell???
 //   dude literally says to make a custom struct...isn't that just a pair
 //   without the syntax sugar around it bruh...
 // I agree with making a custom struct -> some guy:
 // "What's so bad about having to write 6 lines of perfectly simple, clear,"
 //   "and explicit code? A point is not a pair. Just because a structure has 2"
 //   "members doesn't make it immediately semantically a pair."
 // Amen...
 
 struct Cfloat
 {
   int mantissa;
   int exponent;
 };
 

class Cpolynomial
{
  public:
  
  template<class Cfloat... T>
  Cpolynomial(T... these)
  {
    cout << "Constructor\n";
  }
  
  private:
  std::vector<std::pair<int, int>> term_list;
};

int main()
{
    cout<<"Hello World";

    return 0;
}
