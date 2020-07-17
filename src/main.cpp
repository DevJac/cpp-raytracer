#include "vec3.hpp"
#include <iostream>

void write_color(std::ostream &out, const vec3 &pixel_color) {
  out << static_cast<int>(pixel_color.x() * 255) << ' '
      << static_cast<int>(pixel_color.y() * 255) << ' '
      << static_cast<int>(pixel_color.z() * 255) << '\n';
}

int main() {
  const int image_width = 256;
  const int image_height = 256;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "Scanlines remaining: " << j + 1 << '\n' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      const vec3 pixel_color{float(i) / (image_width - 1),
                             float(j) / (image_height - 1), 0.25};
      write_color(std::cout, pixel_color);
    }
  }
  std::cerr << "Done.\n";
}
