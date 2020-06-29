#include "vec3.h"
#include <iostream>

int main() {
  const int image_width = 256;
  const int image_height = 256;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "Scanlines remaining: " << j + 1 << '\n' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      auto r = double(i) / (image_width - 1);
      auto g = double(j) / (image_height - 1);
      auto b = 0.25;

      int ir = static_cast<int>(255 * r);
      int ig = static_cast<int>(255 * g);
      int ib = static_cast<int>(255 * b);

      std::cout << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
  std::cerr << "Done.\n";

  vec3 v1{1, 2, 3};
  vec3 v2(1, 2, 3);
  vec3 v3 = -v2;
  std::cout << v1.at(0) << ' ' << v1.at(1) << ' ' << v1.at(2) << std::endl;
  std::cout << v2.at(0) << ' ' << v2.at(1) << ' ' << v2.at(2) << std::endl;
  std::cout << v3.at(0) << ' ' << v3.at(1) << ' ' << v3.at(2) << std::endl;
}
