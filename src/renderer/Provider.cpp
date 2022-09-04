#include "Provider.h"

std::vector<renderer::Primitive *> renderer::primitivesList{};


renderer::Cube *renderer::CreateCube() {
  auto *value = new renderer::Cube;
  primitivesList.push_back(value);
  return value;
}

