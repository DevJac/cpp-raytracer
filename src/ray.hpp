#include "vec3.hpp"

class ray {
private:
  vec3 orig;
  vec3 dir;

public:
  ray() : orig{0, 0, 0}, dir{0, 0, -1} {}
  ray(const vec3 &orig, const vec3 &dir) : orig{orig}, dir{dir} {}

  vec3 origin() const { return orig; }
  vec3 direction() const { return dir; }

  vec3 at(float t) const { return orig + t * dir; }
};

TEST(ray, default_constructor) {
  const ray r;
  EXPECT_EQ(r.at(0), vec3(0, 0, 0));
  EXPECT_EQ(r.at(1), vec3(0, 0, -1));
  EXPECT_EQ(r.at(2), vec3(0, 0, -2));
  EXPECT_EQ(r.origin(), vec3(0, 0, 0));
  EXPECT_EQ(r.direction(), vec3(0, 0, -1));
}

TEST(ray, orig_dir_constructor) {
  const vec3 orig{1, 1, 1};
  const vec3 dir{0, 1, 0};
  const ray r(orig, dir);
  EXPECT_EQ(r.origin(), orig);
  EXPECT_EQ(r.direction(), dir);
  EXPECT_EQ(r.at(0), orig);
  EXPECT_EQ(r.at(1), vec3(1, 2, 1));
}
