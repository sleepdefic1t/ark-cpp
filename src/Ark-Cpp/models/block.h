

#ifndef BLOCK_H
#define BLOCK_H

/********************************************************************************
*
* block: 
*		{  
*			"id":	String(lluint),
*			"version":	int,
*			"timestamp":	String(lluint),
*			"height":	uint,
*			"previousBlock":	String(lluint),
*			"numberOfTransactions": int,
*			"totalAmount": Balance,
*			"totalFee":	Balance::arktoshi,
*			"reward":	Balance::arktoshi,
*			"payloadLength": int,
*			"payloadHash":	Hash,
*			"generatorPublicKey":	Publickey,
*			"generatorId": Address,
*			"blockSignature": Signature,
*			"confirmations":	int,
*			"totalForged":	Balance
*		}
*
********************************************************************************/

#define MAX_UINT128_CHARS 40

namespace ARK
{
/*************************************************
*   ARK::block_t 
*
**************************************************/
struct block_t
{
	public:
		char id[MAX_UINT128_CHARS];
		int version;
		char timestamp[MAX_UINT128_CHARS];
		char height[64];
		char previousBlock[MAX_UINT128_CHARS];
		char numberOfTransactions[64];
		Balance totalAmount;
		Balance totalFee;
		Balance reward;
		char payloadLength[64];
		Hash payloadHash;
		Publickey generatorPublicKey;
		Address generatorId;
		Signature blockSignature;
		char confirmations[64];
		Balance totalForged;
};
/*************************************************/

/**************************************************************************************************/

/*************************************************
*   ARK::Block 
*
**************************************************/
struct Block :
		public block_t, Printable
{
	public:

		Block(
				const char* const newID,
				int newVersion,
				const char* const newTimestamp,
				const char* const newHeight,
				const char* const newPreviousBlock,
				const char* const newNumberOfTransactions,
				const char* const newTotalAmount,
				const char* const newTotalFee,
				const char* const newReward,
				const char* const newPayloadLength,
				const char* const newPayloadHash,
				const char* const newGeneratorPublickey,
				const char* const newGeneratorID,
				const char* const newBlockSignature,
				const char* const newConfirmations,
				const char* const newTotalForged
		)
		{
			strncpy(id, newID, sizeof(id) / sizeof(id[0]));
				version = newVersion;
			strncpy(timestamp, newTimestamp, sizeof(timestamp) / sizeof(timestamp[0]));
			strncpy(height, newHeight, sizeof(height) / sizeof(height[0]));
			strncpy(previousBlock, newPreviousBlock, sizeof(previousBlock) / sizeof(previousBlock[0]));
			strncpy(numberOfTransactions, newNumberOfTransactions, sizeof(numberOfTransactions) / sizeof(numberOfTransactions[0]));
				totalAmount = Balance(newTotalAmount);
				totalFee = Balance(newTotalFee);
				reward = Balance(newReward);
			strncpy(payloadLength, newPayloadLength, sizeof(payloadLength) / sizeof(payloadLength[0]));
				payloadHash = Hash(newPayloadHash);
				generatorPublicKey = Publickey(newGeneratorPublickey);
				generatorId = Address(newGeneratorID);
				blockSignature = Signature(newBlockSignature);
			strncpy(confirmations, newConfirmations, sizeof(confirmations) / sizeof(confirmations[0]));
				totalForged = Balance(newTotalForged);
		};


		/*************************************************
		*
		**************************************************/
		virtual size_t printTo(Print& p) const
		{
			size_t size = 0;

			size += p.print("id: ");
			size += p.print(this->id);

			size += p.print("\nversion: ");
			size += p.print(this->version);

			size += p.print("\ntimestamp: ");
			size += p.print(this->timestamp);

			size += p.print("\nheight: ");
			size += p.print(this->height);

			size += p.print("\npreviousBlock: ");
			size += p.print(this->previousBlock);

			size += p.print("\nnumberOfTransactions: ");
			size += p.print(this->numberOfTransactions);

			size += p.print("\ntotalAmount: ");
			size += p.print(this->totalAmount.ark());

			size += p.print("\ntotalFee: ");
			size += p.print(this->totalFee.ark());

			size += p.print("\nreward: ");
			size += p.print(this->reward.ark());

			size += p.print("\npayloadLength: ");
			size += p.print(this->payloadLength);

			size += p.print("\npayloadHash: ");
			size += p.print(this->payloadHash);

			size += p.print("\ngeneratorPublicKey: ");
			size += p.print(this->generatorPublicKey);

			size += p.print("\ngeneratorId: ");
			size += p.print(this->generatorId);

			size += p.print("\nblockSignature: ");
			size += p.print(this->blockSignature);

			size += p.print("\nconfirmations: ");
			size += p.print(this->confirmations);

			size += p.print("\ntotalForged: ");
			size += p.print(this->totalForged.ark());

			return size;
		}
		/*************************************************/
};
/*************************************************/

};

#endif
