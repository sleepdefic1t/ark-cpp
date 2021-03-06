#include "gtest/gtest.h"

#include "api/api.h"

TEST(api, test_block)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto block = _arkManager.block("4367122150875693402");
	ASSERT_STREQ("4367122150875693402", block.id());
	ASSERT_EQ(0, block.version());
	ASSERT_STREQ("25271824", block.timestamp());
	ASSERT_STREQ("2287265", block.height());
	ASSERT_STREQ("17021413347323836951", block.previous_block());
	ASSERT_STREQ("0", block.number_of_transactions());
	ASSERT_STREQ("0", block.total_amount().arktoshi());
	ASSERT_STREQ("0", block.total_fee().arktoshi());
	ASSERT_STREQ("200000000", block.reward().arktoshi());
	ASSERT_STREQ("0", block.payload_length());
	ASSERT_STREQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855", block.payload_hash().getValue());
	ASSERT_STREQ("02a9a0ac34a94f9d27fd9b4b56eb3c565a9a3f61e660f269775fb456f7f3301586", block.generator_public_key().getValue());
	ASSERT_STREQ("D5PXQVeJmchVrZFHL7cALZK8mWWzjCaVfz", block.generator_id().getValue());
	ASSERT_STREQ("3045022100954a3726e3592d74e6005841ebf9eaef576a40291881ba0b3739da325b75fcbf022023ff247d11a1238052b48f01930f04380c501309f01ae0dbc6b6cf637c16f3b0", block.block_signature().getValue());
	ASSERT_STRNE("0", block.confirmations());
	ASSERT_STRNE("", block.confirmations());
	ASSERT_STREQ("200000000", block.total_forged().arktoshi());

	/*  ==================================  */
	/* needs stream->string size fix for large callbacks */
	//  String blocks = _arkManager.blocks();
	//	Serial.println(blocks);
	//	Serial.println();
	/*  ==================================  */
}

TEST(api, test_block_epoch)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	char epoch[24 + 1];
	_arkManager.blockEpoch(epoch);
	const char* epochResponse = epoch;
	ASSERT_STREQ("2017-03-21T13:00:00.000Z", epochResponse);
}

TEST(api, test_block_height)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto height = _arkManager.blockHeight();
	ASSERT_STRNE("0", height.id());
	ASSERT_STRNE("0", height.height());
}

TEST(api, test_block_net_hash)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", _arkManager.blockNethash().getValue());
}

TEST(api, test_block_fee)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto block_fee = _arkManager.blockFee();
	ASSERT_STREQ(".10000000", block_fee.ark());
	ASSERT_STREQ("10000000", block_fee.arktoshi());
}

TEST(api, test_block_fees)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto fees = _arkManager.blockFees();
	ASSERT_STREQ("10000000", fees.send().arktoshi());
	ASSERT_STREQ("100000000", fees.vote().arktoshi());
	ASSERT_STREQ("500000000", fees.delegate().arktoshi());
	ASSERT_STREQ("2500000000", fees.second_signature().arktoshi());
	ASSERT_STREQ("500000000", fees.multi_signature().arktoshi());
}

TEST(api, test_block_milestone)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	ASSERT_STRNE("0", _arkManager.blockMilestone());
}

TEST(api, test_block_reward)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto block_reward = _arkManager.blockReward();
	ASSERT_STREQ("2.00000000", block_reward.ark());
	ASSERT_STREQ("200000000", block_reward.arktoshi());
}

TEST(api, test_block_supply)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);
	const auto block_supply = _arkManager.blockSupply();
	ASSERT_STRNE("0.0", block_supply.ark());
	ASSERT_STRNE("0", block_supply.arktoshi());
}

TEST(api, test_block_status)
{
	ARK::API::Manager _arkManager(ARK::Constants::Networks::Model::Devnet);	
	const auto block_status = _arkManager.blockStatus();
	ASSERT_STREQ("2017-03-21T13:00:00.000Z", block_status.epoch());
	ASSERT_STRNE("0", block_status.height());
	const auto& fee = block_status.fee();
	ASSERT_STREQ(".10000000", fee.ark());
	ASSERT_STREQ("10000000", fee.arktoshi());
	ASSERT_NE(0, block_status.milestone());
	ASSERT_STREQ("578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23", block_status.nethash().getValue());
	const auto& reward = block_status.reward();
	ASSERT_STREQ("2.00000000", reward.ark());
	ASSERT_STREQ("200000000", reward.arktoshi());
	const auto& supply = block_status.supply();
	ASSERT_STRNE("0.0", supply.ark());
	ASSERT_STRNE("0", supply.arktoshi());
}
