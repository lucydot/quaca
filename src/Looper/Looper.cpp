// ini parser
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
namespace pt = boost::property_tree;

#include "Looper.h"

Looper::Looper(double start, double end, int number_of_steps, std::string scale,
               std::string type, QuantumFriction *quantum_friction)
    : start(start), end(end), number_of_steps(number_of_steps), scale(scale),
      quantum_friction(quantum_friction) {
  assert(start < end);
  this->calculate_steps();
};

Looper::Looper(std::string input_file, QuantumFriction *quantum_friction)
    : quantum_friction(quantum_friction) {

  // read parameters
  pt::ptree root;
  pt::read_ini(input_file, root);
  this->start = root.get<double>("Looper.start");
  this->end = root.get<double>("Looper.end");
  this->number_of_steps = root.get<double>("Looper.N");
  this->scale = root.get<std::string>("Looper.scale");
  this->type = root.get<std::string>("Looper.type");

  assert(start < end);
  this->calculate_steps();
};

void Looper::calculate_steps() {
  if (scale == "linear") {
    double spacing = (end - start) / ((double)number_of_steps);
    for (int i = 0; i < number_of_steps; i++) {
      this->steps[i] = start + i * spacing;
    };
  } else if (scale == "log") {
    double spacing = pow(end / start, 1. / number_of_steps);
    for (int i = 0; i < number_of_steps; i++) {
      this->steps[i] = start * pow(spacing, i);
    };

  } else {
    std::cerr << "Unknown scale: " << scale << std::endl;
    exit(-1);
  };
}
