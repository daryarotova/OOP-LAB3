#include <gtest/gtest.h>
#include <sstream>
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/figure_array.h"

TEST(FigureTest, PentagonConstructorAndArea) {
    std::vector<Point> pts{{0,0},{1,0},{1,1},{0,1},{-0.5,0.5}};
    Pentagon p(pts);
    EXPECT_NEAR(double(p), 1.25, 1e-5);
}

TEST(FigureTest, HexagonConstructorAndCenter) {
    std::vector<Point> pts{{0,0},{1,0},{1.5,0.87},{1,1.73},{0,1.73},{-0.5,0.87}};
    Hexagon h(pts);
    Point c = h.GeometricCenter();
    EXPECT_NEAR(c.x, 0.5, 1e-5);
    EXPECT_NEAR(c.y, 0.8666667, 1e-5);
}

TEST(FigureTest, OctagonComparison) {
    std::vector<Point> pts{{0,0},{1,0},{2,0},{2,1},{2,2},{1,2},{0,2},{0,1}};
    Octagon o1(pts);
    Octagon o2(pts);
    EXPECT_TRUE(o1 == o2);
}

TEST(FigureTest, StreamInputOutput) {
    Pentagon p;
    std::istringstream iss("0 0 1 0 1 1 0 1 -0.5 0.5");
    iss >> p;
    std::ostringstream oss;
    oss << p;
    std::string output = oss.str();
    EXPECT_FALSE(output.empty());
}

TEST(FigureArrayTest, AddAndTotalArea) {
    FigureArray arr;
    Pentagon* p = new Pentagon({{0,0},{1,0},{1,1},{0,1},{-0.5,0.5}});
    Hexagon* h = new Hexagon({{0,0},{1,0},{1.5,0.87},{1,1.73},{0,1.73},{-0.5,0.87}});
    arr.Add(p);
    arr.Add(h);
    double total = arr.TotalArea();
    EXPECT_NEAR(total, double(*p) + double(*h), 1e-5);
}

TEST(FigureArrayTest, RemoveFigure) {
    FigureArray arr;
    Pentagon* p = new Pentagon({{0,0},{1,0},{1,1},{0,1},{-0.5,0.5}});
    arr.Add(p);
    EXPECT_EQ(arr.Size(), 1);
    arr.Remove(0);
    EXPECT_EQ(arr.Size(), 0);
}

TEST(FigureArrayTest, PrintAll) {
    FigureArray arr;
    Pentagon* p = new Pentagon({{0,0},{1,0},{1,1},{0,1},{-0.5,0.5}});
    arr.Add(p);
    std::ostringstream oss;
    testing::internal::CaptureStdout();
    arr.PrintAll();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}
