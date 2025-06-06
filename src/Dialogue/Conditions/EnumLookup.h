#pragma once

// stolen from DAV (https://github.com/Exit-9B/DynamicArmorVariants)

class EnumLookup
{
public:
	EnumLookup() = delete;

	static auto LookupActorValue(const std::string& a_str) -> RE::ActorValue
	{
		if (auto it = ActorValueLookup.find(a_str); it != ActorValueLookup.end()) {
			return it->second;
		} else {
			return RE::ActorValue::kNone;
		}
	}

	static auto LookupAxis(const std::string& a_str) -> std::int32_t
	{
		assert(a_str.empty() == false);
		switch (std::toupper(a_str.front())) {
		case 'X':
			return 0;
		case 'Y':
			return 1;
		case 'Z':
			return 2;
		default:
			return -1;
		}
	}

	static auto LookupCastingSource(std::string a_str)
		-> RE::MagicSystem::CastingSource
	{
		Util::ToUpper(a_str);
		if (a_str == "LEFT"s) {
			return RE::MagicSystem::CastingSource::kLeftHand;
		} else if (a_str == "RIGHT"s) {
			return RE::MagicSystem::CastingSource::kRightHand;
		} else if (a_str == "VOICE"s) {
			return RE::MagicSystem::CastingSource::kOther;
		} else if (a_str == "INSTANT"s) {
			return RE::MagicSystem::CastingSource::kInstant;
		} else {
			return static_cast<RE::MagicSystem::CastingSource>(-1);
		}
	}

	static auto LookupSex(std::string a_str) -> RE::SEX
	{
		Util::ToUpper(a_str);
		if (a_str == "MALE"s) {
			return RE::SEX::kMale;
		} else if (a_str == "FEMALE"s) {
			return RE::SEX::kFemale;
		} else {
			return static_cast<RE::SEX>(-1);
		}
	}

private:
	struct StringCmp
	{
		bool operator()(const std::string& a_lhs, const std::string& a_rhs) const
		{
			return _strcmpi(a_lhs.c_str(), a_rhs.c_str()) < 0;
		}
	};

	inline static const std::map<std::string, RE::ActorValue, StringCmp> ActorValueLookup{
		{ "AGGRESSION"s, RE::ActorValue::kAggression },
		{ "CONFIDENCE"s, RE::ActorValue::kConfidence },
		{ "ENERGY"s, RE::ActorValue::kEnergy },
		{ "MORALITY"s, RE::ActorValue::kMorality },
		{ "MOOD"s, RE::ActorValue::kMood },
		{ "ASSISTANCE"s, RE::ActorValue::kAssistance },
		{ "ONEHANDED"s, RE::ActorValue::kOneHanded },
		{ "TWOHANDED"s, RE::ActorValue::kTwoHanded },
		{ "MARKSMAN"s, RE::ActorValue::kArchery },
		{ "BLOCK"s, RE::ActorValue::kBlock },
		{ "SMITHING"s, RE::ActorValue::kSmithing },
		{ "HEAVYARMOR"s, RE::ActorValue::kHeavyArmor },
		{ "LIGHTARMOR"s, RE::ActorValue::kLightArmor },
		{ "PICKPOCKET"s, RE::ActorValue::kPickpocket },
		{ "LOCKPICKING"s, RE::ActorValue::kLockpicking },
		{ "SNEAK"s, RE::ActorValue::kSneak },
		{ "ALCHEMY"s, RE::ActorValue::kAlchemy },
		{ "SPEECHCRAFT"s, RE::ActorValue::kSpeech },
		{ "ALTERATION"s, RE::ActorValue::kAlteration },
		{ "CONJURATION"s, RE::ActorValue::kConjuration },
		{ "DESTRUCTION"s, RE::ActorValue::kDestruction },
		{ "ILLUSION"s, RE::ActorValue::kIllusion },
		{ "RESTORATION"s, RE::ActorValue::kRestoration },
		{ "ENCHANTING"s, RE::ActorValue::kEnchanting },
		{ "HEALTH"s, RE::ActorValue::kHealth },
		{ "MAGICKA"s, RE::ActorValue::kMagicka },
		{ "STAMINA"s, RE::ActorValue::kStamina },
		{ "HEALRATE"s, RE::ActorValue::kHealRate },
		{ "MAGICKARATE"s, RE::ActorValue::kMagickaRate },
		{ "STAMINARATE"s, RE::ActorValue::kStaminaRate },
		{ "SPEEDMULT"s, RE::ActorValue::kSpeedMult },
		{ "INVENTORYWEIGHT"s, RE::ActorValue::kInventoryWeight },
		{ "CARRYWEIGHT"s, RE::ActorValue::kCarryWeight },
		{ "CRITCHANCE"s, RE::ActorValue::kCriticalChance },
		{ "MELEEDAMAGE"s, RE::ActorValue::kMeleeDamage },
		{ "UNARMEDDAMAGE"s, RE::ActorValue::kUnarmedDamage },
		{ "MASS"s, RE::ActorValue::kMass },
		{ "VOICEPOINTS"s, RE::ActorValue::kVoicePoints },
		{ "VOICERATE"s, RE::ActorValue::kVoiceRate },
		{ "DAMAGERESIST"s, RE::ActorValue::kDamageResist },
		{ "POISONRESIST"s, RE::ActorValue::kPoisonResist },
		{ "FIRERESIST"s, RE::ActorValue::kResistFire },
		{ "ELECTRICRESIST"s, RE::ActorValue::kResistShock },
		{ "FROSTRESIST"s, RE::ActorValue::kResistFrost },
		{ "MAGICRESIST"s, RE::ActorValue::kResistMagic },
		{ "DISEASERESIST"s, RE::ActorValue::kResistDisease },
		{ "PERCEPTIONCONDITION"s, RE::ActorValue::kPerceptionCondition },
		{ "ENDURANCECONDITION"s, RE::ActorValue::kEnduranceCondition },
		{ "LEFTATTACKCONDITION"s, RE::ActorValue::kLeftAttackCondition },
		{ "RIGHTATTACKCONDITION"s, RE::ActorValue::kRightAttackCondition },
		{ "LEFTMOBILITYCONDITION"s, RE::ActorValue::kLeftMobilityCondition },
		{ "RIGHTMOBILITYCONDITION"s, RE::ActorValue::kRightMobilityCondition },
		{ "BRAINCONDITION"s, RE::ActorValue::kBrainCondition },
		{ "PARALYSIS"s, RE::ActorValue::kParalysis },
		{ "INVISIBILITY"s, RE::ActorValue::kInvisibility },
		{ "NIGHTEYE"s, RE::ActorValue::kNightEye },
		{ "DETECTLIFERANGE"s, RE::ActorValue::kDetectLifeRange },
		{ "WATERBREATHING"s, RE::ActorValue::kWaterBreathing },
		{ "WATERWALKING"s, RE::ActorValue::kWaterWalking },
		{ "IGNORECRIPPLEDLIMBS"s, RE::ActorValue::kIgnoreCrippledLimbs },
		{ "FAME"s, RE::ActorValue::kFame },
		{ "INFAMY"s, RE::ActorValue::kInfamy },
		{ "JUMPINGBONUS"s, RE::ActorValue::kJumpingBonus },
		{ "WARDPOWER"s, RE::ActorValue::kWardPower },
		{ "RIGHTITEMCHARGE"s, RE::ActorValue::kRightItemCharge },
		{ "ARMORPERKS"s, RE::ActorValue::kArmorPerks },
		{ "SHIELDPERKS"s, RE::ActorValue::kShieldPerks },
		{ "WARDDEFLECTION"s, RE::ActorValue::kWardDeflection },
		{ "VARIABLE01"s, RE::ActorValue::kVariable01 },
		{ "VARIABLE02"s, RE::ActorValue::kVariable02 },
		{ "VARIABLE03"s, RE::ActorValue::kVariable03 },
		{ "VARIABLE04"s, RE::ActorValue::kVariable04 },
		{ "VARIABLE05"s, RE::ActorValue::kVariable05 },
		{ "VARIABLE06"s, RE::ActorValue::kVariable06 },
		{ "VARIABLE07"s, RE::ActorValue::kVariable07 },
		{ "VARIABLE08"s, RE::ActorValue::kVariable08 },
		{ "VARIABLE09"s, RE::ActorValue::kVariable09 },
		{ "VARIABLE10"s, RE::ActorValue::kVariable10 },
		{ "BOWSPEEDBONUS"s, RE::ActorValue::kBowSpeedBonus },
		{ "FAVORACTIVE"s, RE::ActorValue::kFavorActive },
		{ "FAVORSPERDAY"s, RE::ActorValue::kFavorsPerDay },
		{ "FAVORSPERDAYTIMER"s, RE::ActorValue::kFavorsPerDayTimer },
		{ "LEFTITEMCHARGE"s, RE::ActorValue::kLeftItemCharge },
		{ "ABSORBCHANCE"s, RE::ActorValue::kAbsorbChance },
		{ "BLINDNESS"s, RE::ActorValue::kBlindness },
		{ "WEAPONSPEEDMULT"s, RE::ActorValue::kWeaponSpeedMult },
		{ "SHOUTRECOVERYMULT"s, RE::ActorValue::kShoutRecoveryMult },
		{ "BOWSTAGGERBONUS"s, RE::ActorValue::kBowStaggerBonus },
		{ "TELEKINESIS"s, RE::ActorValue::kTelekinesis },
		{ "FAVORPOINTSBONUS"s, RE::ActorValue::kFavorPointsBonus },
		{ "LASTBRIBEDINTIMIDATED"s, RE::ActorValue::kLastBribedIntimidated },
		{ "LASTFLATTERED"s, RE::ActorValue::kLastFlattered },
		{ "MOVEMENTNOISEMULT"s, RE::ActorValue::kMovementNoiseMult },
		{ "BYPASSVENDORSTOLENCHECK"s, RE::ActorValue::kBypassVendorStolenCheck },
		{ "BYPASSVENDORKEYWORDCHECK"s, RE::ActorValue::kBypassVendorKeywordCheck },
		{ "WAITINGFORPLAYER"s, RE::ActorValue::kWaitingForPlayer },
		{ "ONEHANDEDMOD"s, RE::ActorValue::kOneHandedModifier },
		{ "TWOHANDEDMOD"s, RE::ActorValue::kTwoHandedModifier },
		{ "MARKSMANMOD"s, RE::ActorValue::kMarksmanModifier },
		{ "BLOCKMOD"s, RE::ActorValue::kBlockModifier },
		{ "SMITHINGMOD"s, RE::ActorValue::kSmithingModifier },
		{ "HEAVYARMORMOD"s, RE::ActorValue::kHeavyArmorModifier },
		{ "LIGHTARMORMOD"s, RE::ActorValue::kLightArmorModifier },
		{ "PICKPOCKETMOD"s, RE::ActorValue::kPickpocketModifier },
		{ "LOCKPICKINGMOD"s, RE::ActorValue::kLockpickingModifier },
		{ "SNEAKMOD"s, RE::ActorValue::kSneakingModifier },
		{ "ALCHEMYMOD"s, RE::ActorValue::kAlchemyModifier },
		{ "SPEECHCRAFTMOD"s, RE::ActorValue::kSpeechcraftModifier },
		{ "ALTERATIONMOD"s, RE::ActorValue::kAlterationModifier },
		{ "CONJURATIONMOD"s, RE::ActorValue::kConjurationModifier },
		{ "DESTRUCTIONMOD"s, RE::ActorValue::kDestructionModifier },
		{ "ILLUSIONMOD"s, RE::ActorValue::kIllusionModifier },
		{ "RESTORATIONMOD"s, RE::ActorValue::kRestorationModifier },
		{ "ENCHANTINGMOD"s, RE::ActorValue::kEnchantingModifier },
		{ "ONEHANDEDSKILLADVANCE"s, RE::ActorValue::kOneHandedSkillAdvance },
		{ "TWOHANDEDSKILLADVANCE"s, RE::ActorValue::kTwoHandedSkillAdvance },
		{ "MARKSMANSKILLADVANCE"s, RE::ActorValue::kMarksmanSkillAdvance },
		{ "BLOCKSKILLADVANCE"s, RE::ActorValue::kBlockSkillAdvance },
		{ "SMITHINGSKILLADVANCE"s, RE::ActorValue::kSmithingSkillAdvance },
		{ "HEAVYARMORSKILLADVANCE"s, RE::ActorValue::kHeavyArmorSkillAdvance },
		{ "LIGHTARMORSKILLADVANCE"s, RE::ActorValue::kLightArmorSkillAdvance },
		{ "PICKPOCKETSKILLADVANCE"s, RE::ActorValue::kPickpocketSkillAdvance },
		{ "LOCKPICKINGSKILLADVANCE"s, RE::ActorValue::kLockpickingSkillAdvance },
		{ "SNEAKSKILLADVANCE"s, RE::ActorValue::kSneakingSkillAdvance },
		{ "ALCHEMYSKILLADVANCE"s, RE::ActorValue::kAlchemySkillAdvance },
		{ "SPEECHCRAFTSKILLADVANCE"s, RE::ActorValue::kSpeechcraftSkillAdvance },
		{ "ALTERATIONSKILLADVANCE"s, RE::ActorValue::kAlterationSkillAdvance },
		{ "CONJURATIONSKILLADVANCE"s, RE::ActorValue::kConjurationSkillAdvance },
		{ "DESTRUCTIONSKILLADVANCE"s, RE::ActorValue::kDestructionSkillAdvance },
		{ "ILLUSIONSKILLADVANCE"s, RE::ActorValue::kIllusionSkillAdvance },
		{ "RESTORATIONSKILLADVANCE"s, RE::ActorValue::kRestorationSkillAdvance },
		{ "ENCHANTINGSKILLADVANCE"s, RE::ActorValue::kEnchantingSkillAdvance },
		{ "LEFTWEAPONSPEEDMULT"s, RE::ActorValue::kLeftWeaponSpeedMultiply },
		{ "DRAGONSOULS"s, RE::ActorValue::kDragonSouls },
		{ "COMBATHEALTHREGENMULT"s, RE::ActorValue::kCombatHealthRegenMultiply },
		{ "ONEHANDEDPOWERMOD"s, RE::ActorValue::kOneHandedPowerModifier },
		{ "TWOHANDEDPOWERMOD"s, RE::ActorValue::kTwoHandedPowerModifier },
		{ "MARKSMANPOWERMOD"s, RE::ActorValue::kMarksmanPowerModifier },
		{ "BLOCKPOWERMOD"s, RE::ActorValue::kBlockPowerModifier },
		{ "SMITHINGPOWERMOD"s, RE::ActorValue::kSmithingPowerModifier },
		{ "HEAVYARMORPOWERMOD"s, RE::ActorValue::kHeavyArmorPowerModifier },
		{ "LIGHTARMORPOWERMOD"s, RE::ActorValue::kLightArmorPowerModifier },
		{ "PICKPOCKETPOWERMOD"s, RE::ActorValue::kPickpocketPowerModifier },
		{ "LOCKPICKINGPOWERMOD"s, RE::ActorValue::kLockpickingPowerModifier },
		{ "SNEAKPOWERMOD"s, RE::ActorValue::kSneakingPowerModifier },
		{ "ALCHEMYPOWERMOD"s, RE::ActorValue::kAlchemyPowerModifier },
		{ "SPEECHCRAFTPOWERMOD"s, RE::ActorValue::kSpeechcraftPowerModifier },
		{ "ALTERATIONPOWERMOD"s, RE::ActorValue::kAlterationPowerModifier },
		{ "CONJURATIONPOWERMOD"s, RE::ActorValue::kConjurationPowerModifier },
		{ "DESTRUCTIONPOWERMOD"s, RE::ActorValue::kDestructionPowerModifier },
		{ "ILLUSIONPOWERMOD"s, RE::ActorValue::kIllusionPowerModifier },
		{ "RESTORATIONPOWERMOD"s, RE::ActorValue::kRestorationPowerModifier },
		{ "ENCHANTINGPOWERMOD"s, RE::ActorValue::kEnchantingPowerModifier },
		{ "DRAGONREND"s, RE::ActorValue::kDragonRend },
		{ "ATTACKDAMAGEMULT"s, RE::ActorValue::kAttackDamageMult },
		{ "HEALRATEMULT"s, RE::ActorValue::kHealRateMult },
		{ "MAGICKARATEMULT"s, RE::ActorValue::kMagickaRateMult },
		{ "STAMINARATEMULT"s, RE::ActorValue::kStaminaRateMult },
		{ "WEREWOLFPERKS"s, RE::ActorValue::kWerewolfPerks },
		{ "VAMPIREPERKS"s, RE::ActorValue::kVampirePerks },
		{ "GRABACTOROFFSET"s, RE::ActorValue::kGrabActorOffset },
		{ "GRABBED"s, RE::ActorValue::kGrabbed },
		{ "DEPRECATED05"s, RE::ActorValue::kDEPRECATED05 },
		{ "REFLECTDAMAGE"s, RE::ActorValue::kReflectDamage },
	};
};