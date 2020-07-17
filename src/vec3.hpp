#include <cmath>
#include <gtest/gtest.h>
#include <iostream>

class vec3;
vec3 operator/(const vec3 &, float);

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

  float length() const { return std::sqrt(length_squared()); }

  float length_squared() const { return x() * x() + y() * y() + z() * z(); }

  vec3 unit() const { return (*this) / this->length(); }
};

std::ostream &operator<<(std::ostream &out, const vec3 &v) {
  return out << "vec3(" << v.x() << ", " << v.y() << ", " << v.z() << ")";
}

bool operator==(const vec3 &u, const vec3 &v) {
  return u.x() == v.x() && u.y() == v.y() && u.z() == v.z();
}

bool operator!=(const vec3 &u, const vec3 &v) { return !(u == v); }

vec3 operator+(const vec3 &u, const vec3 &v) {
  return vec3{
      u.x() + v.x(),
      u.y() + v.y(),
      u.z() + v.z(),
  };
}

vec3 operator-(const vec3 &u, const vec3 &v) {
  return vec3{
      u.x() - v.x(),
      u.y() - v.y(),
      u.z() - v.z(),
  };
}

vec3 operator*(const vec3 &u, const vec3 &v) {
  return vec3{
      u.x() * v.x(),
      u.y() * v.y(),
      u.z() * v.z(),
  };
}

vec3 operator*(float t, const vec3 &v) {
  return vec3{
      v.x() * t,
      v.y() * t,
      v.z() * t,
  };
}

vec3 operator*(const vec3 &v, float t) { return t * v; }

vec3 operator/(const vec3 &v, float t) {
  return vec3{
      v.x() / t,
      v.y() / t,
      v.z() / t,
  };
}

float dot(const vec3 &u, const vec3 &v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

vec3 cross(const vec3 &u, const vec3 &v) {
  return vec3{u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x()};
}

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
  const vec3 vn = -vp;
  EXPECT_EQ(vn, vec3(-1, -2, -3));
  EXPECT_TRUE(vp != vn);
  EXPECT_TRUE(vp == -vn);
}

TEST(vec3, math) {
  const vec3 v1{1, 1, 1};
  const vec3 v2{1, 2, 3};
  EXPECT_EQ(v1 + v2, vec3(2, 3, 4));
  EXPECT_EQ(v1 - v2, vec3(0, -1, -2));
  EXPECT_EQ(v1 * v2, vec3(1, 2, 3));
  EXPECT_EQ(2 * v2 * 2 / 4, v2);
}

TEST(vec3, inplace_math) {
  vec3 v;
  EXPECT_EQ(v, vec3(0, 0, 0));
  v += vec3(1, 2, 3);
  EXPECT_EQ(v, vec3(1, 2, 3));
  v *= 2;
  EXPECT_EQ(v, vec3(2, 4, 6));
  v /= 2;
  EXPECT_EQ(v, vec3(1, 2, 3));
  v += vec3{10, 10, 10};
  EXPECT_EQ(v, vec3(11, 12, 13));
  v -= vec3(1, 2, 3);
  EXPECT_EQ(v, vec3(10, 10, 10));
}

TEST(vec3, ostream_format) {
  const vec3 v{1, 2, 3};
  std::ostringstream oss;
  oss << v;
  EXPECT_EQ(oss.str(), "vec3(1, 2, 3)");
}

TEST(vec3, length) {
  const vec3 v{2, 3, 5};
  const float v_length = v.length();
  const float v_length_squared = v.length_squared();
  EXPECT_FLOAT_EQ(v_length, 6.1644139);
  EXPECT_EQ(v_length_squared, 38);
}

TEST(vec3, unit) {
  const vec3 v1{2, 0, 0};
  EXPECT_EQ(v1.unit(), vec3(1, 0, 0));
  const vec3 v2{2, 3, 5};
  const float v2_length = v2.length();
  EXPECT_EQ(v2.unit(), vec3(2 / v2_length, 3 / v2_length, 5 / v2_length));
}

TEST(vec3, dot) { EXPECT_EQ(dot(vec3(1, 2, 3), vec3(3, 4, 5)), 26); }

TEST(vec3, cross) {
  EXPECT_EQ(cross(vec3(1, 2, 3), vec3(4, 3, 2)), vec3(-5, 10, -5));
}
