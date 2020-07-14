#include <gtest/gtest.h>
#include <iostream>

class vec3 {
private:
  float e[3];

public:
  vec3() : e{0, 0, 0} {}
  vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

  float x() const { return e[0]; }
  float y() const { return e[1]; }
  float z() const { return e[2]; }

  float operator[](int i) const { return e[i]; }

  float at(int i) const {
    if (0 <= i && i <= 2) {
      return e[i];
    } else {
      throw std::out_of_range("invalid index in vec3::at");
    }
  }

  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

  void operator+=(const vec3 &other) {
    e[0] += other[0];
    e[1] += other[1];
    e[2] += other[2];
  }

  void operator-=(const vec3 &other) {
    e[0] -= other[0];
    e[1] -= other[1];
    e[2] -= other[2];
  }

  void operator*=(const float &scalar) {
    e[0] *= scalar;
    e[1] *= scalar;
    e[2] *= scalar;
  }

  void operator/=(const float &scalar) {
    e[0] /= scalar;
    e[1] /= scalar;
    e[2] /= scalar;
  }
};

TEST(vec3, accessors) {
  const vec3 v{1, 2, 3};
  EXPECT_EQ(v.x(), 1);
  EXPECT_EQ(v.y(), 2);
  EXPECT_EQ(v.z(), 3);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(1), 2);
  EXPECT_EQ(v.at(2), 3);
  bool caught_out_of_range = false;
  try {
    v.at(3);
  } catch (std::out_of_range &_err) {
    caught_out_of_range = true;
  }
  EXPECT_TRUE(caught_out_of_range);
}

TEST(vec3, negation) {
  const vec3 vp{1, 2, 3};
  const vec3 vn{-vp};
  EXPECT_EQ(vp.x(), 1);
  EXPECT_EQ(vp.y(), 2);
  EXPECT_EQ(vp.z(), 3);
  EXPECT_EQ(vn.x(), -1);
  EXPECT_EQ(vn.y(), -2);
  EXPECT_EQ(vn.z(), -3);
}
