
#include <libbhlc/version.hxx>
#include <libbhlc/bhlc.hxx>

#include <iostream>

int main ()
{
  auto hlconfig = *bhlc::read_config_expression("blah");
  auto config_descs = *bhlc::generate_config_descriptions(hlconfig, {});
  for(const auto& config_desc : config_descs)
    bhlc::write_config_file(std::cout, config_desc);
}
