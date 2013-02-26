/*********************************************************************************
* Copyright (c) 2013 David D. Marshall <ddmarsha@calpoly.edu>
*
* All rights reserved. This program and the accompanying materials
* are made available under the terms of the Eclipse Public License v1.0
* which accompanies this distribution, and is available at
* http://www.eclipse.org/legal/epl-v10.html
*
* Contributors:
*    David D. Marshall - initial code and implementation
********************************************************************************/

#ifndef explicit_bezier_curve_test_suite_hpp
#define explicit_bezier_curve_test_suite_hpp

#include "eli/code_eli.hpp"

#include "eli/constants/math.hpp"
#include "eli/geom/point/distance.hpp"
#include "eli/geom/curve/explicit_bezier.hpp"
#include "eli/geom/curve/length.hpp"
#include "eli/geom/curve/curvature.hpp"

#include <cmath>    // std::pow, std::exp
#include <cassert>  // assert()

#include <typeinfo> // typeid
#include <string>   // std::string
#include <sstream>  // std::stringstream
#include <iomanip>  // std::setw
#include <limits>   // std::numeric_limits

template<typename data__>
class explicit_bezier_curve_test_suite : public Test::Suite
{
  private:
    typedef eli::geom::curve::explicit_bezier<data__> curve_type;
    typedef typename curve_type::control_point_type control_point_type;
    typedef typename curve_type::point_type point_type;
    typedef typename curve_type::data_type data_type;
    typedef typename curve_type::index_type index_type;
    typedef typename curve_type::fit_container_type fit_container_type;

  protected:
    void AddTests(const float &)
    {
      // add the tests
      TEST_ADD(explicit_bezier_curve_test_suite<float>::assignment_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::reverse_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::evaluation_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::derivative_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::promotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::demotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::length_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::fit_free_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::fit_C0_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::fit_C1_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::fit_C2_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<float>::interpolate_test);
    }
    void AddTests(const double &)
    {
      // add the tests
      TEST_ADD(explicit_bezier_curve_test_suite<double>::assignment_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::reverse_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::evaluation_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::derivative_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::promotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::demotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::length_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::fit_free_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::fit_C0_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::fit_C1_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::fit_C2_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<double>::interpolate_test);
    }
    void AddTests(const long double &)
    {
      // add the tests
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::assignment_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::reverse_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::evaluation_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::derivative_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::promotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::demotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::length_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::fit_free_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::fit_C0_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::fit_C1_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::fit_C2_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<long double>::interpolate_test);
    }
#ifdef ELI_QD_FOUND
    void AddTests(const dd_real &)
    {
      // add the tests
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::assignment_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::reverse_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::evaluation_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::derivative_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::promotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::demotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::length_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::fit_free_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::fit_C0_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::fit_C1_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::fit_C2_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<dd_real>::interpolate_test);
    }

    void AddTests(const qd_real &)
    {
      // add the tests
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::assignment_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::reverse_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::evaluation_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::derivative_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::promotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::demotion_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::length_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::fit_free_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::fit_C0_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::fit_C1_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::fit_C2_ends_test);
      TEST_ADD(explicit_bezier_curve_test_suite<qd_real>::interpolate_test);
    }
#endif

  public:
    explicit_bezier_curve_test_suite()
    {
      AddTests(data__());
    }
    ~explicit_bezier_curve_test_suite()
    {
    }

  private:
    void octave_print(int figno, const std::vector<point_type, Eigen::aligned_allocator<point_type> > &pts, const curve_type &bez) const
    {
      size_t i;

      std::cout << "figure(" << figno << ");" << std::endl;
      std::cout << "xpts=[" << pts[0].x();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].x();
      std::cout << "];" << std::endl;
      std::cout << "ypts=[" << pts[0].y();
      for (i=1; i<pts.size(); ++i)
        std::cout << ", " << pts[i].y();
      std::cout << "];" << std::endl;

      std::vector<data_type> t(101);
      for (i=0; i<t.size(); ++i)
        t[i]=static_cast<data_type>(i)/(t.size()-1);

      std::cout << "xint=[" << bez.f(t[0])(0);
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << bez.f(t[i])(0);
      std::cout << "];" << std::endl;
      std::cout << "yint=[" << bez.f(t[0])(1);
      for (i=1; i<t.size(); ++i)
        std::cout << ", " << bez.f(t[i])(1);
      std::cout << "];" << std::endl;

      std::cout << "plot(xpts, ypts, 'bo', xint, yint, 'k-');" << std::endl;
    }

    void create_circle(std::vector<point_type, Eigen::aligned_allocator<point_type> > &pts)
    {
      // NOTE: This will create a semi-circle
      size_t n=pts.size();
      for (size_t i=0; i<n; ++i)
      {
        data__ theta(eli::constants::math<data__>::pi()*static_cast<data__>(i)/(n-1));
        pts[i](0)=(1-std::cos(theta))/2;
        pts[i](1)=std::sin(theta);
      }
    }

    void assignment_test()
    {
      curve_type ebc1(3), ebc2;
      control_point_type cntrl_in[4];

      // test default constructor then set control points
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.0;
      cntrl_in[2] << 3.5;
      cntrl_in[3] << 4.0;

      for (index_type i=0; i<4; ++i)
      {
        ebc1.set_control_point(cntrl_in[i], i);
      }

      for (index_type i=0; i<4; ++i)
      {
        TEST_ASSERT(ebc1.get_control_point(i)==cntrl_in[i]);
      }

      // test copy ctr
      curve_type ebcc1(ebc1);
      for (index_type i=0; i<4; ++i)
      {
        TEST_ASSERT(ebcc1.get_control_point(i)==cntrl_in[i]);
      }

      // test assignment operator
      ebc2=ebc1;
      for (index_type i=0; i<4; ++i)
      {
        TEST_ASSERT(ebc2.get_control_point(i)==cntrl_in[i]);
      }

      // test order
      TEST_ASSERT(ebc2.degree()==3);
    }

    void reverse_test()
    {
      curve_type ebc1(3), ebc2;
      control_point_type cntrl_in[4];

      // test default constructor then set control points
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.0;
      cntrl_in[2] << 3.5;
      cntrl_in[3] << 4.0;

      for (index_type i=0; i<4; ++i)
      {
        ebc1.set_control_point(cntrl_in[i], i);
      }

      ebc2=ebc1;
      ebc1.reverse();
      for (index_type i=0; i<4; ++i)
      {
        TEST_ASSERT(ebc1.get_control_point(i)==ebc2.get_control_point(3-i));
      }
    }

    void evaluation_test()
    {
      typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif

      control_point_type cntrl_in[5];
      typename bezier_curve_type::control_point_type bez_cntrl[5];
      curve_type ebc;
      bezier_curve_type bc;
      typename curve_type::point_type eval_out, eval_ref;
      typename curve_type::data_type t;

      // set control points and create curves
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.5;
      cntrl_in[2] << 0.0;
      cntrl_in[3] << 1.0;
      cntrl_in[4] << 0.5;
      bez_cntrl[0] << 0,    2;
      bez_cntrl[1] << 0.25, 1.5;
      bez_cntrl[2] << 0.5,  0;
      bez_cntrl[3] << 0.75, 1;
      bez_cntrl[4] << 1,    0.5;

      ebc.resize(4);
      bc.resize(4);
      for (index_type i=0; i<5; ++i)
      {
        ebc.set_control_point(cntrl_in[i], i);
        bc.set_control_point(bez_cntrl[i], i);
      }

      // test evaluation at end points
      t=0;
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      TEST_ASSERT(eval_out==eval_ref);

      // test evaluation at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<1.1*eps);
    }

    void derivative_test()
    {
      typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif

      control_point_type cntrl_in[5];
      typename bezier_curve_type::control_point_type bez_cntrl[5];
      curve_type ebc;
      bezier_curve_type bc;
      typename curve_type::point_type eval_out, eval_ref;
      typename curve_type::data_type t;

      // set control points and create curves
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.5;
      cntrl_in[2] << 0.0;
      cntrl_in[3] << 1.0;
      cntrl_in[4] << 0.5;
      bez_cntrl[0] << 0,    2;
      bez_cntrl[1] << 0.25, 1.5;
      bez_cntrl[2] << 0.5,  0;
      bez_cntrl[3] << 0.75, 1;
      bez_cntrl[4] << 1,    0.5;

      ebc.resize(4);
      bc.resize(4);
      for (index_type i=0; i<5; ++i)
      {
        ebc.set_control_point(cntrl_in[i], i);
        bc.set_control_point(bez_cntrl[i], i);
      }

      // test 1st derivative at end points
      t=0;
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      TEST_ASSERT(eval_out==eval_ref);

      // test 1st derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      if (typeid(data__)==typeid(float))
      {
        TEST_ASSERT((eval_out-eval_ref).norm()<3*eps);
      }
      else
      {
        TEST_ASSERT(eval_out==eval_ref);
      }

      // test 2nd derivative at end points
      t=0;
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      TEST_ASSERT(eval_out==eval_ref);

      // test 2nd derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      if (typeid(data__)==typeid(float))
      {
        TEST_ASSERT((eval_out-eval_ref).norm()<17*eps);
      }
      else
      {
        TEST_ASSERT(eval_out==eval_ref);
      }

      // test 3rd derivative at end points
      t=0;
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT(eval_out==eval_ref);

      // test 3rd derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT(eval_out==eval_ref);

      // test curvature at end points
      data_type curv_out, curv_ref;
      t=0;
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      TEST_ASSERT(curv_out==curv_ref);
      t=1;
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      TEST_ASSERT(curv_out==curv_ref);

      // test curvature at interior point
      t=static_cast<data__>(0.45);
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      if (typeid(data__)==typeid(float))
      {
        TEST_ASSERT((eval_out-eval_ref).norm()<3*eps);
      }
      else
      {
        TEST_ASSERT(curv_out==curv_ref);
      }
    }

    void promotion_test()
    {
      typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif

      control_point_type cntrl_in[5];
      typename bezier_curve_type::control_point_type bez_cntrl[5];
      curve_type ebc;
      bezier_curve_type bc;
      typename curve_type::point_type eval_out, eval_ref;
      typename curve_type::data_type t, curv_out, curv_ref;

      // set control points and create curves
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.5;
      cntrl_in[2] << 0.0;
      cntrl_in[3] << 1.0;
      cntrl_in[4] << 0.5;
      bez_cntrl[0] << 0,    2;
      bez_cntrl[1] << 0.25, 1.5;
      bez_cntrl[2] << 0.5,  0;
      bez_cntrl[3] << 0.75, 1;
      bez_cntrl[4] << 1,    0.5;

      ebc.resize(4);
      bc.resize(4);
      for (index_type i=0; i<5; ++i)
      {
        ebc.set_control_point(cntrl_in[i], i);
        bc.set_control_point(bez_cntrl[i], i);
      }

      ebc.degree_promote();
      bc.degree_promote();

      // test to see if degree has increased
      TEST_ASSERT(ebc.degree()==bc.degree());

      // test evaluation at end points
      t=0;
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      if (typeid(data_type)==typeid(double))
      {
        TEST_ASSERT((eval_out-eval_ref).norm()<5*eps);
      }
      else
      {
        TEST_ASSERT(eval_out==eval_ref);
      }

      // test evaluation at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.f(t);
      eval_ref=bc.f(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<2.1*eps);

      // test 1st derivative at end points
      t=0;
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<25*eps);

      // test 1st derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fp(t);
      eval_ref=bc.fp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<4.1*eps);

      // test 2nd derivative at end points
      t=0;
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      TEST_ASSERT(eval_out==eval_ref);
      t=1;
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<11*eps);

      // test 2nd derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fpp(t);
      eval_ref=bc.fpp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<17*eps);

      // test 3rd derivative at end points
      t=0;
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<31*eps);
      t=1;
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<151*eps);

      // test 3rd derivative at interior point
      t=static_cast<data__>(0.45);
      eval_out=ebc.fppp(t);
      eval_ref=bc.fppp(t);
      TEST_ASSERT((eval_out-eval_ref).norm()<65*eps);

      // test curvature at end points
      t=0;
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      TEST_ASSERT(curv_out==curv_ref);
      t=1;
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      TEST_ASSERT(std::abs(curv_out-curv_ref)<48*eps);

      // test curvature at interior point
      t=static_cast<data__>(0.45);
      eli::geom::curve::curvature(curv_out, ebc, t);
      eli::geom::curve::curvature(curv_ref, bc, t);
      TEST_ASSERT(std::abs(curv_out-curv_ref)<10*eps);
    }

    void demotion_test()
    {
      // no constraint
      {
        typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;

        control_point_type cntrl_in[9];
        typename bezier_curve_type::control_point_type bez_cntrl[9];
        curve_type ebc;
        bezier_curve_type bc;

        // set control points and create curves
        cntrl_in[0] <<  2.0;
        cntrl_in[1] <<  1.5;
        cntrl_in[2] <<  1.0;
        cntrl_in[3] <<  0.5;
        cntrl_in[4] <<  0.0;
        cntrl_in[5] << -0.5;
        cntrl_in[6] << -1.0;
        cntrl_in[7] <<  1.0;
        cntrl_in[8] <<  0.5;
        bez_cntrl[0] << static_cast<data__>(0),     2.0;
        bez_cntrl[1] << static_cast<data__>(0.125), 1.5;
        bez_cntrl[2] << static_cast<data__>(0.25),  1.0;
        bez_cntrl[3] << static_cast<data__>(0.375), 0.5;
        bez_cntrl[4] << static_cast<data__>(0.5),   0.0;
        bez_cntrl[5] << static_cast<data__>(0.625),-0.5;
        bez_cntrl[6] << static_cast<data__>(0.75), -1.0;
        bez_cntrl[7] << static_cast<data__>(0.875), 1.0;
        bez_cntrl[8] << static_cast<data__>(1),     0.5;

        ebc.resize(8);
        bc.resize(8);
        for (index_type i=0; i<9; ++i)
        {
          ebc.set_control_point(cntrl_in[i], i);
          bc.set_control_point(bez_cntrl[i], i);
        }

        ebc.degree_demote(eli::geom::general::NOT_CONNECTED);
        bc.degree_demote(eli::geom::general::NOT_CONNECTED);
        for(index_type i=0; i<8; ++i)
        {
          TEST_ASSERT(ebc.get_control_point(i).col(0)==bc.get_control_point(i).col(1));
        }
      }

      // C0 constraint
      {
        typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;

        control_point_type cntrl_in[9];
        typename bezier_curve_type::control_point_type bez_cntrl[9];
        curve_type ebc;
        bezier_curve_type bc;

        // set control points and create curves
        cntrl_in[0] <<  2.0;
        cntrl_in[1] <<  1.5;
        cntrl_in[2] <<  1.0;
        cntrl_in[3] <<  0.5;
        cntrl_in[4] <<  0.0;
        cntrl_in[5] << -0.5;
        cntrl_in[6] << -1.0;
        cntrl_in[7] <<  1.0;
        cntrl_in[8] <<  0.5;
        bez_cntrl[0] << static_cast<data__>(0),     2.0;
        bez_cntrl[1] << static_cast<data__>(0.125), 1.5;
        bez_cntrl[2] << static_cast<data__>(0.25),  1.0;
        bez_cntrl[3] << static_cast<data__>(0.375), 0.5;
        bez_cntrl[4] << static_cast<data__>(0.5),   0.0;
        bez_cntrl[5] << static_cast<data__>(0.625),-0.5;
        bez_cntrl[6] << static_cast<data__>(0.75), -1.0;
        bez_cntrl[7] << static_cast<data__>(0.875), 1.0;
        bez_cntrl[8] << static_cast<data__>(1),     0.5;

        ebc.resize(8);
        bc.resize(8);
        for (index_type i=0; i<9; ++i)
        {
          ebc.set_control_point(cntrl_in[i], i);
          bc.set_control_point(bez_cntrl[i], i);
        }

        ebc.degree_demote(eli::geom::general::C0);
        bc.degree_demote(eli::geom::general::C0);
        for(index_type i=0; i<8; ++i)
        {
          TEST_ASSERT(ebc.get_control_point(i).col(0)==bc.get_control_point(i).col(1));
        }
      }

      // C1 constraint
      {
        typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;

        control_point_type cntrl_in[9];
        typename bezier_curve_type::control_point_type bez_cntrl[9];
        curve_type ebc;
        bezier_curve_type bc;

        // set control points and create curves
        cntrl_in[0] <<  2.0;
        cntrl_in[1] <<  1.5;
        cntrl_in[2] <<  1.0;
        cntrl_in[3] <<  0.5;
        cntrl_in[4] <<  0.0;
        cntrl_in[5] << -0.5;
        cntrl_in[6] << -1.0;
        cntrl_in[7] <<  1.0;
        cntrl_in[8] <<  0.5;
        bez_cntrl[0] << static_cast<data__>(0),     2.0;
        bez_cntrl[1] << static_cast<data__>(0.125), 1.5;
        bez_cntrl[2] << static_cast<data__>(0.25),  1.0;
        bez_cntrl[3] << static_cast<data__>(0.375), 0.5;
        bez_cntrl[4] << static_cast<data__>(0.5),   0.0;
        bez_cntrl[5] << static_cast<data__>(0.625),-0.5;
        bez_cntrl[6] << static_cast<data__>(0.75), -1.0;
        bez_cntrl[7] << static_cast<data__>(0.875), 1.0;
        bez_cntrl[8] << static_cast<data__>(1),     0.5;

        ebc.resize(8);
        bc.resize(8);
        for (index_type i=0; i<9; ++i)
        {
          ebc.set_control_point(cntrl_in[i], i);
          bc.set_control_point(bez_cntrl[i], i);
        }

        ebc.degree_demote(eli::geom::general::C1);
        bc.degree_demote(eli::geom::general::C1);
        for(index_type i=0; i<8; ++i)
        {
          TEST_ASSERT(ebc.get_control_point(i).col(0)==bc.get_control_point(i).col(1));
        }
      }

      // C2 constraint
      {
        typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;

        control_point_type cntrl_in[9];
        typename bezier_curve_type::control_point_type bez_cntrl[9];
        curve_type ebc;
        bezier_curve_type bc;

        // set control points and create curves
        cntrl_in[0] <<  2.0;
        cntrl_in[1] <<  1.5;
        cntrl_in[2] <<  1.0;
        cntrl_in[3] <<  0.5;
        cntrl_in[4] <<  0.0;
        cntrl_in[5] << -0.5;
        cntrl_in[6] << -1.0;
        cntrl_in[7] <<  1.0;
        cntrl_in[8] <<  0.5;
        bez_cntrl[0] << static_cast<data__>(0),     2.0;
        bez_cntrl[1] << static_cast<data__>(0.125), 1.5;
        bez_cntrl[2] << static_cast<data__>(0.25),  1.0;
        bez_cntrl[3] << static_cast<data__>(0.375), 0.5;
        bez_cntrl[4] << static_cast<data__>(0.5),   0.0;
        bez_cntrl[5] << static_cast<data__>(0.625),-0.5;
        bez_cntrl[6] << static_cast<data__>(0.75), -1.0;
        bez_cntrl[7] << static_cast<data__>(0.875), 1.0;
        bez_cntrl[8] << static_cast<data__>(1),     0.5;

        ebc.resize(8);
        bc.resize(8);
        for (index_type i=0; i<9; ++i)
        {
          ebc.set_control_point(cntrl_in[i], i);
          bc.set_control_point(bez_cntrl[i], i);
        }

        ebc.degree_demote(eli::geom::general::C2);
        bc.degree_demote(eli::geom::general::C2);
        for(index_type i=0; i<8; ++i)
        {
          TEST_ASSERT(ebc.get_control_point(i).col(0)==bc.get_control_point(i).col(1));
        }
      }
    }

    void length_test()
    {
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif
      typedef eli::geom::curve::bezier<data__, 2> bezier_curve_type;

      control_point_type cntrl_in[5];
      typename bezier_curve_type::control_point_type bez_cntrl[5];
      curve_type ebc;
      bezier_curve_type bc;
      typename curve_type::point_type eval_out, eval_ref;
      typename curve_type::data_type length_cal, length_ref;

      // set control points and create curves
      cntrl_in[0] << 2.0;
      cntrl_in[1] << 1.5;
      cntrl_in[2] << 0.0;
      cntrl_in[3] << 1.0;
      cntrl_in[4] << 0.5;
      bez_cntrl[0] << 0,    2;
      bez_cntrl[1] << 0.25, 1.5;
      bez_cntrl[2] << 0.5,  0;
      bez_cntrl[3] << 0.75, 1;
      bez_cntrl[4] << 1,    0.5;

      ebc.resize(4);
      bc.resize(4);
      for (index_type i=0; i<5; ++i)
      {
        ebc.set_control_point(cntrl_in[i], i);
        bc.set_control_point(bez_cntrl[i], i);
      }

      // calculate the length of curve
      data_type tol(std::sqrt(eps));
      length(length_cal, ebc, tol);
      length(length_ref, bc, tol);
      TEST_ASSERT(length_cal==length_ref);

      // test computing some segment length
      typename curve_type::data_type t0, t1;
      t0 = static_cast<data__>(0.2);
      t1 = static_cast<data__>(0.7);

      length(length_cal, ebc, t0, t1, tol);
      length(length_ref, bc, t0, t1, tol);
      TEST_ASSERT(length_cal==length_ref);
    }

    void fit_free_ends_test()
    {
      fit_container_type fcon;
      size_t i, deg(5);
      std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(10);
      curve_type ebez;
      std::vector<data_type> t;
      data_type err_out, err_ref;

      // get points
      create_circle(pts);

      // configure fit container
      fcon.set_points(pts.begin(), pts.end());

      // fit points
      err_out=ebez.fit(t, fcon, deg);

      // calculate the error at the point
      for (err_ref=0, i=0; i<pts.size(); ++i)
      {
        data_type d;
        eli::geom::point::distance(d, pts[i], ebez.f(t[i]));
        err_ref+=d;
      }

      TEST_ASSERT(err_ref==err_out);
      TEST_ASSERT(err_out < 0.430);

      // check if went through points
      TEST_ASSERT(pts[0]!=ebez.f(t[0]));
      TEST_ASSERT(pts[pts.size()-1]!=ebez.f(t[t.size()-1]));

//       octave_print(1, pts, ebez);
    }

    void fit_C0_ends_test()
    {
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif
      fit_container_type fcon;
      size_t i, deg(5);
      std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(10);
      curve_type ebez;
      std::vector<data_type> t;
      data_type err_out, err_ref;

      // get points
      create_circle(pts);

      // configure fit container
      fcon.set_points(pts.begin(), pts.end());
      fcon.add_start_C0_constraint();
      fcon.add_end_C0_constraint();

      // fit points
      err_out=ebez.fit(t, fcon, deg);

      // calculate the error at the point
      for (err_ref=0, i=0; i<pts.size(); ++i)
      {
        data_type d;
        eli::geom::point::distance(d, pts[i], ebez.f(t[i]));
        err_ref+=d;
      }

      TEST_ASSERT(err_out==err_ref);
      TEST_ASSERT(err_out < 0.431);

      // check if went through points
      TEST_ASSERT(pts[0]==ebez.f(t[0]));
      TEST_ASSERT((pts[pts.size()-1]-ebez.f(t[t.size()-1])).norm()<65*eps);

//       octave_print(2, pts, ebez);
    }

    void fit_C1_ends_test()
    {
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif
      fit_container_type fcon;
      size_t i, deg(5);
      std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(10);
      curve_type ebez;
      std::vector<data_type> t;
      data_type err_out, err_ref;

      // get points
      create_circle(pts);

      // configure fit container
      point_type fp;
      typename fit_container_type::constraint_info ci;
      fcon.set_points(pts.begin(), pts.end());
      fcon.add_start_C0_constraint();
      fcon.add_end_C0_constraint();
      fcon.add_C1_constraint(4);
      fcon.get_constraint(4, ci);
      fp << 1, ci.get_fp()(0);

      // fit points
      err_out=ebez.fit(t, fcon, deg);

      // calculate the error at the point
      for (err_ref=0, i=0; i<pts.size(); ++i)
      {
        data_type d;
        eli::geom::point::distance(d, pts[i], ebez.f(t[i]));
        err_ref+=d;
      }

      TEST_ASSERT(err_out==err_ref);
      TEST_ASSERT(err_out < 0.682);

      // check if went through points
      TEST_ASSERT(pts[0]==ebez.f(t[0]));
      TEST_ASSERT((pts[pts.size()-1]-ebez.f(t[t.size()-1])).norm()<40*eps);
      TEST_ASSERT((pts[4]-ebez.f(t[4])).norm()<35*eps);
      TEST_ASSERT((fp-ebez.fp(t[4])).norm()<48*eps);

//       octave_print(3, pts, ebez);
    }

    void fit_C2_ends_test()
    {
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif
      fit_container_type fcon;
      size_t i, deg(7);
      std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(10);
      curve_type ebez;
      std::vector<data_type> t;
      data_type err_out, err_ref;

      // get points
      create_circle(pts);

      // configure fit container
      point_type fp, fpp;
      typename fit_container_type::constraint_info ci;
      fcon.set_points(pts.begin(), pts.end());
      fcon.add_start_C0_constraint();
      fcon.add_end_C0_constraint();
      fcon.add_C2_constraint(4);
      fcon.get_constraint(4, ci);
      fp << 1, ci.get_fp()(0);
      fpp << 0, ci.get_fpp()(0);

      // fit points
      err_out=ebez.fit(t, fcon, deg);

      // calculate the error at the point
      for (err_ref=0, i=0; i<pts.size(); ++i)
      {
        data_type d;
        eli::geom::point::distance(d, pts[i], ebez.f(t[i]));
        err_ref+=d;
      }

      TEST_ASSERT(err_out==err_ref);
      TEST_ASSERT(err_out < 0.310);

      // check if went through points
      TEST_ASSERT((pts[0]-ebez.f(t[0])).norm()<6*eps);
      TEST_ASSERT((pts[pts.size()-1]-ebez.f(t[t.size()-1])).norm()<512*eps);
      TEST_ASSERT((pts[4]-ebez.f(t[4])).norm()<35*eps);
      TEST_ASSERT((fp-ebez.fp(t[4])).norm()<240*eps);
      TEST_ASSERT((fpp-ebez.fpp(t[4])).norm()<1.54e3*eps);

//       octave_print(4, pts, ebez);
    }

    void interpolate_test()
    {
      data_type eps(std::numeric_limits<data__>::epsilon());
#ifdef ELI_QD_FOUND
      if ( (typeid(data_type)==typeid(dd_real)) || (typeid(data_type)==typeid(qd_real)) )
        eps=std::numeric_limits<double>::epsilon();
#endif
      // interpolate through all points
      {
        fit_container_type fcon;
        std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(5);
        curve_type ebez;
        std::vector<data_type> t;

        // get points
        create_circle(pts);

        // configure fit container
        fcon.set_points(pts.begin(), pts.end());

        // fit points
        ebez.interpolate(t, fcon);

        TEST_ASSERT(static_cast<size_t>(ebez.degree()+1)==pts.size());

        // check if went through points
        TEST_ASSERT(ebez.f(t[0])==pts[0]);
        TEST_ASSERT((ebez.f(t[1])-pts[1]).norm()<3*eps);
        TEST_ASSERT((ebez.f(t[2])-pts[2]).norm()<7*eps);
        TEST_ASSERT((ebez.f(t[3])-pts[3]).norm()<23*eps);

//         octave_print(5, pts, ebez);
      }

      // interpolate through all points and specify C1
      {
        fit_container_type fcon;
        std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(5);
        curve_type ebez;
        std::vector<data_type> t;

        // get points
        create_circle(pts);

        // configure fit container
        point_type fp;
        typename fit_container_type::constraint_info ci;
        fcon.set_points(pts.begin(), pts.end());
        fcon.add_C1_constraint(1);
        fcon.get_constraint(1, ci);
        fp << 1, ci.get_fp()(0);

        // fit points
        ebez.interpolate(t, fcon);

        TEST_ASSERT(static_cast<size_t>(ebez.degree()+1)==(pts.size()+1));

        // check if went through points
        TEST_ASSERT((ebez.f(t[0])-pts[0]).norm()<2*eps);
        TEST_ASSERT((ebez.f(t[1])-pts[1]).norm()<3*eps);
        TEST_ASSERT((ebez.f(t[2])-pts[2]).norm()<9*eps);
        TEST_ASSERT((ebez.f(t[3])-pts[3]).norm()<44*eps);
        TEST_ASSERT((fp-ebez.fp(t[1])).norm()<48*eps);

//         octave_print(6, pts, ebez);
      }

      // interpolate through all points and specify C2
      {
        fit_container_type fcon;
        std::vector<point_type, Eigen::aligned_allocator<point_type> > pts(5);
        curve_type ebez;
        std::vector<data_type> t;

        // get points
        create_circle(pts);

        // configure fit container
        point_type fp, fpp;
        typename fit_container_type::constraint_info ci;
        fcon.set_points(pts.begin(), pts.end());
        fcon.add_C2_constraint(1);
        fcon.get_constraint(1, ci);
        fp << 1, ci.get_fp()(0);
        fpp << 0, ci.get_fpp()(0);

        // fit points
        ebez.interpolate(t, fcon);

        TEST_ASSERT(static_cast<size_t>(ebez.degree()+1)==(pts.size()+2));

        // check if went through points
        TEST_ASSERT((ebez.f(t[0])-pts[0]).norm()<3*eps);
        TEST_ASSERT((ebez.f(t[1])-pts[1]).norm()<3*eps);
        TEST_ASSERT((ebez.f(t[2])-pts[2]).norm()<9*eps);
        TEST_ASSERT((ebez.f(t[3])-pts[3]).norm()<70*eps);
        TEST_ASSERT((fp-ebez.fp(t[1])).norm()<48*eps);
        TEST_ASSERT((fpp-ebez.fpp(t[1])).norm()<81*eps);

//         octave_print(7, pts, ebez);
      }
    }
};
#endif

