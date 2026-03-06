// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>

#include <cmath>
#include <stdexcept>

#include "circle.h"
#include "tasks.h"

namespace {
constexpr double kPi = 3.14159265358979323846;
constexpr double kEps = 1e-9;
}

TEST(Circle_Constructor, CreatesCircleWithZeroRadius) {
  Circle c(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle_Constructor, CreatesCircleWithPositiveRadius) {
  Circle c(1.0);
  EXPECT_NEAR(c.getRadius(), 1.0, kEps);
  EXPECT_NEAR(c.getFerence(), 2.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), kPi, kEps);
}

TEST(Circle_Constructor, ThrowsOnNegativeRadius) {
  EXPECT_THROW(Circle(-1.0), std::invalid_argument);
}

TEST(Circle_SetRadius, UpdatesRadius) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_NEAR(c.getRadius(), 5.0, kEps);
}

TEST(Circle_SetRadius, UpdatesFerence) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_NEAR(c.getFerence(), 10.0 * kPi, kEps);
}

TEST(Circle_SetRadius, UpdatesArea) {
  Circle c(1.0);
  c.setRadius(5.0);
  EXPECT_NEAR(c.getArea(), 25.0 * kPi, kEps);
}

TEST(Circle_SetRadius, ThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setRadius(-2.0), std::invalid_argument);
}

TEST(Circle_SetFerence, UpdatesFerence) {
  Circle c(1.0);
  c.setFerence(4.0 * kPi);
  EXPECT_NEAR(c.getFerence(), 4.0 * kPi, kEps);
}

TEST(Circle_SetFerence, RecalculatesRadius) {
  Circle c(1.0);
  c.setFerence(4.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 2.0, kEps);
}

TEST(Circle_SetFerence, RecalculatesArea) {
  Circle c(1.0);
  c.setFerence(4.0 * kPi);
  EXPECT_NEAR(c.getArea(), 4.0 * kPi, kEps);
}

TEST(Circle_SetFerence, WorksWithZero) {
  Circle c(3.0);
  c.setFerence(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getArea(), 0.0, kEps);
}

TEST(Circle_SetFerence, ThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setFerence(-1.0), std::invalid_argument);
}

TEST(Circle_SetArea, UpdatesArea) {
  Circle c(1.0);
  c.setArea(9.0 * kPi);
  EXPECT_NEAR(c.getArea(), 9.0 * kPi, kEps);
}

TEST(Circle_SetArea, RecalculatesRadius) {
  Circle c(1.0);
  c.setArea(9.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 3.0, kEps);
}

TEST(Circle_SetArea, RecalculatesFerence) {
  Circle c(1.0);
  c.setArea(9.0 * kPi);
  EXPECT_NEAR(c.getFerence(), 6.0 * kPi, kEps);
}

TEST(Circle_SetArea, WorksWithZero) {
  Circle c(3.0);
  c.setArea(0.0);
  EXPECT_NEAR(c.getRadius(), 0.0, kEps);
  EXPECT_NEAR(c.getFerence(), 0.0, kEps);
}

TEST(Circle_SetArea, ThrowsOnNegativeValue) {
  Circle c(1.0);
  EXPECT_THROW(c.setArea(-10.0), std::invalid_argument);
}

TEST(Circle_Getters, ReturnCorrectValuesAfterSeveralChanges) {
  Circle c(2.0);
  c.setArea(16.0 * kPi);
  EXPECT_NEAR(c.getRadius(), 4.0, kEps);
  EXPECT_NEAR(c.getFerence(), 8.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 16.0 * kPi, kEps);
}

TEST(Circle_Precision, CorrectForFractionalRadius) {
  Circle c(2.5);
  EXPECT_NEAR(c.getFerence(), 5.0 * kPi, kEps);
  EXPECT_NEAR(c.getArea(), 6.25 * kPi, kEps);
}

TEST(Task_EarthRope, ReturnsCorrectGap) {
  const double gap = solveEarthRopeTask();
  EXPECT_NEAR(gap, 1.0 / (2.0 * kPi), kEps);
}

TEST(Task_EarthRope, GapIsAbout159Millimeters) {
  const double gap = solveEarthRopeTask();
  EXPECT_NEAR(gap, 0.15915494309189535, 1e-12);
}

TEST(Task_Pool, ReturnsCorrectConcreteCost) {
  PoolCosts costs = solvePoolTask();
  EXPECT_NEAR(costs.concrete_cost, 7000.0 * kPi, kEps);
}

TEST(Task_Pool, ReturnsCorrectFenceCost) {
  PoolCosts costs = solvePoolTask();
  EXPECT_NEAR(costs.fence_cost, 16000.0 * kPi, kEps);
}

