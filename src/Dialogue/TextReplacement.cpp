#include "TextReplacement.h"

#include "Util/FormLookup.h"

namespace DDR
{
  TextReplacement::TextReplacement(const YAML::Node& a_node) :
    _script(a_node["script"].as<std::string>()),
    _speakerId(Util::FormFromString(a_node["speaker"].as<std::string>(""))),
    _type(magic_enum::enum_cast<ReplacemenType>(a_node["type"].as<int>(0)).value_or(ReplacemenType::Any))
  {
    if (_script.empty()) {
      throw std::runtime_error("Failed to load script");
    }
  }

	bool TextReplacement::CanApplyReplacement(RE::TESObjectREFR* a_speaker, ReplacemenType a_type) const
  {
    if (_type == ReplacemenType::Any || _type == a_type) {
      if (_speakerId == 0) {
        return true;
      }
      if (a_speaker) {
        return a_speaker->GetFormID() == _speakerId;
      }
    }
    return false;
  }

} // namespace DDR