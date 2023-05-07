#pragma once

#include <iosfwd>
#include <stdexcept>

#include <libbhlc/export.hxx>

#include <tl/expected.hpp>
#include <tl/optional.hpp>

namespace bhlc
{
  using tl::optional;
  using tl::expected;

  // Options to use when generating a configuration to alter it's details.
  struct ConfigOptions
  {};

  // Describes a high-level build2 configuration.
  struct HighLevelConfig
  {};

  // Describes a detailed build2 configuration with all the data to generate a configuration file.
  struct ConfigDesc
  {};


  // Returned by functions that read expressions when the expressions is invalid.
  struct InvalidExpr
  {};

  // Exception for error handling in this library.
  struct Error : std::runtime_error
  {};

  
  // Parse a UTF-8 string as a high-level configuration and returned a decomposed version of it if valid.
  LIBBHLC_SYMEXPORT
  auto read_config_expression(std::string_view config_expr) -> expected<HighLevelConfig, InvalidExpr>;

  // Generate detailed build2 configurations by interpreting a high-level configuration, altered by provided options.
  LIBBHLC_SYMEXPORT
  auto generate_config_descriptions(const HighLevelConfig& hlconfig, optional<const ConfigOptions&> options)
    -> expected<std::vector<ConfigDesc>, InvalidExpr>;
  
  // Writes in a UTF-8 stream the text of a configuration file with the provided configuration information.
  LIBBHLC_SYMEXPORT
  auto write_config_file(std::ostream& out, const ConfigDesc& config_desc) -> void;

}
