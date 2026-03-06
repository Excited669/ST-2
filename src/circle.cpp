// Copyright 2022 UNN-CS

#include "circle.h"

#include <cmath>
#include <stdexcept>

namespace {
constexpr double kPi = 3.14159265358979323846;
}  // namespace

double Circle::getPi() {
  return kPi;
}

void Circle::updateFromRadius() {
  ference_ = 2.0 * getPi() * radius_;
  area_ = getPi() * radius_ * radius_;
}

Circle::Circle(double radius) : radius_(0.0), ference_(0.0), area_(0.0) {
  setRadius(radius);
}

void Circle::setRadius(double radius) {
  if (radius < 0.0) {
    throw std::invalid_argument("Radius cannot be negative");
  }
  radius_ = radius;
  updateFromRadius();
}

void Circle::setFerence(double ference) {
  if (ference < 0.0) {
    throw std::invalid_argument("Ference cannot be negative");
  }
  ference_ = ference;
  radius_ = ference_ / (2.0 * getPi());
  area_ = getPi() * radius_ * radius_;
}

void Circle::setArea(double area) {
  if (area < 0.0) {
    throw std::invalid_argument("Area cannot be negative");
  }
  area_ = area;
  radius_ = std::sqrt(area_ / getPi());
  ference_ = 2.0 * getPi() * radius_;
}

double Circle::getRadius() const {
  return radius_;
}

double Circle::getFerence() const {
  return ference_;
}

double Circle::getArea() const {
  return area_;
}