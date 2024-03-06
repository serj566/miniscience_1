#include <set>
#include <gmsh.h>

int main(int argc, char **argv)
{
  gmsh::initialize();

  gmsh::model::add("t2");

  double lc = 1e-2;
  gmsh::model::geo::addPoint(0, 0, 0, lc, 1);


  //Внутренний тор
  gmsh::model::geo::addPoint(-0.2, 0, 0, lc, 2);
  gmsh::model::geo::addPoint(0.2, 0, 0, lc, 3);
  gmsh::model::geo::addPoint(-0.15, 0, 0, lc, 4);
  gmsh::model::geo::addPoint(0.15, 0, 0, lc, 5);
  gmsh::model::geo::addPoint(-0.1, 0, 0, lc, 6);
  gmsh::model::geo::addPoint(0.1, 0, 0, lc, 7);

  gmsh::model::geo::addCircleArc(2, 4, 6, 1, 0, 1, 0);
  gmsh::model::geo::addCircleArc(7, 5, 3, 2, 0, 1, 0);
  gmsh::model::geo::addCircleArc(3, 1, 2, 3, 0, 0, 1);
  gmsh::model::geo::addCircleArc(7, 1, 6, 4, 0, 0, 1);

  gmsh::model::geo::addCurveLoop({1, -4, 2, 3}, 1);
  gmsh::model::geo::addSurfaceFilling({1}, 1);


  gmsh::model::geo::addCircleArc(2, 4, 6, 5, 0, -1, 0);
  gmsh::model::geo::addCircleArc(7, 5, 3, 6, 0, -1, 0);
  gmsh::model::geo::addCircleArc(3, 1, 2, 7, 0, 0, -1);
  gmsh::model::geo::addCircleArc(7, 1, 6, 8, 0, 0, -1);

  gmsh::model::geo::addCurveLoop({5, -8, 6, 7}, 2);
  gmsh::model::geo::addSurfaceFilling({2}, 2);

  gmsh::model::geo::addCurveLoop({1, -8, 2, 7}, 3);
  gmsh::model::geo::addSurfaceFilling({3}, 3);

  gmsh::model::geo::addCurveLoop({5, -4, 6, 3}, 4);
  gmsh::model::geo::addSurfaceFilling({4}, 4);


  //Внешний тор
  gmsh::model::geo::addPoint(-0.25, 0, 0, lc, 8);
  gmsh::model::geo::addPoint(0.25, 0, 0, lc, 9);
  //gmsh::model::geo::addPoint(-0.15, 0, 0, lc, 10);//4
  //gmsh::model::geo::addPoint(0.15, 0, 0, lc, 11);//5
  gmsh::model::geo::addPoint(-0.05, 0, 0, lc, 12);
  gmsh::model::geo::addPoint(0.05, 0, 0, lc, 13);

  gmsh::model::geo::addCircleArc(8, 4, 12, 9, 0, 1, 0);
  gmsh::model::geo::addCircleArc(13, 5, 9, 10, 0, 1, 0);
  gmsh::model::geo::addCircleArc(9, 1, 8, 11, 0, 0, 1);
  gmsh::model::geo::addCircleArc(13, 1, 12, 12, 0, 0, 1);


  gmsh::model::geo::addCurveLoop({9, -12, 10, 11}, 5);
  gmsh::model::geo::addSurfaceFilling({5}, 5);


  gmsh::model::geo::addCircleArc(8, 4, 12, 13, 0, -1, 0);
  gmsh::model::geo::addCircleArc(13, 5, 9, 14, 0, -1, 0);
  gmsh::model::geo::addCircleArc(9, 1, 8, 15, 0, 0, -1);
  gmsh::model::geo::addCircleArc(13, 1, 12, 16, 0, 0, -1);



  gmsh::model::geo::addCurveLoop({13, -16, 14, 15}, 6);
  gmsh::model::geo::addSurfaceFilling({6}, 6);

  gmsh::model::geo::addCurveLoop({9, -16, 10, 15}, 7);
  gmsh::model::geo::addSurfaceFilling({7}, 7);

  gmsh::model::geo::addCurveLoop({13, -12, 14, 11}, 8);
  gmsh::model::geo::addSurfaceFilling({8}, 8);
  
  gmsh::model::geo::addLine(8, 2, 17);
  gmsh::model::geo::addLine(6, 12, 18);
  gmsh::model::geo::addLine(13, 7, 19);
  gmsh::model::geo::addLine(3, 9, 20);

  
  gmsh::model::geo::addCircleArc(9, 1, 8, 21, 0, 0, -1);
  gmsh::model::geo::addCircleArc(13, 1, 12, 22, 0, 0, -1);
  gmsh::model::geo::addCircleArc(9, 1, 8, 23, 0, 0, 1);
  gmsh::model::geo::addCircleArc(13, 1, 12, 24, 0, 0, 1);

  gmsh::model::geo::addCurveLoop({17, 5, 18, -13}, 9);
  gmsh::model::geo::addSurfaceFilling({9}, 9);
  gmsh::model::geo::addCurveLoop({17, 1, 18, -9}, 10);
  gmsh::model::geo::addSurfaceFilling({10}, 10);
  gmsh::model::geo::addCurveLoop({19, 6, 20, -14}, 11);
  gmsh::model::geo::addSurfaceFilling({11}, 11);
  gmsh::model::geo::addCurveLoop({19, 2, 20, -10}, 12);
  gmsh::model::geo::addSurfaceFilling({12}, 12);

  gmsh::model::geo::addCurveLoop({17, -3, 20, 11}, 13);
  gmsh::model::geo::addSurfaceFilling({13}, 13);

  gmsh::model::geo::addCurveLoop({-17, 7, -20, -21}, 14);
  gmsh::model::geo::addSurfaceFilling({14}, 14);


  gmsh::model::geo::addCurveLoop({18, -12, 19, 4}, 15);
  gmsh::model::geo::addSurfaceFilling({15}, 15);

  gmsh::model::geo::addCurveLoop({-18, 22, -19, -8}, 16);
  gmsh::model::geo::addSurfaceFilling({16}, 16);


  //Вторая половина
  gmsh::model::geo::addPoint(0.05, 0, 0, lc, 14);
  gmsh::model::geo::addPoint(0.05, 0, 0, lc, 15);


  gmsh::model::geo::addSurfaceLoop({1, 5, 10, 12, 13, 15}, 1);
  gmsh::model::geo::addVolume({1});
  //gmsh::model::geo::addSurfaceLoop({2, 6, 9, 11, 14, 16}, 2);
  //gmsh::model::geo::addVolume({2});
  //gmsh::model::geo::addSurfaceLoop({3, 7, 10, 12, 14, 16}, 3);
  //gmsh::model::geo::addVolume({3});
  //gmsh::model::geo::addSurfaceLoop({2, 6, 16, 3, 7, 10, 12, 14}, 2);
  //gmsh::model::geo::addVolume({2});

  gmsh::model::geo::addSurfaceLoop({4, 8, 9, 11, 13, 15}, 4);
  gmsh::model::geo::addVolume({4});





  gmsh::model::geo::synchronize();

  gmsh::model::mesh::generate(3);

  gmsh::write("t2.msh");

  std::set<std::string> args(argv, argv + argc);
  if(!args.count("-nopopup")) gmsh::fltk::run();

  gmsh::finalize();

  return 0;
}

