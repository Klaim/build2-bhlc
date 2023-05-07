#include <iostream>

#include <libbhlc/bhlc.hxx>

void diagnose_invalid_config_expr(const bhlc::InvalidExpr& invalid_expr)
{
  std::cerr << "High-Level Configuration is Invalid: NOT IMPLEMENTED YET"; // FIXME: missing implementation
}

int main (int argc, char* argv[])
{
  if (argc < 2)
  {
    std::cerr << "error: high-level configuration expression" << std::endl;
    return EXIT_FAILURE;
  }
  
  auto maybe_hlconfig = bhlc::read_config_expression(argv[1]);
  if(not maybe_hlconfig)
  {
    diagnose_invalid_config_expr(maybe_hlconfig.error());
    return EXIT_FAILURE;
  }

  auto maybe_config_descs = bhlc::generate_config_descriptions(*maybe_hlconfig, {});
  if(not maybe_config_descs)
  {
    diagnose_invalid_config_expr(maybe_config_descs.error());
    return EXIT_FAILURE;
  }

  for(const auto& config_desc : *maybe_config_descs)
  {
    std::cout << "\nHigh-Level Configuration:\n";
    bhlc::write_config_file(std::cout, config_desc);
  }
  std::cout << std::endl;
  return EXIT_SUCCESS;
}
