//
//    Copyright 2003 � The Trustees of Indiana University.  All rights
//    reserved.
//
//    See the file enable_if_LICENSE for licensing conditions.
//
//    Authors: Jaakko J�rvi (jajarvi at osl.iu.edu)
//             Jeremiah Willcock (jewillco at osl.iu.edu)
//             Andrew Lumsdaine (lums at osl.iu.edu)
//

#include <boost/test/minimal.hpp>
#include <boost/mpl/not.hpp>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_arithmetic.hpp>

using boost::enable_if;
using boost::mpl::not_;
using boost::is_arithmetic;

namespace A {
  template<class T>
  typename enable_if<is_arithmetic<T>, bool>::type
  arithmetic_object(T t) { return true; }
}

namespace B {
  template<class T>
  typename enable_if<not_<is_arithmetic<T> >, bool>::type
  arithmetic_object(T t) { return false; }
}

int test_main(int, char*[])
{
  using namespace A;
  using namespace B;
  BOOST_TEST(arithmetic_object(1));
  BOOST_TEST(arithmetic_object(1.0));

  BOOST_TEST(!arithmetic_object("1"));  
  BOOST_TEST(!arithmetic_object(static_cast<void*>(0)));  

  return 0;
}

