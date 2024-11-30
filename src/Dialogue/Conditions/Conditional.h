#pragma once

#include "ConditionParser.h"

namespace Conditions
{
	struct Conditional
	{
		Conditional() = default;
		Conditional(const std::vector<std::string>& a_rawConditions, const ConditionParser::RefMap& a_refs) :
			_conditions(ConditionParser::ParseConditions(a_rawConditions, a_refs))
		{
			if (!_conditions) {
				throw std::runtime_error("Failed to parse conditions");
			}
		}
		~Conditional() = default;

	public:
		_NODISCARD bool ConditionsMet(RE::TESObjectREFR* a_subject, RE::TESObjectREFR* a_target) const;

		operator bool() const { return _conditions != nullptr; }

	private:
		static bool ProgressOr(RE::TESConditionItem*& a_item, RE::ConditionCheckParams& a_params);
		static bool IsTrue(RE::TESConditionItem* a_item, RE::ConditionCheckParams& a_params);

		std::shared_ptr<RE::TESCondition> _conditions{ nullptr };
	};
} // namespace Condition
