#include <iostream>

// ini parser
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/ptree.hpp>
namespace pt = boost::property_tree;

#include "LooperFactory.h"
#include "LooperV.h"

Looper *LooperFactory::create(std::string input_file,
                              QuantumFriction *quantum_friction) {
  // set return pointer to NULL
  Looper *looper = NULL;

  // Create a root
  pt::ptree root;

  // Load the ini file in this ptree
  pt::read_ini(input_file, root);

  // read the type of the kernel
  std::string type = root.get<std::string>("Looper.variable");

  // set the right pointer, show error if type is unknown
  if (type == "v") {
    looper = new LooperV(input_file, quantum_friction);
  } else {
    std::cerr << "Error: Unknown Looper type (" << type << ")!" << std::endl;
    exit(0);
  };

  // return looper pointer
  return looper;
};
