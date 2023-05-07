#pragma once

#include <iosfwd>
#include <string>

#include <libbhlc/export.hxx>

namespace bhlc
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBBHLC_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
