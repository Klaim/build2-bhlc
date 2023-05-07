#include <libbhlc/bhlc.hxx>

#include <ostream>
#include <stdexcept>

using namespace std;

namespace bhlc
{
  auto read_config_expression(std::string_view config_expr)
    -> expected<HighLevelConfig, InvalidExpr>
  {
    return HighLevelConfig{};
  }

  auto generate_config_descriptions(const HighLevelConfig& hlconfig, optional<const ConfigOptions&> options)
    -> expected<std::vector<ConfigDesc>, InvalidExpr>
  {
    return std::vector{ ConfigDesc{} };
  }
  
  auto write_config_file(std::ostream& out, const ConfigDesc& config_desc)
    -> void
  {
    out << "libbhlc: not implemented yet!";
  }

}
